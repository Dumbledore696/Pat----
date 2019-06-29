#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=600;
const int INF=1000000000;

int n,m;

bool vis[maxn]={false};
int d[maxn];
int G[maxn][maxn]={0};
int weight[maxn]={0};
int num[maxn]={0};
int w[maxn]={0};

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int v=0;v<n;v++){
		int u=-1,min1=INF;
		for(int j=0;j<n;j++){
			if(d[j]<min1&&vis[j]==false){
				u=j;
				min1=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int i=0;i<n;i++){
			if(vis[i]==false&&G[u][i]!=INF){
				if(d[u]+G[u][i]<d[i]){
					d[i]=d[u]+G[u][i];
					num[i]=num[u];
					w[i]=w[u]+weight[i];
				}
				else if(d[u]+G[u][i]==d[i]){
					if(w[u]+weight[i]>w[i]){
						w[i]=w[u]+weight[i];
					}
					num[i]+=num[u];
				}
				
			}
		}
	}
}

int main(){
	int s,t;
	cin>>n>>m>>s>>t;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	for(int i=0;i<m;i++){
		int id1,id2,value;
		cin>>id1>>id2>>value;
		G[id1][id2]=value;
		G[id2][id1]=value;
	}
	Dijkstra(s);
	cout<<num[t]<<' '<<w[t]<<endl;
	return 0;
}

