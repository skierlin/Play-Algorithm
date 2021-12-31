#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    void select_sort(vector<int>& arr){
        int index = 0;
        for(int i = 0; i < arr.size(); i++){
            int min = arr[i];
            index = i;
            for(int j = i+1; j < arr.size(); j++) {
                if (min > arr[j]){
                    index = j;
                    min = arr[j];
                }
            }
            swap(arr[i], arr[index]);
        }
        return;
    }
    
    void insert_sort(vector<int> &arr){
        for(int i = 1; i < arr.size(); i ++){
            for(int j = i; j > 0; j--) {
                if (arr[j] < arr[j-1]) {
                    swap(arr[j], arr[j-1]);
                }
                else{
                    break;
                }
            }
        }
        return ;
    }
    
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
    Solution().select_sort(arr);
    print_vec(arr);
    return 0;
}
