import torch
import torch.nn.functional as F

def softmax(x):
    """Tính toán softmax theo công thức thông thường"""
    exp_x = torch.exp(x)
    return exp_x / torch.sum(exp_x)

def softmax_stable(x):
    """Tính toán softmax ổn định để tránh tràn số"""
    x_max = torch.max(x)  # Lấy giá trị lớn nhất để ổn định số mũ
    exp_x = torch.exp(x - x_max)  # Trừ đi max(x) để giữ giá trị nhỏ
    return exp_x / torch.sum(exp_x)

# Ví dụ 1: Softmax thường
data = torch.tensor([1.0, 2.0, 3.0])  # Định dạng số thực chính xác hơn
output = softmax(data)
print("Softmax thường:", output)

# Ví dụ 2: Softmax ổn định
output_stable = softmax_stable(data)
print("Softmax ổn định:", output_stable)
