class Solution
{
  public:
    vector<int> countBits(int n)
    {
        // Initialisation du vecteur pour stocker le nombre de bits
        vector<int> dp(n + 1);

        // Cas particulier : si n est 0
        // aucun bit n'est défini, donc le vecteur est simplement renvoyé
        if (n == 0)
        {
            return dp;
        }

        // Initialisation : le nombre de bits pour 1 est 1
        dp[1] = 1;

        // Variable c pour suivre le nombre de bits par groupe
        int c = 1;

        // Boucle principale pour remplir dp
        for (int i = 2; i <= n;)
        {
            // Copie des bits du groupe précédent
            for (int currentC = 0; currentC < c && i <= n; currentC++, i++)
            {
                dp[i] = dp[i - c];
            }
            // Ajout d'un bit supplémentaire au groupe précédent
            for (int currentC = 0; currentC < c && i <= n; currentC++, i++)
            {
                dp[i] = dp[i - c] + 1;
            }
            c *= 2; // Double le nombre de bits dans le groupe suivant
        }

        return dp;
    }
};