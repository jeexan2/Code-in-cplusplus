#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define ppi pair<pii,int>
#define mx 5019
vector < pii > G[mx];
int dist[mx][2];
set< int > s;
set< int > ::iterator it;
int dijkstra(int src,int dst){
    int u,v,w,bst,sbst,nbst,nsbst;
    priority_queue<ppi,vector <ppi>,greater < ppi> > q;
    dist[src][0] = 0;
    q.push(ppi(pii(0,inf),src));
    while(!q.empty()) {
        bst = q.top().first.first;
        sbst = q.top().first.second;
        u = q.top().second;q.pop();
        int len = G[u].size();
        for(int i = 0; i < len;i++){
            v = G[u][i].second;
            w = G[u][i].first;
            s.clear();
            s.insert(min(bst + w,inf));
            s.insert(min(sbst + w,inf));
            s.insert(dist[v][0]);
            s.insert(dist[v][1]);
            it = s.begin();
            nbst = *it++;
            nsbst = *it;
            if(dist[v][0] > nbst || dist[v][1] > nsbst) {
                dist[v][0] = nbst;
                dist[v][1] = nsbst;
                q.push(ppi(pii(dist[v][0],dist[v][1]),v));
            }
        }
    }
    return dist[dst][1];
}
int main()
{
    int t,u,v,w,n,e;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d %d",&n,&e);
        for(int i = 0; i <= n; i++)
            G[i].clear();
        memset(dist,inf,sizeof(dist));
        for(int i = 0; i < e; i++) {
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back(pii(w,v));
            G[v].push_back(pii(w,u));
        }
        int res = dijkstra(1,n);
        printf("Case %d: ",cs);
        if(res == inf) puts("-1");
        else printf("%d\n",res);
    }
    return 0;
}
 
