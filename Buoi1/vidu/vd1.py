def sum_1_to_n(n):
    s = 0  # Khởi tạo biến tổng
    for i in range(1, n + 1):  # Lặp từ 1 đến n
        s += i  # Cộng dồn vào tổng
    return s  # Trả về tổng

# Hàm main
def main():
    print("Tong 1...n =", sum_1_to_n(15))  # Xuất tổng từ 1 đến 15

# Gọi hàm main
if __name__ == "__main__":
    main()
