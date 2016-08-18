#include <bits/stdc++.h>
using namespace std;
#define mx 100019
 
struct edge
{
    int u,v;
    double w;
    edge() {};
    edge(int a,int b,double c):u(a),v(b),w(c) {};
    bool operator < (const edge &t) const
    {
        return w < t.w;
    }
};
edge e[mx];
int par[2*mx];
int Find(int u) {
    if(par[u] == u) return u;
    else return par[u] = Find(par[u]);
}
int main()
{
    int t,n,m,a,u,v,w;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++){
        scanf("%d %d %d",&n,&m,&a);
        for(int i = 0; i <= n; i++)
            par[i] = i;
        for(int i = 0; i < m; i++){
            scanf("%d %d %d",&u,&v,&w);
            e[i].u = u;
            e[i].v = v;
            e[i].w = w;
        }
        sort(e,e+m);
        int cost = 0;
         int cnt = 0;
        for(int i = 0; i < m && e[i].w < a; i++) {
            u = Find(e[i].u);
            v = Find(e[i].v);
            if(u != v){
                par[v] = par[u];
                cost += e[i].w;
                cnt++;
            }
        }
 
        printf("Case %d: %d %d\n",cs,cost+ ((n-cnt) * a),n-cnt);
 
    }
    return 0;
}
 
