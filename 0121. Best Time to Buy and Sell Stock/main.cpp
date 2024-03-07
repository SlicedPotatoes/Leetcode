class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;      // Initialiser le profit maximum à 0
        int minValue = INT_MAX; // Initialiser la valeur minimale à la plus grande valeur possible

        for (int i = 0; i < prices.size(); i++)
        {
            minValue = min(prices[i], minValue);              // Mettre à jour la valeur minimale jusqu'à présent
            maxProfit = max(prices[i] - minValue, maxProfit); // Calculer le profit maximum possible jusqu'à présent
        }

        return maxProfit; // Retourner le profit maximum
    }
};