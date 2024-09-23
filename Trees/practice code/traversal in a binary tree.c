#include<stdio.h>
#include<malloc.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data){

struct Node *n;
n=(struct Node*)malloc(sizeof(struct Node));

n->data=data;
n->left=NULL;
n->right=NULL;
return n;
}


struct Node* preOrder(struct Node *root){
if(root!=NULL){

    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

}



struct Node* postOrder(struct Node *root){
if(root!=NULL){

    
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

}

struct Node* inOrder(struct Node *root){
if(root!=NULL){

    
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

}
int main(){

struct Node*p=createNode(10);
struct Node*p1=createNode(20);
struct Node*p2=createNode(30);
struct Node*p3=createNode(40);
struct Node*p4=createNode(50);
struct Node*p5=createNode(60);

p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
p2->left=p5;

printf("Traversal in pre order: \n");
preOrder(p);

printf("\n");

printf("Traversal in post order: \n");
postOrder(p);

printf("\n");

printf("Traversal in in order: \n");
inOrder(p);

    return 0;
}