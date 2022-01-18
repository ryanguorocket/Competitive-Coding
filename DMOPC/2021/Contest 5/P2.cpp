#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
typedef pair<double,double>pd;
typedef tuple<int,int,int>ti;
typedef tuple<ll,ll,ll>tll;
typedef tuple<double,double,double>td;
typedef complex<double>cd;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>bbst;

const int MAX=1e6;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    if(n==2){
        cout<<-1<<"\n";
        return 0;
    }
    if(n==3){
        cout<<"1 3 2\n";
        return 0;
    }
    cout<<"1 3 2 ";
    for(int i=4;i<n;i++)cout<<i<<" ";
    cout<<n<<"\n";
}
