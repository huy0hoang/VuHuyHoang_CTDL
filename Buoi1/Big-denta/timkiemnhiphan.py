def binary_search(arr, target):
    left, right = 0, len(arr) - 1  # Điều chỉnh right để là len(arr) - 1
    while left <= right:
        mid = (left + right) // 2  # Sửa lỗi tính mid
        if arr[mid] == target:
            return mid  # Nếu tìm thấy phần tử
        elif arr[mid] < target:
            left = mid + 1  # Tìm ở nửa bên phải
        else:
            right = mid - 1  # Tìm ở nửa bên trái
    return -1  # Nếu không tìm thấy

arr = list(range(1, 17))  # [1, 2, 3, ..., 16]
print(binary_search(arr, 10))  # Output: 9
