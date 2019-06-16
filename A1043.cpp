#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=1010;
int input[maxn];
vector<int> output1,output2;
vector<int> post1,post2;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* newnode(int x){
	node* root=new node;
	root->data=x;
	root->lchild=NULL;
	root->rchild=NULL;
	return root;
}
void insert(node* &root,int x){
	if(root==NULL){
		root=newnode(x);
		return;
	}
	else if(x>=root->data){
		insert(root->rchild,x);
	}
	else if(x<root->data){
		insert(root->lchild,x);
	}
}
node* create(int n){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,input[i]);
	}
	return root;
}
void preorder(node* root){
	if(root==NULL)return;
	output1.push_back(root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void mirrorpreorder(node* root){
	if(root==NULL)return;
	output2.push_back(root->data);
	mirrorpreorder(root->rchild);
	mirrorpreorder(root->lchild);
}
void postorder(node* root){
	if(root==NULL)return;
	postorder(root->lchild);
	postorder(root->rchild);
	post1.push_back(root->data);
}
void mirrorpostorder(node* root){
	if(root==NULL)return;
	mirrorpostorder(root->rchild);
	mirrorpostorder(root->lchild);
	post2.push_back(root->data);
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	node* root=create(n);
	preorder(root);
	mirrorpreorder(root);
	bool flag1=true;
	bool flag2=true;
	for(int i=0;i<n;i++){
		if(input[i]!=output1[i]){
			flag1=false;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(input[i]!=output2[i]){
			flag2=false;
			break;
		}
	}
	if(flag1==true){
		cout<<"YES\n";
		postorder(root);
		printf("%d",post1[0]);
		for(int i=1;i<n;i++){
			printf(" %d",post1[i]);
		}
	}
	else if(flag2==true){
		cout<<"YES\n";
		mirrorpostorder(root);
		printf("%d",post2[0]);
		for(int i=1;i<n;i++){
			printf(" %d",post2[i]);
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}