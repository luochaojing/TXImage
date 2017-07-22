//
//  main.cpp
//  TwoSum
//
//  Created by Luo on 16/11/15.
//  Copyright © 2016年 com.aspire. All rights reserved.
//

// -- 使用hash_table

#include <iostream>
#include <vector>
#include <ext/hash_map>//hash_map

#include <map>
//hash 表咋做呢？

using namespace std;
using namespace __gnu_cxx;


//打印向量
void printVector(vector<int> &nums)
{
    cout<<"向量为：";
    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<"->";
    }
    cout<<endl;
};




struct KeyValue
{
    int key;
    int value;
    
    int getValue()const
    {
        return value;
    }
};


//hash__函数
struct hash_KeyValue
{
    size_t operator()(KeyValue & keyValue)const
    {
        return keyValue.value;
    }
};





class Solution
{
public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        
        
        vector<int> resultVector;
        
        
        //使用哈希表，一边查找一边插入，时间复杂度就是n。
        __gnu_cxx::hash_map<int, int> myHash_map;
        //~~unordered_map 是Windows和leetcode上
        
        for (int i = 0; i < nums.size(); i++) {
            
            int num = nums[i];

            //有的话
            if (myHash_map.find(target - num) != myHash_map.end())
            {
                int index = myHash_map[target - num];
                resultVector.push_back(index);
                resultVector.push_back(i);
                
                return resultVector;
                
                
            }
            
            
            myHash_map[num] = i;
            
        }
        return resultVector;
        
        
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> nums;
    int array[20] = {3,3,3,3,2,4,16,18,20,23,12,22,98,23,23,42,12,14};
    for (int i = 0; i < 1; i++) {
    
        nums.push_back(array[i]);
    }
    
    Solution solution =  Solution();
    solution.twoSum(nums, 6);
    
    //printVector(solution.twoSum(nums, 19));
    
    vector<int> num1 = solution.twoSum(nums, 6);
    printVector(num1);
    
    //printVector(solution.twoSum(nums, 19));
    
    
    
    
    
    
    return 0;
}




