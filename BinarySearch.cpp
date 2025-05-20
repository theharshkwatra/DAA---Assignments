#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>& arr, int target){
    int start = 0, end = arr.size() - 1;
    
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    return -1;
}


int main(){
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int search = binarySearch(arr, target);

    if(search == -1) cout << "Element not found in the array " << endl;
    else cout << "The targeted element is present at " << search << endl;

    return 0;
}