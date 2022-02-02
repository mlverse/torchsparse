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


