#include <stdio.h>
int size=5;
int s[5];
int top=-1;
void push(int value){
    if(top==size-1){
        printf("\nStack Overflow\n");
    }
    top++;
    s[top]=value;
}
void pop(){
    int y;
    if(top==-1){
        printf("\nPrint Underflow\n");
    }
    else{
        y=s[top];
        top--;
    printf("\n The Value is %d\n",y);
    }
}
void printList(){
    printf("The Stack List is: ");
    for(int i=0;i<=top;i++){
        printf("%d ",s[i]);
    }
}
int main(){
    int value,choice;
    while(1){
    printf("\n\n1.Push\n2.Pop\n3.Print The list\n4.Exit\n");
    printf("Enter The choice: ");
    scanf("%d",&choice);
    i
    if(choice==1){
        printf("Enter The Value: ");
        scanf("%d",&value);
        push(value);
    }
    else if(choice==2){
        pop();
    }
    else if(choice==3){
        printList();
    }
    else if(choice==4){
        printf("EXIT");
        break;
    }
    else{
        printf("\nWrong Choice.Try Again\n");
    }
}

}
