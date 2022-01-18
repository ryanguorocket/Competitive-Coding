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
        cout<<-1<<"\n";
        return 0;
    }
    if(n==4){
        cout<<-1<<"\n";
        return 0;
    }
    vector<int>outp;
    for(int i=1;i<=n;i++)if(i%2==1&&i!=5)outp.push_back(i);
    outp.push_back(5);
    outp.push_back(4);
    for(int i=1;i<=n;i++)if(i%2==0&&i!=4)outp.push_back(i);
    for(int i=0;i<n-1;i++)cout<<outp[i]<<" ";
    cout<<outp[n-1]<<"\n";
}
