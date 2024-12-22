//Modify the Insertion Sort algorithm to
//count the number of inversions in the array.
#include <stdio.h>
int Insertion_Sort(int arr[],int n){
    int j,temp,count=0;
    for(int i=1;i<n;i++){
      temp=arr[i];
      j=i-1;
      while(j>=0&&arr[j]>temp){
        arr[j+1]=arr[j];
        j--;
        count++;
      }
      arr[j+1]=temp;
  }
  printf("The Sorted Value is: ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return count;
}
void printList(int arr[],int n){
  printf("The Array Value is: ");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}
int main(){
    int n,count;
    printf("Enter The Number: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter The Array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printList(arr,n);
    printf("\n");
    count= Insertion_Sort(arr,n);
    printf("\nInversion: %d",count);
    return 0;
}
