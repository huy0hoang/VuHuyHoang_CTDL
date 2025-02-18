def binary_search(arr, target):
    left, right = 0, len(arr) - 1  # Sửa 'len(arr)' thành 'len(arr) - 1' để tránh lỗi chỉ số ngoài phạm vi
    while left <= right:
        mid = (left + right) // 2  # Tìm chỉ số giữa
        if arr[mid] == target:     # Nếu phần tử ở giữa là mục tiêu, trả về chỉ số
            return mid
        elif arr[mid] < target:    # Nếu giá trị giữa nhỏ hơn mục tiêu, tìm bên phải
            left = mid + 1
        else:                      # Nếu giá trị giữa lớn hơn mục tiêu, tìm bên trái
            right = mid - 1
    return -1                      # Nếu không tìm thấy, trả về -1

# Mảng đầu vào
arr = list(range(1, 17))  # Tạo mảng [1, 2, 3, ..., 16]

# Gọi hàm và in kết quả
print(binary_search(arr, 10))  # Output: 9
