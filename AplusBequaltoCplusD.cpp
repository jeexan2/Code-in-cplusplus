#include <bits/stdc++.h>
using namespace std;
bool findPairs(int a[],int n) {
    map<int, pair<int,int> > Hash;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++){
            int sum = a[i] + a[j];
            if(Hash.find(sum) == Hash.end()){
                Hash[sum] = make_pair(i,j);
            }
            else {
                pair <int,int> prev = Hash[sum];
                cout<<a[prev.first]<<" + "<<a[prev.second]<<"  =  "<<a[i]<<" + "<<a[j]<<endl;
                return true;
            }
        }
    }
    cout<<"No such pair"<<endl;
    return false;
}
int main()
{
    int arr[] =  {3, 4, 7, 1, 12, 9};

    int n  =  sizeof arr / sizeof arr[0];
    bool x = findPairs(arr, n);
    return 0;
}
