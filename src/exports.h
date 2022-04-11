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
torchsparse::tensor_pair rcpp_sparse_spmm_min (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor opt_value, torch::Tensor mat);
torchsparse::tensor_pair rcpp_sparse_spmm_max (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor opt_value, torch::Tensor mat);
torchsparse::tensor_tensor_optionaltensor rcpp_sparse_spspmm_sum (torch::Tensor rowptrA, torch::Tensor colA, torch::optional::Tensor optional_valueA, torch::Tensor rowptrB, torch::Tensor colB, torch::optional::Tensor optional_valueB, int64_t K);
torchsparse::tensor_tensor_optionaltensor_tensor rcpp_sparse_relabel_one_hop (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor optional_value, torch::Tensor idx, bool bipartite);
void rcpp_delete_tensor_pair (void* x);
torch::Tensor rcpp_tensor_pair_get_first (torchsparse::tensor_pair x);
torch::Tensor rcpp_tensor_pair_get_second (torchsparse::tensor_pair x);
void rcpp_delete_tensor_tensor_optionaltensor (void* x);
torch::Tensor rcpp_tensor_tensor_optionaltensor_get_first (torchsparse::tensor_tensor_optionaltensor x);
torch::Tensor rcpp_tensor_tensor_optionaltensor_get_second (torchsparse::tensor_tensor_optionaltensor x);
torch::optional::Tensor rcpp_tensor_tensor_optionaltensor_get_third (torchsparse::tensor_tensor_optionaltensor x);
void rcpp_delete_tensor_tensor_optionaltensor_tensor (void* x);
torch::Tensor rcpp_tensor_tensor_optionaltensor_tensor_get_first (torchsparse::tensor_tensor_optionaltensor_tensor x);
torch::Tensor rcpp_tensor_tensor_optionaltensor_tensor_get_second (torchsparse::tensor_tensor_optionaltensor_tensor x);
torch::optional::Tensor rcpp_tensor_tensor_optionaltensor_tensor_get_third (torchsparse::tensor_tensor_optionaltensor_tensor x);
torch::Tensor rcpp_tensor_tensor_optionaltensor_tensor_get_fourth (torchsparse::tensor_tensor_optionaltensor_tensor x);
