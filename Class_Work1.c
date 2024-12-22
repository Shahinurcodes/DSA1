#include <stdio.h>
int main(){

    int n;
    printf("Enter The Number:");
    scanf("%d",&n);

    int arr[n];
    int flag;

    printf("Enter The Array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("\nThe elements are:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("\n\n\n");

    int choice;

    printf("1.Access an element of the array.\n");
    printf("2.Updating an element.\n");
    printf("3.Insert an element.\n");

    printf("\nEnter The choice: ");
    scanf("%d",&choice);

     if(choice==1){//linear search
            int findVal;
            flag=0;
    printf("Enter The searching element:");
    scanf("%d",&findVal);


       for(int i=0;i<n;i++) {
         if(arr[i]==findVal){
           printf("The element %d is in %d index.",findVal,i);
           flag=1;
           break;
        }
       }
       if(!flag){
        printf("Invalid element");
       }
       printf("\n");
    }
    else if(choice==2){

        int index;
        int newVal;

        printf("Enter The intended index:");
        scanf("%d",&index);

        printf("Enter The updated value:");
        scanf("%d",&newVal);

        arr[index]=newVal;

        printf("The updated array is: ");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
       }
       else if(choice==3){
        int position;
        int insertedVal;
        int len=n;

        printf("Enter The intended index:");
        scanf("%d",&position);

        printf("Enter The updated value:");
        scanf("%d",&insertedVal);

        if(position==len+1){
            arr[position]=insertedVal;
            int len=n;
        }
        else{
            for(int i=len;i<=position;i--){
                arr[i+1]=arr[i];
                len++;
            }
            arr[position]=insertedVal;

            printf("The New array is:");
            for(int i=0;i<len;i++){
                printf("%d ",arr[i]);
            }
        }
       }

    return 0;

}
