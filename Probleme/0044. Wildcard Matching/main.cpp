class Solution
{
  public:
    bool isMatch(string &s, string &p)
    {
        // Initialisation d'une matrice de dimensions (p.size() + 1) x (s.size() + 1) avec des valeurs booléennes
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));

        // Initialisation de dp[0][0] à true, car les chaînes vides correspondent
        dp[0][0] = true;

        // Remplissage de la première colonne de la matrice dp
        for (int i = 0; i < p.size() && dp[i][0]; i++)
        {
            // Si le caractère actuel dans le motif est une étoile '*' et que dp[i][0] est vrai, alors dp[i+1][0] est
            // également vrai
            if (p[i] == '*')
            {
                dp[i + 1][0] = dp[i][0];
            }
            if (!dp[i][0])
            {
                break;
            }
        }

        // Remplissage du reste de la matrice dp
        for (int i = 1; i <= p.size(); i++)
        {
            for (int j = 1; j <= s.size(); j++)
            {
                // Si les caractères correspondent ou que le motif contient un caractère générique '?'
                if (p[i - 1] == '?' || p[i - 1] == s[j - 1])
                {
                    // Dépend de si les sous-chaînes sans le caractère actuel correspondent également
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Si le caractère actuel dans le motif est une étoile '*'
                else if (p[i - 1] == '*')
                {
                    // Soit ignorer le '*' (dp[i - 1][j]), soit ignorer le caractère actuel de s correspondant dans s
                    // (dp[i][j - s])
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[p.size()][s.size()];
    }
};