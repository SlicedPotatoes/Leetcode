class Solution
{
  public:
    int minStartValue(vector<int> &nums)
    {
        int sum = 0; // Initialise la somme des éléments du vecteur
        int min = 0; // Initialise la valeur minimale rencontrée

        // Parcourt tous les éléments du vecteur
        for (int n : nums)
        {
            sum += n; // Ajoute l'élément actuel à la somme
            // Vérifie si la somme actuelle est inférieure à la valeur minimale rencontrée
            if (sum < min)
            {
                min = sum; // Met à jour la valeur minimale
            }
        }

        return 1 - min; // Retourne startValue
    }
};