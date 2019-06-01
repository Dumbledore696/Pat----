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
    string s1,s2;
    char c;
    cin>>c;
    char ch=getchar();
    getline(cin,s1);
    if(c=='C'){
        int i,j;
        for(i=0;i<s1.size();i=j){
            for(j=i;j<s1.size()&&s1[i]==s1[j];j++);
            if((j-i)!=1)
                cout<<j-i<<s1[i];
            else
                cout<<s1[i];
        }
    }
    else{
        int i,j;
        for(i=0;i<s1.size();i=j+1){
            int num=0;
            if(s1[i]>='0'&&s1[i]<='9'){
                for(j=i;j<s1.size()&&s1[j]>='0'&&s1[j]<='9';j++){
                    num=10*num;
                    num+=s1[j]-'0';
                }
            }
            else{
                j=i;
                num=1;
            }
            for(int p=0;p<num;p++){
                printf("%c",s1[j]);
            }
        }
    }


    return 0;
}
