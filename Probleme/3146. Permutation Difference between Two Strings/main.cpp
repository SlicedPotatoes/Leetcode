class Solution
{
  public:
    int findPermutationDifference(string &s, string &t)
    {
        vector<int> arr(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a'] = i;
        }

        int ans = 0;

        for (int i = 0; i < t.size(); i++)
        {
            ans += abs(i - arr[t[i] - 'a']);
        }

        return ans;
    }
};