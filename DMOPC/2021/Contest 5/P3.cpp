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

const int MAX=1e5;

int n;

bool isBad[MAX+1];

bool prime[MAX+1];
vector<int>primes;

bool sieve[MAX+1];
void construct(){
    sieve[1]=true;
    for(int i=2;i<=MAX;i++){
        if(!sieve[i]){
            prime[i]=true;
            primes.push_back(i);
            for(int j=i;j<=MAX;j+=i)sieve[j]=true;
        }
    }
}

void makeBad(){
    for(int i=3;i<MAX+1;i++){
        for(int j:primes){
            if(i-j<=0)break;
            if(!isBad[i-j]){
                isBad[i]=true;
                break;
            }
        }
    }
}

void solve(){
    cin>>n;
    if(n==1||n==2){
        cout<<-1<<"\n";
        return;
    }
    if(isBad[n]){
        for(int i=1;i<n;i++)cout<<i<<" ";
        cout<<n<<"\n";
        return;
    }
    if(n==11){
        for(int i=1;i<9;i++)cout<<i<<" ";
        cout<<"11 9 10\n";
        return;
    }
    if(n==36){
        for(int i=1;i<34;i++)cout<<i<<" ";
        cout<<"36 34 35\n";
        return;
    }
    if(n==311){
        for(int i=1;i<309;i++)cout<<i<<" ";
        cout<<"311 309 310\n";
        return;
    }
    for(int i=1;i<n-1;i++)cout<<i<<" ";
    cout<<n<<" "<<n-1<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    construct();
    makeBad();
    int t;
    cin>>t;
    while(t--)solve();
}
