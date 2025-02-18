# Hàm Bubble Sort
function bubble_sort(arr)
    n = length(arr)
    for i in 1:n-1
        swapped = false  # Đánh dấu có hoán đổi hay không
        
        for j in 1:n-1-i
            if arr[j] > arr[j + 1]
                # Hoán đổi các phần tử
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = true  # Đã có hoán đổi
            end
        end
        
        # Nếu không có hoán đổi nào, mảng đã được sắp xếp
        if !swapped
            break
        end
    end
end

# Mảng đầu vào
arr = [5, 2, 9, 1, 5, 6]  # Khởi tạo mảng
bubble_sort(arr)  # Gọi hàm sắp xếp

# In kết quả
println("Kết quả sau Bubble Sort: ", arr)
