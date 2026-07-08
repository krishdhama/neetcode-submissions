class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<numbers.size();i++){
            int new_target=target-numbers[i];
            if(mpp.find(new_target)!=mpp.end())return {mpp[new_target]+1,i+1};
            else mpp[numbers[i]]=i;
        }
        return {};
    }
};
