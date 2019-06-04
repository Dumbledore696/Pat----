#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main() {
    int N;
    cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),cmp);
    int m,n;
    for(n=sqrt(double(N));n>=1;n--){
        if(N%n==0){
            m=N/n;
            break;
        }
    }
    vector<vector<int>> b(m,vector<int>(n));
    int t=0;
    int level=m/2+m%2;
    for(int i=0;i<level;i++){
        int j;
        for(j=i;j<=n-1-i&&t<=N-1;j++){
            b[i][j]=v[t++];
        }
        for(j=i+1;j<=m-1-i&&t<=N-1;j++){
            b[j][n-1-i]=v[t++];
        }
        for(j=n-2-i;j>=i&&t<=N-1;j--){
            b[m-1-i][j]=v[t++];
        }
        for(j=m-2-i;j>=i+1&&t<=N-1;j--){
            b[j][i]=v[t++];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j];
            if(j<n-1)cout<<' ';
        }
        cout<<'\n';
    }
    return 0;

}
