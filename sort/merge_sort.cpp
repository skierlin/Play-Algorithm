//
// Created by lance on 2021/12/31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> aux(arr.size(),-1);
        for (int i = l; i <= r; i++)
            aux[i - l] = arr[i];
        
        int i = l, j = mid + 1;
        for (int k = l; k <= r; k++) {
            if (i > mid) {
                arr[k] = aux[j - l];
                j++;
            }
            else if( j > r ){
                arr[k] = aux[i - l];
                i++;
            }
            else if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            }
            else {
                arr[k] = aux[j - l];
                j++;
            }
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r)
            return;
        
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {
    vector<int> arr{2,4,3,6,7,1};
    Solution().mergeSort(arr, 0, arr.size());
    print_vec(arr);
    return 0;
}
