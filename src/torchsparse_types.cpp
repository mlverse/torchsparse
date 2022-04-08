#include <Rcpp.h>
#include "torchsparse_types.h"
#include "exports.h"

namespace torchsparse {

void* tensor_pair::get() {
  return ptr.get();
}

tensor_pair::operator SEXP () const {
  Rcpp::List out;
  out.push_back(rcpp_tensor_pair_get_first(*this));
  out.push_back(rcpp_tensor_pair_get_second(*this));
  return out;
}

tensor_pair::tensor_pair (void* x) : ptr(x, rcpp_delete_tensor_pair) {};

void* tensor_tensor_optionaltensor::get() {
  return ptr.get();
}

tensor_tensor_optionaltensor::operator SEXP () const {
  Rcpp::List out;
  out.push_back(rcpp_tensor_tensor_optionaltensor_get_first(*this));
  out.push_back(rcpp_tensor_tensor_optionaltensor_get_second(*this));
  out.push_back(rcpp_tensor_tensor_optionaltensor_get_third(*this));
  return out;
}

tensor_tensor_optionaltensor::tensor_tensor_optionaltensor (void* x) : ptr(x, rcpp_delete_tensor_tensor_optionaltensor) {};


}

