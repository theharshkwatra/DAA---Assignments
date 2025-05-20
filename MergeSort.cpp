#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for(int i = 0; i < n1; i++){
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& arr, int left, int right){
    if(left >= right) return;

    int  mid = left + (right-left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}


void printVector(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    vector<int> arr = {43,67,23,46,69,12,88};
    int n = arr.size();

    cout << "Given Vector is ";
    printVector(arr);

    mergeSort(arr, 0, n-1);

    cout << "Sorted Vector is ";
    printVector(arr);

    return 0;
}