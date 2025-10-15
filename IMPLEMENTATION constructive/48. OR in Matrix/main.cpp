// https://codeforces.com/problemset/problem/486/B


#include <bits/stdc++.h>
using namespace std;

#define II pair<int,int>
#define X first
#define Y second
#define PB push_back

int ans[200][200],s[200][200];
int n,m;

bool check(int a,int b){
    for(int i=1;i<=m;i++){
        if( ans[a][i]==1 ) return 1;
    }
    for(int i=1;i<=n;i++){
        if( ans[i][b]==1 ) return 1;
    }
    return 0;
}

int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
            if(s[i][j]==0){
                for(int k=1;k<=m;k++) ans[i][k]=0;
                for(int k=1;k<=n;k++) ans[k][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){  
        for(int j=1;j<=m;j++){
            if( s[i][j]==1 and check(i,j)==0 ) {cout<<"NO";return 0;}
        }
    }

    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}