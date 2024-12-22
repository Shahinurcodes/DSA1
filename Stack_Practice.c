#include <stdio.h>
int size=5;
int s[5];
int top=-1;
void push(int value){
    if(top==size-1){
        printf("\nStack Overflow\n");
        return;
    }
    top++;
    s[top]=value;
}
void pop(){
    int y;
    if(top==-1){
        printf("\nStack Underflow\n");
        return -1;
    }
    else{
        int y=s[top];
        top--;
        printf("\nPopped the value %d",y);
    }
}
void print_stack(){
    printf("\nCurrent stack: ");
    for(int i=0;i<=top;i++){
        printf("%d ",s[i]);
    }
    printf("\n\n");
}
int main(){
    int choice,data,y;
    while(1){
        {
        printf("\n1.Push\n2.Pop\n3.Print\n0.Exit");
        printf("\n\nEnter The choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter the value to insert: ");
            scanf("%d",&data);
            push(data);
        }
        else if(choice==2){
                printf("\nPopped the value %d",y);
        }
        else if(choice==3){
            print_stack();
        }
        else if(choice==0){
            return 0;
        }
        else{
            printf("\nWrong choice,enter again!\n");
        }
    }
}
}

