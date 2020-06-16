#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *random_arr,*sorted_array,*reverse_sorted_array;
int N=150;
//int inputarr[]={10000,20000,30000,40000,50000,60000,70000,80000,90000,100000};
void generate_num(int N);
void print_elements(int *arr,int N);
void quick_sort(int *arr,int start,int end);
void bubble_sort(int *arr,int N);
void swap(int *a,int *b);
void dummybubblesort(int *arr,int N);
void merge_sort(int *arr,int p,int q);
void selectionsort(int *arr,int N);
void merge_procedure(int *arr,int low,int high,int mid);
void mergesortcaller(int* arr,int N);
void quick_sort_caller(int *a,int N);
int partition(int *arr,int start,int end);
void allcall(int n);

int main()
{
    generate_num(N);
    printf("bubble sort \n");
     printf("random arr time\n");

    bubble_sort(random_arr,N);

    printf("sorted array time \n");
    bubble_sort(sorted_array,N);
    printf("reverse sorted array\n");
    bubble_sort(reverse_sorted_array,N);
    //insertion sort
   printf("insertion sort \n");
    printf("random arr time \n ");
    insertion_sort(random_arr,N);
   printf("sorted arr time \n");
    insertion_sort(sorted_array,N);
    printf("reverse sorted arr time \n");
    insertion_sort(reverse_sorted_array,N);
    //selection sort
    printf("selection sort \n");
    printf("random arr time \n ");
    selectionsort(random_arr,N);
    printf("sorted arr time \n");
    selectionsort(sorted_array,N);
    printf("reverse sorted arr time \n");
    selectionsort(reverse_sorted_array,N);

    //merge sort
    printf("merge sort 1\n");
    printf("random arr time 2 \n ");
    mergesortcaller(random_arr,N);
   printf("sorted arr time 3\n");
    mergesortcaller(sorted_array,N);
    printf("reverse sorted arr time \n");
    mergesortcaller(reverse_sorted_array,N);

   printf("quick sort \n");
    printf("random arr time  \n ");
    quick_sort_caller(random_arr,N);
  printf("sorted arr time \n");
    quick_sort_caller(sorted_array,N);
    printf("reverse sorted arr time \n");
    quick_sort_caller(reverse_sorted_array,N);

    return 0;
}
void generate_num(int N)
{
    //int *random_arr,*sorted_array,*reverse_sorted_array;

    random_arr=(int *)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        random_arr[i]=rand();
    }
   //printf("rand arr \n");
    //print_elements(random_arr,N);
    sorted_array=(int *)malloc(sizeof(int)*N);
    //printf("sorted array \n");
    dummybubblesort(random_arr,N);
    //print_elements(sorted_array,N);
    reverse_sorted_array=(int *)malloc(sizeof(int)*N);
    /*for(int i=0;i<N;i++)
    {
        sorted_array[i]=i;
    }
    */
    //print_elements(sorted_array,N);
    int ele=N-1;
    for(int i=0;i<N;i++)
    {
        reverse_sorted_array[ele]=sorted_array[i];
        ele=ele-1;
    }
    //print_elements(reverse_sorted_array,N);
    //printf("reverse sorted array \n");
    //print_elements(reverse_sorted_array,N);



}
void print_elements(int *arr,int N)
{
    for(int i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubble_sort(int *tempa,int N)
{
    int *tempb=(int *)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        tempb[i]=tempa[i];
    }
    //printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(tempa,N);

    clock_t start,end;
    double time1;
    start=clock();
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-i-1;j++)
        {
            if(tempb[j]>tempb[j+1])
            {
                swap(&tempb[j],&tempb[j+1]);
            }
        }
    }
    //printf("after executing \n");
    //printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(tempa,N);

    end=clock();
    time1=((double)(end-start));
    printf("time to sort %f \n",time1);
    //return &tempb;
    free(tempb);

}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void dummybubblesort(int *tempa,int N)
{
    int *tempb=(int *)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        tempb[i]=tempa[i];
    }
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-i-1;j++)
        {
            if(tempb[j]>tempb[j+1])
            {
                swap(&tempb[j],&tempb[j+1]);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        sorted_array[i]=tempb[i];
    }
}
void insertion_sort(int *arr,int N)
{
   // print_elements(arr,N);

   int *tempb=(int *)malloc(sizeof(int)*N);
   for(int i=0;i<N;i++)
    {
        tempb[i]=arr[i];
    }
    //printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(arr,N);

    int key,j;
    clock_t start,end;
    double time1;
    start=clock();
    for(int i=0;i<N;i++)
    {
        key=tempb[i];
        j=i-1;
        while(j>=0 && tempb[j]>key)
        {
            tempb[j+1]=tempb[j];
            j=j-1;
        }
        tempb[j+1]=key;
    }
    //print_elements(arr,N);
    //printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(arr,N);

    end=clock();
    time1=((double)(end-start));
    printf("time to sort %f \n",time1);
    free(tempb);
}
void selectionsort(int *arr,int N)
{
    int *tempb=(int *)malloc(sizeof(int)*N);
   for(int i=0;i<N;i++)
    {
        tempb[i]=arr[i];
    }
   // printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(arr,N);
    clock_t start,end;
    double time1;
    int minimum_index,j;
    start=clock();

    for(int i=0;i<N-1;i++)
    {
        minimum_index=i;
        for(j=i+1;j<N;j++)
        {
            if(tempb[j]<tempb[minimum_index])
                minimum_index=j;
        }
        swap(&tempb[minimum_index],&tempb[i]);
    }
    //printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(arr,N);
    end=clock();
    time1=((double)(end-start));
    printf("time to sort %f \n",time1);
    free(tempb);
}
void merge_sort(int *arr,int low,int high)
{
    /*int *tempb=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        tempb[i]=arr[i];
    }
    */

   // printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(arr,N);
    //clock_t start,end;
    //double time1;
    //start=clock();
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge_procedure(arr,low,high,mid);
    }
   /* end=clock();
    time1=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time to sort %f \n",time1);
    printf("copied arr \n");
    print_elements(tempb,N);
    printf("og arr \n");
    print_elements(arr,N);
    */
}
void merge_procedure(int *arr,int low,int high,int mid)
{
    int i,j,k,temp[high-low+1];
    i=low;
    k=0;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void mergesortcaller(int *arr,int N)
{
    int *tempb=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        tempb[i]=arr[i];
    }
    //printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(arr,N);

    clock_t start,end;
    double time1;
    start=clock();
    merge_sort(tempb,0,N-1);

    //printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(arr,N);

    end=clock();
    time1=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time to sort %f \n",time1);
    free(tempb);

}
void quick_sort(int *arr,int start,int end)
{
    if(start<end)
    {
        int q=partition(arr,start,end);
        quick_sort(arr,start,q-1);
        quick_sort(arr,q+1,end);
    }
}

int partition(int *arr,int start,int end)
{
    int piv=arr[end];
    int i=start-1;
    for(int j=start;j<=end-1;j++)
    {
        if(arr[j]<=piv)
        {
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[end]);
    return (i+1);
}
void quick_sort_caller(int *arr,int N)
{
    int *tempb=(int*)malloc(sizeof(int)*N);
     for(int i=0;i<N;i++)
    {
        tempb[i]=arr[i];
    }
   // printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(arr,N);

    clock_t start,end;
    double time1;
    start=clock();
    quick_sort(tempb,1,N-1);

    //printf("copied arr \n");
    //print_elements(tempb,N);
    //printf("og arr \n");
    //print_elements(arr,N);
    end=clock();
    time1=((double)(end-start));
    printf("time to sort %f \n",time1);


}

