// Generated by using torchexport::export() -> do not edit by hand
#include "exports.h"
#define TORCHSPARSE_HEADERS_ONLY
#include <torchsparse/torchsparse.h>

// [[Rcpp::export]]
torch::Tensor rcpp_sparse_ind2ptr (torch::Tensor ind, int64_t M) {
  return  sparse_ind2ptr(ind.get(), M);
}
// [[Rcpp::export]]
torch::Tensor rcpp_sparse_ptr2ind (torch::Tensor ptr, int64_t E) {
  return  sparse_ptr2ind(ptr.get(), E);
}
// [[Rcpp::export]]
torch::Tensor rcpp_sparse_partition (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor optional_value, int64_t num_parts, bool recursive) {
  return  sparse_partition(rowptr.get(), col.get(), optional_value.get(), num_parts, recursive);
}
// [[Rcpp::export]]
torch::Tensor rcpp_sparse_partition2 (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor optional_value, torch::optional::Tensor optional_node_weight, int64_t num_parts, bool recursive) {
  return  sparse_partition2(rowptr.get(), col.get(), optional_value.get(), optional_node_weight.get(), num_parts, recursive);
}
// [[Rcpp::export]]
torch::Tensor rcpp_sparse_mt_partition (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor optional_value, torch::optional::Tensor optional_node_weight, int64_t num_parts, bool recursive, int64_t num_workers) {
  return  sparse_mt_partition(rowptr.get(), col.get(), optional_value.get(), optional_node_weight.get(), num_parts, recursive, num_workers);
}
// [[Rcpp::export]]
torchsparse::tensor_pair rcpp_sparse_relabel (torch::Tensor col, torch::Tensor idx) {
  return  sparse_relabel(col.get(), idx.get());
}
// [[Rcpp::export]]
torch::Tensor rcpp_sparse_random_walk (torch::Tensor rowptr, torch::Tensor col, torch::Tensor start, int64_t walk_length) {
  return  sparse_random_walk(rowptr.get(), col.get(), start.get(), walk_length);
}
// [[Rcpp::export]]
torch::Tensor rcpp_sparse_spmm_sum (torch::optional::Tensor opt_row, torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor opt_value, torch::optional::Tensor opt_colptr, torch::optional::Tensor opt_csr2csc, torch::Tensor mat) {
  return  sparse_spmm_sum(opt_row.get(), rowptr.get(), col.get(), opt_value.get(), opt_colptr.get(), opt_csr2csc.get(), mat.get());
}
// [[Rcpp::export]]
torch::Tensor rcpp_sparse_spmm_mean (torch::optional::Tensor opt_row, torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor opt_value, torch::optional::Tensor opt_rowcount, torch::optional::Tensor opt_colptr, torch::optional::Tensor opt_csr2csc, torch::Tensor mat) {
  return  sparse_spmm_mean(opt_row.get(), rowptr.get(), col.get(), opt_value.get(), opt_rowcount.get(), opt_colptr.get(), opt_csr2csc.get(), mat.get());
}
// [[Rcpp::export]]
torchsparse::tensor_pair rcpp_sparse_spmm_min (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor opt_value, torch::Tensor mat) {
  return  sparse_spmm_min(rowptr.get(), col.get(), opt_value.get(), mat.get());
}
// [[Rcpp::export]]
torchsparse::tensor_pair rcpp_sparse_spmm_max (torch::Tensor rowptr, torch::Tensor col, torch::optional::Tensor opt_value, torch::Tensor mat) {
  return  sparse_spmm_max(rowptr.get(), col.get(), opt_value.get(), mat.get());
}
// [[Rcpp::export]]
void rcpp_delete_tensor_pair (void* x) {
   delete_tensor_pair(x);
}
// [[Rcpp::export]]
torch::Tensor rcpp_tensor_pair_get_first (torchsparse::tensor_pair x) {
  return  tensor_pair_get_first(x.get());
}
// [[Rcpp::export]]
torch::Tensor rcpp_tensor_pair_get_second (torchsparse::tensor_pair x) {
  return  tensor_pair_get_second(x.get());
}
// [[Rcpp::export]]
void rcpp_delete_tensor_tensor_optionaltensor (void* x) {
   delete_tensor_tensor_optionaltensor(x);
}
// [[Rcpp::export]]
torch::Tensor rcpp_tensor_tensor_optionaltensor_get_first (torchsparse::tensor_tensor_optionaltensor x) {
  return  tensor_tensor_optionaltensor_get_first(x.get());
}
// [[Rcpp::export]]
torch::Tensor rcpp_tensor_tensor_optionaltensor_get_second (torchsparse::tensor_tensor_optionaltensor x) {
  return  tensor_tensor_optionaltensor_get_second(x.get());
}
// [[Rcpp::export]]
torch::optional::Tensor rcpp_tensor_tensor_optionaltensor_get_third (torchsparse::tensor_tensor_optionaltensor x) {
  return  tensor_tensor_optionaltensor_get_third(x.get());
}
