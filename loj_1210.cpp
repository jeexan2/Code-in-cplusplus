#include <bits/stdc++.h>
using namespace std;
#define mx 20019
int stck[mx];
bool vis[mx];
int in[mx];
int out[mx];
int comp[mx];
vector <int> G[mx],R[mx];
int top,cnt;
void dfs(int u) {
    int v;
    for(int i = 0; i < G[u].size();i++) {
        v = G[u][i];
        if(!vis[v]) {
            vis[v] = 1;
            dfs(v);
        }
    }
    stck[top++] = u;
}
void dfs2(int u) {
    int v;
    for(int i = 0; i < R[u].size();i++) {
        v = R[u][i];
        if(!vis[v]) {
            vis[v] = 1;
            dfs2(v);
        }
    }
    comp[u] = cnt;
}
int main(){
    int t,n,e,u,v;
    cin>>t;
    for(int cs = 1; cs <= t; cs++) {
        cin>>n>>e;
        for(int i = 0; i <= n; i++) {
            G[i].clear();
            R[i].clear();
        }
        for(int i = 0; i < e; i++) {
            scanf("%d %d",&u,&v);
            u--;
            v--;
            G[u].push_back(v);
            R[v].push_back(u);
        }
        memset(vis,0,sizeof(vis));
        top = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vis[i] = 1;
                dfs(i);
            }
        }
        cnt = 0;
        memset(vis,0,sizeof(vis));
        while(top--) {
            int nd = stck[top];
            if(!vis[nd]) {
                vis[nd] = 1;
                dfs2(nd);
                cnt++;
            }
        }
        printf("Case %d: ",cs);
        if(cnt == 1)
        {
            puts("0");
            continue;
        }
         memset(in,0,sizeof(in));
         memset(out,0,sizeof(out));
         for(int i = 0; i < n; i++) {
            for(int j = 0; j < G[i].size();j++) {
                v = G[i][j];
                if(comp[v] != comp[i]) {
                    in[comp[v]]++;
                    out[comp[i]]++;
                }
            }
         }
         int ans1,ans2;
         ans1 = ans2 = 0;
         for(int i = 0; i < cnt; i++) {
            if(!in[i]) ans1++;
            if(!out[i]) ans2++;
         }
        printf("%d\n",max(ans1,ans2));
    }
    return 0;
}
