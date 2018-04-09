//Write class Student.Class Student has 4 variables : ID#, age, Gender, and LastName, and two functions : init and print.Instantiate 4 - 5 students and push them into a vector.Use a for loop to print the information 
//for each student.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class other_kids {
private:
	string n;
	string i;
	string a;
	bool g;
	string l;
public:
	void studentinit(string name, string id, string age, string gender, string lastname);
	void drawstudent();
};

int main() {

	other_kids leon;
	other_kids dat_boi_tj;
	other_kids frannando;
	other_kids spook;



	leon.studentinit("leon", "789654", "2", 1, "noon");
	dat_boi_tj.studentinit("cj", "357951", "86", 1, "merktanmis");
	frannando.studentinit("ferdnandodo", "321654", "27", 1, "gonzolace");
	spook.studentinit("spook", "684264","18", 1, "masterkey");

	vector <other_kids>::iterator iter;
	vector <other_kids>school;

	school.push_back(leon);
	school.push_back(dat_boi_tj);
	school.push_back(frannando);
	school.push_back(spook);

	for (iter = school.begin(); iter != school.end(); iter++) {
		iter->drawstudent();
		system("Pause");
	}
}

void other_kids::studentinit(string name, string id, string age, bool gender, string lastname) {
	n = name;
	i = id;
	a = age;
	g = gender;
	l = lastname;
}

void other_kids::drawstudent() {
	cout << "Your student" << n << " " << l << " has a id# of " << i << " is " << a << " year old "<< << endl;
	if (g == 1) {
		cout << "boy." << endl;
	}
	else
		cout << "girl" << endl;

}
