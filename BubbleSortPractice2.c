//Bubble Sort with Strings Implement a
//bubble sort algorithm to sort an array of
//strings in alphabetical order.
#include <stdio.h>
#include <string.h>
void Bubble_Sort(char *arr[],int n){
    char *temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(arr[i],arr[j])>0){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\n\nSorted Array: ");
    for(int i=0;i<n;i++){
        printf("%s ",arr[i]);
    }
}
int main(){
    char *arr[]={"Dog","Cat","Elephant","Ant","Bird"};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    for(int i=0;i<n;i++){
        printf("%s ",arr[i]);
    }
    Bubble_Sort(arr,n);
    printf("\n");
    return 0;
}
