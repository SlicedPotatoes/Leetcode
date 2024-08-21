class Solution
{
  public:
    int minimumPushes(string word)
    {
        vector<int> count(26, 0); // Tableau pour compter les occurrences de chaque lettre

        // Compter les occurrences de chaque lettre dans le mot
        for (char c : word)
        {
            count[c - 'a']++;
        }

        // Trier les comptes par ordre décroissant
        sort(count.begin(), count.end(), greater<int>());

        // Variable pour stocker le résultat final
        int ans = 0;

        // Calculer le nombre de pressions nécessaires
        for (int i = 0; i < 26 && count[i] > 0; i++)
        {
            // Les 8 premières lettres nécessitent 1 pression, les 8 suivantes 2 pressions, etc.
            ans += count[i] * ((i / 8) + 1);
        }

        return ans;
    }
};