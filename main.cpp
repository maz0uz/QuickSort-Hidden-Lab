//
//  main.cpp
//  Quicksort Hidden Lab
//
//  Created by Mohamed Azouz on 18/05/2023.
//

#include <iostream>
using namespace std;


void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quickSort(int arr[],int low,int high)
{
    int pi;
    if(low<high)
    {
        pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main()
{
    int arr[10];
    
    cout<<"Array before:"<<endl;
    for(int i=0;i<10;i++)
    {
        arr[i]=rand()%20+1;
        cout<<arr[i]<<' ';
    }
    quickSort(arr,0,9);
    cout<<"Array after:"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<' ';
    }
}
