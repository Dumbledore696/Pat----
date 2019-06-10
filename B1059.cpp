#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
const int maxn=10010;
bool isprime(int x){
    if(x<=1)return false;
    int sqr=(int)sqrt(1.0*x);
    for(int i=2;i<=sqr;i++){
        if(x%i==0)return false;
    }
    return true;
}
bool hashtable[maxn]={false};
map<string,int> mp;
int main() {
    int n;
    cin>>n;
    int cnt=1;
    for(int i=0;i<n;i++){
        string seq;
        cin>>seq;
        mp[seq]=cnt++;
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        string query;
        cin>>query;
        cout<<query<<": ";
        if(mp.find(query)!=mp.end()){
            if(hashtable[mp[query]]==false){
                if(isprime(mp[query])){
                    cout<<"Minion"<<endl;
                }
                else if(mp[query]==1){
                    cout<<"Mystery Award"<<endl;
                }
                else{
                    cout<<"Chocolate"<<endl;
                }
                hashtable[mp[query]]=true;
            }
            else{
                cout<<"Checked"<<endl;
            }

        }
        else{
            cout<<"Are you kidding?"<<endl;
        }
    }
    return 0;
}
