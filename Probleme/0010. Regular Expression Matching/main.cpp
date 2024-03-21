class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        // Création d'une matrice pour stocker les résultats des comparaisons entre les chaînes s et p
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        // Initialisation de dp[0][0] à true, car deux chaînes vides correspondent
        dp[0][0] = true;

        // Traitement pour les cas spéciaux de '*'
        for (int j = 1; j <= p.size(); j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Parcours de chaque caractère de la chaîne s
        for (int i = 1; i <= s.size(); i++)
        {
            // Parcours de chaque caractère de la chaîne p
            for (int j = 1; j <= p.size(); j++)
            {
                if (p[j - 1] == '*')
                {
                    // Si le caractère actuel est '*', il peut correspondre à un motif vide (0 occurrence)
                    // ou à plusieurs occurrences, donc nous vérifions ces deux cas
                    dp[i][j] = (dp[i][j - 2]) || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else
                {
                    // Si le caractère actuel n'est pas '*', nous vérifions simplement s'il correspond à p
                    // ou si le caractère de p est un '.' (qui correspond à n'importe quel caractère)
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};