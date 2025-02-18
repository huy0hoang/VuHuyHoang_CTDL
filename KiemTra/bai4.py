def levenshtein_distance(s, t):
    m, n = len(s), len(t)
    
    # Tạo bảng m x n, bảng dp với các giá trị ban đầu
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Khởi tạo bảng: dp[i][0] = i (chuyển đổi chuỗi S dài i thành chuỗi rỗng)
    for i in range(m + 1):
        dp[i][0] = i
        
    # Khởi tạo bảng: dp[0][j] = j (chuyển đổi chuỗi rỗng thành chuỗi T dài j)
    for j in range(n + 1):
        dp[0][j] = j
    
    # Điền bảng dp
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s[i - 1] == t[j - 1]:  # Nếu ký tự ở vị trí i và j giống nhau
                dp[i][j] = dp[i - 1][j - 1]  # Không cần thay đổi gì
            else:
                dp[i][j] = min(dp[i - 1][j] + 1,    # Xóa ký tự từ S
                                dp[i][j - 1] + 1,    # Thêm ký tự vào S
                                dp[i - 1][j - 1] + 1) # Thay thế ký tự
    
    # Trả về giá trị cuối cùng trong bảng dp, đó chính là khoảng cách Levenshtein
    return dp[m][n]

# Test case
s = "kitten"
t = "sitting"
print(f"Khoảng cách Levenshtein giữa '{s}' và '{t}' là: {levenshtein_distance(s, t)}")
def levenshtein_distance(s, t):
    m, n = len(s), len(t)
    
    # Tạo bảng m x n, bảng dp với các giá trị ban đầu
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Khởi tạo bảng: dp[i][0] = i (chuyển đổi chuỗi S dài i thành chuỗi rỗng)
    for i in range(m + 1):
        dp[i][0] = i
        
    # Khởi tạo bảng: dp[0][j] = j (chuyển đổi chuỗi rỗng thành chuỗi T dài j)
    for j in range(n + 1):
        dp[0][j] = j
    
    # Điền bảng dp
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s[i - 1] == t[j - 1]:  # Nếu ký tự ở vị trí i và j giống nhau
                dp[i][j] = dp[i - 1][j - 1]  # Không cần thay đổi gì
            else:
                dp[i][j] = min(dp[i - 1][j] + 1,    # Xóa ký tự từ S
                                dp[i][j - 1] + 1,    # Thêm ký tự vào S
                                dp[i - 1][j - 1] + 1) # Thay thế ký tự
    
    # Trả về giá trị cuối cùng trong bảng dp, đó chính là khoảng cách Levenshtein
    return dp[m][n]

# Test case
s = "kitten"
t = "sitting"
print(f"Khoảng cách Levenshtein giữa '{s}' và '{t}' là: {levenshtein_distance(s, t)}")
