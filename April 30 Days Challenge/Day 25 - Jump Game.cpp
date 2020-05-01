class Solution {
public:
    bool canJump(vector<int> nums) {
        int maxIndex = nums.size() - 1;
        for(int i=nums.size()-2; i>=0; i--){
            if(i + nums[i] >= maxIndex){
                maxIndex = i;
            }
        }
        return maxIndex == 0;
    }
};