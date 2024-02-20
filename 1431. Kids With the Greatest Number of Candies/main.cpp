class Solution
{
  public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int biggest = 0;
        vector<bool> result(candies.size());

        for (int c : candies)
        {
            biggest = max(c, biggest);
        }

        for (int indexKids = 0; indexKids < candies.size(); indexKids++)
        {
            if (candies[indexKids] + extraCandies >= biggest)
            {
                result[indexKids] = true;
            }
        }

        return result;
    }
};