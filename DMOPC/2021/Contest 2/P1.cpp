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

int n;
ll h,p;
ll freq[MAX+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>h>>p;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        freq[a]++;
    }
    ll cn=n;
    ll ch=0;
    ll cp=0;
    for(int i=1;i<=MAX;i++)cp+=p*i*freq[i];
    ll outp=ch+cp;
    for(int i=1;i<=MAX;i++){
        ch+=h;
        cp-=p*cn;
        cn-=freq[i];
        outp=min(outp,ch+cp);
    }
    cout<<outp<<"\n";
}
