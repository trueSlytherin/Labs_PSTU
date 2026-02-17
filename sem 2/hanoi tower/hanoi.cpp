#include <iostream>
using namespace std;

void hanoi(int n, int start, int point, int temp) {
	if (n <= 0) return;
	hanoi(n - 1, start, temp, point);
	cout << start << " => " << point << endl;
	hanoi(n - 1, temp, point, start);
}

int main() {
	int n;
	cin >> n;
	hanoi(n, 1, 3, 2);
	return 0;
}
