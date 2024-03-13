class Solution
{
  public:
    int maxOperations(vector<int> &nums, int k)
    {
        // Trie le vecteur pour faciliter la recherche des paires
        sort(nums.begin(), nums.end());

        // Initialise deux indices : i pour le début et j pour la fin du vecteur
        int i = 0;
        int j = nums.size() - 1;

        // Initialise le compteur d'opérations
        int count = 0;

        // Parcourt le vecteur jusqu'à ce que i atteigne ou dépasse j
        while (i < j)
        {
            // Calcule la somme des éléments actuellement pointés par les indices i et j
            int sum = nums[i] + nums[j];

            // Si la somme est égale à k, on a trouvé une paire, donc on incrémente le compteur et déplace les indices
            if (sum == k)
            {
                count++;
                i++;
                j--;
            }
            // Si la somme est supérieure à k, cela signifie que la valeur à j est trop grande, donc on décrémente j
            else if (sum > k)
            {
                j--;
            }
            // Sinon, la somme est inférieure à k, donc la valeur à i est trop petite, donc on incrémente i
            else
            {
                i++;
            }
        }

        // Retourne le nombre total d'opérations trouvées
        return count;
    }
};