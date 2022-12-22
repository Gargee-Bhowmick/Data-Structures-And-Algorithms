#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        int k;
        cin>>n>>k;
        int s=0;
        map<int, int> m;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
             m.insert({x,0});
             s+=x;
        }
        int large;
        for(auto &pr:m)
        {
            large=pr.first;
        }
        int sum=((large+1)*(large))/2 - s;
        if(k<sum){cout<<"NO"<<endl;}
        else if(k==sum){cout<<"YES"<<endl;}
        else{
            k-=sum;
            // cout<<k<<" "<<sum<<endl;
            while(++large)
            {
                k-=large;
                if(k==0)
                {
                    cout<<"YES"<<endl;break;
                }
                else if(k<0)
                {
                    cout<<"NO"<<endl;break;
                }
                else;
            }
        }
    }
    return 0;
}
