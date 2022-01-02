#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pp;
typedef tuple<int,int,int>tt;
const int MAXN=1e6;
int n;
ll inp[2*MAXN];
ll s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    s=0;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        inp[i+n]=inp[i];
        s+=inp[i];
    }
    int r=0;
    ll cs=0;
    for(int i=0;i<n;i++){
        while(abs(s-2*(cs+inp[r]))<abs(s-2*cs)){
            cs+=inp[r];
            r++;
        }
        if(i!=n-1)cout<<abs(s-2*cs)<<" ";
        else cout<<abs(s-2*cs)<<"\n";
        cs-=inp[i];
    }
}
