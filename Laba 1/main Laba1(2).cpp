#include <iostream>
#include <math.h>
using namespace std; 
int main(int argc, char** argv) 
{double a,b,x,y;
cout<<"vvedit a =";
cin>> a;
cout<<"vvedit b = ";
cin>>b;
cout<<"Vvedit x = ";
cin>>x;
y=log(sqrt(x)+b*x*x)/(pow(a+x,1.0/9.0))*exp(3.9)-tan(a+b)+acos(b);
cout<<"y"<<y<<endl;
	return 0;
}
