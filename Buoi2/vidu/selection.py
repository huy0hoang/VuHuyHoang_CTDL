# Hàm Selection Sort
def selection_sort(arr):
    n = len(arr)  # Lấy chiều dài mảng
    for i in range(n - 1):
        min_index = i  # Khởi tạo minIndex
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j  # Cập nhật minIndex nếu tìm thấy giá trị nhỏ hơn
        
        # Hoán đổi nếu min_index khác i
        if min_index != i:
            arr[i], arr[min_index] = arr[min_index], arr[i]

# Mảng đầu vào
arr = [5, 2, 9, 1, 5]  # Khởi tạo mảng
selection_sort(arr)  # Gọi hàm sắp xếp

# In kết quả
print("Kết quả sau Selection Sort:", arr)
