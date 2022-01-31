## usethis namespace: start
#' @importFrom Rcpp sourceCpp
#' @importFrom utils download.file packageDescription unzip
## usethis namespace: end
NULL

.onLoad <- function(lib, pkg) {
  if (torch::torch_is_installed()) {

    if (!torchsparse_is_installed())
      install_torchsparse()

    if (!torchsparse_is_installed()) {
      if (interactive())
        warning("libtorchsparse is not installed. Run `intall_torchsparse()` before using the package.")
    } else {
      dyn.load(lib_path("torchsparse"), local = FALSE)
      dyn.load(lib_path("torchsparselib"), local = FALSE)

      # when using devtools::load_all() the library might be available in
      # `lib/pkg/src`
      pkgload <- file.path(lib, pkg, "src", paste0(pkg, .Platform$dynlib.ext))
      if (file.exists(pkgload))
        dyn.load(pkgload)
      else
        library.dynam("torchsparse", pkg, lib)
    }
  }
}

inst_path <- function() {
  install_path <- Sys.getenv("TORCHSPARSE_HOME")
  if (nzchar(install_path)) return(install_path)

  system.file("", package = "torchsparse")
}

lib_path <- function(name = "torchsparse") {
  install_path <- inst_path()

  if (.Platform$OS.type == "unix") {
    if (file.exists(file.path(install_path, "lib64"))) {
      file.path(install_path, "lib64", paste0("lib", name, lib_ext()))
    } else {
      file.path(install_path, "lib", paste0("lib", name, lib_ext()))
    }
  } else {
    file.path(install_path, "bin", paste0(name, lib_ext()))
  }
}

lib_ext <- function() {
  if (grepl("darwin", version$os))
    ".dylib"
  else if (grepl("linux", version$os))
    ".so"
  else
    ".dll"
}

torchsparse_is_installed <- function() {
  file.exists(lib_path())
}

install_torchsparse <- function(url = Sys.getenv("TORCHSPARSE_URL", unset = NA)) {

  if (!interactive() && Sys.getenv("TORCH_INSTALL", unset = 0) == "0") return()

  if (is.na(url)) {
    tmp <- tempfile(fileext = ".zip")
    version <- packageDescription("torchsparse")$Version
    os <- get_cmake_style_os()
    dev <- if (torch::cuda_is_available()) "cu" else "cpu"

    url <- sprintf("https://github.com/mlverse/torchsparse/releases/download/libtorchsparse/torchsparse-%s+%s-%s.zip",
                   version, dev, os)
  }

  if (is_url(url)) {
    file <- tempfile(fileext = ".zip")
    on.exit(unlink(file), add = TRUE)
    download.file(url = url, destfile = file)
  } else {
    message('Using file ', url)
    file <- url
  }

  tmp <- tempfile()
  on.exit(unlink(tmp), add = TRUE)
  unzip(file, exdir = tmp)

  file.copy(
    list.files(list.files(tmp, full.names = TRUE), full.names = TRUE),
    inst_path(),
    recursive = TRUE
  )
}

get_cmake_style_os <- function() {
  os <- version$os
  if (grepl("darwin", os)) {
    "Darwin"
  } else if (grepl("linux", os)) {
    "Linux"
  } else {
    "win64"
  }
}

is_url <- function(x) {
  grepl("^https", x) || grepl("^http", x)
}

