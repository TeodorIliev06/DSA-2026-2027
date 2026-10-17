class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool inA[1001] = {}, added[1001] = {};
        vector<int> result;

        for (int num : nums1) {
            inA[num] = true;
        }

        for (int num : nums2) {
            if (inA[num] && !added[num]) {
                added[num] = true;
                result.push_back(num);
            }
        }

        return result;
    }
};
