# Project name and cmake minimum requirement.
project(torchsparselib)
cmake_minimum_required(VERSION 3.16)

# We find a LibTorch installation trough the torch package.
# This is the best approach if we want to make sure we are
# targetting the same LibTorch version as used by torch.
execute_process (
    COMMAND Rscript -e "cat(torch::torch_install_path())"
    OUTPUT_VARIABLE TORCH_HOME
)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${TORCH_HOME}")

# Now that the prefix path is set we can tell cmake to go
# and find Torch.
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# Setup compilation for pytorch_sparse
include(ExternalProject)
set(PyTorchSparse_DESTDIR ${CMAKE_CURRENT_BINARY_DIR}/lib/)
set(PyTorchSparse_CMAKE_ARGS -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH} -DCMAKE_INSTALL_PREFIX=${PyTorchSparse_DESTDIR})

ExternalProject_Add(PyTorchSparse-project
  GIT_REPOSITORY https://github.com/rusty1s/pytorch_sparse
  GIT_TAG master
  CMAKE_ARGS ${PyTorchSparse_CMAKE_ARGS}
  PREFIX "${CMAKE_CURRENT_BINARY_DIR}/libpytorchsparse"
)

SET(PyTorchSparse_INCLUDE_DIR ${PyTorchSparse_DESTDIR}/include)
SET(PyTorchSparse_LIB_DIR ${PyTorchSparse_DESTDIR}/lib)

if(APPLE)
  SET(PyTorchSparse_LIB_LOCATION ${PyTorchSparse_LIB_DIR}/libtorchsparse.dylib)
elseif(WIN32)
  SET(PyTorchSparse_LIB_LOCATION ${PyTorchSparse_DESTDIR}/bin/torchsparse.dll)
else()
  SET(PyTorchSparse_LIB_LOCATION ${PyTorchSparse_LIB_DIR}/libtorchsparse.so)
endif()

add_library(PyTorchSparse SHARED IMPORTED)
add_library(PyTorchSparse::library ALIAS PyTorchSparse)
set_target_properties(PyTorchSparse PROPERTIES IMPORTED_LOCATION ${PyTorchSparse_LIB_LOCATION})
set_target_properties(PyTorchSparse PROPERTIES OUTPUT_NAME "pytorchsparse")

# Here we tell CMake what are the source files of our package.
# If you want to separate your implementation in multiple files
# add their paths after `src/lltm.cpp`, the spearator is a simple
# space.
set(TORCHSPARSE_SRC src/torchsparse.cpp src/exports.cpp)
set(TORCHSPARSE_HEADERS include/torchsparse/torchsparse.h include/torchsparse/exports.h)

# On Windows we use module definition files to declare what are
# the exported functions from the library. It's similar to the
# Namespace file in the R ecossystem.
# We need to fill it manually as its used to link the Rcpp interface
# with the `csrc` library.
if(WIN32)
  set(LLRM_SRC ${LLTM_SRC} lltm.def)
endif()

# Tell cmake to build the shared library.
add_library(torchsparselib SHARED ${TORCHSPARSE_SRC})
add_library(torchsparselib::library ALIAS torchsparselib)

# Tell cmake what are the include files.
target_include_directories(torchsparselib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PyTorchSparse_INCLUDE_DIR}
)
set_property(TARGET torchsparselib
 PROPERTY PUBLIC_HEADER ${TORCHSPARSE_HEADERS})

add_dependencies(torchsparselib PyTorchSparse-project)

# Tell cmake the libraries we want to link to.
message(STATUS "${TORCH_LIBRARIES}")
target_link_libraries(torchsparselib "${TORCH_LIBRARIES}")
target_link_libraries(torchsparselib PyTorchSparse)

set_property(TARGET torchsparselib PROPERTY CXX_STANDARD 17)

add_custom_target(torchsparselib_export
  COMMAND Rscript -e "torchexport::export()"
  COMMENT "Regenerating export code."
  VERBATIM
)
add_dependencies(torchsparselib torchsparselib_export)

# Syncronize the headers and the def file with the Rcpp
# interface.
add_custom_command(TARGET torchsparselib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/src/torchsparse.def ${PROJECT_SOURCE_DIR}/../inst/def/torchsparse.def
    COMMENT "Copied def file to inst folder."
)

# Set CPack related code to automatically generate installation bundles.
# The bundle name will have the same version as defined in the R DESCRIPTION
# file.
# The cpack configuration is used by the CI/CD workflows to create the pre-built
# binaries bundles and upload them to the GitHub Releases page.
set(CPACK_GENERATOR ZIP)
execute_process (
    COMMAND Rscript -e "cat(desc::description$new(file = '../../DESCRIPTION')$get('Version'))"
    OUTPUT_VARIABLE CPACK_PACKAGE_VERSION
)

if(DEFINED ${CUDA_VERSION_STRING})
  set(CPACK_PACKAGE_VERSION ${CPACK_PACKAGE_VERSION}+cu${CUDA_VERSION_STRING})
else()
  set(CPACK_PACKAGE_VERSION ${CPACK_PACKAGE_VERSION}+cpu)
endif()


include(CPack)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../inst)
install(TARGETS torchsparselib LIBRARY PUBLIC_HEADER DESTINATION include/torchsparse)
