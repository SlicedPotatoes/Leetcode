class Solution
{
  public:
    int minimumDeletions(string s)
    {
        int ans = 0;    // Initialiser le nombre minimum de suppressions nécessaires
        int countB = 0; // Compteur pour le nombre de 'b' rencontrés

        // Parcourir chaque caractère de la chaîne
        for (int i = 0; i < s.size(); i++)
        {
            // Incrémenter le compteur de 'b' lorsque le caractère est 'b'
            if (s[i] == 'b')
            {
                countB++;
            }
            // Si le caractère est 'a', calculer le minimum entre le nombre actuel de suppressions et le nombre de 'b'
            // rencontrés jusqu'à présent
            else
            {
                ans = min(ans + 1, countB);
            }
        }

        // Retourner le nombre minimum de suppressions nécessaires
        return ans;
    }
};