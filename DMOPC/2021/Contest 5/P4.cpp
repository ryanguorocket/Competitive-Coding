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

vector<int>primes;
bool flag[MAX+1];
bool sieve[MAX+1];

void calcPrimes(){
    for(int i=2;i<=MAX;i++){
        if(!sieve[i]){
            primes.push_back(i);
            flag[i]=true;
            for(int j=i;j<=MAX;j+=i)sieve[j]=true;
        }
    }
}

int arr[MAX];

void solve(){
    cin>>n;
    if(n==1){
        cout<<"1\n";
        return;
    }
    if(n==2){
        cout<<"-1\n";
        return;
    }
    if(n==3){
        cout<<"-1\n";
        return;
    }
    if(n==4){
        cout<<"3 1 4 2\n";
        return;
    }
    if(n==5){
        cout<<"1 4 2 5 3\n";
        return;
    }
    if(n==6){
        cout<<"1 3 5 2 4 6\n";
        return;
    }
    if(n==7){
        cout<<"1 6 4 2 7 5 3\n";
        return;
    }
    int p1,p2;
    for(int i:primes){
        if(flag[2*(n/2)-i]){
            p1=i;
            p2=2*(n/2)-i;
            break;
        }
    }
    arr[0]=n-p2;
    for(int i=1;i<2*(n/2);i++){
        int cur=arr[i-1];
        if(cur-p1>0)arr[i]=cur-p1;
        else arr[i]=cur+p2;
    }
    if(n%2==0){
        for(int i=0;i<n-1;i++)cout<<arr[i]<<" ";
        cout<<arr[n-1]<<"\n";
        return;
    }
    for(int i=1;i<2*(n/2);i++)cout<<arr[i]<<" ";
    cout<<arr[0]<<" "<<n<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    calcPrimes();
    while(t--)solve();
}
