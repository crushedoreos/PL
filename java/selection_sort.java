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
public class selection_sort {
    public void selectionsort(int[] arr)
    {
        int n=arr.length;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               if(arr[j]<arr[i])
               {
                   int temp=arr[j];
               arr[j]=arr[i];
               arr[i]=temp;
               }
               
            }
        }
    }
    public void display(int[] arr)
    {
        int n=arr.length;
        for(int i=0;i<n;i++)
        {
            System.out.println(arr[i]+" ");
        }
    }
    public static void main(String args[])
    {
        selection_sort ob=new selection_sort();
        int arr[]={ 64, 34, 25, 12, 22, 11, 90 };
        ob.selectionsort(arr);
        ob.display(arr);
    }
}
