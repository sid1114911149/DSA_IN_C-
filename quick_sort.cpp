#include <iostream>
using namespace std;

int sort(int arr[], int l, int h) {
    int mid = l + (h - l) / 2;
    int pivot = arr[l];
    int i = l, j = h, temp;
    
    while (i < j) {
        while (i <= h - 1 && arr[i] <= pivot)
            i++;
        while (j >= l + 1 && arr[j] >= pivot)
            j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void divide(int arr[], int l, int h) {
    if (l < h) {
        int j = sort(arr, l, h);
        divide(arr, l, j - 1);
        divide(arr, j + 1, h);
    }
}

int main() {
    int arr[] = {986, 45, 65, 246, 1};
    int n = 5;
    
    divide(arr, 0, n - 1);
    
    cout << "Elements After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}