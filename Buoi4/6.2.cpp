#include <bits/stdc++.h>
using namespace std;

string findSmallestNumber(int N) {
    queue<string> q; // Hàng đợi để duyệt BFS
    set<string> visited; // Tập hợp để tránh lặp lại số

    q.push("9"); // Bắt đầu từ số 9
    while (!q.empty()) {
        string num = q.front();
        q.pop();

        // Chuyển num thành số nguyên để kiểm tra chia hết
        long long number = stoll(num); 
        if (number % N == 0) {
            return num;
        }

        // Tạo số mới bằng cách thêm '0' hoặc '9'
        string num1 = num + "0";
        string num2 = num + "9";

        // Nếu chưa xuất hiện trong tập hợp, thêm vào queue
        if (visited.find(num1) == visited.end()) {
            visited.insert(num1);
            q.push(num1);
        }
        if (visited.find(num2) == visited.end()) {
            visited.insert(num2);
            q.push(num2);
        }
    }
    return "-1"; // Trường hợp không tìm thấy (không thể xảy ra)
}

int main() {
    int T;
    cin >> T; // Đọc số lượng test case

    while (T--) {
        int N;
        cin >> N; // Đọc giá trị N cho mỗi test
        cout << findSmallestNumber(N) << endl; // In kết quả
    }

    return 0;
}
