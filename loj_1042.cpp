#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll one(ll n) {
    ll ret = 0;
    for(ll i = 1; i <= n; i *= 2) {
        if((n & (i)))
            ret++;
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    ll n,nxt;
    for(int cs = 1; cs <= t; cs++) {
        scanf("%lld",&n);
        for(ll i = 1; i <= n; i *= 2)
            if((n & (i))) {
                nxt = n + i;
                break;
        }
        ll ed = one(n) - one(nxt);
        for(ll i = 0; i < ed; i++) {
            nxt += (1<<i);
        }
 
 
        printf("Case %d: %lld\n",cs,nxt);
 
    }
 
 
    return 0;
}
 
