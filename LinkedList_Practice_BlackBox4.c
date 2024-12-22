#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node *head;
void element_List(int Number){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
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
void remove_Duplicate(){
    struct node *current=head;
    while(current!=NULL&&current->next!=NULL){
        struct node *runner=current;
        while(runner->next!=NULL){
            if(current->value==runner->next->value){
                struct node *temp=runner->next;
                runner->next=runner->next->next;
                free(temp);
            }
            else{
                runner=runner->next;
            }
        }
        current=current->next;
    }
}
void print_List(){
    struct node *temp=head;
    if(head==NULL){
        printf("The List is empty\n");
    }
    while(temp!=NULL){
        printf("%d-> ",temp->value);
        temp=temp->next;
    }
    printf("End(for now)\n");
}
int main(){
    int n,number;
    printf("Enter The Number: ");
    scanf("%d",&n);

    printf("Enter The Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&number);
        element_List(number);
    }
    print_List();
    remove_Duplicate();
    print_List();
}
