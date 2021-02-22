#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <algorithm>
//
// Created by Tianyi Zhang on 10/28/20.
//
using namespace std;
class Solution {
public:
    vector<vector<int>> process(vector<int>& nums){
        vector<vector<int>> ret;
        for(auto i : nums){
            vector<int> curNum;
            while(true){
                curNum.insert(curNum.begin(), i%10);
                i/=10;
                if(i == 0)
                    break;
            }
            ret.push_back(curNum);
        }
        return ret;
    }



    string largestNumber(vector<int>& nums) {
        vector<vector<int>> p = vector<vector<int>>(8,vector<int>(1,0));
        sort(p.begin(), p.end(), [](vector<int> const& lhs, vector<int> const& rhs){
            return true;
        });
        string res;
        return res;
    }
};

int main(){
    std::vector<int> a{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> b{0,0,0,0,0,0,0};

    /*vector<vector<int>> p = vector<vector<int>>(8,vector<int>(1,0));
    sort(p.begin(), p.end(), [](vector<int> const& lhs, vector<int> const& rhs){
        return true;
    });*/

    vector<int> pi = vector<int>(10000,0);
    sort(pi.begin(), pi.end(), [](auto const& lhs, auto const& rhs){
        if(lhs < rhs)
            return true;
        else
            return false;
    });

    Solution solution;
    //solution.largestNumber(b);
    return 0;
}
