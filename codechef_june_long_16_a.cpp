#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int n,q,t,mx,mn,vr,qvr;
    cin>>n>>q;
    mx = -1;
    mn = 1e9 + 13;
    for(int i = 1; i <= n; i++){
        cin>>vr;
        mn = min(mn,vr);
        mx = max(mx,vr);
    }
    for(int i = 1; i <= q; i++){
        cin>>qvr;
        if(qvr >= mn && qvr <= mx)
            puts("Yes");
        else puts("No");
    }

    return 0;
}
