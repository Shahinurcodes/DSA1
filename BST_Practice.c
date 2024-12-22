#include <stdio.h>
#include <stdilb.h>
struct node{
    int value;
    struct node *left,*right;
};
struct node *createNode(int number){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->value=number;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct node *insertion(struct node *root,int number){
    if(root==NULL){
        return createNode(number);
    }
    if(root->value<number){
        root->right=insertion(root->right,number);
    }
    else{
        root->left=insertion(root->left,number);
    }
    return root;
}
struct node *searchNode(struct node *root,int number){
    if(root=NULL||root->value==number){
        return root;
    }
    if(root->value<number){
        return searchNode(root->right,number);
    }
    else{
        return searchNode(root->left,number);
    }

}
void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->value);
        inOrder(root->right);
    }
}
void PreOrder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->value);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void postOrder(struct node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->value);
    }
}
void node *findMin(struct node *root){
    if(root==NULL){
        return NULL;
    }
    else if(root->left!=NULL){
        return findMin(root->left);
    }
    return root;
}
void node *findmax(struct node *root){
    if(root==NULL){
        return NULL;
    }
    else if(root->right!=NULL){
        return findmax(root->right);
    }
    return root;
}
struct node *deletion(struct node *root,int number){
    if(root==NULL){
        return NULL;
    }
    if(root->value<number){
        root->right=deletion(root->right,number);
    }
    else if(root->value>number){
        root->left=deletion(root->left,number);
    }
    else{
        if(root->left==NULL||root->right==NULL){
            struct node *temp;
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
            struct node *temp=findMin(root->right);
            root->value=temp->value;
            root->right=deletion(root->right,temp->value);
        }
    }
    return root;
}
struct node *updateNode(struct node *root,int oldValue,int newValue){
    struct node *searchVal=searchNode(root,oldValue);
    root=deletion(root,oldValue);
    root=insertion(root,newValue);
    return root;
}
struct node *findSecondMin(struct node *root){
    struct node *prev;
    if(root==NULL){
        return root;
    }
    while(root->left!=NULL){
        prev=root;
        root=root->left;
    }
    if(root->right!=NULL){
        prev=findMin(root->right);
    }
    return prev;
}


