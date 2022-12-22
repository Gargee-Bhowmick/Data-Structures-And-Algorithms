#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
    	long long n;
        cin>>n;
        long long i;
        long long ar[n];
        long long g = 0;
        for(i=0;i<n;i++)
        {
           cin>>ar[i];
		   g = __gcd(g,ar[i]);
        }
        cout<<ar[n-1]/g<<endl;
    }
    return 0;
}
