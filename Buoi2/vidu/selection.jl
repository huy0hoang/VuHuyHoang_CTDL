# Hàm Selection Sort
function selection_sort(arr)
    n = length(arr)  # Lấy chiều dài mảng
    for i in 1:n-1
        minIndex = i  # Khởi tạo minIndex
        for j in i+1:n
            if arr[j] < arr[minIndex]
                minIndex = j  # Cập nhật minIndex nếu tìm thấy giá trị nhỏ hơn
            end
        end

        # Hoán đổi nếu minIndex khác i
        if minIndex != i
            arr[i], arr[minIndex] = arr[minIndex], arr[i]
        end
    end
end

# Mảng đầu vào
arr = [5, 2, 9, 1, 5]  # Khởi tạo mảng
selection_sort(arr)  # Gọi hàm sắp xếp

# In kết quả
println("Kết quả sau Selection Sort: ", arr)
