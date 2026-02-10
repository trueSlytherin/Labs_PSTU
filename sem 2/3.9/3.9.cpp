#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int arr[n] = { 99, 22, 7546, 1, 547, 848, 123, 425, 6234, 63 };
    int arr_2[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr_2[j++] = arr[i];
        }
    }

    for (int i = 0; i < j; i++) {
        cout << arr_2[i] << " ";
    }

    return 0;
}
