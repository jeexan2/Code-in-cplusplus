#include <bits/stdc++.h>
using namespace std;
#define mx 1019
int n,m;
int a[mx];
vector<int> G[mx];
bool visit[mx];
int cnt = 0;
int dfs(int u) {
    if(visit[u]) return 0;
    cnt++;
    visit[u] = true;
    int ret = a[u];
    int len = G[u].size();
    for(int i = 0; i < len; i++) {
        int v = G[u][i];
        ret += dfs(v);
    }
    return ret;
}
int main()
{
    int t,u,v,n,m;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d %d",&n,&m);
        memset(visit,0,sizeof(visit));
        for(int i = 1; i <= n; i++) {
            G[i].clear();
            scanf("%d",&a[i]);
        }

        for(int i = 0; i < m; i++) {
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bool flag = true;
        set<int> s;
        for(int i = 1; i <= n; i++) {
            if(!visit[i]) {
                cnt = 0;
                int ans = dfs(i);
                if(ans % cnt) {
                    flag = false;
                    break;
                }
                s.insert(ans/cnt);
            }
        }
        printf("Case %d: ",cs);
        if(flag && s.size() == 1)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
