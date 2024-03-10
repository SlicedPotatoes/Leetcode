class Solution
{
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int availableCase = 0;

        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 1)
            {
                continue;
            }
            bool leftAvailable = i - 1 < 0 ? true : flowerbed[i - 1] == 0;
            bool rightAvailable = i + 1 >= flowerbed.size() ? true : flowerbed[i + 1] == 0;

            if (leftAvailable && rightAvailable)
            {
                availableCase++;
                flowerbed[i] = 1;
            }
        }

        return availableCase >= n;
    }
};