#include <Rcpp.h>
#define LLTM_HEADERS_ONLY
#include <torchsparse/torchsparse.h>
#define TORCH_IMPL
#define IMPORT_TORCH
#include <torch.h>

void host_exception_handler ()
{
  if (torchsparse_last_error())
  {
    auto msg = Rcpp::as<std::string>(torch::string(torchsparse_last_error()));
    torchsparse_last_error_clear();
    Rcpp::stop(msg);
  }
}
