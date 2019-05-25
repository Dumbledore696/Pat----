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
int main() {
    int m,n,a,b,t;
    cin>>m>>n>>a>>b>>t;
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int s;
            scanf("%d",&s);
            cnt++;
            if(s>=a&&s<=b)printf("%03d",t);
            else printf("%03d",s);
            if(cnt%n==0)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
