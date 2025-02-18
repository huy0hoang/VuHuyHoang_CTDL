#include <bits/stdc++.h>
using namespace std;

// Hàm tìm số bước ít nhất để biến đổi N về 1
int minSteps(int N) {
    queue<pair<int, int>> q;  // (Giá trị N hiện tại, số bước đã đi)
    unordered_set<int> visited; // Để kiểm tra số đã xét

    q.push({N, 0});
    visited.insert(N);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == 1) return steps;

        // Thử tìm max(u, v) với u * v = current
        for (int i = 2; i * i <= current; ++i) {
            if (current % i == 0) {
                int nextVal = max(i, current / i);
                if (visited.find(nextVal) == visited.end()) {
                    q.push({nextVal, steps + 1});
                    visited.insert(nextVal);
                }
                // Nếu có thể giảm nhanh thì dừng luôn
                if (nextVal == 1) break;
            }
        }

        // Giảm N đi 1
        if (visited.find(current - 1) == visited.end()) {
            q.push({current - 1, steps + 1});
            visited.insert(current - 1);
        }
    }
    
    return -1; // Trường hợp không xảy ra
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << minSteps(N) << endl;
    }
    return 0;
}
