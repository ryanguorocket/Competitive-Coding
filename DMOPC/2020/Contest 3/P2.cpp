#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll base=1e9;
int n,m,outp;
ll k,dif,cur;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n>>k;
    dif=base*k+k;
    //cout<<dif<<"\n";
    int input[m][n];
    vector<ll>col[n-1];
    for(int i=0;i<m;i++){
        for(int y=0;y<n;y++){
            cin>>input[i][y];
            input[i][y]--;
        }
    }
    for(int i=0;i<m;i++)for(int y=0;y<n-1;y++)col[y].push_back(base*input[i][y]+input[i][y+1]);
    for(int i=0;i<n-1;i++)sort(col[i].begin(),col[i].end());
    outp=0;
    for(int i=0;i<n-1;i++){
        int l=0;
        int r=0;
        for(int y=0;y<m;y++){
            while(col[i][r]-col[i][l]<dif&&r<m-1)r++;
            if(col[i][r]-col[i][l]==dif)outp++;
            if(r==m-1)break;
            l++;
        }
    }
    cout<<outp<<"\n";
}
