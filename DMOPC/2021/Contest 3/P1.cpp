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

int n;

ll arr[10000];

ll amb;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cout<<"? 1 2\n";
    cout.flush();
    cin>>amb;
    cout<<"? 2 1\n";
    cout.flush();
    cin>>arr[1];
    arr[1]/=-2;
    arr[0]=amb+arr[1];
    ll cur=2*arr[0];
    for(int i=2;i<n;i++){
        cout<<"? 2 "<<i+1<<"\n";
        cout.flush();
        ll v;
        cin>>v;
        arr[i]=cur-v;
        cur+=arr[i];
    }
    cout<<"! ";
    for(int i=0;i<n-1;i++)cout<<arr[i]<<" ";
    cout<<arr[n-1]<<"\n";
}
