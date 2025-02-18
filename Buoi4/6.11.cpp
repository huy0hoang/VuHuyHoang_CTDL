#include <bits/stdc++.h>
using namespace std;

// Các hướng di chuyển trong không gian 3D: trên, dưới, trái, phải, trước, sau
int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 0, -1, 1};
int dz[] = {-1, 1, 0, 0, 0, 0};

// Kiểm tra xem một vị trí có hợp lệ không
bool isValid(int x, int y, int z, int A, int B, int C) {
    return x >= 0 && x < A && y >= 0 && y < B && z >= 0 && z < C;
}

// Hàm BFS tìm đường đi ngắn nhất
int bfs(int A, int B, int C, vector<vector<vector<char>>>& grid, pair<int, int, int> start, pair<int, int, int> end) {
    queue<pair<pair<int, int, int>, int>> q; // (x, y, z, bước)
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));
    
    // Đưa điểm xuất phát vào hàng đợi
    q.push({start, 0});
    visited[start.first][start.second][start.third] = true;

    while (!q.empty()) {
        auto current = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        // Nếu đã đến đích, trả về số bước
        if (current == end) {
            return steps;
        }

        // Duyệt các hướng di chuyển
        for (int i = 0; i < 6; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            int nz = current.third + dz[i];

            if (isValid(nx, ny, nz, A, B, C) && !visited[nx][ny][nz] && grid[nx][ny][nz] != '#') {
                visited[nx][ny][nz] = true;
                q.push({{nx, ny, nz}, steps + 1});
            }
        }
    }

    return -1; // Nếu không thể tìm đường đến đích
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        
        vector<vector<vector<char>>> grid(A, vector<vector<char>>(B, vector<char>(C)));
        pair<int, int, int> start, end;
        
        // Đọc dữ liệu vào grid và tìm vị trí S và E
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> grid[i][j][k];
                    if (grid[i][j][k] == 'S') {
                        start = {i, j, k};
                    }
                    if (grid[i][j][k] == 'E') {
                        end = {i, j, k};
                    }
                }
            }
        }

        // Tính và in ra số bước ít nhất
        cout << bfs(A, B, C, grid, start, end) << endl;
    }

    return 0;
}
