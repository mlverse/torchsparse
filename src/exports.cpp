// Generated by using torchexport::export() -> do not edit by hand
#include <Rcpp.h>
#include <torch.h>
#define TORCHSPARSE_HEADERS_ONLY
#include <torchsparse/torchsparse.h>

// [[Rcpp::export]]
torch::Tensor rcpp_d_sigmoid (torch::Tensor z) {
  return  d_sigmoid(z.get());
}