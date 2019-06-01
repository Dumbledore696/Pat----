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
set<int> s;
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int item;
        cin>>item;
        s.insert(item);
    }
    int stunum=0,itemnum=0;
    for(int i=0;i<n;i++){
        string name;
        vector<int> item;
        cin>>name;
        int num;
        cin>>num;
        bool flag=false;
        item.clear();
        for(int j=0;j<num;j++){
            int item1;
            cin>>item1;
            if(s.find(item1)!=s.end()){
                flag=true;
                item.push_back(item1);
                itemnum++;
            }
        }
        if(flag==true){
            stunum++;
            cout<<name<<": ";
            for(int i=0;i<item.size();i++){
                printf("%04d",item[i]);
                if(i<item.size()-1)printf(" ");
                else printf("\n");
            }
        }
    }
    cout<<stunum<<" "<<itemnum<<endl;

    return 0;
}
