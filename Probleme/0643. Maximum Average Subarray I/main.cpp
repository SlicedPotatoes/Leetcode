class Solution
{
  public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = 0;
        // Calcul de la somme des premiers k éléments
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        // Initialisation de la somme maximale avec la somme des k premiers éléments
        int maxAvg = sum;

        // Parcours des éléments à partir de l'indice k
        for (int i = k; i < nums.size(); i++)
        {
            // Ajout du nouvel élément et soustraction de l'élément en début de fenêtre
            sum += nums[i] - nums[i - k];
            // Mise à jour de maxAvg si la somme actuelle est plus grande
            maxAvg = max(sum, maxAvg);
        }

        // Retourne la moyenne maximale trouvée
        return ((double)maxAvg) / k;
    }
};