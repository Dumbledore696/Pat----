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
    int d,n;
    cin>>d>>n;
    vector<int>v, v2;
    vector<int> temp;
    temp.push_back(d);
    v.push_back(d);
    v2.push_back(d);
    while(--n){
        int cnt=1;
        if(temp.size()==1)v.push_back(cnt);
        else{
            for(int i=0;i<temp.size();i++){
                if(i!=0)
                    v.push_back(temp[i]);
                cnt=1;
                while(temp[i+1]==temp[i]&&i<temp.size()-1){
                        cnt++;
                        i++;
                }
                v.push_back(cnt);
            }
        }

        temp=v;
        v=v2;
    }
    for(int i=0;i<temp.size();i++){
        cout<<temp[i];
    }
    return 0;
}
