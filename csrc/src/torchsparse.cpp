#include <torch/torch.h>
#define LANTERN_TYPES_IMPL // Should be defined only in a single file.
#include <lantern/types.h>
#include <iostream>
#include <vector>
#include "torchsparse/torchsparse.h"
#include "torchsparse/torchsparse_types.h"
#include <torchsparse/sparse.h>

// [[torch::export]]
torch::Tensor sparse_ind2ptr(torch::Tensor ind, int64_t M) {
  return ind2ptr(ind, M);
}

// [[torch::export]]
torch::Tensor sparse_ptr2ind(torch::Tensor ptr, int64_t E) {
  return ptr2ind(ptr, E);
}

// [[torch::export]]
torch::Tensor sparse_partition(torch::Tensor rowptr,
                        torch::Tensor col,
                        torch::optional<torch::Tensor> optional_value,
                        int64_t num_parts,
                        bool recursive) {
  return partition(rowptr, col, optional_value, num_parts, recursive);
}

// [[torch::export]]
torch::Tensor sparse_partition2(torch::Tensor rowptr,
                         torch::Tensor col,
                         torch::optional<torch::Tensor> optional_value,
                         torch::optional<torch::Tensor> optional_node_weight,
                         int64_t num_parts,
                         bool recursive) {
  return partition2(rowptr, col, optional_value, optional_node_weight, num_parts, recursive);
}

// [[torch::export]]
torch::Tensor sparse_mt_partition(torch::Tensor rowptr,
                           torch::Tensor col,
                           torch::optional<torch::Tensor> optional_value,
                           torch::optional<torch::Tensor> optional_node_weight,
                           int64_t num_parts,
                           bool recursive,
                           int64_t num_workers) {
  return mt_partition(rowptr, col, optional_value, optional_node_weight, num_parts, recursive, num_workers);
}

// [[torch::export(register_types=c("tensor_pair", "TensorPair", "void*", "torchsparse::tensor_pair"))]]
tensor_pair sparse_relabel(torch::Tensor col, torch::Tensor idx) {
  return relabel(col, idx);
}

// [[torch::export]]
torch::Tensor sparse_random_walk(torch::Tensor rowptr, torch::Tensor col, torch::Tensor start, int64_t walk_length) {
  return random_walk(rowptr, col, start, walk_length);
}

// [[torch::export]]
torch::Tensor sparse_spmm_sum(torch::optional<torch::Tensor> opt_row,
                              torch::Tensor rowptr,
                              torch::Tensor col,
                              torch::optional<torch::Tensor> opt_value,
                              torch::optional<torch::Tensor> opt_colptr,
                              torch::optional<torch::Tensor> opt_csr2csc,
                              torch::Tensor mat) {
  return spmm_sum(opt_row, rowptr, col, opt_value, opt_colptr, opt_csr2csc, mat);
}

// [[torch::export]]
torch::Tensor sparse_spmm_mean(torch::optional<torch::Tensor> opt_row,
                               torch::Tensor rowptr,
                               torch::Tensor col,
                               torch::optional<torch::Tensor> opt_value,
                               torch::optional<torch::Tensor> opt_rowcount,
                               torch::optional<torch::Tensor> opt_colptr,
                               torch::optional<torch::Tensor> opt_csr2csc,
                               torch::Tensor mat) {
  return spmm_mean(opt_row, rowptr, col, opt_value, opt_rowcount, opt_colptr, opt_csr2csc, mat);
}

// [[torch::export]]
tensor_pair sparse_spmm_min(torch::Tensor rowptr,
                            torch::Tensor col,
                            torch::optional<torch::Tensor> opt_value,
                            torch::Tensor mat) {
  return spmm_min(rowptr, col, opt_value, mat);
}

// [[torch::export]]
tensor_pair sparse_spmm_max(torch::Tensor rowptr,
                            torch::Tensor col,
                            torch::optional<torch::Tensor> opt_value,
                            torch::Tensor mat) {
  return spmm_max(rowptr, col, opt_value, mat);
}


// [[torch::export]]
tensor_tensor_optionaltensor sparse_spspmm_sum(torch::Tensor rowptrA,
                                               torch::Tensor colA,
                                               torch::optional<torch::Tensor> optional_valueA,
                                               torch::Tensor rowptrB,
                                               torch::Tensor colB,
                                               torch::optional<torch::Tensor> optional_valueB,
                                               int64_t K) {
  return spspmm_sum(rowptrA, colA, optional_valueA, rowptrB, colB, optional_valueB, K);
}

// [[torch::export]]
tensor_tensor_optionaltensor_tensor sparse_relabel_one_hop(torch::Tensor rowptr,
                                                           torch::Tensor col,
                                                           torch::optional<torch::Tensor> optional_value,
                                                           torch::Tensor idx,
                                                           bool bipartite) {
  return relabel_one_hop(rowptr, col, optional_value, idx, bipartite);
}

