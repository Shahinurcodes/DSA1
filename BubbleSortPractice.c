#include <stdio.h>
void Bubble_Sort(int arr[],int n){
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
   printf("The Bubble Sort Array List is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void printList(int arr[],int n){
    printf("The Array List is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter The Number: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter The Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printList(arr,n);
    printf("\n");
    Bubble_Sort(arr,n);
}
