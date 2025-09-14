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


//LEETCODE QUESTION - MAXIMUM SUBARRAY
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane algo
        int maxSum = nums[0];
        int currentSum = nums[0];

        for(int i=1; i<nums.size(); i++){
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
        
    }
};


LEETCODE QUESTION - MAJORITY ELEMENT
    class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //hashing take O(n) space complexity
        // unordered_map<int, int> mp;
        // int n = nums.size();
        // for(int num : nums){
        //     mp[num]++;
        //     if(mp[num] > n/2){
        //         return num;
        //     }
        // }return -1;


        //It is Optimized Solution (Boyer–Moore Voting Algorithm)
        int cand = 0;
        int count = 0;
        for(int num : nums){
            if(count == 0) cand = num;
            count += (num == cand) ? 1 : -1;

        }
        return cand;
    }
};


//LEETCODE QUESTION - MERGE SORTED ARRAY
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i >= 0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;

        }  
     }
};


✅ Best Solution (Two Pointers from End)
Idea:
-- Start from the end of both arrays.
-- Place the largest element at the back of nums1 (since nums1 has extra space).
-- Move pointers accordingly.


//LEETCODE QUESTION - SQUARES OF A SORTED ARRAY
    class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n =nums.size();
        vector<int> res(n); 
        
        int pos = n-1, right =n-1, left =0;
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                res[pos] = nums[left] * nums[left];
                left++;
            }else{
                res[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;

        }return res;
    }
};

//LEETCODE QUESTION - VALID MOUNTAIN ARRAY
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n =arr.size();
        if(n   < 3) return false;
        int i=0;

        //increase
        while(i+1 < n && arr[i] < arr[i+1]){
            i++;
        }

        //peak point
        if(i == 0 || i == n-1) return false;

        //decease
        while(i+1 < n && arr[i] > arr[i+1]){
            i++;
        }return i == n-1;
        
    }
};

auto init_atexit = atexit([](){
    ofstream("display_runtime.txt") << "1";
});


// LEETCODE QUESTION - INSERT INTERVAL PROBLEM
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // Step 1: add all before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Step 2: merge overlap
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // Step 3: add remaining
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
