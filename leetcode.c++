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


//LEETCODE QUESTION - REMOVE ELEMENT
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[j]=nums[i];
                j++;
                
            }
            
        }return j;
        
        
    }
};


//LEETCODE QUESTION - BEST TIME TO BUY AND SELL 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > bestBuy){
                maxProfit = max(maxProfit, prices[i]-bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
        
    }
};
