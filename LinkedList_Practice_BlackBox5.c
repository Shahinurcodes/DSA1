#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node*head;
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
int nth_value(int val){
    struct node *count=head;
    struct node *runner=head;
    for(int i=0;i<val;i++){
        if(runner==NULL){
            printf("The List has fewer than %d nodes.\n",n);
            return -1;
        }
        runner=runner->next;
    }
    while(runner!=NULL){
        count=count->next;
        runner=runner->next;
    }
    return count->value;
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
    int n,number,val;
    printf("Enter The Number: ");
    scanf("%d",&n);

    printf("Enter The node: ");
    scanf("%d",&val);

    printf("Enter The Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&number);
        element_List(number);
    }
    print_List();
    int X=nth_value(val);
    if(X!=-1){
        printf("The %dth node is %d\n",val,X);
    }
    return 0;
}

