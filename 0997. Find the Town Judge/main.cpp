struct Node
{
    int trustedOf = 1;
    int trusted = 0;
};
class Solution
{
  public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<Node> p(n + 1);

        for (vector<int> &pair : trust)
        {
            p[pair[0]].trusted++;
            p[pair[1]].trustedOf++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (p[i].trusted == 0 && p[i].trustedOf == n)
            {
                return i;
            }
        }
        return -1;
    }
};