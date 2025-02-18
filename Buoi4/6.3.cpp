#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull; // Định nghĩa kiểu số lớn

// Hàm đếm số BDN nhỏ hơn N
ull countBDN(ull N) {
    queue<ull> q; // Hàng đợi BFS
    q.push(1);    // Bắt đầu từ số 1
    ull count = 0;

    while (!q.empty()) {
        ull num = q.front();
        q.pop();

        if (num >= N) break; // Dừng lại nếu số sinh ra >= N
        count++;

        // Sinh số mới bằng cách thêm '0' hoặc '1'
        q.push(num * 10);    // Thêm '0' vào cuối
        q.push(num * 10 + 1);// Thêm '1' vào cuối
    }
    return count;
}

int main() {
    int T;
    cin >> T; // Đọc số lượng test case
    while (T--) {
        ull N;
        cin >> N; // Đọc số N
        cout << countBDN(N) << endl; // In kết quả
    }
    return 0;
}
