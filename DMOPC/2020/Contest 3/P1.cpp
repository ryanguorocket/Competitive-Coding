#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool arr[n];
    memset(arr,false,sizeof(arr));
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        a--;
        if(a>=n){
            cout<<"NO"<<"\n";
            return 0;
        }
        if(arr[a]){
            cout<<"NO"<<"\n";
            return 0;
        }
        arr[a]=true;
    }
    cout<<"YES"<<"\n";
}
