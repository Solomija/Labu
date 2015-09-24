#include <iostream>
#include <math.h>
using namespace std ;
int main(int argc, char** argv) {
double d,c,f,k;
cout <<"vvedit d ";
cin>>d;
cout <<"vvedit c";
cin >>c;
cout <<"vvedit f ";
cin >>f;
k=log(d*f+1)+pow(sin(c*f),2);
cout<<"k="<<k<<endl;
	return 0;
}
