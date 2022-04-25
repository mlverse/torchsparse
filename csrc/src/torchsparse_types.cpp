#include <torch/torch.h>
#include "torchsparse/torchsparse_types.h"
#include <torchsparse/sparse.h>
#include <lantern/types.h>

namespace make_raw {
void* TensorPair (const tensor_pair& x) {
  return make_ptr<tensor_pair>(x);
}
void* TensorTensorOptionaltensor (const tensor_tensor_optionaltensor& x) {
  return make_ptr<tensor_tensor_optionaltensor>(x);
}
void* TensorTensorTensor (const tensor_tensor_tensor& x) {
  return make_ptr<tensor_tensor_tensor>(x);
}
void* TensorTensorOptionaltensorTensor (const tensor_tensor_optionaltensor_tensor& x) {
  return make_ptr<tensor_tensor_optionaltensor_tensor>(x);
}
void* TensorTensorTensorTensor (const tensor_tensor_tensor_tensor& x) {
  return make_ptr<tensor_tensor_tensor_tensor>(x);
}
}

namespace from_raw {
tensor_pair TensorPair (void* x) {
  return *reinterpret_cast<tensor_pair*>(x);
}
tensor_tensor_optionaltensor TensorTensorOptionaltensor (void* x) {
  return *reinterpret_cast<tensor_tensor_optionaltensor*>(x);
}
tensor_tensor_tensor TensorTensorTensor (void* x) {
  return *reinterpret_cast<tensor_tensor_tensor*>(x);
}
tensor_tensor_optionaltensor_tensor TensorTensorOptionaltensorTensor (void* x) {
  return *reinterpret_cast<tensor_tensor_optionaltensor_tensor*>(x);
}
tensor_tensor_tensor_tensor TensorTensorTensorTensor (void* x) {
  return *reinterpret_cast<tensor_tensor_tensor_tensor*>(x);
}
}

// [[torch::export]]
void delete_tensor_pair(void* x) {
  delete reinterpret_cast<tensor_pair*>(x);
}

// [[torch::export]]
torch::Tensor tensor_pair_get_first(tensor_pair x) {
  return std::get<0>(x);
}

// [[torch::export]]
torch::Tensor tensor_pair_get_second(tensor_pair x) {
  return std::get<1>(x);
}

// [[torch::export(register_types=c("tensor_tensor_optionaltensor", "TensorTensorOptionaltensor", "void*", "torchsparse::tensor_tensor_optionaltensor"))]]
void delete_tensor_tensor_optionaltensor(void* x) {
  delete reinterpret_cast<tensor_tensor_optionaltensor*>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_optionaltensor_get_first(tensor_tensor_optionaltensor x) {
  return std::get<0>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_optionaltensor_get_second(tensor_tensor_optionaltensor x) {
  return std::get<1>(x);
}

// [[torch::export]]
torch::optional<torch::Tensor> tensor_tensor_optionaltensor_get_third(tensor_tensor_optionaltensor x) {
  return std::get<2>(x);
}

// [[torch::export(register_types=c("tensor_tensor_tensor", "TensorTensorTensor", "void*", "torchsparse::tensor_tensor_tensor"))]]
void delete_tensor_tensor_tensor(void* x) {
  delete reinterpret_cast<tensor_tensor_tensor*>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_tensor_get_first(tensor_tensor_tensor x) {
  return std::get<0>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_tensor_get_second(tensor_tensor_tensor x) {
  return std::get<1>(x);
}

// [[torch::export]]
torch::optional<torch::Tensor> tensor_tensor_tensor_get_third(tensor_tensor_tensor x) {
  return std::get<2>(x);
}

// [[torch::export(register_types=c("tensor_tensor_optionaltensor_tensor", "TensorTensorOptionaltensorTensor", "void*", "torchsparse::tensor_tensor_optionaltensor_tensor"))]]
void delete_tensor_tensor_optionaltensor_tensor(void* x) {
  delete reinterpret_cast<tensor_tensor_optionaltensor_tensor*>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_optionaltensor_tensor_get_first(tensor_tensor_optionaltensor_tensor x) {
  return std::get<0>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_optionaltensor_tensor_get_second(tensor_tensor_optionaltensor_tensor x) {
  return std::get<1>(x);
}

// [[torch::export]]
torch::optional<torch::Tensor> tensor_tensor_optionaltensor_tensor_get_third(tensor_tensor_optionaltensor_tensor x) {
  return std::get<2>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_optionaltensor_tensor_get_fourth(tensor_tensor_optionaltensor_tensor x) {
  return std::get<3>(x);
}

// [[torch::export(register_types=c("tensor_tensor_tensor_tensor", "TensorTensorTensorTensor", "void*", "torchsparse::tensor_tensor_tensor_tensor"))]]
void delete_tensor_tensor_tensor_tensor(void* x) {
  delete reinterpret_cast<tensor_tensor_tensor_tensor*>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_tensor_tensor_get_first(tensor_tensor_tensor_tensor x) {
  return std::get<0>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_tensor_tensor_get_second(tensor_tensor_tensor_tensor x) {
  return std::get<1>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_tensor_tensor_get_third(tensor_tensor_tensor_tensor x) {
  return std::get<2>(x);
}

// [[torch::export]]
torch::Tensor tensor_tensor_tensor_tensor_get_fourth(tensor_tensor_tensor_tensor x) {
  return std::get<3>(x);
}
