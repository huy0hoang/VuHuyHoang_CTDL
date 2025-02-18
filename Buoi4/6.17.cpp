#include <bits/stdc++.h>
using namespace std;

// Các hướng di chuyển hợp lệ của quân mã
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

// Hàm chuyển đổi tọa độ bàn cờ từ dạng "a1" thành chỉ số mảng (0-based)
pair<int, int> convertToIndex(string s) {
    int x = s[0] - 'a';  // Cột (từ 'a' đến 'h')
    int y = s[1] - '1';  // Hàng (từ '1' đến '8')
    return {x, y};
}

// Hàm BFS tìm số bước di chuyển ngắn nhất
int bfs(pair<int, int> start, pair<int, int> end) {
    // Nếu điểm xuất phát và điểm đích giống nhau
    if (start == end) return 0;

    // Queue để thực hiện BFS
    queue<pair<int, int>> q;
    // Mảng visited để tránh thăm lại
    bool visited[8][8] = {false};
    
    // Bắt đầu từ vị trí xuất phát
    q.push(start);
    visited[start.first][start.second] = true;
    int steps = 0;

    // Thực hiện BFS
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();

            // Duyệt qua các hướng di chuyển của quân mã
            for (int j = 0; j < 8; ++j) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                // Kiểm tra nếu tọa độ hợp lệ và chưa thăm
                if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && !visited[nx][ny]) {
                    if (nx == end.first && ny == end.second) {
                        return steps + 1;
                    }
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        steps++;
    }

    return -1;  // Nếu không tìm thấy đường đi
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string start, end;
        cin >> start >> end;

        // Chuyển đổi tọa độ từ dạng "a1", "h8", v.v. thành chỉ số mảng
        pair<int, int> startPos = convertToIndex(start);
        pair<int, int> endPos = convertToIndex(end);

        // Tính số bước di chuyển ít nhất
        cout << bfs(startPos, endPos) << endl;
    }

    return 0;
}
