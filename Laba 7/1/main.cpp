#include <iostream>
using namespace std ;
const int m = 5;
const int n = 4;
int main(int argc, char** argv) 
{
	int i,j;
	float A[m][n],x[n];
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{ 
			cout << "A[" << i << "][" << j << "]= ";cin >> A[i][j];
		}
	for(j = 0; j < n; j++)
	{
		x[j] = 1;
		for(i = 0; i < m; i++)
			x[j] = x[j] * A[i][j];
	}
	for(j = 0; j < n; j++)
		cout << "x[" << j << "]=" << x[j] << endl;
	return 0;
}
