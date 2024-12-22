//Write a function to sort an array of integers
//using the Insertion Sort algorithm.

#include <stdio.h>
void Insertion_Sort(int arr[],int n){
    int j,temp;
    for(int i=1;i<n;i++){
            temp=arr[i];
            j=i-1;
            while(j>=0&&arr[j]>temp){
                arr[j+1]=arr[j];
                j--;
        }
        arr[j+1]=temp;
    }
    printf("\nThe Sorted Array Element's are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void print_List(int arr[],int n){
    printf("\nThe Array Element's are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter The Number: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter The Array Element: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Insertion_Sort(arr,n);
    return 0;
}
