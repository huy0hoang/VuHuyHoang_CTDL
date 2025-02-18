function linear_search(arr, target)
    for (index, value) in enumerate(arr)
        if value == target
            return index - 1  # Trả về chỉ số (trừ 1 vì Julia đánh chỉ số từ 1)
        end
    end
    return -1  # Trả về -1 nếu không tìm thấy
end

arr = [4, 2, 5, 1, 3]
println(linear_search(arr, 5))  # Output: 2
