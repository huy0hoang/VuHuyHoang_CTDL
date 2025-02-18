function binary_search(arr, target)
    left, right = 1, length(arr)  # Chỉ số trong Julia bắt đầu từ 1

    while left <= right
        mid = div(left + right, 2)  # Tính chỉ số giữa
        if arr[mid] == target
            return mid  # Trả về chỉ số nếu tìm thấy
        elseif arr[mid] < target
            left = mid + 1  # Tìm ở nửa bên phải
        else
            right = mid - 1  # Tìm ở nửa bên trái
        end
    end
    return -1  # Trả về -1 nếu không tìm thấy
end

# Mảng đầu vào
arr = collect(1:16)  # Tạo mảng [1, 2, ..., 16]
target = 10

# Gọi hàm và in kết quả
result = binary_search(arr, target)
println(result)  # Output: 10 (do Julia đếm chỉ số từ 1)
