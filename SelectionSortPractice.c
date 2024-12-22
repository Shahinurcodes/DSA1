#include <stdio.h>
void Selection_Sort(int arr[],int n){
    int minimum,temp;
    for(int i=0;i<n-1;i++){
        minimum=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minimum]){
                minimum=j;
            }
        }
        temp=arr[minimum];
        arr[minimum]=arr[i];
        arr[i]=temp;
    }
    printf("The Sorted Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void print_List(int arr[],int n){
    printf("The Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter The Number: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    print_List(arr,n);
    printf("\n");
    Selection_Sort(arr,n);

    return 0;
}
