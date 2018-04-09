#include <iostream>
#include <vector>
#include <string>

using namespace std;

class car {
private:
	string c;
	int f;
	string b;
	bool d;
public:
	void trotterinit(string color, int fuel, string brand, bool drive_type);
	void drawtrotter();
};

int main() {

	car car1;
	car car2;
	car car3;
	car car4;
	car car5;
	car car6;

	car1.trotterinit("purple", 1, "Bord", 1);
	car2.trotterinit("yellow", 9001, "Bolt's SWAGGIN'", 1);
	car3.trotterinit("red", 0, "Jesus Christler", 0);
	car4.trotterinit("black", 15, "Beep", 0);
	car5.trotterinit("green", 30, "Toy Yoda", 0);
	car6.trotterinit("white", 45, "Volvemort", 1);

	vector <car>::iterator iter;
	vector <car>garage;

	garage.push_back(car1);
	garage.push_back(car2);
	garage.push_back(car3);
	garage.push_back(car4);
	garage.push_back(car5);
	garage.push_back(car6);

	for (iter = garage.begin(); iter != garage.end(); iter++) {
		iter->drawtrotter();
		system("Pause");
	}
}

void car::trotterinit(string color, int fuel, string brand, bool drive_type) {
	c = color;
	f = fuel;
	b = brand;
	d = drive_type;
}

void car::drawtrotter() {
	cout << "Your " << c << " " << b << " has " << f << " gallons of gas." << endl;
	if (d == 1) {
		cout << "It has four wheel drive." << endl;
	}
	else
		cout << "It does not have four wheel drive." << endl;

}
