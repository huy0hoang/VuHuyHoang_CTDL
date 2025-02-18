def print_numbers(n):
    for i in range(1, n + 1):  # Vòng lặp từ 1 đến n
        print(i, end=" ")      # In số trên cùng một dòng, cách nhau bởi khoảng trắng
    print()                    # Xuống dòng sau khi in xong

# Gọi hàm
n = 5
print_numbers(n)  # Output: 1 2 3 4 5
