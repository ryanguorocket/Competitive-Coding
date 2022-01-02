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

mt19937 g1;
ll get_random_long(ll a,ll b){
    return uniform_int_distribution<ll>(a,b)(g1);
}

const int MAX=1000;

int n;

void solve(){
    ll outp=0;
    cout<<0<<"\n";
    cout.flush();
    int ans;
    cin>>ans;
    if(ans==0)return;
    int ub=ans-1;
    outp|=(ll)(1ll<<ub);
    while(true){
        ll bruh=outp+get_random_long(0ll,(ll)(1ll<<ub)-1);
        cout<<bruh<<"\n";
        cout.flush();
        int a;
        cin>>a;
        if(a==0)break;
        a/=2;
        ub--;
        for(int i=ub;i>=a;i--){
            ll fuck1=bruh&(ll)(1ll<<i);
            if(fuck1!=0ll){
                outp|=(ll)(1ll<<i);
            }
        }
        a--;
        ll fuck=bruh&(ll)(1ll<<a);
        if(fuck==0ll){
            outp|=(ll)(1ll<<a);
        }
        ub=a;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)solve();
}
