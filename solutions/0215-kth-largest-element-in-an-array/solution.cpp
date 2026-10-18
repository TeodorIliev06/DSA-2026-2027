class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = k - 1;
        int lo = 0, hi = nums.size() - 1;

        while(true) {
            int pivot = nums[(lo + hi) / 2];
            int lesser = lo, i = lo, greater = hi;

            while (i <= greater) {
                if(nums[i] > pivot) {
                    swap(nums[lesser++], nums[i++]);
                }
                else if(nums[i] < pivot) {
                    swap(nums[i], nums[greater--]);
                }
                else {
                    i++;
                }
            }

            if (target < lesser) {
                hi = lesser - 1;
            }
            else if (target > greater) {
                lo = greater + 1;
            }
            else {
                return pivot;
            }
        }
    }
};
