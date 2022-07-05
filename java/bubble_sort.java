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
public class bubble_sort {
    public void bubblesort(int[] arr)
    {
        int n=arr.length;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
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
        bubble_sort ob=new bubble_sort();
        int arr[]={ 64, 34, 25, 12, 22, 11, 90 };
        ob.bubblesort(arr);
        ob.display(arr);
    }
}
