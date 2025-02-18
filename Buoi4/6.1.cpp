#include <iostream>
#include <queue>
using namespace std;

// Hàm sinh số nhị phân từ 1 đến n
void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1"); // Hàng đợi ban đầu chứa "1"
    
    for (int i = 0; i < n; i++) {
        string front = q.front();
        q.pop();
        cout << front << " "; // In ra số nhị phân hiện tại
        
        // Thêm hai số nhị phân mới vào hàng đợi
        q.push(front + "0");
        q.push(front + "1");
    }
    cout << endl; // Xuống dòng sau mỗi test case
}

int main() {
    int T, n;
    cin >> T; // Đọc số lượng test case
    
    while (T--) {
        cin >> n; // Đọc giá trị n cho mỗi test case
        generateBinaryNumbers(n);
    }

    return 0;
}
