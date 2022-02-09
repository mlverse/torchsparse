#include <Rcpp.h>
#include "torchsparse_types.h"
#define TORCHSPARSE_HEADERS_ONLY
#include <torchsparse/torchsparse.h>

namespace torchsparse {

tensor_pair::operator SEXP () const {
  Rcpp::List out;
  out.push_back(torch::Tensor(tensor_pair_get_first(ptr.get())));
  out.push_back(torch::Tensor(tensor_pair_get_second(ptr.get())));
  return out;
}

tensor_pair::tensor_pair (void* x) : ptr(x, delete_tensor_pair) {};

}

