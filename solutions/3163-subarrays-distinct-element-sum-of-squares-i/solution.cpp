class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();

        for (int j = 0; j < size; j++) {
            int freq[101] = {0};
            int distinctCount = 0;

            for (int i = j; i < nums.size(); i++) {
                if(freq[nums[i]] == 0) {
                    distinctCount++;
                }
                freq[nums[i]]++;

                sum+= distinctCount * distinctCount;
            }
        }

        return sum;
    }
};
