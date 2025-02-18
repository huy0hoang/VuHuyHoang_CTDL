#include <bits/stdc++.h>
using namespace std;

vector<int> rotateLeft(const vector<int>& board, int index) {
    vector<int> new_board = board;
    // Quay miếng ghép ở vị trí index sang trái
    if (index == 0) {
        swap(new_board[0], new_board[1]);
        swap(new_board[1], new_board[3]);
        swap(new_board[3], new_board[4]);
        swap(new_board[4], new_board[0]);
    } else {
        swap(new_board[1], new_board[2]);
        swap(new_board[2], new_board[5]);
        swap(new_board[5], new_board[3]);
        swap(new_board[3], new_board[1]);
    }
    return new_board;
}

int bfs(const vector<int>& start, const vector<int>& goal) {
    queue<pair<vector<int>, int>> q;  // (trạng thái bảng, số bước)
    unordered_set<string> visited;    // Set các trạng thái đã thăm
    q.push({start, 0});
    visited.insert(to_string(start[0]) + to_string(start[1]) + to_string(start[2]) + to_string(start[3]) + to_string(start[4]) + to_string(start[5]));
    
    while (!q.empty()) {
        auto [current_board, steps] = q.front();
        q.pop();
        
        if (current_board == goal) {
            return steps;  // Đã tìm thấy kết quả
        }
        
        // Duyệt qua các phép quay
        for (int i = 0; i < 2; ++i) {
            vector<int> new_board = rotateLeft(current_board, i);
            string board_str = to_string(new_board[0]) + to_string(new_board[1]) + to_string(new_board[2]) + to_string(new_board[3]) + to_string(new_board[4]) + to_string(new_board[5]);
            
            if (visited.find(board_str) == visited.end()) {
                visited.insert(board_str);
                q.push({new_board, steps + 1});
            }
        }
    }
    return -1;  // Nếu không thể đưa về trạng thái đích
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> start(6), goal(6);
        for (int i = 0; i < 6; ++i) cin >> start[i];
        for (int i = 0; i < 6; ++i) cin >> goal[i];

        cout << bfs(start, goal) << endl;
    }
    return 0;
}
