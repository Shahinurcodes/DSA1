#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node *head;
void printList(){
    if(head==NULL){
        printf("The LinkedList  is currently empty");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp=temp->next;
    }
    printf("\nEnd for now");
}
void insertHead(int Number){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
    new_node->next=NULL;
    new_node->next=head;
    head=new_node;
}
void insertTail(int Number){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value= Number;
    new_node->next=NULL;
    struct node *prev=head;
    while(prev->next!=NULL){
        prev=prev->next;
    }
    prev->next=new_node;
}
void insertAtPosition(int Number,int pos){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
    new_node->next=NULL;
    struct node *prev=head;
    for(int i=0;i<pos-1;i++){
        prev=prev->next;
    }
    new_node->next=prev->next;
    prev->next=new_node;
}
void insertAfterValue(int Number,int val){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
    new_node->next=NULL;
    struct node *prev=head;
    while(prev->value!=val){
        prev=prev->next;
    }
    new_node->next=prev->next;
    prev->next=new_node;
}
void deleteHead(){
    struct node *cur=head;
    if(head==NULL){
        return;
    }
    head=head->next;
    free(cur);
}
void deleteTail(){
    struct node *cur=head;
    struct node *prev=NULL;
    if(head==NULL){
        return;
    }
    while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }
    free(cur);
}
void deleteFromPosition(int pos){
    struct node *cur=head;
    struct node *prev=NULL;
    if(head==NULL){
        return;
    }
    for(int i=0;i<pos-1;i++){
       prev=cur;
       cur=cur->next;
    }
    if(prev!=NULL){
        prev->next=cur->next;
        free(cur);
    }
}
void deleteValue(int val){
    struct node *cur=head;
    struct node *prev=NULL;
    if(head==NULL){
        return;
    }
    while(cur->value!=val){
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL){
        prev->next=cur->next;
        free(cur);
    }
}

int main(){
    while(1){
        int pos,Number,val,choice;
        printf("\n\n1.Insert in Head.\n2.Insert in Last.\n3.Insert in a specific position.\n4.Insert after a value.\n5.Delete the head.\n6.Delete the tail.\n7.Delete from a position.\n8.Delete a specific value.\n9.Print the linkedList.\n10.Exit.");
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter the Number to insert:");
            scanf("%d",&Number);
            insertHead(Number);
        }
        else if(choice==2){
            printf("Enter the number to insert:");
            scanf("%d",&Number);
            insertTail(Number);
        }
        else if(choice==3){
            printf("Enter the number to insert:");
            scanf("%d",&Number);

            printf("Enter the position:");
            scanf("%d",&pos);

            insertAtPosition(Number,pos);
        }
        else if(choice==4){
            printf("Enter The number to insert:");
            scanf("%d",&Number);

            printf("Enter The value:");
            scanf("%d",&val);

            insertAfterValue(Number,val);
        }
        else if(choice==5){
            deleteHead();
        }
        else if(choice==6){
            deleteTail();
        }
        else if(choice==7){
            printf("Enter The Position:");
            scanf("%d",&pos);

            deleteFromPosition(pos);
        }
        else if(choice==8){
            printf("Enter The value: ");
            scanf("%d",&val);
            deleteValue(val);
        }
        else if(choice==9){
            printList();
        }
        else if(choice==10){
            printf("Exit");
            break;
        }
    }
}
