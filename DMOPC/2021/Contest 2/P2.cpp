#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int>pi;
typedef tuple<int,int,int>ti;

const int MAX=300;

int n,q,arr[MAX],pos[MAX],query[MAX],outp[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        arr[i]=i;
        pos[i]=i;
    }
    for(int i=0;i<q;i++){
        char op;
        cin>>op;
        if(op=='B'){
            int a,b;
            cin>>a>>b;
            a--;b--;
            swap(arr[pos[a]],arr[pos[b]]);
            swap(pos[a],pos[b]);
        }
        else if(op=='E'){
            int a,b;
            cin>>a>>b;
            a--;b--;
            swap(pos[arr[a]],pos[arr[b]]);
            swap(arr[a],arr[b]);
        }
        else{
            for(int j=0;j<n;j++){
                cin>>query[j];
                query[j]--;
            }
            for(int j=0;j<n;j++){
                outp[arr[j]]=query[j];
            }
            for(int j=0;j<n;j++){
                if(j!=n-1)cout<<outp[j]+1<<" ";
                else cout<<outp[j]+1<<"\n";
            }
        }
    }
}
