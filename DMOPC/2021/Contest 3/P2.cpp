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

const int MAX=1000002;

ll k;

//as long as a+b<=1e6+1

ll a[MAX];

gp_hash_table<ll,int>st;

vector<int>outp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    if(k==0){
        cout<<1<<"\n";
        cout<<1<<"\n";
        return 0;
    }
    for(int i=0;i<MAX;i++){
        ll bruh=(ll)i;
        a[i]=(bruh*(bruh-1))>>1;
        if(i!=1)st[a[i]]=i;
    }
    for(int i=1;i<MAX;i++){
        ll f=k-a[i];
        if(st.find(f)!=st.end()){
            if(i-1+st[f]<MAX-1){
                for(int j=0;j<i-1;j++)outp.push_back(0);
                if(st[f]!=0)outp.push_back(1);
                for(int j=0;j<st[f]-1;j++)outp.push_back(0);

                cout<<outp.size()<<"\n";
                for(int i=0;i<outp.size()-1;i++)cout<<outp[i]<<" ";
                cout<<outp.back()<<"\n";
                return 0;
            }
        }
    }
    cout<<-1<<"\n";
}
