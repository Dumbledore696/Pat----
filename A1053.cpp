#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=110;
int n,m,k;
vector<int> single,ans[maxn];
struct node{
	int data;
	vector<int> child;
}Node[maxn];
bool cmp(int a,int b){
	return Node[a].data>Node[b].data;
}
int cnt=0;
void DFS(int root,int sum){
	if(sum>k)return;
	if(sum==k){
		if(Node[root].child.size()!=0){
			
			return;
		}
		ans[cnt++]=single;
		return;
	}
	for(int i=0;i<Node[root].child.size();i++){
		int child=Node[root].child[i];
		single.push_back(Node[child].data);
		DFS(child,sum+Node[child].data);
		single.pop_back();
	}
}
int main(){
	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>Node[i].data;
	}	
	for(int i=0;i<m;i++){
		int id,temp;
		cin>>id>>temp;
		for(int j=0;j<temp;j++){
			int temp2;
			cin>>temp2;
			Node[id].child.push_back(temp2);
		}
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);
	}
	single.push_back(Node[0].data);
	DFS(0,Node[0].data);
	for(int i=0;i<cnt;i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j];
			if(j<ans[i].size()-1)cout<<' ';
			else cout<<"\n";
		}
	}
	return 0;
}