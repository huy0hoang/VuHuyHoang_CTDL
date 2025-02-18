#include <bits/stdc++.h>
using namespace std;

int minSteps(int S, int T) {
    queue<pair<int, int>> q; // (giá trị S hiện tại, số bước đã đi)
    unordered_set<int> visited; // Tập hợp để tránh lặp lại

    q.push({S, 0}); // Bắt đầu từ (S, 0 bước)
    visited.insert(S);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Nếu tìm được T, trả về số bước
        if (current == T) return steps;

        // Thử nhân 2 nếu chưa vượt quá 2*T
        if (current * 2 <= 2 * T && visited.find(current * 2) == visited.end()) {
            q.push({current * 2, steps + 1});
            visited.insert(current * 2);
        }

        // Thử trừ 1 nếu S > 1
        if (current - 1 > 0 && visited.find(current - 1) == visited.end()) {
            q.push({current - 1, steps + 1});
            visited.insert(current - 1);
        }
    }

    return -1; // Trường hợp không thể xảy ra
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int S, T;
        cin >> S >> T;
        cout << minSteps(S, T) << endl;
    }
    return 0;
}
