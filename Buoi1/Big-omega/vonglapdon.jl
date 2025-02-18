function print_numbers(n)
    for i in 1:n                # Vòng lặp từ 1 đến n
        print("$i ")            # In số trên cùng một dòng, cách nhau bởi khoảng trắng
    end
    println()                   # Xuống dòng sau khi in xong
end

# Gọi hàm
n = 5
print_numbers(n)  # Output: 1 2 3 4 5
