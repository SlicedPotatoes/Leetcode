class Solution
{
  public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        // Trie le vecteur de bonheur par ordre décroissant.
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;

        // Parcourt les k premières valeurs du vecteur trié.
        for (int i = 0; i < k; i++)
        {
            // Ajuste la valeur en soustrayant l'indice.
            int value = happiness[i] - i;

            // Si la valeur ajustée est négative ou nulle, arrêter le processus.
            if (value <= 0)
            {
                break;
            }

            // Ajoute la valeur ajustée à la somme totale.
            ans += value;
        }

        return ans;
    }
};