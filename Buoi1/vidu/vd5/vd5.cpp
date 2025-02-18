#include <iostream>
#include <vector>
using namespace std;

// Hàm phân chia để sắp xếp
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Chọn pivot là phần tử cuối
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Hoán đổi
        }
    }

    swap(arr[i + 1], arr[high]);  // Đưa pivot vào vị trí chính xác
    return i + 1;
}

// Hàm Quick Sort
void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);  // Sắp xếp nửa bên trái
        quick_sort(arr, pi + 1, high);  // Sắp xếp nửa bên phải
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    cout << "Mảng trước khi sắp xếp: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    quick_sort(arr, 0, arr.size() - 1);

    cout << "Mảng sau khi Quick Sort: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    // Mảng đầu vào
    arr = {5, 2, 9, 1, 5, 6};

    // Gọi hàm Quick Sort
    quick_sort(arr, 0, arr.size() - 1);

    // In kết quả
    cout << "Kết quả Quick Sort: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
