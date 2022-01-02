#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,inp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll outp=0;
    ll num=1;
    stack<int>free;
    for(int i=0;i<n;i++){
        cin>>inp;
        if(inp<num){
            outp+=num-inp-1;
            free.push(i);
        }
        else if(inp==num)num++;
        else{
            for(int y=0;y<inp-num;y++){
                outp+=i-free.top();
                free.pop();
            }
            num=inp+1;
        }
        if(i!=n-1)cout<<outp<<" ";
        else cout<<outp<<"\n";
    }
}
