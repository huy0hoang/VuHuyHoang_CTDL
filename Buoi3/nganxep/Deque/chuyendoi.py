def decimal_to_binary(n):
    stack = []  # Ngăn xếp để lưu các phần dư
    print(f"Chuyển đổi số thập phân: {n} sang nhị phân.")
    
    # Trường hợp đặc biệt nếu n = 0
    if n == 0:
        stack.append(0)
        print(f"Đã đẩy phần dư '0' vào ngăn xếp.")
    
    # Xử lý chuyển đổi thập phân sang nhị phân
    while n > 0:
        remainder = n % 2
        stack.append(remainder)
        print(f"Chia {n} cho 2, phần dư: {remainder}. Đẩy {remainder} vào ngăn xếp.")
        n = n // 2
        print(f"Thương mới: {n}")
    
    # Kết hợp các phần tử trong ngăn xếp thành số nhị phân
    binary = ""
    print("Chuyển đổi ngăn xếp thành số nhị phân:")
    while stack:
        binary += str(stack.pop())
        print(f"Lấy {binary[-1]} từ ngăn xếp và nối vào kết quả.")
    
    return binary

# Minh họa
number = 13
binary = decimal_to_binary(number)
print(f"Số thập phân {number} chuyển sang nhị phân là {binary}")
