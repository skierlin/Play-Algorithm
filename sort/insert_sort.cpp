//
// Created by lance on 2021/12/31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    
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
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {
    vector<int> arr{2,4,3,6,7,1};
    Solution().insert_sort(arr);
    print_vec(arr);
    return 0;
}

