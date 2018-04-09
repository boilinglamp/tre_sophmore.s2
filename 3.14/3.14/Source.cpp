//Create a string array and initialize it with user input, asking for their favorite foods.Then, search through the array looking for the word “taco”.If it’s there, tell them 
//that tacos are great.Otherwise, insult them.


#include <iostream>
#include <string>
using namespace std;
//int main() {
//	string input;
//	string taco;
//
//	cout << "what is your favorite food boi?" << endl;
//	cin >> input;
//
//	if (input.compare("taco")==0) {
//		cout << "you duh best boi"<< endl;
//	}
//	else
//		cout << "BAKA!!!!!!!!" << endl;
//	
//}

	int main()
	{
		char fInitial, mInitial, lInitial;
		string fName, mName, lName;

		cout << "Enter your first middle and last name" << endl;

		getline(cin, fName, ' ');
		fInitial = fName[0];

		getline(cin, mName, ' ');
		mInitial = mName[0];

		getline(cin, lName, '\n');
		lInitial = lName[0];

		cout 
			<< " your monogram is " << fInitial << lInitial << mInitial << endl;

		return 0;
	}