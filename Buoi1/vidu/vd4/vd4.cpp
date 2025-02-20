#include <vector>
#include <iostream>
using namespace std;

// Khai báo hàm merge
void merge(vector<int>& arr, int left, int mid, int right);

// Định nghĩa hàm mergeSort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sắp xếp nửa bên trái
        mergeSort(arr, left, mid);
        // Sắp xếp nửa bên phải
        mergeSort(arr, mid + 1, right);

        // Gộp hai nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

// Định nghĩa hàm merge
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    cout << "Truoc khi sap xep: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sau khi Merge Sort: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
