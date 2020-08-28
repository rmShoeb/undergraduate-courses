#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

int fact(int n)
{
	if(n>1)
		return n*fact(n-1);
	else
		return 1;
}

double d_y(double x, double y)
{
	return (x-y*y);
}

double d2_y(double x, double y)
{
	return (1-2*y*d_y(x,y));
}

double d3_y(double x, double y)
{
	return (-2*y*d2_y(x,y)-2*d_y(x,y)*d_y(x,y));
}

int main(void)
{
	double x_initial;
	double y_initial;
	double find_x;
	double find_y;
	int i;
	vector<double>y;

	printf("Enter the initial value of x: ");
	cin>>x_initial;
	printf("Enter the initial value of y: ");
	cin>>y_initial;

	y.push_back(d_y(x_initial, y_initial));
	y.push_back(d2_y(x_initial, y_initial));
	y.push_back(d3_y(x_initial, y_initial));

	printf("Enter the value of x to find the value of y: ");
	cin>>find_x;

	find_y=1;
	for(i=0;i<3;i++)
	{
		find_y+=((pow(find_x,i+1)*y[i])/fact(i+1));
	}

	printf("The value of y: ");
	cout<<find_y;
}
