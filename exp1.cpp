#include <iostream>
#include <vector> //数组
#include <map> //实现哈希表
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                   return {i,j};
                }
            }
        }
        return {i,j};
    };

    vector<int> twoSum1(vector<int>& nums, int target) {
        map<int,int> a;//建立hash表存放数组元素
        vector<int> b(2,-1);//存放结果
        for(int i=0;i<nums.size();i++)
            a.insert(map<int,int>::value_type(nums[i],i));
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i)) //count返回是否存在键(target-nums[i])，存在返回1，不存在返回0
            //判断是否找到目标元素且目标元素不能是本身
            {
                b[0]=i;
                b[1]=a[target-nums[i]]; //键的值是索引
                break;
            }
        }
        return b;
    };

    //solution 3 
    vector<int> twoSum2(vector<int>& nums, int target){
        map<int,int> a;//建立哈希表
        vector<int> b(2,-1);//存放结果
        for(int i=0;i<nums.size();i++){
            if(a.count(target-nums[i])>0) //寻找键
            {
                b[0] = a[target-nums[i]]; //键值，即array索引
                b[1] = i;   //索引
                break;
            }
            a[nums[i]] = i;
        }
        return b;
    }

};

int main() 
{

    cout << "Hello, World!"<<endl;

    int target;
    cout<<"input the target number"<<endl;
    cin>>target;
    vector<int> nums = {2, 7, 11, 15};

    Solution solution;
    vector<int> result = solution.twoSum2(nums, target);
    int len = nums.size();
    cout<<"the length of array is: "<<len<<endl;
    for(int i=0;i<len;i++){
        cout<<nums[i]<<endl;
    }

    if (!result.empty()) {
        cout << "Indices of the two numbers that add up to " << target << " are: ";
        cout << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two sum solution" << endl;
    }

    system("Pause");

    return 0;
}