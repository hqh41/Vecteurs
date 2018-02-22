#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
	Vector v1(3);
	cout << v1 << endl;
	Vector v2(3);
	cout << v2 << endl;
	//Vector v3(v2);
	cout << v1 + v2 << endl;
	cout << v1 - v2 << endl;
	cout << v1 * v2 << endl;
	cout << v1 / 2 << endl;
	cout << v1.norm(3) << endl;
	Vector v3(v2);
	cout << v3 << endl;
	return 0;
}
