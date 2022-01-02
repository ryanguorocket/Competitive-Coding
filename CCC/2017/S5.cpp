#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAX=150000;
const int BLK=600;
int n,m,q;
int arr[MAX],ind[MAX],psa[MAX];
int lsi[MAX],lstart[MAX];
vector<int>lines[MAX],lpsa[MAX];
unordered_map<int,int>mp;
void reconstruct(){
    for(int i=0;i<m;i++){
        for(int j=0;j<lines[i].size();j++){
            int p=j+lstart[i];
            arr[lines[i][j]]=lpsa[i][p]-(p!=0?lpsa[i][p-1]:0);
        }
    }
    psa[0]=arr[0];
    for(int i=1;i<n;i++)psa[i]=arr[i]+psa[i-1];
    mp.clear();
}
int query(int l,int r){
    int ret=psa[r]-(l!=0?psa[l-1]:0);
    for(auto&[i,j]:mp){
        int lp=lower_bound(lines[i].begin(),lines[i].end(),l)-lines[i].begin()+lstart[i];
        int rp=upper_bound(lines[i].begin(),lines[i].end(),r)-lines[i].begin()-1+lstart[i];
        if(lp>rp)continue;
        ret-=lpsa[i][rp+j]-(lp+j!=0?lpsa[i][lp+j-1]:0);
        ret+=lpsa[i][rp]-(lp!=0?lpsa[i][lp-1]:0);
    }
    return ret;
}
void rotateLine(int p){
    lstart[p]=(lstart[p]+lsi[p]-1)%lsi[p];
    if(mp.find(p)==mp.end())mp[p]=0;
    mp[p]++;
    mp[p]%=lsi[p];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        cin>>ind[i];
        ind[i]--;
        lines[ind[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
        psa[i]=arr[i]+(i!=0?psa[i-1]:0);
    }
    for(int i=0;i<n;i++){
        if(lpsa[ind[i]].empty())lpsa[ind[i]].push_back(arr[i]);
        else lpsa[ind[i]].push_back(arr[i]+lpsa[ind[i]].back());
    }
    for(int i=0;i<m;i++)lsi[i]=lines[i].size();
    for(int i=0;i<n;i++)lpsa[ind[i]].push_back(arr[i]+lpsa[ind[i]].back());
    for(int i=0;i<n;i++)lpsa[ind[i]].push_back(arr[i]+lpsa[ind[i]].back());
    for(int i=0;i<q;i++){
        if((i+1)%BLK==0)reconstruct();
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            cout<<query(l,r)<<"\n";
        }
        else{
            int a;
            cin>>a;
            a--;
            rotateLine(a);
        }
    }
}
