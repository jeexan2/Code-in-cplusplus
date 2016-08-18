#include<bits/stdc++.h>
using namespace std;
int a[2019];
int bin(int lo,int hi,int val)
{
    int mid,ret;
    ret = lo - 1;
    while(lo <= hi)
    {
        mid = (lo + hi)/2;
        if(a[mid]<val)
        {
            ret = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return ret;
}
int main()
{
    int t,n;
    cin>>t;
    for(int cs = 1; cs <= t; cs++)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>a[i];
        sort(a,a+n);
        int res = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                res += bin(j+1,n-1,a[i]+a[j]) - j;
            }
        printf("Case %d: %d\n",cs,res);
    }

    return 0;
}
