#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    unordered_set<ll>r,c;
    for(int i=0;i<k;i++){
        ll a,b;
        cin>>a>>b;
        if(r.find(a)!=r.end())r.erase(a);
        else r.insert(a);
        if(c.find(b)!=c.end())c.erase(b);
        else c.insert(b);
    }
    int rs=r.size();
    int cs=c.size();
    cout<<max(rs,cs)<<"\n";
    vector<ll>rl,cl;
    for(auto&i:r)rl.push_back(i);
    for(auto&i:c)cl.push_back(i);
    for(int i=0;i<min(rs,cs);i++)cout<<rl[i]<<" "<<cl[i]<<"\n";
    for(int i=0;i<abs(rs-cs);i++){
        if(rs>cs)cout<<rl[i+min(rs,cs)]<<" "<<1<<"\n";
        else cout<<1<<" "<<cl[i+min(rs,cs)]<<"\n";
    }
}
