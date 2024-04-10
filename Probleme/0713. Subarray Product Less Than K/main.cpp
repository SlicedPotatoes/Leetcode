class Solution
{
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        // Initialise le produit partiel du sous-tableau
        int prefix = 1;
        // Initialise le nombre de sous-tableaux
        int count = 0;

        // Indice gauche du sous-tableau
        int left = -1;

        // Parcours le vecteur
        for (int right = 0; right < nums.size(); right++)
        {
            // Met à jour le produit partiel
            prefix *= nums[right];

            // Tant que le produit partiel est supérieur ou égal à k et l'indice gauche est inférieur ou égal à l'indice
            // droit
            while (prefix >= k && left < right)
            {
                // Avance l'indice gauche pour réduire le sous-tableau
                left++;
                // Réduit le produit partiel en retirant l'élément le plus à gauche
                prefix /= nums[left];
            }

            // Ajoute le nombre de sous-tableaux valides
            count += right - left;
        }

        // Retourne le nombre total de sous-tableaux
        return count;
    }
};