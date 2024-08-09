#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    unordered_map<int,int> save;
    void maxHeapify(vector<int>& nums, int i, int heapsize){
        int l = i*2+1, r = i*2+2, largest = i;
        if(l<heapsize && save[nums[l]]>save[nums[largest]]){
            largest = l;
        }
        if(r<heapsize && save[nums[r]]>save[nums[largest]]){
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> num;
        for(int i = 0;i<nums.size();i++){
            if(save.count(nums[i])){
                save[nums[i]]++;
            }else{
                save[nums[i]] = 1;
                num.push_back(nums[i]);
            }
        }

        // for(int i:num){
        //     cout<<i<<" "<<save[i]<<endl;;
        // }
        // cout<<endl<<endl;

        int heapSize = num.size();

        buildMaxTree(num,heapSize);

        vector<int> ans;
        for(int i=num.size()-1;i>=num.size()-k;i--){
            ans.push_back(num[0]);
            swap(num[0],num[i]);
            heapSize--;
            maxHeapify(num,0,heapSize);
        }

        for(int i = num.size() - 1; i >= num.size() - k; i--){
            ans.push_back(num[0]);
            swap(num[0], num[i]);
            heapSize--;

            // Debug: 打印当前的 i 和 heapSize
            cout << "i: " << i << ", heapSize: " << heapSize << endl;

            if (heapSize <= 0) {
                cout << "Heap size is non-positive, breaking the loop." << endl;
                break;
            }

            maxHeapify(num, 0, heapSize);
        }

        return ans;
    }
};

int main(){
    cout<<"hello world!"<<endl;

    vector<int> nums = {1};
    int k = 1;

    Solution sol;
    auto result = sol.topKFrequent(nums,k);
    for(int i:result){
        cout<<i<<" ";
    }
    
}