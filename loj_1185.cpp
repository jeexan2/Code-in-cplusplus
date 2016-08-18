#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
vector <int> G[119];
int n,e;
int node[119];
int odd[119];
int even[119];
int bfs(int src) {
    memset(node,-1,sizeof(node));
    memset(odd,0,sizeof(odd));
    memset(even,0,sizeof(even));
    queue<pii> q;
    q.push(mp(1,0));
    node[src] = 0;
 
    while(!q.empty()) {
        int uf = q.front().first;
        int us = q.front().second;
        q.pop();
        int len = G[uf].size();
        for(int i = 0; i < len; i++) {
            int v = G[uf][i];
            int rem = !(us % 2);
            if(node[v] == -1) {
                node[v] = 1;
                q.push(mp(v,rem));
                if(!rem)
                    even[v] = 1;
                else
                    odd[v] = 1;
            }
            else {
              if(!rem && !even[v]) {
                even[v] = 1;
                q.push(mp(v,rem));
              }
              else if(rem && !odd[v]){
                odd[v] = 1;
                q.push(mp(v,rem));
              }
            }
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++)
        if(even[i])
            ret++;
    return ret;
}
int main()
{
    int t,u,v;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d %d",&n,&e);
        for(int i = 0; i < 119; i++)
            G[i].clear();
        for(int i = 0; i < e; i++) {
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        printf("Case %d: %d\n",cs,bfs(1));
    }
    return 0;
}
