#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 10019
ll c4[mx];
ll cnt[mx];
ll res[mx];
int main()
{
    c4[4] = 1;
    for(int i = 5; i < mx; i++)
        c4[i] = c4[i-1] * i/(i - 4);
 
    int t,n,in,maxa;
    cin>>t;
    for(int cs = 1; cs <= t; cs++){
        maxa = 0;
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        for(int i = 1; i <= n; i++) {
            cin>>in;
            maxa = max(in,maxa);
            for(int j = 1; j * j <= in; j++){
                if(!(in%j)){
                    cnt[j]++;
                    if(j*j != in)
                        cnt[in/j]++;
                }
            }
 
        }
        for(int i = maxa; i > 0; i--){
            res[i] = c4[cnt[i]];
            for(int j = 2*i; j <= maxa;j+= i)
                res[i] -= res[j];
        }
        printf("Case %d: %lld\n",cs,res[1]);
    }
    return 0;
}
 

VOLUME
Volume Home
Problem Set
Problem Category
Problem Setters
Submit Problem
My Submissions
Judge Status
Ranklist
User Statistics
Compare User Statistics
 
