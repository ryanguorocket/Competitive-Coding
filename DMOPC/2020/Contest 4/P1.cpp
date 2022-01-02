#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,s;
    cin>>n>>s;
    ll tar=(n*(n+1))/2;
    ll d=tar-s;
    if(d>=2*n||d<=0){
        cout<<0<<"\n";
        return;
    }
    if(d>n)cout<<n-d/2<<"\n";
    else cout<<d-1-d/2<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)solve();
}
