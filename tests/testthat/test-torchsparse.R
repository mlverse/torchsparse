test_that("multiplication works", {

  expect_error(
    rcpp_sparse_ind2ptr(torch::torch_tensor(1), 1)
  )

  expect_error(
    rcpp_sparse_ptr2ind(torch::torch_tensor(1), 1)
  )

})
