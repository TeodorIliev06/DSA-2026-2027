class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counter[3] = {};

        for (int num : nums) {
            counter[num]++;
        }

        int index = 0;
        for (int colour = 0; colour < 3; colour ++){
            while(counter[colour]-- > 0) {
                nums[index++] = colour;
            }
        }
    }
};
