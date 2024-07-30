#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int max = 0;
//         for(int i=0;i<height.size();i++){
//             for (int j = i+1; j < height.size(); j++)
//             {
//                 int h = min(height[i],height[j]);
//                 int area = h*(j-i);
//                 if(area>max){
//                     max = area;
//                 }
//             }
            
//         }
//         return max;

//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int i=0;
        int j = height.size()-1;
        while (i<j)
        {
            int h = min(height[i],height[j]);
            int area = h*(j-i);
             if(area>max){
                max = area;
             }
             if (height[i]>height[j] || height[i]==height[j])
             {
                j--;
             }
             else{
                i++;
             }
             
        }
        
        
        return max;

    }
};


int main(void){
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    Solution solution;
    int max = solution.maxArea(nums);
    cout<<"max area = "<<max<<endl;
}