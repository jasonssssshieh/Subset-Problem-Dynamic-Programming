//
//  main.cpp
//  No.4 Subset Sum Problem
//
//  Created by Zijian Xie on 2016/11/5.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//
// Given a target and nums, to find out wether there exist a subset which sum is the target
// target = 11, nums = {2,3,7,8,10}
#include <iostream>
#include <vector>
using namespace std;

class subsetsum{
private:
    vector<int> nums;
    int target;
public:
    subsetsum(vector<int>& num, int n){
        nums = num;
        target = n;
    }
    bool dynamicpro(){
        vector<vector<int>> dp(nums.size(), vector<int>(target+1,0));
        for(int i = 0; i < nums.size(); ++i){
            dp[i][0] = 1;
        }
        for(int i = 0; i < nums.size();++i){
            for(int j = 0; j <= target; ++j){
                if(j >= nums[i]){dp[i][j] = dp[i][j - nums[i]];}
                if(!dp[i][j] && i > 0){dp[i][j] = dp[i-1][j];}
            }
            if(dp[i][target]){return true;}
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> num = {2,3,7,8,10};
    int n = 11;
    subsetsum* test = new subsetsum(num,n);
    if(test->dynamicpro()){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}
