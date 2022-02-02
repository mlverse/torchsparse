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

// torch::Tensor partition(torch::Tensor rowptr,
//                         torch::Tensor col,
//                         torch::optional<torch::Tensor> optional_value,
//                         int64_t num_parts,
//                         bool recursive) {
//   return partition(rowptr, col, optional_value, num_parts, recursive);
// }

// std::tuple<torch::Tensor, torch::Tensor> relabel(torch::Tensor col, torch::Tensor idx) {
//   return relabel(col, idx);
// }

// [[torch::export]]
torch::Tensor sparse_random_walk(torch::Tensor rowptr, torch::Tensor col, torch::Tensor start, int64_t walk_length) {
  return random_walk(rowptr, col, start, walk_length);
}


