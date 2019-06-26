#include<cstdio>
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,int> strToint;
map<int,string> intTostr;
map<string,int> Gang;

const int maxn=2010;
const int INF=1000000000;
int G[maxn][maxn]={0};
int weight[maxn]={0};
bool vis[maxn]={false};

int n,k,numperson=0;

int change(string str){
	if(strToint.find(str)!=strToint.end()){
		return strToint[str];
	}
	else{
		strToint[str]=numperson;
		intTostr[numperson]=str;
		return numperson++;
	}
}

void DFS(int id,int &personnum,int &totalvalue,int &head){
	personnum++;
	vis[id]=true;
	if(weight[id]>weight[head]){
		head=id;
	}
	for(int i=0;i<numperson;i++){
		if(G[id][i]>0){
			totalvalue+=G[id][i];
			G[id][i]=G[i][id]=0;
			if(vis[i]==false){
				DFS(i,personnum,totalvalue,head);
			}
		}
	}
	
}
void DFSTraverse(){
	for(int i=0;i<numperson;i++){
		int personnum=0,totalvalue=0,head=i;
		if(vis[i]==false){
			DFS(i,personnum,totalvalue,head);
            
		}
        if(personnum>2&&totalvalue>k){
			    Gang[intTostr[head]]=personnum;
		}
		
	}
	
}

int main(){
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		string str1,str2;
		int v;
		cin>>str1>>str2>>v;
		int id1=change(str1);
		int id2=change(str2);
		weight[id1]+=v;
		weight[id2]+=v;
		G[id1][id2]+=v;
		G[id2][id1]+=v;
	}
	DFSTraverse();
	cout<<Gang.size()<<endl;
	for(auto it=Gang.begin();it!=Gang.end();it++){
		cout<<it->first<<' '<<it->second<<endl;
	}
	return 0;
}