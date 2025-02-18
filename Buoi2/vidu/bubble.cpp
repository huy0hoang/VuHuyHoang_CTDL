#include <iostream>
#include <vector>
using namespace std;

// Hàm Bubble Sort
void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // Đánh dấu có hoán đổi hay không
        
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi các phần tử
                swap(arr[j], arr[j + 1]);
                swapped = true;  // Đã có hoán đổi
            }
        }
        
        // Nếu không có hoán đổi nào, mảng đã được sắp xếp
        if (!swapped) {
            break;
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};  // Khởi tạo mảng
    bubble_sort(arr);  // Gọi hàm sắp xếp
    
    cout << "Kết quả sau Bubble Sort: ";
    for (int x : arr) {
        cout << x << " ";  // In kết quả
    }
    cout << endl;
    
    return 0;
}
