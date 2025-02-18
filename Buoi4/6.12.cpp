#include <bits/stdc++.h>
using namespace std;

// Hàm đệ quy để sinh số lộc phát
void generateLuckyNumbers(int N, string current, vector<string>& result) {
    // Nếu độ dài chuỗi hiện tại <= N, ta tiếp tục tạo số lộc phát
    if (current.size() <= N) {
        if (current.size() > 0) {
            result.push_back(current); // Thêm số hiện tại vào kết quả
        }
        // Sinh tiếp số bằng cách thêm 6 hoặc 8
        generateLuckyNumbers(N, current + "6", result);
        generateLuckyNumbers(N, current + "8", result);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> result;

        // Sinh các số lộc phát từ 1 chữ số đến N chữ số
        generateLuckyNumbers(N, "", result);

        // Sắp xếp kết quả theo thứ tự giảm dần
        sort(result.rbegin(), result.rend());

        // In kết quả
        for (const string& num : result) {
            cout << num << endl;
        }
    }
    return 0;
}
