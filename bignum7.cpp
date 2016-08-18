#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    string n;
    cin>>t;
    int m7[110];
    m7[0] = 1;
    m7[1] = 3;
    for(int i = 2; i < 110;i++){
        m7[i] = (m7[i-1]*10)%7;
    }
    while(t--) {
        cin>>n;
        int rem = 0;
        reverse(n.begin(),n.end());
        for(int i = 0;i < n.length();i++) {
            rem += ((n[i]-'0')*m7[i])%7;
            rem %= 7;
            if(rem < 0)
                rem += 7;
        }
        cout<<rem<<endl;

    }
    return 0;
}
