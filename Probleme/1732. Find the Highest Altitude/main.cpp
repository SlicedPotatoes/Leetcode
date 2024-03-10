class Solution
{
  public:
    int largestAltitude(vector<int> &gain)
    {
        // Initialiser une variable pour suivre l'altitude actuelle
        int current = 0;
        // Initialiser une variable pour stocker l'altitude maximale rencontrée
        int m = 0;

        // Parcourir chaque élément du vecteur gain
        for (int g : gain)
        {
            // Ajouter le gain actuel à l'altitude actuelle
            current += g;
            // Mettre à jour l'altitude maximale si l'altitude actuelle est plus grande
            m = max(current, m);
        }

        return m; // Retourner l'altitude maximale rencontrée
    }
};