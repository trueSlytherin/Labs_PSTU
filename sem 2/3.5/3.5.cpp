#include <iostream>
using namespace std;
int main()
{
     const int n = 11;
     int max;
     int arr[n] = { 41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22 };
     max = arr[0];
     cout << arr[0] << " ";
     for (int i = 1; i < n; i++)
     {
         cout << arr[i] << " ";
         if (arr[i] > max)
         { max = arr[i]; }
     cout << endl;
     cout << "Max: " << max << endl;

     return 0;
 }
