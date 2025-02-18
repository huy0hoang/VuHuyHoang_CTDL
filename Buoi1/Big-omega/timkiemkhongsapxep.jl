function find_first_element(arr, target)
    if arr[1] == target  # Chỉ số trong Julia bắt đầu từ 1
        return 1
    end
    return -1
end

arr = [10, 20, 30, 40, 50]
println(find_first_element(arr, 10))  # Output: 1
