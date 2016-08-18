#include <bits/stdc++.h>
using namespace std;
struct edge{
    int from,to,w;
    edge(int a,int b,int c):from(a),to(b),w(c){ };
    bool operator < (const edge &e) const {
        return  this->w < e.w  ;
    }
};
 
vector <edge> v;
int par[191];
int Find(int u) {
    if(u == par[u]) return u;
    return par[u] = Find(par[u]);
}
 
int main()
{
    int t,n,wt;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++)
    {
        for(int i = 0; i < 191; i++)
            par[i] = i;
        v.clear();
        scanf("%d",&n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                scanf("%d",&wt);
 
                if(!wt) continue;
                 sum += wt;
                if(i != j)
                    v.push_back(edge(i,j,wt));
            }
        }
        sort(v.begin(),v.end());
        int sz = v.size();
        int cnt = 0;
        int ans = 0;
        for(int i = 0; cnt < n -1 && i < sz; i++){
            int U = Find(v[i].from);
            int V = Find(v[i].to);
            if(U != V) {
                ans += v[i].w;
                cnt++;
                par[U] = par[V];
            }
        }
        printf("Case %d: ",cs);
        if(cnt != n-1) printf("-1\n");
        else printf("%d\n",sum - ans);
 
 
    }
    return 0;
}
