#include <bits/stdc++.h>
using namespace std;

// Hàm BFS tìm đường đi ngắn nhất
int minSteps(int M, int N, vector<vector<int>>& A) {
    // Định nghĩa các hướng di chuyển (phải, xuống)
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}};
    
    // Queue để thực hiện BFS
    queue<pair<int, int>> q;
    // Mảng visited để tránh thăm lại
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    
    // Bắt đầu BFS từ A[0][0]
    q.push({0, 0});
    visited[0][0] = true;
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        
        // Duyệt tất cả các điểm trong queue ở mức hiện tại
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();

            // Nếu đến đích (M-1, N-1)
            if (x == M - 1 && y == N - 1) {
                return steps;
            }

            // Di chuyển theo các hướng hợp lệ
            int jump = A[x][y];

            // 1. Di chuyển phải
            if (y + jump < N && !visited[x][y + jump]) {
                visited[x][y + jump] = true;
                q.push({x, y + jump});
            }

            // 2. Di chuyển xuống
            if (x + jump < M && !visited[x + jump][y]) {
                visited[x + jump][y] = true;
                q.push({x + jump, y});
            }
        }
        
        // Tăng số bước sau khi duyệt hết các ô ở mức hiện tại
        ++steps;
    }

    // Nếu không thể tìm thấy đường đi, trả về -1
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N;
        cin >> M >> N;
        
        vector<vector<int>> A(M, vector<int>(N));
        
        // Đọc ma trận A
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> A[i][j];
            }
        }

        // Tính số bước ít nhất từ A[0][0] đến A[M-1][N-1]
        cout << minSteps(M, N, A) << endl;
    }

    return 0;
}
