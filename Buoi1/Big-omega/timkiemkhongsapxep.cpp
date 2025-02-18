#include <iostream>
#include <vector>
using namespace std;

int find_first_element(const vector<int>& arr, int target) {
    if (arr[0] == target) {
        return 0;
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << find_first_element(arr, 10) << endl;  // Output: 0
    return 0;
}
