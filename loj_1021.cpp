#include <bits/stdc++.h>
using namespace std;
#define check(mask,i) (mask & (1<<i))
#define Set(mask,i) (mask | (1<<i))
#define reset(mask,i) (mask ~ (1<<i))
#define toggle(mask,i) (mask ^ (1<<i))
#define inf 1<<31
#define ll long long int
int b,k,len;
string num;
int a[20];
ll dp[20][1<<17];
 
ll rec(ll mod,int mask){
    ll &ret = dp[mod][mask];
    if(mask == (1<<len)-1)
        return (mod == 0);
    if(ret != -1) return ret;
    ret = 0;
 
    for(int i = len - 1; i >= 0; i--){
        if(!check(mask,i))
            ret += rec((mod * b + a[i])%k,Set(mask,i));
    }
    return ret;
}
int main()
{
    int t;
    cin>>t;
    for(int cs = 1; cs <= t; cs++){
        num.clear();
        cin>>b>>k>>num;
        len = num.length();
        for(int i = 0; i < len; i++)
            {
                if(num[i] >= 'A' && num[i] <= 'Z')
                    a[i] = num[i] - 'A' + 10;
                else a[i] = num[i] - '0';
            }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",cs,rec(0,0));
    }
    return 0;
}
