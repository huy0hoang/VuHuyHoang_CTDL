#include <bits/stdc++.h>
using namespace std;

string findSmallestBDN(int N) {
    queue<string> q;
    set<int> visited;
    
    q.push("1"); // Bắt đầu từ số 1

    while (!q.empty()) {
        string num = q.front();
        q.pop();

        // Chuyển số num sang dạng số nguyên để kiểm tra chia hết
        int remainder = stoi(num) % N;
        if (remainder == 0) return num;

        // Nếu chưa xét số này, thêm vào queue
        if (visited.find(remainder) == visited.end()) {
            visited.insert(remainder);
            q.push(num + "0");
            q.push(num + "1");
        }
    }
    return "-1"; // Không thể xảy ra
}

int main() {
    int T;
    cin >> T; // Đọc số lượng test case
    while (T--) {
        int N;
        cin >> N;
        cout << findSmallestBDN(N) << endl;
    }
    return 0;
}
