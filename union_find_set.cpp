#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int father[110];
int n,m;

void initial(){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	return;
}
int find_Father(int x){
	while(x!=father[x]){
		x=father[x];
	}
	return x;
}
void union_set(int x,int y){
	int a=find_Father(x);
	int b=find_Father(y);
	if(a!=b){
		father[a]=b;
	}
	return;
}
int main(){
	cin>>n>>m;
	initial();
	for(int i=0;i<m;i++){
		int in1,in2;
		cin>>in1>>in2;
		union_set(in1,in2);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(father[i]==i){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
	
	
}