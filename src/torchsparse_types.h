#include <torch.h>

namespace torchsparse {
class tensor_pair {
public:
  std::shared_ptr<void> ptr;
  tensor_pair (void* x);
  operator SEXP () const;
};
}
