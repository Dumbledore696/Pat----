#include<cstdio>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int n=5;

typedef struct BTNode{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

void insert(BTNode *&root,int x){
	if(root==NULL){
		root=new BTNode;
		root->data=x;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(root->data>x){
		insert(root->lchild,x);
	}
	else if(root->data<x){
		insert(root->rchild,x);
	}
}
BTNode *createTree(int A[]){
	BTNode *root=NULL;
	for(int i=0;i<n;i++){
		insert(root,A[i]);
	}
	return root;
}
void countdouble(BTNode *bt,int &num){
	if(bt==NULL)return;
	if(bt->lchild!=NULL&&bt->rchild!=NULL){
		num++;
	}
	countdouble(bt->lchild,num);
	countdouble(bt->rchild,num);
}
void FindK(BTNode *bt,int k){
	if(bt==NULL)return;
	if(num==k)cout<<bt->data<<endl;
	FindK(bt->lchild);
	FindK(bt->rchild);
}
void postordernorecursion(BTNode *bt){
	stack<BTNode *>s;
	BTNode *r=NULL;
	BTNode *p=bt;
	while(!s.empty()||p){
		while(p){
			s.push(p);
			p=p->lchild;
		}
		p=s.top();
		if(p->rchild!=NULL&&p->rchild!=r){
			p=p->rchild;
			s.push(p);
			p=p->lchild;
		}
		else{
			p=s.top();
			s.pop();
			cout<<p->data<<" ";
			r=p;
			p=NULL;
		}
	}
}

void printancestorpath(BTNode *bt,int k){//在出栈时判断是否为k，只要写一次判断，
                                         //但要先将自己出栈才能打印路径
										 //在入栈时判断要写两次判断
	stack<BTNode *>s;
	BTNode *r=NULL;
	BTNode *p=bt;
	while(!s.empty()||p){
		while(p){
			s.push(p);
			p=p->lchild;
		}
		p=s.top();
		if(p->rchild!=NULL&&p->rchild!=r){
			p=p->rchild;
			s.push(p);
			p=p->lchild;
		}
		else{
			p=s.top();
			if(p&&p->data==k){
				while(!s.empty()){
					s.pop();
					if(!s.empty()){
						p=s.top();
						cout<<p->data<<' ';
					}
				}
				return;
			}
			s.pop();
			//cout<<p->data<<" ";
			r=p;
			p=NULL;
		}
	}
}

void nearestcommonancestor(BTNode *bt,int k,int q){//在出栈时判断是否为p或k，这样k一定在q前面，而入栈时不一定
	BTNode* s[10];
	BTNode* s1[10];
	int top=-1;
	int top1=-1;
	BTNode *r=NULL;
	BTNode *p=bt;
	while(p||top>-1){
		while(p){
			s[++top]=p;
			p=p->lchild;
		}
		p=s[top];
		if(p->rchild!=NULL&&p->rchild!=r){
			p=p->rchild;
			s[++top]=p;
			p=p->lchild;
		}
		else{
			p=s[top];
			if(p&&p->data==k){
				for(int i=0;i<=top;i++){
					s1[i]=s[i];
					top1=top;
				}
			}
			else if(p&&p->data==q){
				for(int i=top-1;i>=0;i--){
					for(int j=top1-1;j>=0;j--){
						if(s[i]->data==s1[i]->data){
							cout<<s[i]->data;
							return;
						}
					}
				}
			}
			top--;
			//cout<<p->data<<" ";
			r=p;
			p=NULL;
		}
	}
}
int main(){
	int A[5]={3,1,4,2,5};
	BTNode *root=createTree(A);
	nearestcommonancestor()
	return 0;
}