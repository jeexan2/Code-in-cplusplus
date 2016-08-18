#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mx 219
struct point{int x,y;};
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
char maze[mx][mx];
int r,c;
int dist[mx][mx];
point jane_pos,fire_pos;
bool check(int x,int y){
    return (x >= 0 && x < r && y >= 0 && y < c);
}
bool func(point s) {
    return (s.x == 0 || s.y == 0 || s.x == r-1 || s.y == c-1);
}
void bfs_for_fire(){
    queue<point> q;
    point u,v;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            if(maze[i][j] == 'F')
            {
                dist[i][j] = 0;
                u.x = i;
                u.y = j;
                q.push(u);
            }
    }
    while(!q.empty()) {
        u = q.front();q.pop();
        for(int i = 0; i < 4; i++) {
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];
            if(check(v.x,v.y) && dist[v.x][v.y] > dist[u.x][u.y] + 1) {
                dist[v.x][v.y] = dist[u.x][u.y] + 1;
                q.push(v);
            }
        }
 
    }
}
int bfs_for_jane(point s){
    queue<point> q;
    q.push(s);
    point u,v;
    dist[s.x][s.y] = 0;
    if(func(s)) return 0;
    while(!q.empty()) {
        u = q.front();q.pop();
        for(int i = 0; i < 4; i++) {
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];
            if(check(v.x,v.y) && dist[v.x][v.y] > dist[u.x][u.y] + 1) {
                dist[v.x][v.y] = dist[u.x][u.y] + 1;
                if(func(v)) return dist[v.x][v.y];
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d %d",&r,&c);
        for(int i = 0; i <= r; i++)
            for(int j = 0; j <= c; j++)
                dist[i][j] = inf;
        for(int i = 0; i < r; i++) {
            scanf("%s",maze[i]);
            for(int j = 0; j < c; j++) {
                if(maze[i][j] == 'J')
                    jane_pos.x = i,jane_pos.y = j;
                else if(maze[i][j] == '#')
                    dist[i][j] = -1;
            }
        }
        //cout<<jane_pos.x<<" "<<jane_pos.y<<" "<<fire_pos.x<<" "<<fire_pos.y<<endl;
        bfs_for_fire();
        int res = bfs_for_jane(jane_pos);
        printf("Case %d: ",cs);
        if(res == -1) puts("IMPOSSIBLE");
        else printf("%d\n",++res);
    }
    return 0;
}
 
