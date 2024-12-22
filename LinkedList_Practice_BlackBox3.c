//Error

#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node *next;
};
struct node *head=NULL;
void Element_List(int number){
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
void print_List(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp=temp->next;
    }
    printf("End(for now)\n");
}
void create_cycle(){
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
}
int hasCycle(){
    struct node *fast=head;
    struct node *slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n,number;
    printf("Enter The Number: ");
    scanf("%d",&n);
    printf("Enter The elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&number);
        Element_List(number);
    }
    print_List();
    create_cycle();
    if(hasCycle()){
        printf("Yes");
    }
    else{
        printf("\nNo\n");
    }

    return 0;
}
