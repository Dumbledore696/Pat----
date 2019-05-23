#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
map<int,string> mp1,mp2,mp3;
int main() {
    string t1,t2,t3;
    getline(cin,t1);
    int cnt=0;
    for(int i=0;i<t1.size();){
        if(t1[i++]!='['){
                continue;
        }
        string s1;
        while(t1[i]!=']'&&i<t1.size()){
            s1+=t1[i];
            i++;
        }
        mp1[++cnt]=s1;
    }

    getline(cin,t2);
    cnt=0;
    for(int i=0;i<t2.size();){
        if(t2[i++]!='['){
                continue;
        }
        string s2;
        while(t2[i]!=']'&&i<t2.size()){
            s2+=t2[i];
            i++;
        }
        mp2[++cnt]=s2;
    }
    getline(cin,t3);
    cnt=0;
    for(int i=0;i<t3.size();){
        if(t3[i++]!='['){
                continue;
        }
        string s3;
        while(t3[i]!=']'&&i<t3.size()){
            s3+=t3[i];
            i++;
        }
        mp3[++cnt]=s3;
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        if(a>mp1.size()||b>mp2.size()||c>mp3.size()||d>mp2.size()||e>mp1.size()||a<1||b<1||c<1||d<1||e<1){
            cout<<"Are you kidding me? @\\/@";
        }
        else{
            cout<<mp1[a]<<'('<<mp2[b]<<mp3[c]<<mp2[d]<<')'<<mp1[e]<<endl;
        }

    }
    return 0;
}
//hello
