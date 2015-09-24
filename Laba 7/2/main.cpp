#include <iostream>
using namespace std;
const int m = 5;
const int n = 5;
int main(int argc, char** argv)
{
 int i, j;
    float S, A[m][n];
    for(i = 0; i < m; i++)
	for(j = 0; j < n; j++)
       { cout << "A[" << i << "][" << j <<"]= ";
	     cin >> A[i][j];
       }
    for(i = 0; i < m; i++)
	     {
		 	S = 0;
	     	for(j = 0; j < n; j++)
	     		 S += A[i][j];
	 	    cout << "strithcka " << i << "  symma " << S << endl;
	     }
   return 0;
}
