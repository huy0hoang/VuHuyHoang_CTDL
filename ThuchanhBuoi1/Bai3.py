import torch
import torch.nn as nn

class MySoftmax(nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, x):
        # ## Your Code Here
        exp_x = torch.exp(x)  # Tính e^(x)
        return exp_x / torch.sum(exp_x, dim=0)  # Tính softmax
        # ## End Code Here

data = torch.Tensor([1, 2, 300000000])
my_softmax = MySoftmax()
output = my_softmax(data)

assert round(output[0].item(), 2) == 0.0
print(output)
