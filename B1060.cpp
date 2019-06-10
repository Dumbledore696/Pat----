#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=0;
    int i=0;
    while(i<n){
        if(v[i]>i+1)cnt++;
        i++;
    }
    cout<<cnt<<endl;
    return 0;
}
