//Vòng lặp đơn
#include <iostream>
using namespace std;
 
 void printNumber(int n)
 {
    for(int i = 1;i<=n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
 }
 int main()
 {
    int n = 5;
    printNumber(n); //output: 1 2 3 4 5
    return 0;
 }