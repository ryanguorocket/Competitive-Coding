#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pp;
typedef tuple<int,int,int>tt;
const int MAXN=5*1e5;
int n;
map<int,vector<int>>arr;
set<pp,greater<pp>>st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<2*n;i++){
        int a;
        cin>>a;
        if(arr.find(a)==arr.end()){
            vector<int>temp;
            arr[a]=temp;
        }
        arr[a].push_back(i+1);
    }
    for(auto&i:arr){
        st.insert({i.second.size(),i.first});
    }
    vector<pp>outp;
    while(st.size()>=2){
        pp x=*st.begin();
        pp y=*next(st.begin());
        outp.push_back({arr[x.second].back(),arr[y.second].back()});
        pp nx={x.first-1,x.second};
        pp ny={y.first-1,y.second};
        arr[x.second].pop_back();
        arr[y.second].pop_back();
        st.erase(st.find(x));
        st.erase(st.find(y));
        if(nx.first!=0)st.insert(nx);
        if(ny.first!=0)st.insert(ny);
    }
    cout<<outp.size()<<"\n";
    for(pp i:outp){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    if(st.size()==1){
        for(int i=0;i<arr[(*st.begin()).second].size();i+=2){
            cout<<arr[(*st.begin()).second][i]<<" "<<arr[(*st.begin()).second][i+1]<<"\n";
        }
    }
}
