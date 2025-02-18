# Hàm gộp hai mảng đã sắp xếp
function merge!(arr, left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid
    L = arr[left:left+mid-1]
    R = arr[mid+1:right]

    i, j, k = 1, 1, left
    while i <= n1 && j <= n2
        if L[i] <= R[j]
            arr[k] = L[i]
            i += 1
        else
            arr[k] = R[j]
            j += 1
        end
        k += 1
    end

    while i <= n1
        arr[k] = L[i]
        i += 1
        k += 1
    end

    while j <= n2
        arr[k] = R[j]
        j += 1
        k += 1
    end
end

# Hàm phân chia để sắp xếp
function mergeSort!(arr, left, right)
    if left < right
        mid = div(left + right, 2)
        
        mergeSort!(arr, left, mid)
        mergeSort!(arr, mid + 1, right)

        merge!(arr, left, mid, right)
    end
end

# Main function
arr = [5, 2, 9, 1, 5, 6]
println("Trước khi sắp xếp: ", arr)
mergeSort!(arr, 1, length(arr))
println("Sau khi Merge Sort: ", arr)
