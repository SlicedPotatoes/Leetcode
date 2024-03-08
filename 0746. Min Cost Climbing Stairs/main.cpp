class Solution
{
  public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int a = cost[0]; // Coût pour atteindre l'étape 1
        int b = cost[1]; // Coût pour atteindre l'étape 2

        for (int i = 2; i < cost.size(); i++)
        {
            swap(a, b);              // Échange des valeurs pour simuler le déplacement vers l'étape suivante
            b = min(a, b) + cost[i]; // Calcul du coût minimum pour atteindre l'étape actuelle
        }

        return min(a, b); // Retourne le coût minimum pour atteindre la dernière étape
    }
};