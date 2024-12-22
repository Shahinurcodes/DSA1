#include <stdio.h>
void Bubble_Sort(int arr[],int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            temp=arr[i];
            if(arr[j]>arr[i]){
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("The Sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    printf("The Number is: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter The Array List: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Bubble_Sort(arr,n);
}
