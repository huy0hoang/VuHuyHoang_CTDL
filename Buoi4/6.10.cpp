#include <bits/stdc++.h>
using namespace std;

// Các hướng di chuyển (trái, phải, trên, dưới)
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct Node {
    int x, y, days;
};

// Kiểm tra xem một ô có hợp lệ không
bool isValid(int x, int y, int R, int C) {
    return x >= 0 && y >= 0 && x < R && y < C;
}

int bfs(int R, int C, vector<vector<int>>& board) {
    queue<Node> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int totalMounds = 0;  // Số hạt mầm ban đầu (A[i][j] = 1)

    // Đưa tất cả các cây non vào hàng đợi và đếm số hạt mầm
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 2) {
                q.push({i, j, 0});  // Cây non (x, y, ngày)
                visited[i][j] = true;
            } else if (board[i][j] == 1) {
                totalMounds++;
            }
        }
    }

    int maxDays = 0;  // Thời gian tối đa để tất cả các hạt mầm nảy mầm

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        // Duyệt các hướng di chuyển (trái, phải, trên, dưới)
        for (int i = 0; i < 4; i++) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];

            // Kiểm tra xem ô (nx, ny) có hợp lệ và chưa được thăm
            if (isValid(nx, ny, R, C) && !visited[nx][ny] && board[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny, node.days + 1});
                maxDays = max(maxDays, node.days + 1);
                totalMounds--;
            }
        }
    }

    // Nếu còn hạt mầm chưa nảy mầm
    if (totalMounds > 0) return -1;
    return maxDays;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> board(R, vector<int>(C));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> board[i][j];
            }
        }

        cout << bfs(R, C, board) << endl;
    }

    return 0;
}
