#include <iostream>
#include<Windows.h>
#include <ctime>
using namespace std;
//function declaration

int knockBack(int D, int w, int p, double s, int b, double r);

int main() {

	cout << "knockback is " << knockBack(10, 75, 25, .5, 20, 1.2) << endl;;
	system("pause");


}
int knockBack(int D, int w, int p, double s, int b, double r) {
	int num;
	num = ((((7 * (D + 2)*(D + p) / (w + 100)) + 9) * 2 * s) + b)*r;
	cout << "knockback is calculated to be " << num << endl;
	return num;



}
