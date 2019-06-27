#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1010;
int n,L;
struct Node{
	int v;
	int layer;
};

vector<Node> adj[maxn];
bool inq[maxn]={false};

int BFS(int nowvisit,int num){
	queue<Node> q;
	Node node;
	node.v=nowvisit;
	node.layer=0;
	q.push(node);
	inq[nowvisit]=true;
	while(!q.empty()){
		Node topnode=q.front();
		q.pop();
		for(int i=0;i<adj[topnode.v].size();i++){
			int v=adj[topnode.v][i].v;
			if(inq[v]==false){
				Node nownode;
				nownode.v=v;
				nownode.layer=topnode.layer+1;
				if(nownode.layer<=L&&nownode.layer>0)num++;
				q.push(nownode);
				inq[v]=true;
			}
		}
	}
	return num;
}

int main(){
	cin>>n>>L;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		for(int j=0;j<m;j++){
			int follow;
			cin>>follow;
			Node node;
			node.v=i;
			node.layer=0;
			adj[follow].push_back(node);
		}
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		memset(inq,false,sizeof(inq));
		int que;
		cin>>que;
		int ans=BFS(que,0);
		cout<<ans<<endl;
	}
	return 0;
}
