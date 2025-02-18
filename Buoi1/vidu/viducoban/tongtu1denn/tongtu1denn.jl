# Hàm tính tổng từ 1 đến n
function sum_1_to_n(n)
    s = 0  # Khởi tạo biến tổng
    for i in 1:n  # Lặp từ 1 đến n
        s += i  # Cộng dồn vào tổng
    end
    return s  # Trả về tổng
end

# In kết quả
println("Tổng 1...n = ", sum_1_to_n(15))  # Xuất tổng từ 1 đến 15
