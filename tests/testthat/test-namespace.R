test_that("can list namespace operations", {

  ops <- torch::jit_ops$torch_sparse
  funs <- .DollarNames(ops)
  expect_gt(length(funs), 0)

})

