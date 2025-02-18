#include <bits/stdc++.h>
using namespace std;

int solve(string &s) {
    int balance = 0, changes = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        
        if (balance < 0) { // Too many ')', add '('
            changes++;
            balance = 0;
        }
    }
    return changes + balance / 2; // Handle excess '('
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << solve(S) << "\n";
    }
    return 0;
}
