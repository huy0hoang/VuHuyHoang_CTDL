def binary_search(arr, target):
    left = 0  # Chỉ số đầu tiên (Python cũng sử dụng chỉ số từ 0)
    right = len(arr) - 1  # Chỉ số cuối cùng

    while left <= right:
        mid = (left + right) // 2  # Chỉ số giữa (chia lấy phần nguyên)

        if arr[mid] == target:
            return mid  # Trả về chỉ số tìm được
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1  # Không tìm thấy

arr = [1, 3, 5, 7, 9, 11]
print(binary_search(arr, 7))  # Output: 3
