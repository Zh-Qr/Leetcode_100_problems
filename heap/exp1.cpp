#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

// class Solution {
// public:
//     void maxHeapify(vector<int>& a, int i, int heapSize) { //建立小根堆
//         int l = i * 2 + 1, r = i * 2 + 2, largest = i;
//         if (l < heapSize && a[l] > a[largest]) {
//             largest = l;
//         } 
//         if (r < heapSize && a[r] > a[largest]) {
//             largest = r;
//         }
//         if (largest != i) {
//             swap(a[i], a[largest]);
//             maxHeapify(a, largest, heapSize); //递归操作！！！
//         }
//     }

//     void buildMaxHeap(vector<int>& a, int heapSize) {
//         for (int i = heapSize / 2; i >= 0; --i) {
//             maxHeapify(a, i, heapSize);
//         } 
//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         int heapSize = nums.size();
//         buildMaxHeap(nums, heapSize);

//         //堆建立完成

//         for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
//             swap(nums[0], nums[i]);
//             --heapSize;
//             maxHeapify(nums, 0, heapSize); //只需要考虑根部元素即可
//         }
//         return nums[0];
//     }
// };

class Solution{
public:
    void maxHeapify(vector<int>& nums, int i, int heapsize){
        int l = i*2+1, r = i*2+2, largest = i;
        if(l<heapsize && nums[l]>nums[largest]){
            largest = l;
        }
        if(r<heapsize && nums[r]>nums[largest]){
            largest = r;
        }
        if(largest!=i){
            swap(nums[largest],nums[i]);
            maxHeapify(nums, largest, heapsize);
        }
    }

    void buildMaxTree(vector<int> &nums, int heapsize){
        for(int i=heapsize/2-1;i>=0;i--){
            maxHeapify(nums, i, heapsize);
        }
    }
    int findKthLargest(vector<int>& nums, int k){
        int heapsize = nums.size();
        //建立大根堆
        buildMaxTree(nums, heapsize);
        // for(int i=0;i<k-1;i++){
        //     swap(nums[0],nums[heapsize-1-i]);
        //     --heapsize;
        //     maxHeapify(nums,0,heapsize);
        // }

        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapsize;
            maxHeapify(nums, 0, heapsize); //只需要考虑根部元素即可
        }

        // for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
        //     swap(nums[0], nums[i]);
        //     --heapsize;
        //     maxHeapify(nums, 0, heapsize); //只需要考虑根部元素即可
        // }

        return nums[0];
    }
};



int main(){
    cout<<"hello world!"<<endl;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;

    Solution sol;
    int result = sol.findKthLargest(nums,k);
    cout<<"result: "<<result;
    
}