/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package infytq;

/**
 *
 * @author racha
 */
public class quick_sort 
{
void quicksort(int[] number,int first,int last){
   int i, j,  temp;
   int pivot;
   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;
      while(i<j)
      {
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}
static void printArray(int[] arr)
    {
        int n=arr.length;
        for(int i=0;i<n;i++)
        {
            System.out.println(arr[i]);
        }
    }
public static void main(String args[])
{
    quick_sort ob=new quick_sort();
    int arr[] = {7,6,10,5,9,2,1,15,7};
    ob.quicksort(arr, 0, arr.length-1);
    printArray(arr);
}
}