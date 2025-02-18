# Hàm gộp hai mảng đã sắp xếp
def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    L = arr[left:left + n1]
    R = arr[mid + 1:mid + 1 + n2]

    i = j = k = left
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

# Hàm phân chia để sắp xếp
def mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)

        merge(arr, left, mid, right)

# Main function
arr = [5, 2, 9, 1, 5, 6]
print("Trước khi sắp xếp:", arr)
mergeSort(arr, 0, len(arr) - 1)
print("Sau khi Merge Sort:", arr)
