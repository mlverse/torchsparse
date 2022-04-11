// Generated by using torchexport::export() -> do not edit by hand
#include "torchsparse/torchsparse.h"
#include <lantern/types.h>
#include "torchsparse/torchsparse_types.h"
void * p_torchsparse_last_error = NULL;

TORCHSPARSE_API void* torchsparse_last_error()
{
  return p_torchsparse_last_error;
}

TORCHSPARSE_API void torchsparse_last_error_clear()
{
  p_torchsparse_last_error = NULL;
}

torch::Tensor sparse_ind2ptr (torch::Tensor ind, int64_t M);
TORCHSPARSE_API void* _sparse_ind2ptr (void* ind, int64_t M) {
  try {
    return  make_raw::Tensor(sparse_ind2ptr(from_raw::Tensor(ind), M));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor sparse_ptr2ind (torch::Tensor ptr, int64_t E);
TORCHSPARSE_API void* _sparse_ptr2ind (void* ptr, int64_t E) {
  try {
    return  make_raw::Tensor(sparse_ptr2ind(from_raw::Tensor(ptr), E));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor sparse_partition (torch::Tensor rowptr, torch::Tensor col, torch::optional<torch::Tensor> optional_value, int64_t num_parts, bool recursive);
TORCHSPARSE_API void* _sparse_partition (void* rowptr, void* col, void* optional_value, int64_t num_parts, bool recursive) {
  try {
    return  make_raw::Tensor(sparse_partition(from_raw::Tensor(rowptr), from_raw::Tensor(col), from_raw::optional::Tensor(optional_value), num_parts, recursive));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor sparse_partition2 (torch::Tensor rowptr, torch::Tensor col, torch::optional<torch::Tensor> optional_value, torch::optional<torch::Tensor> optional_node_weight, int64_t num_parts, bool recursive);
TORCHSPARSE_API void* _sparse_partition2 (void* rowptr, void* col, void* optional_value, void* optional_node_weight, int64_t num_parts, bool recursive) {
  try {
    return  make_raw::Tensor(sparse_partition2(from_raw::Tensor(rowptr), from_raw::Tensor(col), from_raw::optional::Tensor(optional_value), from_raw::optional::Tensor(optional_node_weight), num_parts, recursive));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor sparse_mt_partition (torch::Tensor rowptr, torch::Tensor col, torch::optional<torch::Tensor> optional_value, torch::optional<torch::Tensor> optional_node_weight, int64_t num_parts, bool recursive, int64_t num_workers);
TORCHSPARSE_API void* _sparse_mt_partition (void* rowptr, void* col, void* optional_value, void* optional_node_weight, int64_t num_parts, bool recursive, int64_t num_workers) {
  try {
    return  make_raw::Tensor(sparse_mt_partition(from_raw::Tensor(rowptr), from_raw::Tensor(col), from_raw::optional::Tensor(optional_value), from_raw::optional::Tensor(optional_node_weight), num_parts, recursive, num_workers));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
tensor_pair sparse_relabel (torch::Tensor col, torch::Tensor idx);
TORCHSPARSE_API void* _sparse_relabel (void* col, void* idx) {
  try {
    return  make_raw::TensorPair(sparse_relabel(from_raw::Tensor(col), from_raw::Tensor(idx)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor sparse_random_walk (torch::Tensor rowptr, torch::Tensor col, torch::Tensor start, int64_t walk_length);
TORCHSPARSE_API void* _sparse_random_walk (void* rowptr, void* col, void* start, int64_t walk_length) {
  try {
    return  make_raw::Tensor(sparse_random_walk(from_raw::Tensor(rowptr), from_raw::Tensor(col), from_raw::Tensor(start), walk_length));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor sparse_spmm_sum (torch::optional<torch::Tensor> opt_row, torch::Tensor rowptr, torch::Tensor col, torch::optional<torch::Tensor> opt_value, torch::optional<torch::Tensor> opt_colptr, torch::optional<torch::Tensor> opt_csr2csc, torch::Tensor mat);
TORCHSPARSE_API void* _sparse_spmm_sum (void* opt_row, void* rowptr, void* col, void* opt_value, void* opt_colptr, void* opt_csr2csc, void* mat) {
  try {
    return  make_raw::Tensor(sparse_spmm_sum(from_raw::optional::Tensor(opt_row), from_raw::Tensor(rowptr), from_raw::Tensor(col), from_raw::optional::Tensor(opt_value), from_raw::optional::Tensor(opt_colptr), from_raw::optional::Tensor(opt_csr2csc), from_raw::Tensor(mat)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor sparse_spmm_mean (torch::optional<torch::Tensor> opt_row, torch::Tensor rowptr, torch::Tensor col, torch::optional<torch::Tensor> opt_value, torch::optional<torch::Tensor> opt_rowcount, torch::optional<torch::Tensor> opt_colptr, torch::optional<torch::Tensor> opt_csr2csc, torch::Tensor mat);
TORCHSPARSE_API void* _sparse_spmm_mean (void* opt_row, void* rowptr, void* col, void* opt_value, void* opt_rowcount, void* opt_colptr, void* opt_csr2csc, void* mat) {
  try {
    return  make_raw::Tensor(sparse_spmm_mean(from_raw::optional::Tensor(opt_row), from_raw::Tensor(rowptr), from_raw::Tensor(col), from_raw::optional::Tensor(opt_value), from_raw::optional::Tensor(opt_rowcount), from_raw::optional::Tensor(opt_colptr), from_raw::optional::Tensor(opt_csr2csc), from_raw::Tensor(mat)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
tensor_pair sparse_spmm_min (torch::Tensor rowptr, torch::Tensor col, torch::optional<torch::Tensor> opt_value, torch::Tensor mat);
TORCHSPARSE_API void* _sparse_spmm_min (void* rowptr, void* col, void* opt_value, void* mat) {
  try {
    return  make_raw::TensorPair(sparse_spmm_min(from_raw::Tensor(rowptr), from_raw::Tensor(col), from_raw::optional::Tensor(opt_value), from_raw::Tensor(mat)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
tensor_pair sparse_spmm_max (torch::Tensor rowptr, torch::Tensor col, torch::optional<torch::Tensor> opt_value, torch::Tensor mat);
TORCHSPARSE_API void* _sparse_spmm_max (void* rowptr, void* col, void* opt_value, void* mat) {
  try {
    return  make_raw::TensorPair(sparse_spmm_max(from_raw::Tensor(rowptr), from_raw::Tensor(col), from_raw::optional::Tensor(opt_value), from_raw::Tensor(mat)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
tensor_tensor_optionaltensor sparse_spspmm_sum (torch::Tensor rowptrA, torch::Tensor colA, torch::optional<torch::Tensor> optional_valueA, torch::Tensor rowptrB, torch::Tensor colB, torch::optional<torch::Tensor> optional_valueB, int64_t K);
TORCHSPARSE_API void* _sparse_spspmm_sum (void* rowptrA, void* colA, void* optional_valueA, void* rowptrB, void* colB, void* optional_valueB, int64_t K) {
  try {
    return  make_raw::TensorTensorOptionaltensor(sparse_spspmm_sum(from_raw::Tensor(rowptrA), from_raw::Tensor(colA), from_raw::optional::Tensor(optional_valueA), from_raw::Tensor(rowptrB), from_raw::Tensor(colB), from_raw::optional::Tensor(optional_valueB), K));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
tensor_tensor_optionaltensor_tensor sparse_relabel_one_hop (torch::Tensor rowptr, torch::Tensor col, torch::optional<torch::Tensor> optional_value, torch::Tensor idx, bool bipartite);
TORCHSPARSE_API void* _sparse_relabel_one_hop (void* rowptr, void* col, void* optional_value, void* idx, bool bipartite) {
  try {
    return  make_raw::TensorTensorOptionaltensorTensor(sparse_relabel_one_hop(from_raw::Tensor(rowptr), from_raw::Tensor(col), from_raw::optional::Tensor(optional_value), from_raw::Tensor(idx), bipartite));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
void delete_tensor_pair (void* x);
TORCHSPARSE_API void _delete_tensor_pair (void* x) {
  try {
     (delete_tensor_pair(x));
  } TORCHSPARSE_HANDLE_EXCEPTION
  
}
torch::Tensor tensor_pair_get_first (tensor_pair x);
TORCHSPARSE_API void* _tensor_pair_get_first (void* x) {
  try {
    return  make_raw::Tensor(tensor_pair_get_first(from_raw::TensorPair(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor tensor_pair_get_second (tensor_pair x);
TORCHSPARSE_API void* _tensor_pair_get_second (void* x) {
  try {
    return  make_raw::Tensor(tensor_pair_get_second(from_raw::TensorPair(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
void delete_tensor_tensor_optionaltensor (void* x);
TORCHSPARSE_API void _delete_tensor_tensor_optionaltensor (void* x) {
  try {
     (delete_tensor_tensor_optionaltensor(x));
  } TORCHSPARSE_HANDLE_EXCEPTION
  
}
torch::Tensor tensor_tensor_optionaltensor_get_first (tensor_tensor_optionaltensor x);
TORCHSPARSE_API void* _tensor_tensor_optionaltensor_get_first (void* x) {
  try {
    return  make_raw::Tensor(tensor_tensor_optionaltensor_get_first(from_raw::TensorTensorOptionaltensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor tensor_tensor_optionaltensor_get_second (tensor_tensor_optionaltensor x);
TORCHSPARSE_API void* _tensor_tensor_optionaltensor_get_second (void* x) {
  try {
    return  make_raw::Tensor(tensor_tensor_optionaltensor_get_second(from_raw::TensorTensorOptionaltensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::optional<torch::Tensor> tensor_tensor_optionaltensor_get_third (tensor_tensor_optionaltensor x);
TORCHSPARSE_API void* _tensor_tensor_optionaltensor_get_third (void* x) {
  try {
    return  make_raw::optional::Tensor(tensor_tensor_optionaltensor_get_third(from_raw::TensorTensorOptionaltensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
void delete_tensor_tensor_tensor (void* x);
TORCHSPARSE_API void _delete_tensor_tensor_tensor (void* x) {
  try {
     (delete_tensor_tensor_tensor(x));
  } TORCHSPARSE_HANDLE_EXCEPTION
  
}
torch::Tensor tensor_tensor_tensor_get_first (tensor_tensor_tensor x);
TORCHSPARSE_API void* _tensor_tensor_tensor_get_first (void* x) {
  try {
    return  make_raw::Tensor(tensor_tensor_tensor_get_first(from_raw::TensorTensorTensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor tensor_tensor_tensor_get_second (tensor_tensor_tensor x);
TORCHSPARSE_API void* _tensor_tensor_tensor_get_second (void* x) {
  try {
    return  make_raw::Tensor(tensor_tensor_tensor_get_second(from_raw::TensorTensorTensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::optional<torch::Tensor> tensor_tensor_tensor_get_third (tensor_tensor_tensor x);
TORCHSPARSE_API void* _tensor_tensor_tensor_get_third (void* x) {
  try {
    return  make_raw::optional::Tensor(tensor_tensor_tensor_get_third(from_raw::TensorTensorTensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
void delete_tensor_tensor_optionaltensor_tensor (void* x);
TORCHSPARSE_API void _delete_tensor_tensor_optionaltensor_tensor (void* x) {
  try {
     (delete_tensor_tensor_optionaltensor_tensor(x));
  } TORCHSPARSE_HANDLE_EXCEPTION
  
}
torch::Tensor tensor_tensor_optionaltensor_tensor_get_first (tensor_tensor_optionaltensor_tensor x);
TORCHSPARSE_API void* _tensor_tensor_optionaltensor_tensor_get_first (void* x) {
  try {
    return  make_raw::Tensor(tensor_tensor_optionaltensor_tensor_get_first(from_raw::TensorTensorOptionaltensorTensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor tensor_tensor_optionaltensor_tensor_get_second (tensor_tensor_optionaltensor_tensor x);
TORCHSPARSE_API void* _tensor_tensor_optionaltensor_tensor_get_second (void* x) {
  try {
    return  make_raw::Tensor(tensor_tensor_optionaltensor_tensor_get_second(from_raw::TensorTensorOptionaltensorTensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::optional<torch::Tensor> tensor_tensor_optionaltensor_tensor_get_third (tensor_tensor_optionaltensor_tensor x);
TORCHSPARSE_API void* _tensor_tensor_optionaltensor_tensor_get_third (void* x) {
  try {
    return  make_raw::optional::Tensor(tensor_tensor_optionaltensor_tensor_get_third(from_raw::TensorTensorOptionaltensorTensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
torch::Tensor tensor_tensor_optionaltensor_tensor_get_fourth (tensor_tensor_optionaltensor_tensor x);
TORCHSPARSE_API void* _tensor_tensor_optionaltensor_tensor_get_fourth (void* x) {
  try {
    return  make_raw::Tensor(tensor_tensor_optionaltensor_tensor_get_fourth(from_raw::TensorTensorOptionaltensorTensor(x)));
  } TORCHSPARSE_HANDLE_EXCEPTION
  return (void*) NULL;
}
