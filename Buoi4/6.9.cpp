#include <bits/stdc++.h>
using namespace std;

// Định nghĩa các hướng di chuyển: trái, phải, lên, xuống
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y, steps;
};

// Kiểm tra xem một ô có hợp lệ không (nằm trong bảng và không phải vật cản)
bool isValid(int x, int y, vector<string>& board, vector<vector<bool>>& visited) {
    return x >= 0 && y >= 0 && x < board.size() && y < board.size() && board[x][y] != 'X' && !visited[x][y];
}

int bfs(int n, vector<string>& board, int a, int b, int c, int d) {
    queue<Node> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    q.push({a, b, 0});
    visited[a][b] = true;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        // Nếu đến được đích
        if (node.x == c && node.y == d) {
            return node.steps;
        }

        // Di chuyển trên cùng hàng hoặc cột
        for (int i = 0; i < 4; i++) {
            int nx = node.x, ny = node.y;
            // Di chuyển theo hướng i cho đến khi gặp vật cản hoặc ra ngoài bảng
            while (true) {
                nx += dx[i];
                ny += dy[i];
                if (!isValid(nx, ny, board, visited)) break;

                // Nếu chưa thăm, thêm vào hàng đợi
                visited[nx][ny] = true;
                q.push({nx, ny, node.steps + 1});
            }
        }
    }

    return -1; // Nếu không tìm được đường đi (tuy nhiên dữ liệu đảm bảo luôn có đường đi)
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<string> board(N);
        
        for (int i = 0; i < N; i++) {
            cin >> board[i];
        }

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << bfs(N, board, a, b, c, d) << endl;
    }

    return 0;
}
