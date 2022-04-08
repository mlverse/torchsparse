#pragma once
#include <torch.h>

namespace torchsparse {
class tensor_pair {
public:
  std::shared_ptr<void> ptr;
  tensor_pair (void* x);
  operator SEXP () const;
  void* get ();
};
class tensor_tensor_optionaltensor {
public:
  std::shared_ptr<void> ptr;
  tensor_tensor_optionaltensor (void* x);
  operator SEXP () const;
  void* get ();
};
}
