#include <cstdlib>
#include <iostream>
#include <string.h>
#include <math.h>

#define a 7.83
#define x 4.15
#define y 5.37
#define z 4.01

#define p(k) ((exp(a)+k)/(1+exp(k)))

using namespace std;

int main(int argc, char *argv[])
{
     double func;
    
     func = (((p(pow(x,2))-1)/(p(pow(y,3.0/2.0)))+x*y)+p(z));
    
     cout << func <<endl;    
    
    system("PAUSE");
    return 0;
}
