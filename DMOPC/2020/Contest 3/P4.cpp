#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
const int MAXN=30000;
int n,psa[MAXN];
vector<int>inp,fbest,bbest;
vector<pi>pma[MAXN];
int findFirst(int p){
    if(inp[p]>psa[p-1])return -1;
    int lef=0;
    int rig=p-1;
    int mid=(lef+rig)/2;
    while(rig-lef>1){
        if(psa[mid]<psa[p]-psa[mid])lef=mid;
        else rig=mid;
        mid=(lef+rig)/2;
    }
    if(psa[lef]>=psa[p]-psa[lef])return lef+1;
    else return rig+1;
}
void solve(vector<int>&cbest){
    psa[0]=inp[0];
    for(int i=1;i<n;i++)psa[i]=psa[i-1]+inp[i];
    for(int i=0;i<n;i++)pma[i].clear();
    cbest.push_back(1);
    for(int i=1;i<n;i++){
        int pnt,pot,clast;
        pnt=pot=clast=-1;
        int ff=findFirst(i);
        if(ff==-1){
            cbest.push_back(1);
            continue;
        }
        else pma[i].push_back({ff,2});
        for(int j=ff;j<=i;j++){
            clast=psa[i]-psa[j-1];
            while(psa[j-1]-(pnt!=-1?psa[pnt]:0)>=clast)pnt++;
            if(pnt==-1)continue;
            while(!pma[j-1].empty()&&pnt<pma[j-1].back().first)pma[j-1].pop_back();
            if(!pma[j-1].empty()&&pma[j-1].back().second+1>pma[i].back().second)pma[i].push_back({j,pma[j-1].back().second+1});
        }
        cbest.push_back(pma[i].back().second);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    inp=vector<int>(n);
    for(int i=0;i<n;i++)cin>>inp[i];
    solve(fbest);
    reverse(inp.begin(),inp.end());
    solve(bbest);
    reverse(bbest.begin(),bbest.end());
    int outp=1;
    for(int i=0;i<n-1;i++)outp=max(outp,fbest[i]+bbest[i+1]);
    cout<<outp<<"\n";
}
