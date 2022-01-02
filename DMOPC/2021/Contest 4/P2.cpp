#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int>pi;
typedef tuple<int,int,int>ti;

const int MAX=2*1e6;

int n,arr[MAX];

bool flag[5000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int outp=0;
    for(int i=0;i<n;i++){
        if(!flag[arr[i]]){
            outp++;
            for(int j=arr[i];j<=5000000;j+=arr[i])flag[j]=true;
        }
    }
    cout<<outp<<"\n";
}
