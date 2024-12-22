#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node *head;

void Reverse_List(){
    struct node *prev=NULL;
    struct node *cur=head;
    struct node *temp=NULL;
    while(cur!=NULL){
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    head=prev;
}
void Element_Node(int number){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=number;
    new_node->next=NULL;

    if(head==NULL){
        head=new_node;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void printList(){
    if(head==NULL){
       printf("\nThe List is Empty\n");
       return;
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->value);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int n;
    int value;
    printf("Enter The Number: ");
    scanf("%d",&n);
    printf("Enter The Value: ");
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        Element_Node(value);
    }
    printList();
    Reverse_List();
    printList();
}
