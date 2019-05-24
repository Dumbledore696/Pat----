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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int ans=i/2+i/3+i/5;
        s.insert(ans);
    }
    cout<<s.size();
    return 0;
}
