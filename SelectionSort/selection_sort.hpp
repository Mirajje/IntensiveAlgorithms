class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        int index = 0;

        while (index < nums.size())
        {
            int elem = index;
            int min = index;
            while (elem < nums.size())
            {
                if (nums[elem] < nums[min])
                    min = elem;

                ++elem;
            }

            std::swap(nums[index], nums[min]);
            ++index;
        }

        return nums;
    }
};
