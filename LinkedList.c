#include <stdio.h>
#include <stdlib.h>
//define the structure for a linked list node
struct node{
    int value;
    struct node *next;
};

struct node *head;
//Function to print the linked list
void printList(){
    if(head==NULL){
        printf("The array is currently empty.");
        return;
    }
    struct node *temp=head;
    //Traversing the list
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp=temp->next;
    }
    printf("End(for now)");
}
void insertHead(int Number){
    //create a new node
    struct node *new_code;
    new_code= (struct node *)malloc(sizeof (struct node));
    new_code->value=Number;
    new_code->next=NULL;
    //insert the new node at the head
    new_code->next=head;
    head=new_code;
}
void insertTail(int Number){
    //create a new node to be inserted
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof (struct node));
    newItem-> value=Number;
    newItem->next=NULL;
    //set prev to point to the last node of the list
    struct node *prev=head;
    //prev will go from first to last until it gets NULL
    while(prev->next!=NULL){
        prev=prev->next;
    }
    //inserting in the last node
     prev->next=newItem;
}

void instertAtPosition(int Number,int pos){
    //creating a new node
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof(struct node));
    newItem->value=Number;
    newItem->next=NULL;

    struct node *prev=head;
    //moving through prev
    for(int i=0;i<pos-1;i++){
        prev=prev->next;
    }
    //inserting in the position
    newItem->next=prev->next;
    prev->next=newItem;
}
void insertAfterValue(int Number,int val){
    //creating a new node
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof(struct node));
    newItem->value=Number;
    newItem->next=NULL;

    struct node *prev=head;
    //moving through prev
    while(prev->value!=val){
        prev=prev->next;
    }
    //inserting after a value
    newItem->next=prev->next;
    prev->next=newItem;
}
void DeleteHead(){
    struct node *cur;//it will store head pointer before it's deleted
    if(head==NULL){//no list at all
        return;
    }
    cur=head;//current head in the cur pointer
    head=head->next;//head is now the second node
    free(cur);//deleting previous head
}
void DeleteTail(){
    if(head==NULL){
        return;
    }
    struct node *cur=head;//pointer for traversing till last node
    struct node *prev=NULL;//pointer for making previous node's next as NULL
    while(cur->next!=NULL){
        prev=cur;//traversing prev
        cur=cur->next;//traversing cur
    }
    if(prev!=NULL){//updating previous node
        prev->next=NULL;
    }
    free(cur);//deleting the last node
}
void DeleteFromPosition(int pos){
    if(head==NULL){
        return;
    }
    struct node *cur=head;//pointer from traversing till desire node
    struct node *prev=NULL;//pointer to remember the previous node

    for(int i=0;i<pos-1;i++){
        prev=cur;//traversing prev;
        cur=cur->next;//traversing cur
    }
    if(prev!=NULL){
        prev->next=cur->next;//connecting with prev node with the node after the deleting node
        free(cur);//deleting the desire node
    }
}
void deleteVal(int val){
    if(head==NULL){
        return;
    }
    struct node *cur=head;
    struct node *prev=NULL;
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
    int ch,Number,pos,val;
    printf("\n\n1.Insert first\n2.Insert Last\n3.Insert Middle-Any position\n4.Insert Middle-After any value\n5.Delete Head\n6.Delete Last\n7.Delete-Specific Position\n8.Delete-Given Value\n9.Print the LinkedList\n10.Exit\n\nEnter A Choice: ");
    scanf("%d",&ch);

    if(ch==1){
        printf("Enter The Number to Insert: ");
        scanf("%d",&Number);
        insertHead(Number);
    }
    else if(ch==2){
        printf("Enter The Number to Insert: ");
        scanf("%d",&Number);
        insertTail(Number);
    }
    else if(ch==3){
        printf("Enter The Position: ");
        scanf("%d",&pos);

        printf("\nEnter the Number to insert: ");
        scanf("%d",&Number);

        insertAtPosition(Number,pos);
    }
    else if(ch==4){
        printf("Enter Value to insert after: ");
        scanf("%d",&val);

        printf("Enter The Number to Insert: ");
        scanf("%d",&Number);

        insertAfterValue(Number,val);
    }
    else if(ch==5){
        DeleteHead();
    }
    else if(ch==6){
        DeleteTail();
    }
    else if(ch==7){
        printf("\nEnter Position to Delete from: ");
        scanf("%d",&pos);
        DeleteFromPosition(pos);
    }
    else if(ch==8){
        printf("\nEnter Value to delete: ");
        scanf("%d",&val);
        deleteVal(val);
    }
    else if(ch==9){
        printList();
    }
    else if(ch==10){
        printf("Exit");
        break;
    }
  }
  return 0;
}
