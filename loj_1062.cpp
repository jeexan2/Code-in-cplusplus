#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8

int main()
{
    double x,y,c,lo,hi,mid,a,b,fct;
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++) {
        cin>>x>>y>>c;
        lo = 0;
        hi = max(x,y);
        while(fabs(hi - lo)>eps){
                mid = (lo + hi)/2.0;
                a = sqrt(x * x - mid * mid);
                b = sqrt(y * y - mid * mid);
                fct = a * b / (a + b);
                if(fabs(fct - c) <= eps) break;
                else if (fct > c) lo = mid;
                else hi = mid;

        }
        printf("Case %d: %.7lf\n",cs,mid + eps);

    }
    return 0;
}
