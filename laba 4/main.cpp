#include <iostream>
#include <math.h>
using namespace std ;

int main(int argc, char** argv) 
{ double D,a;
  int i ;
  cout<<"vvedit a = ";
  cin>>a;
  cout<<"Vvedit i = ";
  cin>> i ;
  D=1;
  for(i=1;i<=11;i++)
  {D*=pow(a,i);
  }
  cout<<" Dobytok = "<<D<<endl;
	return 0;
}
