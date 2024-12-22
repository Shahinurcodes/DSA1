#define size 5
int s[size];
int front=-1;
int rear=-1;
void enqueue(int value){
    if(rear==size-1){
        printf("\nQueue Overflow");
    }
    else if(front==-1&&rear==-1){//if queue is empty
        front=rear=0;
        s[rear]=value;
    }
    else{
        rear++;
        s[rear]=value;
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("\nQueue Underflow\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("\nThe Value is %d\n",s[front]);
        front++;
    }
}
void printList(){
    printf("The queue is: ");
    for(int i=front;i<=rear;i++){
        printf("%d ",s[i]);
    }
}
int main(){
    int value, choice;
    while(1){
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Print List\n4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        if(choice==1){

                printf("Enter The Value: ");
                scanf("%d",&value);

             enqueue(value);
        }
        else if(choice==2){
            dequeue();
        }
        else if(choice==3){
            printList();
        }
        else if(choice==4){
            printf("\nExit\n");
            break;
        }
        else{
            printf("Wrong choice.try again");
        }
    }
}
