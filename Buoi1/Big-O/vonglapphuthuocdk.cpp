#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;  // Tính chỉ số giữa
        if (arr[mid] == target) {
            return mid;  // Trả về chỉ số nếu tìm thấy
        } else if (arr[mid] < target) {
            left = mid + 1;  // Tìm ở nửa bên phải
        } else {
            right = mid - 1;  // Tìm ở nửa bên trái
        }
    }
    return -1;  // Trả về -1 nếu không tìm thấy
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};  // Mảng đầu vào
    int target = 10;

    int result = binary_search(arr, target);  // Gọi hàm tìm kiếm
    cout << result << endl;  // Output: 9

    return 0;
}
