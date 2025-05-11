import torch
import torch.nn as nn

class SoftmaxStable(nn.Module):
    def __init__(self):
        super().__init__()
    
    def forward(self, x):
        x_exp = torch.exp(x)  # Tính e^x mà không trừ max(x)
        partition = x_exp.sum(0, keepdims=True)  # Tính tổng tất cả các e^x
        return x_exp / partition  # Chuẩn hóa về phân phối xác suất

# Dữ liệu đầu vào
data = torch.Tensor([1, 2, 3])
softmax_stable = SoftmaxStable()
output = softmax_stable(data)

# Kiểm tra kết quả
assert round(output[-1].item(), 2) == 0.67
print(output)
