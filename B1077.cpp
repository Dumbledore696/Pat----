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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int t;
        double sum=0;
        cin>>t;
        int max1=-1;
        int min1=110;
        int cnt=0;
        for(int j=0;j<n-1;j++){
            int s;
            cin>>s;
            if(s>=0&&s<=m){
                sum+=s;
                cnt++;
                if(s<min1)min1=s;
                if(s>max1)max1=s;
            }
        }
        sum-=max1;sum-=min1;
        sum/=cnt-2;
        double re=(sum+t)/2;
        printf("%.0f\n",round(re));
        //printf("%d\n",int(re+0.5));
    }

    return 0;
}
