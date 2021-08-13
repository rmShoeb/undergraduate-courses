#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

double f(double x, double y)
{
	return (x-y*y);
}

int main(void)
{
	double x;
	vector<double>y;
	double find_x;
	double find_y;
	double h, temp;
	int i=0;

	printf("Enter the initial value of x: ");
	cin>>x;
	printf("Enter the initial value of y: ");
	cin>>temp;
	y.push_back(temp);
	printf("Enter the value of x to find the value of y: ");
	cin>>find_x;
	printf("Enter the value of h: ");
	cin>>h;

	while(x<=find_x)
	{
		temp=y[i]+h*f(x,y[i]);
		y.push_back(temp);
		x+=h;
		i++;
	}

	printf("The value of y: ");
	cout<<y[i];
}
