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
    int N,D;
    double e;
    cin>>N>>e>>D;
    double likeempty=0.0;
    double empty1=0.0;
    for(int i=0;i<N;i++){
        int d;
        int cnt=0;
        cin>>d;
        for(int j=0;j<d;j++){
            double usage;
            cin>>usage;
            if(usage<e){
                cnt++;
            }
        }
        if(cnt>d/2&&d<=D){
            likeempty++;
        }
        else if(cnt>d/2&&d>D){
            empty1++;
        }
    }
    double likerate,emptyrate;
    likerate=likeempty/N;
    emptyrate=empty1/N;
    printf("%.1f%% ",likerate*100);
    printf("%.1f%%",emptyrate*100);
    return 0;

}
