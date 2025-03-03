#include<iostream>
using namespace std;

void merge(int arr[], int s , int e){

    int mid = (s+e)/2; 

    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    // create left and right array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // copy values from original array to left array
    int k = s;
    // k -> starting index of left array values in origina array
    for(int i=0; i<lenLeft; i++){
        left[i] = arr[k];
        k++;
    }

    // copy values from original array to Right array
    k = mid + 1;
    for(int i=0; i<lenRight; i++){
        right[i] = arr[k];
        k++;
    }

    // actual merge logic here
    // left array is already sorted
    // Right array is already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    // yahi pr galti karte, bhool jate hai
    int mainArrayIndex = s;

    while(leftIndex < lenLeft && rightIndex < lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;  
        }
    }
    // 2 more cases
    // 1st case -> left array exhaust ho gaya pr abhi bhi right array mai element bache h
    while(rightIndex < lenRight){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++; 
    }
    // 2nd case -> right array exhaust ho gaya pr abhi bhi left array mai element bache h
    while(leftIndex < lenLeft){
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    // 1 more step pending for freeing dynamic memory allocation from heap
    delete[] left;
    delete[] right;
}
void mergeSort(int arr[], int s , int e){
    // base Case
    if(s > e) return;
    if(s == e) return;

    // break
    int mid = (s + e)/2;
    // s -> mid -> left part
    // mid+1 -> e -> right part

    // Call recursion ans sort left and right side
    // Recursion call for left array
    mergeSort(arr, s, mid);

    // Recursion call for Right array
    mergeSort(arr, mid+1, e);

    // ṃerge 2 sorted arrays
    merge(arr, s, e);
}

int main(){
    int arr[]  ={2,1,6,9,4,5};
    int size = 6;
    int start = 0;
    int end = size-1;
    cout<<"Before Merge Sort: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr, start, end);
    cout<<"After Merge Sort: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}