#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node *head;
void elementList(int number){
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
int middle_Element(){
    struct node *fast_ptr=head;
    struct node *slow_ptr=head;
    if(head!=NULL){
        while(fast_ptr!=NULL&&fast_ptr->next!=NULL){
            fast_ptr=fast_ptr->next->next;
            slow_ptr=slow_ptr->next;
        }
        return slow_ptr->value;
    }
    return -1;
}
void print_List(){
    if(head==NULL){
        printf("\nThe List is Empty\n");
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp=temp->next;
    }
    printf("End(for now)\n");
}
int main(){
    int n,number;
    printf("Enter The Number: ");
    scanf("%d",&n);

    printf("Enter The element: ");
    for(int i=0;i<n;i++){
        scanf("%d",&number);
        elementList(number);
    }
    print_List();
   int middle= middle_Element();
   if(middle!=-1){
    printf("The middle element is: %d\n",middle);
   }
   else{
    printf("\nThe list is empty\n");
   }
   return 0;
}
