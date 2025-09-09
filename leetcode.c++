// LEETCODE QUESTION - TWO SUM PROBLEM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    // Hashing O(n)
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int comp = target - nums[i];
            if(mp.find(comp) != mp.end()){
                return {mp[comp], i};
            }
            mp[nums[i]] = i;

        }
        return {};
        
        
    }
};


//LEETCODE QUESTION - REMOVE DUPLICATE FROM SORTED ARRAY
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Two Pointer
        if(nums.empty()) return 0;
        int j =0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
            }
        }return j+1;
    }
};
