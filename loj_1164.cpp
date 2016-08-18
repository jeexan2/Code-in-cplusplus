#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100019
#define gin(n) scanf("%d",&n)
ll tree[mx*4];
ll lazy[mx*4];
void update(int pos,int l,int r,int st,int ed,int val){
    if(st > r || ed < l) return;
    if(l >= st && r <= ed) lazy[pos] += val;
    else {
        tree[pos] += val * (min(ed,r) - max(st,l) + 1);
        int mid = (l + r)/2;
        update(2 * pos,l,mid,st,ed,val);
        update(2 * pos + 1,mid + 1, r, st,ed,val);
    }
}
ll query(int pos,int l,int r,int st,int ed){
    if(st > r || ed < l) return 0;
    else {
        tree[pos] += lazy[pos] * (r - l + 1);
        if(l != r) {
            lazy[2 * pos] += lazy[pos];
            lazy[2 * pos + 1] += lazy[pos];
        }
        lazy[pos] = 0;
         int mid = (l + r)/2;
        if(l >= st  && r <= ed) return tree[pos];
 
        else return query(2 * pos,l,mid,st,ed) + query(2 * pos +1,mid +1,r,st,ed);
    }
}
int main()
{
    int t;
    gin(t);
    int n,q,st,ed,ch,val;
    ll ans;
    for(int cs = 1; cs <= t; cs++) {
        printf("Case %d:\n",cs);
        gin(n);gin(q);
        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));
        while(q--) {
            gin(ch);
            if(!ch){
                gin(st);gin(ed);gin(val);
                update(1,0,n-1,st,ed,val);
            }
            else {
                gin(st);gin(ed);
                ans = query(1,0,n-1,st,ed);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
