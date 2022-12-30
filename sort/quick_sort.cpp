//
// Created by lance on 2021/12/31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int partition(vector<int>& vec, int l, int r) {
        int p = vec[l];
        int j = l;
        for (int i = l + 1; i <= r; i++)
            if (vec[i] < vec[l]) {
                j++;
                swap(vec[j], vec[i]);
            }
        swap(vec[l], vec[j]);
        
        return j;
    }
    
    void sort(vector<int>& vec, int l, int r) {
        if (l >= r)
            return;
        int p = partition(vec, l, r);
        sort(vec, l, p - 1);
        sort(vec, p + 1, r);
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {
    vector<int> arr{2,4,3,6,7,1};
    Solution().sort(arr, 0, arr.size());
    print_vec(arr);
    return 0;
}
