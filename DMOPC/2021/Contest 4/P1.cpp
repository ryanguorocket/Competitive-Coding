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

const int MAX=3000;

int n,q,inp[MAX][6];//x1,y1,x2,y2,x3,y3

bool intersect(int x,int y,int t){
    int x1=inp[t][0];
    int y1=inp[t][1];
    int x2=inp[t][2];
    int y2=inp[t][3];
    int x3=inp[t][4];
    int y3=inp[t][5];
    if(x>max(x1,x3)||x<min(x1,x3))return false;
    if(y>max(y1,y2)||y<min(y1,y2))return false;
    if(x==x3){
        if(y==y1)return true;
        else return false;
    }
    int bruh1=1;
    if(x3<x1)bruh1=-1;
    int bruh2=1;
    if(y2<y1)bruh2=-1;
    if(bruh1*bruh2==1&&(ld)(y1-y)/(x-x3)<=(ld)(y1-y2)/(x1-x3))return true;
    if(bruh1*bruh2==-1&&(ld)(y1-y)/(x-x3)>=(ld)(y1-y2)/(x1-x3))return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++)cin>>inp[i][j];
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        int outp=0;
        for(int j=0;j<n;j++){
            if(intersect(x,y,j)){
                outp++;
            }
        }
        cout<<outp<<"\n";
    }
}
