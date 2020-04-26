#include"LinkStack.h"
#include<iostream>
using namespace std;



int main(void)
{
	LinkStack* s = new LinkStack;
	initLStack(s);

	double* temp;
	temp = new double;
	*temp = -1;
	cout << *temp << endl;
	pushLStack(s, *temp);
	getTopLStack(s, temp);
	cout << *temp << endl;
	delete temp;

	double* a;
	a = new double;
	popLStack(s, a);
	cout << *a << endl;
	system("pause");
	return 0;
}