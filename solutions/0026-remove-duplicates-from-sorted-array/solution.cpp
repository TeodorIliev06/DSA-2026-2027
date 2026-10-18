class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int removed = 0;

        for (int i = 1; i < size; i++){
            if(nums[removed] != nums[i]) {
                removed++;
                nums[removed] = nums[i];
            }
        }

        return removed+1;
    }
};
