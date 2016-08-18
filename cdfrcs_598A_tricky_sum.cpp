#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,n,ans;
    cin>>t;
    while(t--){
        cin>>n;
        ans = n*(n+1)/2;

        for(int i = 1; i <= n;i *= 2)
            ans -= (i*2);
        cout<<ans<<endl;

    }
    return 0;
}
