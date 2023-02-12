#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

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
	tree->right = insert(tree->left,data);
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
	root = insert(root,5);
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,3);
	//root = insert(root,1);
	intrav(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
}
