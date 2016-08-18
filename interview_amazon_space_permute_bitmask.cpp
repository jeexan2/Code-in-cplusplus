#include <bits/stdc++.h>
using namespace std;

int main()
{
    string in;
    int t;
    cin>>t;
    while(t--){
        cin>>in;
        int len = in.length();
        len--;
        for(int i = 0; i <(1LL << len);i++) {
            string out;
            out += in[0];
            for(int j = 0; j < len;j++){
                if(i & (1LL << j)) {
                    out += " ";
            }
            out += in[j+1];
            }
            cout<<"("<<out<<")";
        }
        puts("");
    }
    return 0;
}
