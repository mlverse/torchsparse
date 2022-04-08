#include <torch/torch.h>

using tensor_pair = std::tuple<torch::Tensor,torch::Tensor>;
using tensor_tensor_optionaltensor = std::tuple<torch::Tensor,torch::Tensor, torch::optional<torch::Tensor>>;

namespace make_raw {
  void* TensorPair (const tensor_pair& x);
  void* TensorTensorOptionaltensor (const tensor_tensor_optionaltensor& x);
}

namespace from_raw {
  tensor_pair TensorPair (void* x);
  tensor_tensor_optionaltensor TensorTensorOptionaltensor (void* x);
}


