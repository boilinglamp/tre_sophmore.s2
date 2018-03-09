#include <iostream>
#include<Windows.h>
#include <ctime>
using namespace std;
//function declaration

int damage(int x, int y, int m, int z, int a, int b, int t, int n, int g);

int main() {

	cout << "damage is " << damage(10, 75, 25, .5, 20, 1.2) << endl;;
	system("pause");


}
int damage(int x, int y, int m, int z, int a, int b, int t, int n, int g) {
	int num;
	num = ((2*x/5+2)*(y*m)*z/(a*b)/50 +2)*t*n*g/100;
	cout << "damage is calculated to be " << num << endl;
	return num;



}
