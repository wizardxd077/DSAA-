class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        // First element is fixed
        int score = nums[0];

        // To store the smallest and second smallest
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        // Find two smallest numbers from index 1 to n-1
        for (int i = 1; i < n; i++) {
            if (nums[i] < firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            } 
            else if (nums[i] < secondMin) {
                secondMin = nums[i];
            }
        }

        // Return sum of first element + two smallest elements
        return score + firstMin + secondMin;
    }
};
