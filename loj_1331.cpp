#include <bits/stdc++.h>
using namespace std;
 
#define eps 1e-9;
 
int main() {
    int test, cs;
    double a, b, c, ab, bc, ca, s, tarea, area;
    double alp, bet, gam;
    scanf("%d", &test);
    for(cs = 1; cs <= test; cs++) {
        scanf("%lf %lf %lf", &a, &b, &c);
        ab = a + b; bc = b + c; ca = c + a;
        s = (ab + bc + ca) * 0.5;
        tarea = sqrt(s * (s - ab) * (s - bc) * (s - ca));
        alp = acos((ab * ab + ca * ca - bc * bc) / (2.0 * ab * ca));
        bet = acos((ab * ab + bc * bc - ca * ca) / (2.0 * ab * bc));
        gam = acos((bc * bc + ca * ca - ab * ab) / (2.0 * bc * ca));
        area = tarea - 0.5 * alp * a * a - 0.5 * bet * b * b - 0.5 * gam * c * c;
        area=area+eps;
        printf("Case %d: %.8lf\n",cs,area);
 
    }
    return 0;
}
 
