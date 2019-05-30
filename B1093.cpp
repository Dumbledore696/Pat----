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
int main() {
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<a.size();i++){
        if(hashtable[a[i]]==false){
            cout<<a[i];
            hashtable[a[i]]=true;
        }
    }
    for(int i=0;i<b.size();i++){
        if(hashtable[b[i]]==false){
            cout<<b[i];
            hashtable[b[i]]=true;
        }
    }
    return 0;
}
