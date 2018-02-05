//Factorize a number using Pollard p–1 factorization method. Compare the
//time with the “Trial Division” method.

#include<iostream>
#include<stdio.h>
#include <sys/time.h>
#include<math.h>

using namespace std;
long long int func(long long int a, long long int b,long long int n){
long long int x=1,y=a;
while(b>0){
if(b%2==1){x=(x*y)%n;}
y=(y*y)%n;
b/=2;
}
return x%n;
}

int gccd(int a,int b){

    while (a != b)
    {
        if (a > b)
        {
            return gccd(a - b, b);
        }
        else
        {
            return gccd(a, b - a);
        }
    }
    return a;
}
int trial(int n)
{
int a=2;
//cout<<"value of P=\n";
while(a<=sqrt(n)){
        while(n%a==0){
                n=n/a;
                //cout<<a<<endl;
        }

 a=a+1;
}
        return n;
}
int pollard(int n,int b){
int a=2.0;
int e=2.0;
while(e<=b){
a=func(a,e,n);
e=e+1;
}
int p=gccd(a-1,n);
if(p>1&&p<n)
return p;
return -1;
}
int main(){
int n,b;
struct timeval stop1,stop2, start1,start2;
cout<<"Enter the value of n------";
cin>>n;
cout<<"Enter he value of B------";
cin>>b;
//cout<<"pollard P-1 method\n";
gettimeofday(&start1, NULL);
int d=pollard(n,b);
gettimeofday(&stop1, NULL);
//cout<<"value of P="<<d<<"\n";
printf("pollard method took %lu milliseconds\n", stop1.tv_usec - start1.tv_usec);
//cout<<"Trail and error method\n";
gettimeofday(&start2, NULL);
int v=trial(n);
gettimeofday(&stop2, NULL);
//cout<<v<<"\n";
printf("trial method took %lu milliseconds\n", stop2.tv_usec - start2.tv_usec);
}
