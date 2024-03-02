class Solution
{
  public:
    int minOperations(vector<int> &nums, int k)
    {
        int count = 0;
        for (int element : nums)
        {
            if (element < k)
            {
                count++;
            }
        }
        return count;
    }
};