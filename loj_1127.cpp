#include <bits/stdc++.h>
using namespace std;

#define llu long long int
int n,w;
int a[40];
int M;
vector <llu> ara1, ara2;
void rec(int index,llu sum,bool flag) {
    if(sum>w) return;
    if(index>M) {
        if(sum<=w) {
            if(flag) ara1.push_back(sum);
            else ara2.push_back(sum);
        }
        return;
    }
    rec(index+1,sum,flag);
    rec(index+1,sum+a[index],flag);

}
int bin_srch(llu val) {
    int lo=0;
    int hi=(int) ara2.size()-1;
    int mid,ans=lo-1;
    while(lo<=hi) {
        mid=(lo+hi)/2;
        if(ara2[mid]<=val) {
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}
int main()
{
    cout<<abs(1-2)<<endl;
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++) {
        cin>>n>>w;
        for(int i=0;i<n;i++) cin>>a[i];
        M=n/2;
        rec(0,0,true);
        M=n-1;
        rec(n/2+1,0,false);

        sort(ara1.begin(),ara1.end());
        sort(ara2.begin(),ara2.end());
        int out=0;

        for(int i=0;i<ara1.size();i++)
            out+=(1+(bin_srch(w-ara1[i])));
        printf("Case %d: %d\n",cs,out);
        ara1.clear();
        ara2.clear();
        }
    return 0;
    }
