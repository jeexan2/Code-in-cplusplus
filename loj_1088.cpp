#include<bits/stdc++.h>
using namespace std;
#define MAX 100008
#define ll long long int
ll ar[MAX];
int n;
ll low_bound(ll a){
      ll l=0,r=n-1,mid;
      while(l<=r){
            mid=(l+r)/2;
            if(ar[mid]<a) l=mid+1;
            else r=mid-1;

      }
      return l;
}
ll up_bound(ll a){
       ll l=0,r=n-1,mid;
      while(l<=r){
            mid=(l+r)/2;
            if(ar[mid]<=a) l=mid+1;
            else r=mid-1;

      }
      return l;
}
ll solve(ll a,ll b){
      ll x;
      ll y;
      x= low_bound(a);
      y=up_bound(b);
      return y-x;
}
int main()
{
      ll t,q,b,a;

      scanf("%lld",&t);

      for(int cas=1;cas<=t;cas++){

      scanf("%lld%lld",&n,&q);
      for(int i=0;i<n;i++) cin>>ar[i];
      printf("Case %d:",cas);
      printf("\n");
      for(int i=1;i<=q;i++)
      {

            scanf("%lld%lld",&a,&b);
            printf("%lld\n",solve(a,b));

             }


      }
      return 0;
      }
