#include<stdio.h>
void BubbleSort(int temp_n,int temp[]){
    int temp_Place,i,j;
        for(int i=0;i<temp_n-1;i++){
            for(int j=i+1;j<temp_n;j++){
                if(temp[i]>temp[j]){
                    temp_Place=temp[i];
                    temp[i]=temp[j];
                    temp[j]=temp_Place;
                }
            }
        }
        printf("The Sorted array is:");
            for(i=0;i<temp_n;i++){
                printf("%d ",temp[i]);
            }
}
int main(){

    int n,pos,new_Val,flag,choice,i;

    printf("Enter The Array Number: ");
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter The array values:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int temp[n];
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
    }

    int temp_n;
    temp_n=n;

    while(1){
        printf("\n\n1. Print the element \n2. Print the index value\n3. Update\n4. Linear Search\n5. Insert\n6. Delete\n7. Delete nth occurrence\n8. Bubble sort\n9. Binary Search\n10.Median of the Array Elements\n0. EXIT");
        printf("\n\nEnter Choice: ");
        scanf("%d",&choice);

    if(choice==1){
        printf("\nThe array elements are: ");//Printing the element
        for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
     printf("\n");
        }
    else if(choice==2){//Printing the index value
        printf("\nEnter the index to print: ");
        scanf("%d",&pos);
    if(pos<0||pos>temp_n||pos>temp_n+1){
        printf("\nInvalid Input.");
    }
    else{
        printf("\nThe value at index %d: %d",pos,temp[pos]);
    }
    }
    else if(choice==3){//updating a value
        printf("\nEnter The index to update: ");
        scanf("%d",&pos);

        if(pos<0||pos>=temp_n){
            printf("Invalid index. Try Again.\n");
        }
        else{
           printf("Enter The Value to update:");
           scanf("%d",&new_Val);

           temp[pos]=new_Val;

           printf("The updated array elements are:");
           for(int i=0;i<temp_n;i++){
            printf("%d ",temp[i]);
           }
           printf("\n");
        }
    }
    else if(choice==4){//Linear search in an array
        int findVal;
        flag=0;

        printf("Enter The searching element: ");
        scanf("%d",&findVal);

        for(int i=0;i<temp_n;i++){
            if(temp[i]==findVal){
                printf("\nThe searching value %d is at index %d.\n",findVal,i);
                flag=1;
                break;
            }
        }
        if(!flag){
                printf("\nInvalid Element");
            }
    }

    else if(choice==5){//insert an element
        printf("\nEnter The Value to insert:");
        scanf("%d",&new_Val);

        printf("Enter The position to insert:");
        scanf("%d",&pos);

        if(pos==0){//insert in the first place
            for(int i=temp_n;i>=0;i--){
                temp[i+1]=temp[i];
            }
            temp[0]=new_Val;
            temp_n++;

            printf("\n");

            printf("The New array is:");
            for(i=0;i<temp_n;i++){
                printf("%d ",temp[i]);
            }
        }
        else if(pos==temp_n+1){//insert in the last position
                temp[n]=new_Val;
                temp_n++;

            printf("The New array is:");
            for(i=0;i<temp_n;i++){
                printf("%d ",temp[i]);
            }
        }

        else{//insert in the middle
                for(i=temp_n;i>=pos-1;i--){
                temp[i+1]=temp[i];
                }

            temp[pos-1]=new_Val;
            temp_n++;

            printf("The New array is:");
            for(i=0;i<temp_n;i++){
                printf("%d ",temp[i]);
            }

        }
    }
    else if(choice==6){//deleting an element
            printf("\nEnter The position to Delete:");
            scanf("%d",&pos);

            if(pos<0||pos>temp_n||pos>temp_n+1){
           printf("Invalid Input.");
    }

            else{for(i=pos;i<=temp_n;i++){
                temp[i]=temp[i+1];
            }
        }
            temp_n--;

            printf("The New array is:");
            for(i=0;i<temp_n;i++){
                printf("%d ",temp[i]);
            }

    }

    else if(choice==7){//nth occurrence
        int count=0,Occur_Value,Occur_pos,flag=0;

        printf("Enter The Occur Value: ");
        scanf("%d",&Occur_Value);

        printf("Enter The Position:");
        scanf("%d",&Occur_pos);

        for(int i=0;i<temp_n;i++){
            if(temp[i]==Occur_Value){
                count++;
            }
            if(count==Occur_pos){
                pos=i;
                flag=1;
                break;
            }
        }
        if(flag){
            for(int i=pos;i<temp_n;i++){
            temp[i]=temp[i+1];
        }
        temp_n--;

        printf("\nThe New array is:");
            for(i=0;i<temp_n;i++){
                printf("%d ",temp[i]);
            }
        }else{
        printf("Invalid Input.");
        }
    }
    else if(choice==8){//Bubble sort
        BubbleSort(temp_n,temp);
    }
    else if(choice==9){//Binary Search
            BubbleSort(temp_n,temp);
            int sorted_array[temp_n];
            for(int i=0;i<temp_n;i++){
                sorted_array[i]=temp[i];
            }

        int l=0,r=temp_n-1;
        int mid,data,result=-1;

        printf("\nEnter The Data: ");
        scanf("%d",&data);

        while(l<=r){
           mid=(l+r)/2;
           if(data==sorted_array[mid]){
                result=mid;
                break;
              }
            if(data<sorted_array[mid]){
                r=mid-1;
              }
              else{
                l=mid+1;
              }
        }
        if(result!=-1){
            printf("Element is present at index %d\n",result);
        }else{
            printf("Element is not present in array\n");
        }
    }

    else if(choice==10){//median of the elements
        BubbleSort(temp_n,temp);
        double median;
        if(temp_n%2!=0){
           median=temp[(temp_n+1)/2];
        }
        else{
            median=temp[((temp_n/2)+((temp_n/2)+1))/2];
        }
        printf("\n\nThe median is: %.0lf",median);
    }

    else if(choice==0){
            printf("EXIT");
            break;
    }

    else{
        printf("Invalid. Try Again");
    }
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
    }
    temp_n=n;
    }
        return 0;
}

