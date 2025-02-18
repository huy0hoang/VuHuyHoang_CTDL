#include <iostream>
using namespace std;

int sum_1_to_n(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;  // Cộng giá trị của i vào s
    }
    return s;
}

int main() {
    int n = 5;
    cout << "Tong 1..n = " << sum_1_to_n(n) << endl;  // In ra tổng từ 1 đến n
    // Output: 15
    return 0;
}
