class Solution
{
  public:
    int search(vector<int> &arr, int target)
    {
        // Initialisation des indices de début et de fin pour la recherche binaire
        int start = 0;
        int end = arr.size() - 1;

        // Recherche binaire itérative
        while (start <= end)
        {
            // Calcul de l'indice médian
            int mid = (start + end) / 2;

            // Vérifier si la valeur cible est égale à la valeur au milieu
            if (arr[mid] == target)
            {
                return mid;
            }

            // Vérifier si la première moitié du tableau est ordonnée
            if (arr[start] <= arr[mid])
            {
                // Vérifier si la valeur cible se trouve dans la première moitié du tableau
                if (arr[start] <= target && arr[mid] > target)
                {
                    // Mettre à jour la fin pour rechercher dans la première moitié
                    end = mid - 1;
                }
                else
                {
                    // Mettre à jour le début pour rechercher dans la deuxième moitié
                    start = mid + 1;
                }
            }
            // Sinon la deuxième moitié du tableau est ordonnée
            else
            {
                // Vérifier si la valeur cible se trouve dans la deuxième moitié du tableau
                if (arr[mid] < target && arr[end] >= target)
                {
                    // Mettre à jour le début pour rechercher dans la deuxième moitié
                    start = mid + 1;
                }
                else
                {
                    // Mettre à jour la fin pour rechercher dans la première moitié
                    end = mid - 1;
                }
            }
        }

        return -1; // La valeur cible n'est pas trouvée dans le tableau
    }
};