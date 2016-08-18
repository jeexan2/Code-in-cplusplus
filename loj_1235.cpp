#include <bits/stdc++.h>
using namespace std;
#define llu long long int
vector <llu> L,R;
llu a[36];
void rec(llu in,int st,int ed,vector<llu> &v) {
    if(st==ed) {
        v.push_back(in);
        return;
    }
    for(int i=0;i<3;i++) {
        rec(in+a[st]*i,st+1,ed,v);
    }
}

int main()
{
    int t,n,m,mid;
    cin>>t;
    for(int cs=1;cs<=t;cs++) {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>a[i];
        L.clear();
        R.clear();
        mid=n/2;
        rec(0,0,mid,L);
        rec(0,mid,n,R);

        sort(L.begin(),L.end());
        bool flag=false;

        for(int i=0;i<R.size();i++) {
            if(m>=R[i]) {
                if(*lower_bound(L.begin(),L.end(),m-R[i])==m-R[i]) {
                    flag=true;
                    break;
                }
            }
        }
        printf("Case %d: ",cs);
        if(flag) printf("Yes");
        else printf("No");
        printf("\n");
    }
    return 0;
    }
