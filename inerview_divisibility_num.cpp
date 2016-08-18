#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,num,sum;
    int p[10];
    p[0] = 1;
    for(int i = 1; i < 10; i++)
        p[i] = 10 * p[i-1];

    char n[1000];
    cin>>t;
    while(t--){
        cin>>n;
        int len = strlen(n);
        num = sum = 0;
        strrev(n);
        for(int i = 0; i < len; i++) {
            sum += n[i] - '0';
            num += p[i] * (n[i]-'0');
        }
        if(!(num%sum)) puts("1");
        else puts("0");
    }
    return 0;
}
