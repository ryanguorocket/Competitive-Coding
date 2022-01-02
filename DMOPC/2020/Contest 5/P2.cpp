#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pp;
typedef tuple<int,int,int>tt;
ll n,m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    bool bruh=false;
    if(n>m){
        swap(n,m);
        bruh=true;
    }
    vector<int>x,y;
    for(int i=0;i<m;i++){
        ll lef=ceil(((long double)n*i)/(long double)m);
        if(n*i%m==0)lef++;
        ll rig=ceil(((long double)n*(i+1))/(long double)m);
        if(bruh){
            if(lef==rig){
                x.push_back(lef);
                y.push_back(i+1);
            }
            else{
                x.push_back(lef);
                y.push_back(i+1);
                x.push_back(rig);
                y.push_back(i+1);
            }
        }
        else{
            if(lef==rig){
                x.push_back(i+1);
                y.push_back(lef);
            }
            else{
                x.push_back(i+1);
                y.push_back(lef);
                x.push_back(i+1);
                y.push_back(rig);
            }
        }
    }
    cout<<x.size()<<"\n";
    for(int i=0;i<x.size();i++){
        cout<<y[i]<<" "<<x[i]<<"\n";
    }
}
