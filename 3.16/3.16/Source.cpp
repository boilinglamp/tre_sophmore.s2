#include <iostream>
#include <fstream>

using namespace std;

int main() {

	int a;
    int b;
    cout<<"Enter first number:\n";
    cin >> a;
    cout <<"Enter the second number:\n";
    cin>> b;
    cin.ignore();
    int result = a + b;
    cout<<"Result is"<<"  "<<result<<endl;
    cin.get();
    return 0;


}