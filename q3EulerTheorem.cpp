//Find multiplicative inverse using Euler’s theorem.

#include<iostream>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y);
 
void modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        
        int res = (x%m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
    }
}

int gcdExtended(int a, int b, int *x, int *y)
{
    
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 

    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int main()
{
    int a,m;
    cout<<"Enter value of a : ";
    cin>>a;	
    cout<<"Enter Modulo value : ";
    cin>>m;	
    modInverse(a, m);
    return 0;
}
