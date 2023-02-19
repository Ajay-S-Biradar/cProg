#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

int height(node* node){
	if(node==NULL){
		return 0;
	}
	int ans;
	int left = height(node->left);
	int right = height(node->left);
	
	if(left>right){
		ans = left+1;
	}
	else ans = right+1;
	return ans;
}

int countleafnode(node* root,int& count){
	if(root==NULL)
	return 0;
	
	countleafnode(root->left,count);
	if(root->left==NULL && root->right==NULL)
	count++;
	countleafnode(root->right,count);
	return count;
}

node* maketree(int x){
	node *p = (node*)malloc(sizeof(node));
	p->data= x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

node* insert(node* tree,int data){
	if(tree==NULL)
	return maketree(data);
	if(data<tree->data)
	tree->left = insert(tree->left,data);
	else
	tree->right = insert(tree->right,data);
	return tree;
}
void intrav(node* tree){
	if(tree!=NULL){
	intrav(tree->left);
	printf("%d  ",tree->data);
	intrav(tree->right);
	//printf("%d",tree->data);
	}
}
void preorder(node*tree ){
	if(tree!=NULL){
		printf("%d  ",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void postorder(node* tree){
	if(tree!=NULL){
		postorder(tree->left);
		postorder(tree->right);
		printf("%d  ",tree->data);
	}
}

int main(){
	node* root= NULL;
	root = insert(root,10);
	root = insert(root,11);
	root = insert(root,8);
	root = insert(root,9);
	root = insert(root,12);
	root = insert(root,3);
	intrav(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	
	int H = height(root);
	
	printf("\n%d\n",H);
	int cnt = countleafnode(root,cnt);
	printf("%d\n",cnt);
}
