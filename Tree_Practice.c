#include <stdio.h>
#include <stdlib.h>
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
    struct node *searchVal=searchNode(root,oldValue);

    root=deletion(root,oldValue);
    root=deletion(root,newValue);
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
struct node *findSecondMax(struct node *root){
    struct node *prev;
    if(root==NULL){
        return root;
    }
    while(root->right!=NULL){
        prev=root;
        root=root->right;
    }
    if(root->left!=NULL){
        prev=findMax(root->left);
    }
    return prev;
}
int main(){

    struct node *root=NULL;
    int value,choice,oldN;

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

       if(searchNode(root,oldN)){
        root=updateNode(root,oldN,value);
        printf("Value updated");
       }
       else{
        printf("Element not found");
       }
    }
    else if(choice==9){
            struct node *min2= findSecondMin(root);

           if(min2){
            printf("The Second Min is %d\n",min2->value);
           }
           else{
            printf("The tree is empty\n");
           }
        }

    else if(choice==10){
        struct node *max2= findSecondMax(root);
        if(max2){
            printf("The Second Max is %d\n",max2->value);
           }
           else{
            printf("The tree is empty\n");
           }
    }
    else if(choice==11){
        printf("Enter The value to Delete: ");
        scanf("%d", &value);
        if(searchNode(root,value)){

            root=deletion(root,value);
            printf("Element deleted");
        }
        else{
            printf("the element doesn't exist");
        }
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

