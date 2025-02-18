# Hàm Insertion Sort
function insertion_sort(arr)
    n = length(arr)
    for i in 2:n
        key = arr[i]  # Lưu giá trị hiện tại
        j = i - 1

        # Di chuyển các phần tử lớn hơn key lên một vị trí
        while j >= 1 && arr[j] > key
            arr[j + 1] = arr[j]
            j -= 1
        end

        # Chèn key vào vị trí đúng
        arr[j + 1] = key
    end
end

# Mảng đầu vào
arr = [5, 2, 9, 1, 5]  # Khởi tạo mảng
insertion_sort(arr)  # Gọi hàm sắp xếp

# In kết quả
println("Kết quả sau Insertion Sort: ", arr)
