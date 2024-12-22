#include <stdio.h>
void ArrayList(int n,int arr[]){

    printf("The Array List is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void IndexValue(int n,int arr[]){

    int index;

    printf("Enter The specific index: ");
    scanf("%d",&index);

    if(index<0||index>n){
            printf("\nInvalid input.\n");
          }
          else{
            printf("The Value in %d index is: %d\n",index,arr[index]);
          }
}
void UpdateElement(int n,int arr[]){

    int updateVal,index;

    printf("Enter The Value's Index: ");
    scanf("%d",&index);

    if(index<0||index>=n){
        printf("Invalid Input");
    }
    else{

    printf("Enter The Updated value: ");
    scanf("%d",&updateVal);

        arr[index]=updateVal;

        printf("The Updated Array List is: ");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
void LinearSearch(int n,int arr[]){

    int value,flag=0;

    printf("Enter The desired Value: ");
    scanf("%d",&value);

    for(int i=0;i<n;i++){
        if(arr[i]==value){
            printf("The Value is at index %d.\n",i);
            flag=1;
            break;
        }
    }

    if(!flag){
        printf("Invalid input");
    }
}
void InsertAnElement(int n,int arr[]){

    int index,new_Val;

    printf("Enter The index: ");
    scanf("%d",&index);

        if(index==0){
        printf("Enter The Value: ");
        scanf("%d",&new_Val);

        for(int i=n-1;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[index]=new_Val;
        n++;

        printf("New Array is: ");
        for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
    else if(index==n+1){
        printf("Enter The new value: ");
        scanf("%d",&new_Val);
        arr[n]=new_Val;
        n++;

     printf("New Array is: ");
        for(int i=0;i<n;i++){
             printf("%d ",arr[i]);
    }

    }
    else{
        printf("Enter The new value: ");
        scanf("%d",&new_Val);

    for(int i=n-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=new_Val;
    n++;

    printf("New Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    }
}
void DeleteAnElement(int n,int arr[]){

    int index;
    printf("Enter The Index:");
    scanf("%d",&index);

    if(index<0||index>=n){
        printf("Input Invalid");
    }
    else{
        for(int i=index;i<n;i++){
            arr[i]=arr[i+1];
        }
        n--;
        printf("New Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    }
}
void NthOccur(int n,int arr[]){

    int Occur_Value,count=0,pos;

    printf("Enter The Occurred Value: ");
    scanf("%d",&Occur_Value);

    printf("Enter The Position to delete: ");
    scanf("%d",&pos);

    for(int i=0;i<n;i++){
        if(arr[i]==Occur_Value){
            count++;
        }
        if(count==pos){
        pos=i;
        count=1;
        break;
}
    }
    if(count){
        for(int i=0;i<n;i++){
            arr[i]=arr[i+1];
        }

        n--;

        printf("New Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

    else{
        printf("Invalid Input");
    }

}
void BubbleSort(int n,int arr[]){

    int temp;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    printf("New Array is: ");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
}
void BinarySearch(int n,int arr[]){

    BubbleSort(n,arr);

    int value,mid,l=0,r=n-1,result=-1;

    printf("\nEnter The Value: ");
    scanf("%d",&value);

    while(l<=r){

            mid=(l+r)/2;

        if(arr[mid]==value){
            result=mid;
            break;
        }
        else if(value<arr[mid]){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    if(result!=-1){
        printf("The index of the value is: %d",result);
    }
    else{
        printf("The result is invalid");
    }
}
void MedianOfArray(int n,int arr[]){

    BubbleSort(n,arr);

    double median;

    if(n%2==0){
        median=arr[((n/2)+(n/2)-1)/2];
    }
    else{
        median= arr[n/2];
    }
    printf("\nThe Median is: %.0lf",median);
}
int main(){

    int choice,n;

        printf("Enter The Number: ");
        scanf("%d",&n);

        int arr[n];

       printf("Enter The Array element: ");
       for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
       }

    while(1){
        printf("\n\n1.Print The ArrayList.\n2.Find The value from index.\n3.Update an element.\n4.Linear Search.\n5.Insert an element.\n6.Delete an element.\n7.Delete nth occurrence\n8.Bubble Sort the Array.\n9.Binary Search\n10.Median of the array element.\n11.Exit");

        printf("\n\nEnter The Choice: ");
        scanf("%d",&choice);

         if(choice==1){
            ArrayList(n,arr);
        }

          else if(choice==2){
             IndexValue(n,arr);
          }

          else if(choice==3){
            UpdateElement(n,arr);
          }

          else if(choice==4){
            LinearSearch(n,arr);
          }

          else if(choice==5){
            InsertAnElement(n,arr);
          }

          else if(choice==6){
            DeleteAnElement(n,arr);
          }

          else if(choice==7){
            NthOccur(n,arr);
          }

          else if(choice==8){
            BubbleSort(n,arr);
          }

          else if(choice==9){
            BinarySearch(n,arr);
          }

          else if(choice==10){
            MedianOfArray(n,arr);
          }
          else if(choice==11){
            printf("Exit\n");
            break;
          }

        }
}
