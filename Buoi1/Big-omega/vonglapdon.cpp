#include <iostream>
using namespace std;

void printNumbers(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << " ";  // Sửa lỗi cú pháp: thiếu dấu ngoặc kép kết thúc chuỗi
    }
    cout << endl;  // Xuống dòng sau khi in xong
}

int main() {
    int n = 5;
    printNumbers(n);  // Output: 1 2 3 4 5
    return 0;
}
