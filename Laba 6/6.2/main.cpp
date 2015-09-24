#include <iostream>
#include <math.h>
using namespace std;
const int n = 15;
int main(int argc, char** argv)
 {
	int i,k;
	float b = 3.5,d, A[n];
	for(i = 0; i < n; i++)
   	{ 
	  cout << "A[" << i << "]="; cin >> A[i]; 
	};
	if (b > A[9])
	{
		d=1;
		for(i = 0; i < n; i++)
			if(A[i] < 0) 
				d = d * A[i];
		cout << "d = " << d << endl; 
	}
	 else
	 {
	 	k = 0;
	    for(i = 0; i < n; i++)
			if(A[i] < b) 
				k = k + 1;
	    cout << "k = " << k << endl;
	 }
	 return 0;
 }
