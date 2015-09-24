#include <iostream>
#include <math.h>

using namespace std;
const int n = 15;
int main(int argc, char** argv) 
{
  int i,k;
  float max, A[n];
    for(i = 0; i < n; i++)
    { 
	  cout << "A[" << i << "]="; cin >> A[i];
   	}
    max = A[0];
    k=0;
    for(i = 1; i <n; i++)
   		 if (A[i] > max) 
			{
    		 max = A[i];
   			 k = i;
			};
	A[k] = A[0];
	A[0] = max;
    for(i = 0; i < n; i++)
  		 cout << "A[" << i << "]=" << A[i] << endl;
   	return 0;
}
