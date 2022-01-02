#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int MAX=2*1e5;
const int SQRT=(int)ceil(sqrt(MAX));
const int mod=1e9+7;
string inp;
int n,m;
ll outp,base[SQRT];
vector<int>grid[SQRT];
vector<ll>phash[SQRT];
gp_hash_table<ll,ll>hm;
void constructHash(){
    base[0]=1;
    for(int i=1;i<SQRT;i++)base[i]=(2*base[i-1])%mod;
    for(int i=0;i<m;i++)phash[0].push_back(grid[0][i]);
    for(int i=1;i<n;i++)for(int y=0;y<m;y++)phash[i].push_back((phash[i-1][y]+base[i]*grid[i][y])%mod);
}
void hadd(){
    for(auto&i:hm)outp+=(i.second*(i.second-1))/2;
    hm.clear();
}
void solve(int a,int b){
    for(int i=0;i<m;i++){
        if(grid[a][i]!=grid[b][i])hadd();
        else{
            ll h=phash[b][i];
            if(a!=0)h-=phash[a-1][i];
            h%=mod;
            if(h<0)h+=mod;
            if(hm.find(h)!=hm.end())hm[h]++;
            else hm[h]=1;
        }
    }
    hadd();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    if(n>m){
        for(int i=0;i<n;i++){
            cin>>inp;
            for(int y=0;y<m;y++){
                if(inp[y]=='B')grid[y].push_back(0);
                else grid[y].push_back(1);
            }
        }
        swap(n,m);
    }
    else{
        for(int i=0;i<n;i++){
            cin>>inp;
            for(int y=0;y<m;y++){
                if(inp[y]=='B')grid[i].push_back(0);
                else grid[i].push_back(1);
            }
        }
    }
    constructHash();
    outp=0;
    for(int i=0;i<n;i++)for(int y=i+1;y<n;y++)solve(i,y);
    cout<<outp<<"\n";
}
