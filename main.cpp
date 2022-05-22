#include <iostream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

int main() 
{
	Vector<int> a(3), b(3), c(3);
	Matrix<int> d(2, 2), e(2, 2);

	cout << "enter d -" << endl;
	cin >> d;
	cout << "enter e -" << endl;
	cin >> e;
	cout << "enter a -" << endl;
	cin >> a;
	cout << "enter b -" << endl;
	cin >> b;
	cout << d << e << a << b;

	cout << endl << d + e << d - e << d * e << a - b << a + b << a * b;
}