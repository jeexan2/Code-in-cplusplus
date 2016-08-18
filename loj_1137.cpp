#include <bits/stdc++.h>
using namespace std;
#define eps 1e-10
#define pi acos(-1)
double l,n,c,L,ang;
double bin(){
    double lo = 0, hi = pi/2;
    double mid;
    while(hi - lo > eps){
        mid = (hi + lo) / 2.0;
        if(l*mid < L * sin(mid))
            lo = mid;
        else
            hi = mid;
    }
    return mid;
}
int main()
{
    int t;
    cin>>t;
    for(int cs = 1; cs <= t ; cs++){
        cin>>l>>n>>c;
        L = (1+n*c)*l;
        ang = bin();
        double ans;
        ans = (L/2/ang);
        ans *= (1-cos(ang));
        printf("Case %d: %lf\n",cs,ans);

    }


    return 0;
    }
