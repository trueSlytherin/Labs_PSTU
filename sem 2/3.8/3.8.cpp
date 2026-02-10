#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int arr[n] = { 5, 632, 86, 9, 96, 3, 8, 11, 12, 854 };

    int arr_2[2 * n]; 
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr_2[j++] = -1;
            arr_2[j++] = arr[i];
        }
        else {
            arr_2[j++] = arr[i];
        }
    }

    for (int i = 0; i < j; i++) {
        cout << arr_2[i] << " ";
    }

    return 0;
}
