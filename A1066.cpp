#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int input[30];
int n;
struct node{
	int data,height;
	node* lchild;
	node* rchild;
};
node* newnode(int x){
	node* root=new node;
	root->data=x;
	root->height=0;
	root->lchild=NULL;
	root->rchild=NULL;
	return root;
}
int getheight(node* Node){
	if(Node==NULL)return 0;
	else{
		return Node->height;
	}
}
int getbalancefactor(node* Node){
	return getheight(Node->lchild)-getheight(Node->rchild);
}
void updateheight(node* Node){
	Node->height=max(getheight(Node->lchild),getheight(Node->rchild))+1;
}
void Rrotate(node*& root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateheight(root);
	updateheight(temp);
	root=temp;
}
void Lrotate(node*& root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateheight(root);
	updateheight(temp);
	root=temp;
}
void insert(node*& root,int x){
	if(root==NULL){
		root=newnode(x);
		return;
	}
	if(x<root->data){
		insert(root->lchild,x);
		updateheight(root);
		if(getbalancefactor(root)==2){
			if(getbalancefactor(root->lchild)==1){
				Rrotate(root);
			}
			else{
				Lrotate(root->lchild);
				Rrotate(root);
			}
		}
	}
	else{
		insert(root->rchild,x);
		updateheight(root);
		if(getbalancefactor(root)==-2){
			if(getbalancefactor(root->rchild)==-1){
				Lrotate(root);
			}
			else{
				Rrotate(root->rchild);
				Lrotate(root);
			}
		}
	}
}

node* create(){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,input[i]);
	}
	return root;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	node* root=create();
	printf("%d",root->data);
	return 0;
}