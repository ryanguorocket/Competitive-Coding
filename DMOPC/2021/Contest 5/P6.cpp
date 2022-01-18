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

int n,arr[MAX];

bool flag[MAX+1];

bool sieve[2*MAX+1];
int psa[2*MAX+1];

void calcPrimes(){
    for(int i=2;i<=2*MAX;i++){
        if(!sieve[i]){
            psa[i]=i;
            for(int j=i;j<=2*MAX;j+=i)sieve[j]=true;
        }
    }
    for(int i=2*MAX-1;i>=0;i--)if(psa[i]==0)psa[i]=psa[i+1];
}

vector<int>fr;

vector<int>adj[MAX+1];

bool off[2][MAX+1],used[MAX+1];
int mt[MAX+1];

bool kuhn(int p){
    if(used[p])return false;
    used[p]=true;
    for(int i:adj[p]){
        if(off[1][i])continue;
        if(mt[i]==-1||kuhn(mt[i])){
            mt[i]=p;
            return true;
        }
    }
    return false;
}

bool check(){
    for(int i:fr)mt[i]=-1;
    for(int i=max(1,n-154);i<n;i++){
        if(off[0][i+1])continue;
        for(int j=max(1,n-160);j<n;j++)used[j+1]=false;
        if(!kuhn(i+1))return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    calcPrimes();
    if(n%2==0)arr[0]=2;
    else arr[0]=1;
    flag[arr[0]]=true;
    int mt=arr[0];
    for(int i=1;i<n-154;i++){
        if(arr[i-1]!=1&&!flag[arr[i-1]-1]){
            arr[i]=arr[i-1]-1;
            flag[arr[i]]=true;
        }
        else{
            arr[i]=psa[i+1+mt+1]-i-1;
            mt=arr[i];
            flag[arr[i]]=true;
        }
    }
    for(int i=1;i<=n;i++)if(!flag[i])fr.push_back(i);
    for(int i=max(1,n-154);i<n;i++){
        for(int j:fr){
            if(psa[i+1+j]==i+1+j){
                adj[i+1].push_back(j);
            }
        }
    }
    for(int i=max(1,n-154);i<n;i++){
        for(int j:adj[i+1]){
            if(off[1][j])continue;
            off[0][i+1]=true;
            off[1][j]=true;
            if(!check()){
                off[0][i+1]=false;
                off[1][j]=false;
            }
            else{
                arr[i]=j;
                break;
            }
        }
    }
    for(int i=0;i<n-1;i++)cout<<arr[i]<<" ";
    cout<<arr[n-1]<<"\n";
}
