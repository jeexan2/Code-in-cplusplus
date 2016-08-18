#include <bits/stdc++.h>
using namespace std;
struct edge{
    int from,to,w;
    edge(int a,int b,int c):from(a),to(b),w(c){ };
    bool operator < (const edge &e) const {
        return this->w < e.w;
    }
};
map <string,int> m;
vector <edge> v;
int par[191];
int Find(int u) {
    if(u == par[u]) return u;
    return par[u] = Find(par[u]);
}
int main()
{
    string n1,n2;
    int t,n,e,w;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++){
        v.clear();
        m.clear();
        scanf("%d",&e);
        n = 0;
        for(int i = 0; i < e; i++) {
            cin>>n1>>n2>>w;
            if(!m[n1]) m[n1] = ++n;
            if(!m[n2]) m[n2] = ++n;
            v.push_back(edge(m[n1],m[n2],w));
        }
        for(int i = 0; i < 191; i++)
            par[i] = i;
        sort(v.begin(),v.end());
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < e && cnt < n-1; i++) {
            int U = Find(v[i].from);
            int V = Find(v[i].to);
            if(U != V) {
                ans += v[i].w;
                par[U] = par[V];
                cnt++;
            }
        }
        printf("Case %d: ",cs);
        if(cnt != n-1) puts("Impossible");
        else printf("%d\n",ans);
 
    }
    return 0;
}
 
