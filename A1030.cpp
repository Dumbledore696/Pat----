#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=600;
const int INF=1000000000;
vector<int> pre[maxn];
vector<int> path,temppath;
int optvalue=INF;
int cost[maxn][maxn]={0};
int d[maxn];
int G[maxn][maxn];
bool vis[maxn]={false};
int n,m,s,t;
void Dijkstra(){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(d[j]<MIN&&vis[j]==false){
				MIN=d[j];
				u=j;
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[v]>d[u]+G[u][v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[v]==d[u]+G[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	if(v==s){
		temppath.push_back(v);
		int value=0;
		for(int i=temppath.size()-1; i>0;i--){
			int id=temppath[i],idnext=temppath[i-1];
			value+=cost[id][idnext];
		}
		if(value<optvalue){
			optvalue=value;
			path=temppath;
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	temppath.pop_back();
}

int main(){
	cin>>n>>m>>s>>t;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		int id1,id2,value,c;
		cin>>id1>>id2>>value>>c;
		G[id1][id2]=value;
		G[id2][id1]=value;
		cost[id1][id2]=c;
		cost[id2][id1]=c;
	}
	Dijkstra();
	DFS(t);
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i]<<' ';
	}
	cout<<d[t]<<' '<<optvalue<<endl;
	return 0;
}