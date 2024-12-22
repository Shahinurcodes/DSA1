#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
    struct node *prev;
};

struct node *head,*last;

void ftraversal(){

      if(head==NULL){
        printf("\nThe Linked List is Empty\n");
        return;
        }

        struct node *temp=head;
        while(temp!=NULL){
            printf("%d->",temp->value);
            temp=temp->next;
        }
        printf("End(for now)");
    }

void btraversal(){

    struct node *temp=last;
    if(last==NULL){
        printf("\nThe Linked List is empty\n\n");
    }
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp=temp->prev;
    }
    printf("End(for now)");
}

void insertHead(int Number){

    struct node *new_node;
    new_node=(struct node *)malloc(sizeof (struct node));
    new_node->value=Number;
    new_node->next=NULL;
    new_node->prev=NULL;

    if(head==NULL){
        head=new_node;
        head->prev=NULL;
        head->next=NULL;
        last=head;
    }

    else{
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
    }
}
void insertTail(int Number){

    struct node *new_node;
    new_node= (struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
    new_node->next=NULL;
    new_node->prev=NULL;

    if(head==NULL){
        head=new_node;
        head->prev=NULL;
        head->next=NULL;
        last=head;
    }

    else{
        new_node->prev=last;
        last->next=new_node;
        last=new_node;
    }
}
void insertAtPosition(int Number,int position){

    struct node *new_node;
    new_node=(struct node *)malloc(sizeof (struct node));
    new_node->value=Number;
    new_node->next=NULL;
    new_node->prev=NULL;

    if(position==0){
        insertHead(Number);
        return;
    }
    if(position<0){
        printf("Invalid position\n");
        return;
    }
    struct node *temp=head;
    for(int i=0;i<position-1;i++){
            if(temp->next==NULL){
                printf("Position is greater than the nodes\n");
                return;
            }
        temp=temp->next;
    }
    new_node->next=temp->next;
    new_node->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=new_node;
    }
    else{
        last=new_node;
    }
     temp->next=new_node;
}
void insertAfterValue(int Number,int Value){

    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
    new_node->next=NULL;
    new_node->prev=NULL;

    struct node *temp=head;
    while(temp!=NULL){
        if(temp->value==Value){
            new_node->next=temp->next;
            new_node->prev=temp;
            if(temp->next!=NULL){
                temp->next->prev=new_node;
            }
            else{
                last=new_node;
            }
            temp->next=new_node;
            return;
        }
        temp=temp->next;
    }
     printf("Value not found\n");
}
void Deletion(int Number){

    struct node *temp=head;
    while(temp!=NULL){
        if(temp->value==Number){
            if(temp->prev!=NULL){
                temp->prev->next=temp->next;
            }
            else{
                head=temp->next;
                if(head!=NULL){
                    head->prev=NULL;
                }
            }
            if(temp->next!=NULL){
                temp->next->prev=temp->prev;
            }
            else{
                last=temp->prev;
                if(last!=NULL){
                    last->next=NULL;
                }
            }
            free(temp);
            return;
        }
        temp=temp->next;
    }

    printf("Value Not Found\n");
}

void Search(int Number){

    int count=0;
    struct node *temp=head;

    if(head==NULL){
        printf("The Linked List is empty");
    }
    while(temp!=NULL&&temp->value!=Number){
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        printf("\nThe Number doesn't exist in the list");
    }
    else{
        printf("\nThe Number is at %d index.",count);
    }
    return;
}

void length(){
    int count=0;
    struct node *temp=head;

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("The length of the list is %d\n",count);
}
int main(){

    while(1){
        int choice,Number,position,value,n;

        printf("\n1.FTraversal\n2.BTraversal\n3.Insert First\n4.Insert Last\n5.Insert After a value\n6.Insert at a middle position\n7.Delete\n8.Search\n9.My custom function(length)\n10.EXIT");
        printf("\n\nEnter a choice: ");
        scanf("%d",&choice);

        if(choice==1){

               ftraversal();

        }

        else if(choice==2){

                btraversal();
        }

        else if(choice==3){

         printf("Enter The Number: ");
        scanf("%d",&Number);

            insertHead(Number);
        }

        else if(choice==4){

        printf("Enter The Number: ");
        scanf("%d",&Number);

        insertTail(Number);
        }

        else if(choice==5){

        printf("Enter The Number: ");
        scanf("%d",&Number);

        printf("Enter The Value: ");
        scanf("%d",&value);

        insertAfterValue(Number,value);

        }

        else if(choice==6){

        printf("Enter The Number: ");
        scanf("%d",&Number);

        printf("Enter The Position: ");
        scanf("%d",&position);

        insertAtPosition(Number,position);

        }

        else if(choice==7){

        printf("Enter The Number: ");
        scanf("%d",&Number);

        Deletion(Number);

        }

        else if(choice==8){

        printf("Enter The Number: ");
        scanf("%d",&Number);

            Search(Number);
        }

        else if(choice==9){
            length();
        }

        else if(choice==10){

            printf("\nExit\n");
            break;
        }

        else{

            printf("Wrong choice. Try again\n");
        }
    }
}
