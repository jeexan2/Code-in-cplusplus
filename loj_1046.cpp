#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define inf 1<<29
int t,m,n,mn;
int dist[19][19];
char grid[19][19];
int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};
vector <pii> v;
#define valid(x,y) (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] == -1)
void bfs(int x,int y) {
    memset(dist,-1,sizeof(dist));
    dist[x][y] = 0;
    queue <pii> q;
    q.push(mp(x,y));
    while(!q.empty()) {
        pii u = q.front();q.pop();
        for(int i = 0; i < 8; i++) {
            int vx,vy;
            vx = u.first + dx[i];
            vy = u.second + dy[i];
            if(valid(vx,vy)) {
                dist[vx][vy] = dist[u.first][u.second] + 1;
                q.push(mp(vx,vy));
            }
        }
    }
    vector<pii> ::iterator it;
    int sum = 0;
    bool flag = true;
    for(it = v.begin(); it != v.end(); it++) {
        pii tmp = *it;
        double jmp = (grid[tmp.first][tmp.second] - '0')* 1.0;
        int d = dist[tmp.first][tmp.second];
        if(d <= -1) {
            flag = false;
            break;
        }
        sum += (d + jmp - 1)/jmp;
    }
    if(flag) mn = min(mn,sum);
 
}
int main()
{
 
    cin>>t;
    for(int cs = 1; cs <= t; cs++) {
        cin>>m>>n;
        mn = inf;
        v.clear();
        for(int i = 0; i < m; i++) {
            cin>>grid[i];
            for(int j = 0; j < n; j++) {
                if(grid[i][j] >= '1' && grid[i][j] <= '9')
                    v.push_back(mp(i,j));
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                bfs(i,j);
        printf("Case %d: ",cs);
        if(mn == inf) puts("-1");
        else printf("%d\n",mn);
 
    }
    return 0;
}
