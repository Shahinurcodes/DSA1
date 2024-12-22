#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node *dummy_head;
void printlist(){
    if(dummy_head->next==NULL){
        printf("\nThe Linked list is Empty\n");
        return;
    }
    struct node *temp=dummy_head->next;
    while(temp!=NULL){
        printf("%d-> ",temp->value);
        temp=temp->next;
    }
    printf("End (for now)");
}
void InsertAfterValue(int number,int val){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=number;
    new_node->next=NULL;
    struct node *temp=dummy_head;
    while(temp->next!=NULL&&temp->next->value!=val){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}
void deletion(int Number){
    struct node *cur=dummy_head;
    struct node *prev=NULL;
    if(dummy_head==NULL){
        printf("\nThe Linked List is empty\n");
        return;
    }
    while(cur->value!=Number){
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL){
        printf("\nValue Not Found\n");
    }
    if(prev!=NULL){
        prev->next=cur->next;
        free(cur);
    }
}
int main(){
    dummy_head=(struct node *)malloc(sizeof(struct node));
    dummy_head->next=NULL;
    dummy_head->value=-1;
    while(1){
            int number,choice,val;
        printf("\n\n1.Insert After Value\n2.Delete\n3.PrintList\n4.Exit");
        printf("\nEnter The choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter The Number: ");
            scanf("%d",&number);
            printf("Enter The Value: ");
            scanf("%d",&val);

            InsertAfterValue(number,val);
        }
        else if(choice==2){
            printf("Enter The Number: ");
            scanf("%d",&number);

            deletion(number);
        }
        else if(choice==3){
            printlist();
        }
        else if(choice==4){
            printf("Exit");
            break;
        }
        else {
            printf("Wrong Choice.Try Again\n");
        }
    }
    return 0;
}
