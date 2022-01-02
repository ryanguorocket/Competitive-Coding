#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int>pp;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>bbtree;
int n,m;
bbtree t;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<pp>ninp;
    set<int>check;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        ninp.push_back({x,y});
        t.insert(y);
        check.insert(y);
    }
    sort(ninp.begin(),ninp.end());
    int pnt=0;
    ll outp=0;
    vector<pp>minp;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        minp.push_back({x,y});
    }
    sort(minp.begin(),minp.end());
    for(int i=0;i<m;i++){
        int x=minp[i].first;
        int y=minp[i].second;
        while(ninp[pnt].first<x&&pnt<n){
            t.erase(ninp[pnt].second);
            check.erase(check.find(ninp[pnt].second));
            pnt++;
        }
        outp+=t.order_of_key(y);
        if(check.find(y)!=check.end())outp++;
    }
    cout<<outp<<"\n";
}
