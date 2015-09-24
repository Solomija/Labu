#include <iostream>
#include <iostream>
#include <math.h>
using namespace std;
double x[100],rez=1;
void peredprog()
{
	int i;
	for(i=0;i<=100;i++)x[i]=1;
}
void getx(int i,double a,double b, double c)
{
	x[i]+=((a-exp(b))/c);	
}
double getF(double x)
{
	rez*=x;
	return rez;
}
int main(int argc, char *argv[]) 
{
	peredprog();
	int i,j,m,n;
	double F;
	cout<<"m=";
	cin>>m;
	cout<<"n=";
	cin>>n;
	double a,b[m][n],c;
	cout<<"a=";
	cin>>a;
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cout<<"b["<<i+1<<"]["<<j+1<<"]=";
			cin>>b[i][j];
		}
	cout<<"c=";
	cin>>c;
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			getx(i,a,b[i][j],c);
			F=((1+exp(getF(x[i])))/2);}
	cout<<"Rozrahunok vykonano. F="<<F<<endl;
	return 0;}

