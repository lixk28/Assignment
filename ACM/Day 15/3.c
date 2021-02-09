#include<stdio.h>
#define ll long long
const ll p = 1e9+9;
ll Pow(ll a,ll b)
{
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}

ll C(ll n,ll m)
{
int i;
    if(m==0) return 1;
    if(m>n-m) m=n-m;
    ll up=1,down=1;
    for(i=1;i<=m;i++){
        up=(up*(n-i+1))%p;
        down=(down*i)%p;
    }
    return up*Pow(down,p-2)%p;
}
int main()
{
    int m;
    scanf("%d",&m);
    ll ans=C(2*m,m)-C(2*m,m-1);
    if(ans>=0)
        printf("%lld", ans);
    else
        printf("%lld", ans+p);
}