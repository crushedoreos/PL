// MergeSort(arr[], l, r) {
//     if (l<r) {
//         mid = (l+r)/2;
//         MergeSort(arr[],l,mid);
//         MergSort(arr[],mid+1,r);
        
//         Merge(arr[],l,mid,r);
//     }
// }
#include<bits/stdc++.h>
using namespace std;


void merge(int *arr, int startIndex, int endIndex)
{
    int mid = (startIndex+endIndex)>>1;

    int len1 = mid-startIndex+1;
    int len2 = endIndex-mid;

    //Now need to take 2 arrays for both halves
    int *first = new int[len1];
    int *second = new int[len2];

    //Copy the values
    int mainArrayIdx = startIndex;

    for(int i=0;i<len1;i++)
        first[i] = arr[mainArrayIdx++];
    
    mainArrayIdx = mid+1;
    for(int i=0;i<len2;i++)
        second[i] = arr[mainArrayIdx++];





    //Merge the 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIdx= startIndex;

    while(index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainArrayIdx++] = first[index1++];
        }
        else{
            arr[mainArrayIdx++] = second[index2++];
        }
    }


    while(index1<len1 )
        arr[mainArrayIdx++] = first[index1++];
    while(index2<len2)
        arr[mainArrayIdx++] = second[index2++];
    

    //Delete the 2 used arrays to avoid memory leaks
    //delete []first;
    //delete []second;
}

void mergeSort(int *arr, int startIndex, int endIndex)
{
    //Base case
    if(startIndex>=endIndex)
        return;
    
    int mid = (startIndex+endIndex)>>1;
    
    //Sort left array
    mergeSort(arr,startIndex,mid);
    //Sort right array
    mergeSort(arr,mid+1,endIndex);

    //Finally merge both arrays
    merge(arr,startIndex,endIndex);
}
int main()
{
    int arr[7] ={38,27,43,3,9,82,10};
    int n=7;

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }

    return 0;
}
