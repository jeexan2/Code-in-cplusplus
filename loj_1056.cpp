#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)

int main()
{
    int t,a,b;
    double ang,R;
    char ch;
    cin>>t;
    for(int cs = 1; cs <= t; cs++)
    {

        scanf("%d : %d",&a,&b);
        ang = atan(1.0*a/b);
        R = 200.0/(2.0 * sin(ang)+(pi - 2 * ang));
        printf("Case %d: %.10lf %.10lf\n",cs,2*R*sin(ang),2*R*cos(ang));

    }
    return 0;
}
