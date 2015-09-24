#include <iostream>
#include<math.h>
 using namespace std;
int main(int argc, char** argv) {
	float y , x,xp,xk,xd;
	cout<<"xp=";cin>>xp;
	cout<<"xk=";cin>>xk;
	cout<<"xd=";cin>>xd;
	x=xp;
do 
  {
 y=3*pow(log10(x),2)+pow(log(x+1),2);
	cout<<x<<"\t"<<y<<endl;
	x+=xd;
	}
while(x<=xk+xd/2);
	return 0;
}

