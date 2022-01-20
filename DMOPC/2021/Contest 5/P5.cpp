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

const int MAX=100;

int n;

bool isPrime[2*MAX];
void sieve(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<2*MAX;i++){
        if(!isPrime[i])continue;
        for(int j=2*i;j<2*MAX;j+=i)isPrime[j]=false;
    }
}

int adj[MAX][MAX];

int bv,best[MAX],sv,state[MAX];
bool flag[MAX];

const double geo=0.9999995;
double temp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    clock_t init=clock();
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    for(int i=0;i<n;i++)best[i]=i;
    for(int i=0;i<n;i++)state[i]=best[i];
    sieve();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(isPrime[abs(i-j)]){
                adj[i][j]=abs(i-j);
                adj[j][i]=abs(i-j);
            }
        }
    }
    temp=n;
    int cnt;
    while((double)(clock()-init)/CLOCKS_PER_SEC<1.95){
        int a=rand()%(n-1)+1;
        cnt=(a!=n-1?adj[state[a+1]][state[0]]-adj[state[a+1]][state[a]]:0);
        if(exp(cnt/temp)>=(double)rand()/RAND_MAX){
            reverse(state,state+a+1);
            sv+=cnt;
            if(sv>bv){
                for(int i=0;i<n;i++)best[i]=state[i];
                bv=sv;
            }
        }
        temp*=geo;
    }
    for(int i=0;i<n-1;i++)cout<<best[i]+1<<" ";
    cout<<best[n-1]+1<<"\n";
}
