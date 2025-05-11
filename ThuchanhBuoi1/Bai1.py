import torch
import torch.nn as nn

# Khởi tạo tensor
data = torch.tensor([1.0, 2.0, 3.0])  # Đảm bảo giá trị là float

# Hàm Softmax với dim=0 (theo chiều dọc)
softmax_function = nn.Softmax(dim=0)
output = softmax_function(data)

# Kiểm tra kết quả
assert round(output[0].item(), 2) == 0.09, f"Expected 0.09 but got {round(output[0].item(), 2)}"
print(output)  # In kết quả
