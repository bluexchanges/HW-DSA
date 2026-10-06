#include <iostream>
using namespace std;
void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min= i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min= j;
            }
        }
        if (min!= i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        cout << "Buoc " << i + 1 << ": ";
        for (int m = 0; m < n; m++) {
            cout << a[m] << " ";
        }
        cout << "\n";
    }
}
int main() {
    int a[] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout<<'\n';
    selection_sort(a, n);
    return 0;
}