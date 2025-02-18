function binary_search(arr, target)
    left, right = 1, length(arr)
    
    while left <= right
        mid = div(left + right, 2)
        if arr[mid] == target
            return mid
        elseif arr[mid] < target
            left = mid + 1
        else
            right = mid - 1
        end
    end
    return -1
end

arr = 1:16
println(binary_search(arr, 10))  # Output: 10
