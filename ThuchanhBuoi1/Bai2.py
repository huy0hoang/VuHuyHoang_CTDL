import torch
import torch.nn as nn

class MySoftmax(nn.Module):
    def __init__(self):
        super(MySoftmax, self).__init__()

    def forward(self, x):
        return torch.exp(x) / torch.sum(torch.exp(x), dim=0)

# Dữ liệu đầu vào
data = torch.tensor([5.0, 2.0, 4.0])  


my_softmax = MySoftmax()
output = my_softmax(data)

# Kiểm tra đầu ra
assert round(output[-1].item(), 2) == 0.26, f"Expected 0.26 but got {round(output[-1].item(), 2)}"
print(output)  # In kết quả
