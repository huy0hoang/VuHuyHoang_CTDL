#include <iostream>
#include <vector>
using namespace std;

// Hàm Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();  // Khai báo đúng biến n
    for (int i = 0; i < n - 1; i++) {  // Đảm bảo điều kiện cho vòng lặp đúng
        // Tìm chỉ số của phần tử nhỏ nhất trong [i..n-1]
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Cập nhật chỉ số minIndex nếu tìm thấy giá trị nhỏ hơn
            }
        }

        // Hoán đổi nếu minIndex khác i
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};  // Khởi tạo mảng
    selectionSort(arr);  // Gọi hàm sắp xếp

    cout << "Kết quả sau Selection Sort: ";
    for (int x : arr) {
        cout << x << " ";  // In kết quả
    }
    cout << endl;

    return 0;
}
