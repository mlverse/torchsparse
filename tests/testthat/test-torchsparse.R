test_that("rcpp_sparse_ind2ptr", {

  row <- torch::torch_tensor(c(2, 2, 4, 5, 5, 6), dtype = torch::torch_long())
  rowptr <- rcpp_sparse_ind2ptr(row, 8)
  expect_equal(as.numeric(rowptr), c(0, 0, 0, 2, 2, 3, 5, 6, 6))

})

test_that("rcpp_sparse_ptr2ind", {

  rowptr <- torch::torch_tensor(c(0, 0, 0, 2, 2, 3, 5, 6, 6), dtype = torch::torch_long())
  row <- rcpp_sparse_ptr2ind(rowptr, 6)
  expect_equal(as.numeric(row), c(2, 2, 4, 5, 5, 6))

})

test_that("rcpp_partition", {

  NULL


})

test_that("rcpp_sparse_random_walk", {

  w <- rcpp_sparse_random_walk(torch::torch_tensor(c(0, 1, 2), dtype = torch::torch_long()), torch::torch_tensor(1L), torch::torch_tensor(1L), 1)
  expect_equal(length(dim(w)), 2)

})

test_that("rcpp_sparse_spmm_sum", {

 NULL

})

test_that("rcpp_sparse_spmm_mean", {

  NULL

})


