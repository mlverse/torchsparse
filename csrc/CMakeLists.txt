cmake_minimum_required(VERSION 3.16)

# accommodate differing conventions
include(GNUInstallDirs)

# We find a LibTorch installation trough the torch package.
# This is the best approach if we want to make sure we are
# targeting the same LibTorch version as used by torch.
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
set(PyTorchSparse_CMAKE_ARGS -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH} -DCMAKE_INSTALL_PREFIX=${PyTorchSparse_DESTDIR} -DWITH_PYTHON=OFF)

ExternalProject_Add(PyTorchSparse-project
  GIT_REPOSITORY https://github.com/rusty1s/pytorch_sparse
  GIT_TAG f79c8e984e7544ee6f457951980e4e6656caeb94
  CMAKE_ARGS ${PyTorchSparse_CMAKE_ARGS}
  PREFIX "${CMAKE_CURRENT_BINARY_DIR}/libpytorchsparse"
)

SET(PyTorchSparse_INCLUDE_DIR ${PyTorchSparse_DESTDIR}/include)
SET(PyTorchSparse_LIB_DIR ${PyTorchSparse_DESTDIR}/${CMAKE_INSTALL_LIBDIR})

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
if (WIN32)
  set_target_properties(PyTorchSparse PROPERTIES IMPORTED_IMPLIB ${PyTorchSparse_DESTDIR}/lib/torchsparse.lib)
endif()

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
install(DIRECTORY ${PyTorchSparse_DESTDIR}/ DESTINATION .)
