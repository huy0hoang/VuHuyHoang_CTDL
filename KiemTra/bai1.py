from collections import deque #khai bào thư viện collection để sử dụng hàng đợi đôi

def sliding_window(num_list, k):
    if not num_list or k == 0:
        return []  # Nếu danh sách rỗng hoặc k = 0, trả về danh sách rỗng
    
    result = []
    dq = deque()  # Hàng đợi đôi lưu chỉ số phần tử trong cửa sổ trượt
    
    for i in range(len(num_list)):
        # Loại bỏ phần tử không còn nằm trong cửa sổ trượt
        if dq and dq[0] < i - k + 1:
            dq.popleft()
        
        # Loại bỏ phần tử nhỏ hơn phần tử hiện tại (chúng không còn hữu ích)
        while dq and num_list[dq[-1]] < num_list[i]:
            dq.pop()
        
        # Thêm phần tử hiện tại vào deque
        dq.append(i)
        
        # Bắt đầu thu thập kết quả khi cửa sổ đạt kích thước k
        if i >= k - 1:
            result.append(num_list[dq[0]])  # Giá trị lớn nhất trong cửa sổ
        
    return result

# Test case
num_list = [3, 4, 5, 1, -44, 5, 10, 12, 33, 1]
k = 3
print(sliding_window(num_list, k))  # Output: [5, 5, 5, 5, 10, 12, 33, 33]
