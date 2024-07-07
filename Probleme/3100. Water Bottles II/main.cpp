class Solution
{
  public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int ans = 0; // Variable pour stocker le nombre total de bouteilles bues

        // Boucle tant que le nombre de bouteilles actuelles est suffisant pour un échange
        while (numBottles >= numExchange)
        {
            // Ajouter le nombre de bouteilles échangées à la somme totale des bouteilles bues
            ans += numExchange;
            // Réduire le nombre de bouteilles actuelles du nombre échangé
            numBottles -= numExchange;
            // Ajouter une nouvelle bouteille obtenue par échange
            numBottles++;
            // Incrémenter le nombre de bouteilles nécessaires pour le prochain échange
            numExchange++;
        }

        // Retourner le nombre de bouteilles bues
        return ans + numBottles;
    }
};