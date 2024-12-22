//Implement Insertion Sort, but instead of sorting the entire array,
//sort only the first k elements.

#include <stdio.h>
void Insertion_Sort(int arr[],int n,int k){
    int j,temp;
    for(int i=1;i<k;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    printf("The Half Sorted Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void printList(int arr[],int n){
     printf("The Array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n,k;
    printf("Enter The Number N: ");
    scanf("%d",&n);
    printf("Enter The Number K: ");
    scanf("%d",&k);
    int arr[n];
    printf("Enter The Array List: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printList(arr,n);
    printf("\n");
    Insertion_Sort(arr,n,k);
}
