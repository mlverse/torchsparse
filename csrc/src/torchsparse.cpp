#include <torch/torch.h>
#define LANTERN_TYPES_IMPL // Should be defined only in a single file.
#include <lantern/types.h>
#include <iostream>
#include <vector>
#include "torchsparse/torchsparse.h"
#include <torchsparse/sparse.h>

// [[torch::export]]
torch::Tensor sparse_ind2ptr(torch::Tensor ind, int64_t M) {
  return ind2ptr(ind, M);
}

// [[torch::export]]
torch::Tensor sparse_ptr2ind(torch::Tensor ptr, int64_t E) {
  return ptr2ind(ptr, E);
}


