#include <stdio.h>
#include <string.h>
void Insertion_Sort(char *arr[],int n){
    int j;
    char *temp;
    for(int i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0&&strcmp(arr[j],temp)>0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    printf("The Array Element is: ");
    for(int i=0;i<n;i++){
        printf("%s ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the Number: ");
    scanf("%d",&n);

    char *arr[n];
    printf("Enter the Array Element: ");
    for(int i=0;i<n;i++){
        arr[i]=(char *)malloc(100*sizeof(char *));
        scanf("%s",arr[i]);
    }
    Insertion_Sort(arr,n);
    for(int i=0;i<n;i++){
        free(arr[i]);
    }
    return 0;
}
