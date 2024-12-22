#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
struct node *insertNode(struct node *treeNode,int newVal){
   if(treeNode==NULL){
    return createNode(newVal);
   }
   if(treeNode->value<newVal){
    treeNode->right=insertNode(treeNode->right,newVal);
   }
   else{
    treeNode->left=insertNode(treeNode->left,newVal);
   }
   return treeNode;
}
struct node *searchNode(struct node *root,int target){
    if(root==NULL||root->value==target){
        return root;
    }
    if(root->value<target){
        return searchNode(root->right,target);
    }
    else{
        return searchNode(root->left,target);
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
struct node *findMin(struct node *root){
  if(root==NULL){
    return NULL;
  }
  else if(root->left!=NULL){
    return findMin(root->left);
  }
  return root;
}
struct node *findMax(struct node *root){
    if(root==NULL){
        return NULL;
    }
    else if(root->right!=NULL){
        return findMax(root->right);
    }
    return root;
}
struct node *deletion(struct node *root, int target){
    if(root==NULL){
        return NULL;
    }
    if(root->value<target){
        root->right=deletion(root->right,target);
    }
    else if(root->value>target){
        root->left=deletion(root->left,target);
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
    if(root==NULL){
        return root;
    }
    if(root->value==oldValue){
        root->value=newValue;
    }
    else if(root->value<oldValue){
        root->right=updateNode(root->right,oldValue,newValue);
    }
    else{
        root->left=updateNode(root->right,oldValue,newValue);
    }
    return root;
}
void findSecondMin(struct node *root, int *min1,int *min2){
    if(root==NULL){
        return;
    }
    if(root->value<*min1){
        *min2=*min1;
        *min1= root->value;
    }
    else if(root->value>*min1&&root->value<*min2){
        *min2=root->value;
    }
    findSecondMin(root->left,min1,min2);
    findSecondMin(root->right,min1,min2);
}
void findSecondMax(struct node *root,int *max1,int *max2){
    if(root==NULL){
        return;
    }
    if(root->value>*max1){
        *max2=*max1;
        *max1=root->value;
    }
    else if(root->value<*max1&&root->value>*max2){
        *max2=root->value;
    }
    findSecondMax(root->left,max1,max2);
    findSecondMax(root->right,max1,max2);
}
int main(){

    struct node *root=NULL;
    int n,value,choice,oldN;
    printf("Enter The Number: ");
    scanf("%d",&n);

    while(1){
    printf("\n1.insert The elements.\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Search an element\n6.Find the Minimum Number\n7.Find The Maximum Number\n8.Update The element\n9.Find The second Max\n10.Find The Second Min\n11.Delete one element\n12.exit");
    printf("\n\nEnter The choice: ");
    scanf("%d",&choice);

    if(choice==1){
        printf("Enter The element: ");
        scanf("%d",&value);

        root=insertNode(root,value);
    }

    else if(choice==2){
        printf("The inorder traversal: ");
        inOrder(root);
    }
    else if(choice==3){
        printf("The Preorder Traversal: ");
        PreOrder(root);
    }
    else if(choice==4){
        printf("The Postorder traversal: ");
        postOrder(root);
    }
    else if(choice==5){
        printf("Enter The Value to search: ");
        scanf("%d",&value);
        struct node *found=searchNode(root,value);
        if(found){
            printf("Element %d found.\n",value);
        }
        else{
            printf("Element %d not found.\n",value);
        }
    }

    else if(choice==6){
        struct node *minNode=findMin(root);
        if(minNode){
            printf("Minimum element is: %d\n",minNode->value);
        }
        else{
            printf("The tree is Empty\n");
        }
    }

    else if(choice==7){
        struct node *maxNode=findMax(root);
        if(maxNode){
            printf("Maximum element is: %d\n",maxNode->value);
        }
        else{
            printf("The tree is Empty\n");
        }
    }
    else if(choice==8){
       printf("Enter The Old value: ");
       scanf("%d",&oldN);

       printf("Enter The New Value: ");
       scanf("%d",&value);

       root=updateNode(root,oldN,value);

       printf("Value Updated\n");
    }
    else if(choice==9){
        int max1=INT_MIN;
        int max2=INT_MIN;
        findSecondMax(root,&max1,&max2);

        if(max2==INT_MIN){
            printf("There is no second maximum.\n");
        }
        else{
            printf("Second maximum element is: %d\n",max2);
        }
    }

    else if(choice==10){
        int min1=INT_MAX;
        int min2=INT_MAX;
        findSecondMin(root,&min1,&min2);

        if(min2==INT_MIN){
            printf("There is no second minimum.\n");
        }
        else{
            printf("Second minimum element is: %d\n",min2);
        }
    }
    else if(choice==11){
        printf("Enter The value to Delete: ");
        scanf("%d", &value);

        root=deletion(root,value);
    }
    else if(choice==12){
        printf("EXIT\n");
        break;
    }
    else{
        printf("Wrong choice. TRY AGAIN.");
    }
}
  return 0;

}

