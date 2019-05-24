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
const int maxn=10010;
double c[maxn];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        c[i]=a;
    }
    sort(c,c+n);
    for(int i=0;i<n-1;i++){
        double temp=(c[i]+c[i+1])/2;
        c[i+1]=temp;
    }
    printf("%.0f\n",floor(c[n-1]));
    return 0;
}
