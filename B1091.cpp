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
bool hashtable[130]={false};
using namespace std;
bool flag=false;
int cal(int judge){
    int num=0;
    if(judge>=0&&judge<=9)num=10;
    else if(judge>=10&&judge<=99)num=100;
    else num=1000;
    int temp=judge*judge;
    for(int i=1;i<=9;i++){
        int ans=i*temp;
        if(ans%num==judge){
            flag=true;
            return i;
        }
    }
}
int main() {
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        flag=false;
        int judge;
        cin>>judge;
        int ans=cal(judge);
        if(flag==true){
            cout<<ans<<' '<<ans*judge*judge<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }
    return 0;
}
