#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10010;
struct Stu{
    string name;
    int height;
};
typedef struct Stu stu;
bool cmp(stu a,stu b){
    if(a.height!=b.height)return a.height>b.height;
    else return a.name<b.name;
}
int main() {
    int N,K;
    cin>>N>>K;
    vector<stu> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i].name>>v[i].height;
    }
    sort(v.begin(),v.end(),cmp);
    int row=K;
    int t=0;
    while(row){
        int m;//m为每排人数
        if(row==K)m=N-N/K*(K-1);
        else m=N/K;
        vector<string> name(m);
        name[m/2]=v[t].name;
        int j=m/2-1;
        for(int i=t+1;i<t+m;i=i+2){
            name[j--]=v[i].name;
        }
        j=m/2+1;
        for(int i=t+2;i<t+m;i=i+2){
            name[j++]=v[i].name;
        }
        for(int i=0;i<m;i++){
            cout<<name[i];
            if(i<m-1)cout<<' ';
            else cout<<'\n';
        }
        t+=m;
        row--;

    }

    return 0;
}
