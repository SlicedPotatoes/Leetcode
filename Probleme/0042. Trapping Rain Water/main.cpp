class Solution
{
  public:
    int trap(vector<int> &height)
    {
        // Indices pour les côtés gauche et droit du tableau
        int left = 0;
        int right = height.size() - 1;

        // Variables pour stocker la hauteur maximale rencontrée à gauche et à droite
        int maxLeft = 0;
        int maxRight = 0;

        // Variable pour stocker la quantité totale d'eau piégée
        int ans = 0;

        // Boucle pour parcourir le tableau des hauteurs
        while (left <= right)
        {
            // Mettre à jour les hauteurs maximales à gauche et à droite
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            // Si la hauteur maximale à gauche est inférieure ou égale à celle de droite
            if (maxLeft <= maxRight)
            {
                // Ajouter l'eau piégée au-dessus de la barre de gauche
                ans += maxLeft - height[left];
                // Passer à la barre suivante à gauche
                left++;
            }
            else
            {
                // Ajouter l'eau piégée au-dessus de la barre de droite
                ans += maxRight - height[right];
                // Passer à la barre suivante à droite
                right--;
            }
        }

        // Retourner la quantité totale d'eau piégée
        return ans;
    }
};