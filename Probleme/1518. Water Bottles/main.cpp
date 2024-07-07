class Solution
{
  public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = 0;

        while (numBottles >= numExchange)
        {
            int r = numBottles % numExchange;
            ans += numBottles - r;

            numBottles /= numExchange;
            numBottles += r;
        }

        return ans + numBottles;
    }
};