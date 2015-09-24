#include <iostream>
#include <mnmatrix.h>

usingnamespace std ;

int main(int argc, char** argv) 
{ 
  int m,n;
  cout<<"m = " ;
  cin>> m ; 
  cout<<"n = " ;
  cin>> n ; 
  float a,b ;
  float**A;
  A= new float * [m];
  for (int i = 0; i< m ; i++)
  A[i] = new float [n];
  
  for ( int i=0;i<m;i++)
  foe (int j=0;j<n;j++)
  
  cout<< "A"<< i+1<<"]["<<j+1"]=;
  cin>> A [i] [j];
}
a=min ( A,m,n)
b=max ( A,m,n)
cout<<"max="<<a<<endl;
cout<<"min="<<b<<endl;

	return 0;
}
