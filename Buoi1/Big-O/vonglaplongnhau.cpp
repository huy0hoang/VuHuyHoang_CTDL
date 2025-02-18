#include <iostream>
using namespace std;

void printPairs(int n) {
    for (int i = 1; i <= n; i++) {        // Vòng lặp ngoài
        for (int j = 1; j <= n; j++) {    // Vòng lặp trong
            cout << "(" << i << ", " << j << ")" << endl;  // In cặp (i, j)
        }
    }
}

int main() {
    int n = 3;
    printPairs(n);  // Output các cặp số từ (1,1) đến (n,n)
    return 0;
}
