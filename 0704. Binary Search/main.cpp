class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;             // Indice de début de la plage de recherche
        int end = nums.size() - 1; // Indice de fin de la plage de recherche

        // Boucle de recherche tant que la plage de recherche est valide
        while (start <= end)
        {
            int mid = (start + end) / 2; // Calcul de l'indice du milieu de la plage de recherche

            // Si l'élément au milieu est supérieur à la cible
            if (nums[mid] > target)
            {
                end = mid - 1; // Réduire la plage de recherche à la moitié gauche
            }
            // Si l'élément au milieu est inférieur à la cible
            else if (nums[mid] < target)
            {
                start = mid + 1; // Réduire la plage de recherche à la moitié droite
            }
            // Si l'élément au milieu est égal à la cible, on a trouvé la cible
            else
            {
                return mid; // Retourner l'indice où la cible est trouvée
            }
        }

        return -1; // Retourner -1 si la cible n'est pas trouvée dans le vecteur
    }
};