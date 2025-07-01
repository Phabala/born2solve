#include <iostream>

using namespace std;

int isValid(int a, int b, int c) {
	int max, min;
	if (a >= b && a >= c) {
		max = a;
		min = b + c;
	} else if (b >= a && b >= c) {
		max = b;
		min = a + c;
	} else if (c >= a && c >= b) {
		max = c;
		min = a + b;
	}
	if (max < min) {
		return (1);
	}
	return (0);
}

int main() {
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break ;
		}
		if (isValid(a, b, c) == 0) {
			cout << "Invalid\n";
		} else if (a == b && a == c) {
			cout << "Equilateral\n";
		} else if (a == b || a == c || b == c) {
			cout << "Isosceles\n";
		} else {
			cout << "Scalene\n";
		}
	}
}