class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        // Initialisation de la réponse maximale
        int ans = 0;

        // Initialisation des indices avec les extrémités.
        int right = height.size() - 1;
        int left = 0;

        // Tant que l'indice gauche est inférieur à l'indice droit
        while (left < right)
        {
            // Initialisation de la quantité d'eau actuelle
            int currentWater = 0;

            // Si la hauteur à gauche est supérieure à celle de droite
            if (height[left] > height[right])
            {
                // Calcul de la quantité d'eau actuelle
                currentWater = height[right] * (right - left);
                // Décrémentation de l'indice droit
                right--;
            }
            // Sinon (la hauteur à gauche est inférieure ou égale à celle de droite)
            else
            {
                // Calcul de la quantité d'eau actuelle
                currentWater = height[left] * (right - left);
                // Incrémentation de l'indice gauche
                left++;
            }

            // Mise à jour de la réponse maximale
            ans = max(ans, currentWater);
        }

        // Retour de la réponse maximale
        return ans;
    }
};