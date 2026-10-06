#include <iostream>
using namespace std;
void insert_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        cout << "Buoc " << i << ": ";
        for (int m = 0; m < n; m++) {
            cout << a[m] << " ";
        }
        cout << "\n";
    }
}
int main() {
    int a[] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Mang ban dau:\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    insert_sort(a, n);
    return 0;
}