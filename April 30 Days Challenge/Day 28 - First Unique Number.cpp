class FirstUnique {
    vector<int> nums;
    unordered_map<int, int> countMap;
    int firstUniquePos;
public:
    FirstUnique(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            add(nums[i]);
        }
        firstUniquePos = 0;
        showFirstUnique();
    }
    
    int showFirstUnique() {
        for(int i=firstUniquePos; i < nums.size(); i++){
            if(countMap[nums[i]] == 1){
                firstUniquePos = i;
                return nums[i];
            }
        }
        return -1;
    }
    
    void add(int value) {
        if(countMap.find(value) == countMap.end())
        {
            nums.push_back(value);
            countMap[value] = 1;
        } else {
            countMap[value]++;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */