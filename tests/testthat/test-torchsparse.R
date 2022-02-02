test_that("rcpp_sparse_ind2ptr, rcpp_sparse_ptr2ind", {

  expect_length(as.numeric(rcpp_sparse_ind2ptr(rcpp_sparse_ptr2ind(torch::torch_tensor(1L), 1), 1)), 2)

})
