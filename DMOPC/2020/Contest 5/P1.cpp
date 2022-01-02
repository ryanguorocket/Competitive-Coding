#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pp;
typedef tuple<int,int,int>tt;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int i;
    for(i=0;i<min(s.length(),t.length());i++){
        if(s[i]!=t[i])break;
    }
    cout<<s.length()-i+t.length()-i<<"\n";
}
