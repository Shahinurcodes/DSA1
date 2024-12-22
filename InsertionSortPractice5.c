#include <stdio.h>
int Binary_Search(int arr[],int value,int l,int r){
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==value){
            return mid;
        }
        else if(arr[mid]<value){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return 1;
}
void Insertion_Sort(int arr[],int n){
    int pos,temp;
    for(int i=1;i<n;i++){
        temp=arr[i];
        pos=Binary_Search(arr,temp,0,i-1);
        for(int j=i;j>pos;j--){
            arr[j]=arr[j-1];
        }
        arr[pos]=temp;
        }
    printf("The Sorted array elements are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void PrintList(int arr[],int n){
    printf("The array elements are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter The Number: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    PrintList(arr,n);
    printf("\n");
    Insertion_Sort(arr,n);
    return 0;
}


