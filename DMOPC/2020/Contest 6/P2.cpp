#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pp;
typedef tuple<int,int,int>tt;
const int MAXN=5*1e5;
int n,a[MAXN],b[MAXN],fa[2],fb[2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    fa[0]=0;
    fa[1]=0;
    fb[0]=0;
    fb[1]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        fa[a[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        fb[b[i]]++;
    }
    if(fa[0]!=fb[0]||fa[1]!=fb[1]){
        cout<<-1<<"\n";
        return 0;
    }
    int az=0;
    int bz=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)az++;
        if(b[i]==0)bz++;
        if(az>bz){
            cout<<-1<<"\n";
            return 0;
        }
    }
    vector<pp>v;
    int al=0;
    int bl=-1;
    for(int i=0;i<n;i++){
        if(b[i]==1){
            if(bl!=i-1){
                int tar=i-bl-1;
                int ac=0;
                while(ac<tar){
                    if(a[al]==0)ac++;
                    al++;
                }
                if(bl+tar!=al-1)v.push_back({bl+1,al-1});
            }
            bl=i;
        }
    }
    cout<<v.size()<<"\n";
    for(pp i:v)cout<<i.first+1<<" "<<i.second+1<<"\n";
}
