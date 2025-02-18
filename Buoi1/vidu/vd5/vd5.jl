# Hàm phân chia để sắp xếp
function partition(arr, low, high)
    pivot = arr[high]  # Chọn pivot là phần tử cuối
    i = low - 1

    for j in low:(high - 1)
        if arr[j] <= pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Hoán đổi
        end
    end

    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Đưa pivot vào vị trí chính xác
    return i + 1
end

# Hàm Quick Sort
function quick_sort(arr, low, high)
    if low < high
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)  # Sắp xếp nửa bên trái
        quick_sort(arr, pi + 1, high)  # Sắp xếp nửa bên phải
    end
end

# Ví dụ sử dụng
arr = [10, 7, 8, 9, 1, 5]
println("Mảng trước khi sắp xếp: ", arr)
quick_sort(arr, 1, length(arr))  # Julia sử dụng chỉ số từ 1
println("Mảng sau khi Quick Sort: ", arr)

# Mảng đầu vào
arr = [5, 2, 9, 1, 5, 6]

# Gọi hàm Quick Sort
quick_sort(arr, 1, length(arr))  # Julia sử dụng chỉ số từ 1

# In kết quả
println("Kết quả Quick Sort: ", arr)  # Output: [1, 2, 5, 5, 6, 9]
