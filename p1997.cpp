#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const ll N=1e6+10;
ll pos[N];

int main()
{
    ll a,b;
    cin>>a>>b;

    ll maxn=0;
    ll k=0;
    for(ll i=a;i<=b;i++)
    {
        ll temp=i;
        ll index=0;
        while(temp>9)
        {
            ll arr=1;
            while(temp>0)
            {
                arr*=temp%10;
                temp/=10;
            }
            temp=arr;
            index++;
        }

        maxn=max(maxn,index);
        pos[k]=index;
        k++;
    }

    cout<<maxn<<endl;

    ll tt=0;
    for(ll i=0;i<=b-a;i++)
    {
        if(!tt)
        {
            if(pos[i]==maxn)
            {
                cout<<i+a;
                tt=1;
            }
        }
        else if(pos[i]==maxn)
        {
            cout<<" "<<i+a;
        }
    }

    return 0;
}
