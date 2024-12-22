#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode{
    int key;
    struct BinaryTreeNode *left,*right;
};
//create a new node
struct BinaryTreeNode *newNodeCreate(int value){
    struct BinaryTreeNode *temp;
    temp=(struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    temp->key=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
//search for a node in the tree
struct BinaryTreeNode *searchNode(struct BinaryTreeNode *root,int target){
    if(root==NULL||root->key==target){
        return root;
    }
    if(root->key<target){
        return searchNode(root->right,target);
    }
    else{
        return searchNode(root->left,target);
    }
}
//insert a specific value
struct BinaryTreeNode *insertNode(struct BinaryTreeNode *node,int value){
   if(node==NULL){
    return newNodeCreate(value);
   }
   if(value<node->key){
    node->left=insertNode(node->left,value);
   }
   else if(value>node->key){
    node->right=insertNode(node->right,value);
   }
   return node;
}
//inorder traversal
void inOrder(struct BinaryTreeNode *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->key);
        inOrder(root->right);
    }
}
//finding the minimum value
struct BinarytreeNode *findMin(struct BinaryTreeNode* root){
   if(root==NULL){
     return NULL;
}
else if(root->left!=NULL){
    return findMin(root->left);
}

  return root;

}
//delete function
struct BinaryTreeNode *deletion(struct BinaryTreeNode *root,int x){
   if(root==NULL){
    return NULL;
   }
   if(x>root->key){
     root->right=deletion(root->right,x);
   }
   else if(x<root->key){
    root->left=deletion(root->left,x);
   }
   else{
    if(root->left==NULL||root->right==NULL){
        struct BinaryTreeNode *temp;
        if(root->left==NULL){
            temp=root->right;
        }
        else{
            temp=root->left;
        }
        free(root);
        return temp;
    }
    else{
        struct BinaryTreeNode *temp=findMin(root->right);
        root->key=temp->key;
        root->right=deletion(root->right,temp->key);
    }
   }
   return root;
}
int main(){
    //the root node
    struct BinaryTreeNode* root=NULL;

    //inserting nodes
    root=insertNode(root,50);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,40);
    insertNode(root,70);
    insertNode(root,60);
    insertNode(root,90);
    insertNode(root,80);

   //
   if(searchNode(root,60)!=NULL){
    printf("60 found");
   }
   printf("\n");

   printf("\nSOrted using in-order traversal: \n");
   inOrder(root);

   struct BinaryTreeNode* temp=deletion(root,70);
   printf("\n\nAfter Deleting 70: \n");
   inOrder(root);

   printf("\n\n\n");

   return 0;

}
