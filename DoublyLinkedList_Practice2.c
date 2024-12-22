#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
    struct node *prev;
};
struct node *head,*last;
void ftraversal(){
    struct node *temp=head;

    if(head==NULL){
        printf("\nThe Linked List is Empty\n");
    }
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp=temp->next;
    }
    printf("End(for now)");
}
void btraversal(){
    struct node *temp=last;
    if(head=NULL){
        printf("\nThe Linked List is Empty\n");
    }
    while(temp!=NULL){
        printf("%d->",temp->value);
        temp=temp->next;
    }
    printf("End(for now)");
}
void insertHead(int Number){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
    new_node->next=NULL;
    new_node->prev=NULL;

    if(head==NULL){
        head=new_node;
        new_node->next=NULL;
        new_node->prev=NULL;
        last=new_node;
    }
    else{
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
    }
}
void insertTail(int Number){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
    new_node->next=NULL;
    new_node->prev=NULL;

    if(head==NULL){
        head=new_node;
        new_node->next=NULL;
        new_node->prev=NULL;
        last=new_node;
    }
    else{
        new_node->prev=last;
        last->next=new_node;
        last=new_node;
    }
}
void insertAtPosition(int Number,int position){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
    new_node->next=NULL;
    new_node->prev=NULL;

    if(position==0){
        insertHead(Number);
    }
    if(position<0){
        printf("\nWrong Position.Try Again\n");
    }
    struct node *temp=head;
    for(int i=0;i<position-1;i++){
        if(temp->next==NULL){
            printf("\nWrong Position\n");
        }
        temp->next=temp;
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
void insertAfterValue(int Number,int value){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->value=Number;
    new_node->next=NULL;
    new_node->prev=NULL;

    struct node *temp;
    while(temp!=NULL){
        if(temp->value==value){
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
    printf("\nThe value doesn't exist\n");
}
void deletion(int Number){
    struct node *temp;
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
                if(temp->next!=NULL){
                    temp->next->next=temp->prev;
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
    }
    printf("\nThe Number is invalid\n");
}
void search(int Number){
    struct node *temp;
    int count=0;
    if(head==NULL){
        printf("The Linked List is empty");
    }
    while(temp!=NULL&&temp->value!=Number){
         count++;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("The Number is not found in the linkedlist");
    }
    else{
        printf("The Number is in the %d index.",count);
    }
}
void length(){
    int count=0;
    struct node *temp;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("The length is %d",count);
}
void Middle_Element(int Number){
    if(head==NULL){
        printf("\nThe Linked List is empty");
        return;
    }
    struct node *temp=head;
    double median;
    if(Number==1){
        printf("\nMedian=%d\n",temp->value);
        return;
    }
    for(int i=0;i<(n-1)/2;i++){
        temp=temp->next;
    }
    if(n%2!=0){
        median=temp->value;
    }
    else{
        median=(temp->value+temp->next->value)/2.0;
    }
    printf("\nMedian= %lf\n",median);
    return;
}
int main(){
    while(1){
        int Number,value,position,choice;
        printf("\n\n1.Ftraversal\n2.btraversal\n3.Insert Head\n4.Insert Tail\n5.Insert At Position\n6.Insert After A value\n7.Delete\n8.Search\n9.Length\n10.Exit");
        printf("\nEnter The choice: ");
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

            printf("Enter The Position: ");
            scanf("%d",&position);

            insertAtPosition(Number,position);
        }
        else if(choice==6){
            printf("Enter The Number: ");
            scanf("%d",&Number);

            printf("Enter The Value: ");
            scanf("%d",&value);

            insertAfterValue(Number,value);
        }
        else if(choice==7){
            printf("Enter The Number");
            scanf("%d",&Number);
            deletion(Number);
        }
        else if(choice==8){
            printf("Enter The Number");
            scanf("%d",&number);
            search();
        }
        else if(choice==9){
            length();
        }
        else if(choice==10){
            printf("Exit");
            break;
        }
    }
}
