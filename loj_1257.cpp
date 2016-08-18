#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define mx 30019
vector <pii> G[mx];
int d1[mx],d2[mx];
bool visit[mx];
void bfs(int s,int &t,int d[]) {
    memset(visit,false,sizeof(visit));
    queue<int> q;
    q.push(s);
    visit[s] = true;
    d[s] = 0;
    int maxa = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        int len = G[u].size();
        for(int i = 0; i < len; i++) {
            int v = G[u][i].first;
            int w = G[u][i].second;
            if(visit[v])
                continue;
            d[v] = d[u] + w;
            if(d[v] > maxa) {
                maxa = d[v];
                t = v;
            }
            visit[v] = true;
            q.push(v);
        }
    }
}
int main()
{
    int t,n,u,v,w,src,dst,nxt;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            G[i].clear();
        for(int i = 0; i < n-1; i++) {
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back(mp(v,w));
            G[v].push_back(mp(u,w));
        }
     bfs(0,src,d1);
     bfs(src,dst,d1);
     bfs(dst,nxt,d2);
     printf("Case %d:\n",cs);
     for(int i = 0; i < n; i++)
            printf("%d\n",max(d1[i],d2[i]));
    }
    return 0;
}
