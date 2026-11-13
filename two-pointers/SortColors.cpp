#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public : 
    void SortColors(vector<int>&nums){
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid<=high){
            if(nums[mid] == 0){
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main (){
    Solution sol;
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sol.SortColors(arr);
    
    cout<< "Sorted Colours" <<endl;
    for(int num : arr){
        cout << num <<" ";
    }
    cout << endl;
    return 0;
}