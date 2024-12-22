#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *left,*right;
};
struct node *createNode(int number){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=number;
    new_node->left=NULL;
    new_node->right=NULL;
};
struct node *insertNode(struct node *root,int newVal){
    if(root==NULL){
        return root;
    }
    if(root->value<newVal){
        return insertNode(root->right,newVal);
    }
    else{
        return insertNode(root->left,newVal);
    }
}
struct node *height(struct node *root){
    if(root==NULL){
        return root;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);

    if(leftheight>rightheight){
        return leftheight;
    }
    else{
        return rightheight;
    }
}
struct node *balanceTree(struct node *root){
    int leftside,rightside;
    if(root==NULL){
        return 1;
    }
    leftside=height(root->left);
    rightside=height(root->right);

    if(abs(leftside-rightside)<=1&&balanceTree(root->left)&&balanceTree(root->right)){
        return 1;
    }
    return 0;
}
struct node *sumofNodes(struct node *root){
    if(root==NULL){
        return 0;
    }
  int leftSum=sumofNodes(root->left);
  int rightSum=sumofNodes(root->right);

  int total=root->value+leftSum+rightSum;
  return total;
}

int main(){
    struct node *root;
    int value;
    return 0;
}
