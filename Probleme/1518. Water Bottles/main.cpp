class Solution
{
  public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = 0; // Total des bouteilles bues

        // Tant qu'il y a assez de bouteilles pour les échanger contre de nouvelles
        while (numBottles >= numExchange)
        {
            int r = numBottles % numExchange; // Bouteilles restantes après échange (pleine)
            ans += numBottles - r;            // Ajouter les bouteilles bues

            numBottles /= numExchange; // Mettre à jour le nombre de bouteilles après échange
            numBottles += r;           // Ajouter les bouteilles restantes pour le prochain échange
        }

        return ans + numBottles; // Retourner le nombre total de bouteilles bues
    }
};