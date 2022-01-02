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

const int MAX=1e6;

int k,n,arr[MAX],lef[MAX],lf[MAX],rig[MAX],rf[MAX];

void calcLeft(){
    lef[0]=0;
    lf[0]=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            lef[i]=lef[i-1];
            lf[i]=0;
        }
        else if(arr[i]==arr[i-1]){
            if(lf[i-1]!=k-1){
                lef[i]=lef[i-1];
                lf[i]=lf[i-1]+1;
            }
            else{
                lef[i]=i-k;
                lf[i]=k-1;
            }
        }
        else{
            lef[i]=i;
            lf[i]=0;
        }
    }
}

void calcRight(){
    rig[n-1]=n-1;
    rf[n-1]=0;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1]){
            rig[i]=rig[i+1];
            rf[i]=0;
        }
        else if(arr[i]==arr[i+1]){
            if(rf[i+1]!=k-1){
                rig[i]=rig[i+1];
                rf[i]=rf[i+1]+1;
            }
            else{
                rig[i]=i+k;
                rf[i]=k-1;
            }
        }
        else{
            rig[i]=i;
            rf[i]=0;
        }
    }
}

vector<int>range[MAX];

void solve(){
    int outp=0;
    int en=-1;
    int cbest=-1;
    for(int i=0;i<n;i++){
        for(int j:range[i]){
            cbest=max(cbest,j);
        }
        if(i>en){
            outp++;
            en=cbest;
        }
    }
    cout<<outp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>arr[i];
    calcLeft();
    calcRight();
    for(int i=0;i<n;i++){
        range[lef[i]].push_back(rig[i]);
    }
    solve();
}
