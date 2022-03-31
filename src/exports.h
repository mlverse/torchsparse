// Generated by using torchexport::export() -> do not edit by hand
#include <Rcpp.h>
#include <torch.h>
#include "torchsparse_types.h"

torch::Tensor rcpp_sparse_ind2ptr (torch::Tensor ind, int64_t M);
torch::Tensor rcpp_sparse_ptr2ind (torch::Tensor ptr, int64_t E);
torch::Tensor rcpp_sparse_partition (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor optional_value, int64_t num_parts, bool recursive);
torch::Tensor rcpp_sparse_partition2 (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor optional_value, torch::optional::Tensor optional_node_weight, int64_t num_parts, bool recursive);
torch::Tensor rcpp_sparse_mt_partition (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor optional_value, torch::optional::Tensor optional_node_weight, int64_t num_parts, bool recursive, int64_t num_workers);
torchsparse::tensor_pair rcpp_sparse_relabel (torch::Tensor col, torch::Tensor idx);
torch::Tensor rcpp_sparse_random_walk (torch::Tensor rowptr, torch::Tensor col, torch::Tensor start, int64_t walk_length);
torch::Tensor rcpp_sparse_spmm_sum (torch::optional::Tensor opt_row, torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor opt_value, torch::optional::Tensor opt_colptr, torch::optional::Tensor opt_csr2csc, torch::Tensor mat);
torch::Tensor rcpp_sparse_spmm_mean (torch::optional::Tensor opt_row, torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor opt_value, torch::optional::Tensor opt_rowcount, torch::optional::Tensor opt_colptr, torch::optional::Tensor opt_csr2csc, torch::Tensor mat);
void rcpp_delete_tensor_pair (void* x);
torch::Tensor rcpp_tensor_pair_get_first (torchsparse::tensor_pair x);
torch::Tensor rcpp_tensor_pair_get_second (torchsparse::tensor_pair x);