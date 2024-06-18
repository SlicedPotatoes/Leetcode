class Solution
{
  public:
    vector<int> nums = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};

    void backtracking(int n, int currCount, int currI, int hours, int minutes, vector<string> &ans)
    {
        if (currCount == n)
        {
            if (hours < 12 && minutes < 60)
            {
                string r = to_string(hours) + (minutes < 10 ? ":0" : ":") + to_string(minutes);
                ans.push_back(r);
            }
            return;
        }

        for (int i = currI; i < 10; i++)
        {
            if (i < 4)
            {
                backtracking(n, currCount + 1, i + 1, hours + nums[i], minutes, ans);
            }
            else
            {
                backtracking(n, currCount + 1, i + 1, hours, minutes + nums[i], ans);
            }
        }
    }

    vector<string> readBinaryWatch(int turnedOn)
    {
        if (turnedOn >= 9)
        {
            return {};
        }

        vector<string> ans;

        backtracking(turnedOn, 0, 0, 0, 0, ans);

        return ans;
    }
};