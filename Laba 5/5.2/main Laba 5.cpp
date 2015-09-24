#include <iostream>
#include<math.h>
using namespace std;
int main(int argc, char** argv) {
	float y , x,xp,xk,xd;
	
	cout<<"xp=";cin>>xp;
	cout<<"xk=";cin>>xk;
	cout<<"xd=";cin>>xd;
	x=xp;
	while(x<=xk+xd/2)
	{y=3*pow(log10(x),2)+pow(log(x+1),2);
	cout<<x<<"\t"<<y<<endl;
	x+=xd;
	}
	return 0;
}

