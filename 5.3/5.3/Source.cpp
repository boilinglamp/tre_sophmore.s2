//#include <iostream>
//using namespace std;
//int main()
//{
//	const int Numb = 20;
//	int i;
//	int a[Numb];
//	int max = a[10]; {456, 897, 123, 195, 741, 856, 654, 32, 98, 615}
//	int min = a[10]; {654, 8, 354, 45, 987, 357, 987, 3, 915, 64}
//
//	for (i = 0; i < 20; i++)
//	{
//		if (a[i] > max)
//		{
//			max = a[i];
//		}
//		else if (a[i] < min)
//		{
//			min = a[i];
//		}
//	}
//	cout << max << endl;
//	cout << min << endl;
//
//	return 0;;
//}
#include <iostream>
using namespace std;
int main ()
{
int mn,mx;
const int Numb = 10;
int a[Numb]; //10 elements
cout<<"Enter 10 values:"; //prompts user for 10 values.
for(int i=0;i<10;i++)
{
cout<< "\nEnter value: ";
cin>> a[i]; // puts values in array
}

mn=a[0];
mx=a[0];
for(int i=1;i<10;i++)
	{
		if(mn>a[i])
		{
			mn=a[i];
		}
		else if(mx<a[i])
		{
			mx = a[i];
		}
	}

cout<<"Maximum number is: "<< mx << endl;
cout<<"Minimum number is: "<< mn << endl;
system("pause");
return 0;

}