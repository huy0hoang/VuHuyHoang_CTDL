# Hàm tính tổng từ 1 đến n
def sum_1_to_n(n):
    s = 0  # Khởi tạo biến tổng
    for i in range(1, n + 1):  # Lặp từ 1 đến n
        s += i  # Cộng dồn vào tổng
    return s  # Trả về tổng

# In kết quả
print("Tổng 1...n =", sum_1_to_n(15))  # Xuất tổng từ 1 đến 15
