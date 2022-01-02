#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pp;
typedef tuple<int,int,int>tt;
const int MAXN=5*1e5;
int n,m,out[MAXN],outp[MAXN];
vector<int>in[MAXN];
bool p[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==1)p[i]=true;
        else p[i]=false;
    }
    memset(out,0,sizeof(out));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        in[b].push_back(a);
        out[a]++;
    }
    memset(outp,0,sizeof(outp));
    queue<int>evt;
    for(int i=0;i<n;i++)if(out[i]==0)evt.push(i);
    while(!evt.empty()){
        int cur=evt.front();
        evt.pop();
        if(outp[cur]==1)continue;
        outp[cur]=1;
        for(int i:in[cur]){
            if(p[i])evt.push(i);
            else{
                out[i]--;
                if(out[i]==0)evt.push(i);
            }
        }
    }
    for(int i=0;i<n-1;i++)cout<<outp[i]<<" ";
    cout<<outp[n-1]<<"\n";
}
