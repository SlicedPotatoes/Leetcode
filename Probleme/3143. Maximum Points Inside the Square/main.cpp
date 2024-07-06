class Solution
{
  public:
    int maxPointsInsideSquare(vector<vector<int>> &p, string s)
    {
        vector<pair<int, int>> maxDistanceLabel(26, {INT_MAX, INT_MAX});

        for (int i = 0; i < p.size(); i++)
        {
            int index = s[i] - 'a';
            int dThisPoint = max(abs(p[i][0]), abs(p[i][1]));

            if (maxDistanceLabel[index].first > dThisPoint)
            {
                maxDistanceLabel[index].second = maxDistanceLabel[index].first;
                maxDistanceLabel[index].first = dThisPoint;
            }
            else
            {
                maxDistanceLabel[index].second = min(maxDistanceLabel[index].second, dThisPoint);
            }
        }

        int m = INT_MAX;

        for (int i = 0; i < 26; i++)
        {
            if (maxDistanceLabel[i].second != INT_MAX)
            {
                m = min(m, maxDistanceLabel[i].second);
            }
        }

        int ans = 0;

        for (vector<int> &point : p)
        {
            if (max(abs(point[0]), abs(point[1])) < m)
            {
                ans++;
            }
        }

        return ans;
    }
};