#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm sinh tất cả các số nguyên tố có 4 chữ số
vector<int> generatePrimes() {
    vector<int> primes;
    for (int i = 1000; i < 10000; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Hàm tìm số bước ít nhất để biến đổi S thành T
int minSteps(int S, int T, const unordered_set<int>& primesSet) {
    if (S == T) return 0;  // Nếu S đã bằng T, không cần chuyển đổi

    queue<pair<int, int>> q;  // Lưu trữ (số hiện tại, số bước)
    unordered_set<int> visited;  // Để tránh duyệt lại số đã xét

    q.push({S, 0});
    visited.insert(S);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Thử thay đổi từng chữ số
        string currentStr = to_string(current);
        for (int i = 0; i < 4; ++i) {
            char original = currentStr[i];
            for (char digit = '0'; digit <= '9'; ++digit) {
                // Thay đổi chữ số tại vị trí i
                if (digit == original) continue;
                currentStr[i] = digit;
                int nextNum = stoi(currentStr);
                if (nextNum >= 1000 && primesSet.find(nextNum) != primesSet.end() && visited.find(nextNum) == visited.end()) {
                    if (nextNum == T) return steps + 1;  // Nếu tìm thấy T, trả về số bước
                    q.push({nextNum, steps + 1});
                    visited.insert(nextNum);
                }
            }
            currentStr[i] = original;  // Khôi phục lại chữ số ban đầu
        }
    }

    return -1;  // Không thể tìm ra đường đi
}

int main() {
    // Tạo danh sách các số nguyên tố có 4 chữ số
    vector<int> primesList = generatePrimes();
    unordered_set<int> primesSet(primesList.begin(), primesList.end());

    int T;
    cin >> T;
    while (T--) {
        int S, T;
        cin >> S >> T;
        cout << minSteps(S, T, primesSet) << endl;
    }

    return 0;
}
