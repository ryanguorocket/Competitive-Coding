#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int>tt;
const int MAX=1e5;
int n,m,p,q,a,b,parent[MAX][2],si[MAX][2];
ll total,c;
vector<tt>edge;
int findParent(int be,int t){
    if(parent[be][t]==be)return be;
    return parent[be][t]=findParent(parent[be][t],t);
}
bool connected(int be,int en,int t){
    return findParent(be,t)==findParent(en,t);
}
void connect(int be,int en,int t){
    if(si[findParent(be,t)][t]>si[findParent(en,t)][t])swap(be,en);
    parent[findParent(be,t)][t]=findParent(en,t);
    si[findParent(en,t)][t]+=si[findParent(be,t)][t];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>p>>q;
    memset(si,0,sizeof(si));
    for(int i=0;i<max(n,m);i++){
        parent[i][0]=i;
        parent[i][1]=i;
    }
    total=0;
    for(int i=0;i<p;i++){
        cin>>a>>b>>c;
        edge.push_back(make_tuple(10*c,a-1,b-1));
        total+=c*n;
    }
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        edge.push_back(make_tuple(10*c+1,a-1,b-1));
        total+=c*m;
    }
    sort(edge.begin(),edge.end());
    for(tt i:edge){
        if(connected(get<1>(i),get<2>(i),get<0>(i)%10))continue;
        connect(get<1>(i),get<2>(i),get<0>(i)%10);
        if(get<0>(i)%10){
            total-=m*(get<0>(i)/10);
            n--;
        }
        else{
            total-=n*(get<0>(i)/10);
            m--;
        }
    }
    cout<<total<<"\n";
}
