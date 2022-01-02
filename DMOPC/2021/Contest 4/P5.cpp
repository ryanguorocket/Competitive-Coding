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

const int MAX=3*1e3;
const int mod=1e9+7;

int n,m,k;

bool flag[MAX];

vector<int>adj[MAX];

int dist[MAX][MAX];

void bfs(int p){
    dist[p][p]=0;
    queue<int>q;
    q.push(p);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i:adj[cur]){
            if(dist[p][i]==INT_MAX){
                dist[p][i]=dist[p][cur]+1;
                q.push(i);
            }
        }
    }
}

ll total,allRoot,numAll,curCur,numProd,prodProd,curProd,curRoot,prodRoot;

void precalc(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            curCur=(curCur+dist[i][j])%mod;
            if(flag[i]&&flag[j])prodProd=(prodProd+dist[i][j])%mod;
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(flag[i])curProd=(curProd+dist[i][j])%mod;
    for(int i=0;i<n;i++){
        curRoot=(curRoot+dist[0][i])%mod;
        if(flag[i]){
            numProd++;
            prodRoot=(prodRoot+dist[0][i])%mod;
        }
    }
}

void solve(){
    ll ntotal=(numProd*total)%mod;
    ntotal=(ntotal+curCur)%mod;
    ntotal=(ntotal+((n*(allRoot+numAll))%mod)*numProd)%mod;
    ntotal=(ntotal+numAll*curProd)%mod;
    ntotal=(ntotal+((numAll*numAll)%mod)*prodProd)%mod;
    ll a=(numAll*(allRoot+numAll))%mod;
    ll b=(numProd*(numProd-1))%mod;
    ntotal=(ntotal+a*b)%mod;

    ll nallRoot=((allRoot+numAll)*numProd)%mod;
    nallRoot=(nallRoot+prodRoot*numAll)%mod;
    nallRoot=(nallRoot+curRoot)%mod;

    ll nnumAll=(numProd*numAll)%mod;
    nnumAll=(nnumAll+n)%mod;

    total=ntotal;
    allRoot=nallRoot;
    numAll=nnumAll;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a)flag[i]=true;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)dist[i][j]=INT_MAX;
    for(int i=0;i<n;i++)bfs(i);
    precalc();
    for(int i=0;i<k;i++)solve();
    cout<<total<<"\n";
}
