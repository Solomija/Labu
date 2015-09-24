#include <iostream>
#include <math.h>
using namespace std ;
int main(int argc, char** argv) 
{double x1,x2,y,C,D,A1,A2;
C=1.231;
D=1.532;

cout<<"Vvedit x1 = ";
cin >> x1;
cout <<"vvedit x2 = ";
cin>> x2;
cout<<"Vvedit y =";
cin>> y;
cout<<endl;

if (x1<y) A1=x1+pow(y,1.0/3.0);
else A1=cos(C*y)-D*x1;

if (x2<y) A2=x2+pow(y,1.0/3.0);
else A2=cos(C*y)-D*x2;

cout <<"A1="<<A1<< endl;
cout <<"A2="<<A2;
cout<<endl;	
return 0;
}
