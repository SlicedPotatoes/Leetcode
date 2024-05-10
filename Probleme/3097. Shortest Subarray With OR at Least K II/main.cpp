class Solution
{
  public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        // Si k est 0, n'importe quel sous-tableau satisfait la contrainte
        if (k == 0)
        {
            return 1;
        }

        // Initialisation de la réponse à la valeur maximale possible
        int ans = INT_MAX;

        // Utilisation d'un vecteur de 32 bits pour compter les occurrences de chaque bit
        vector<int> bits(32, 0);

        // Variable pour stocker la valeur actuelle du sous-tableau
        int current = 0;
        int left = -1;

        // Parcourir tous les éléments du vecteur nums
        for (int right = 0; right < nums.size(); right++)
        {
            // Création d'un objet bitset à partir de la valeur actuelle
            bitset<32> currentBits(nums[right]);

            // Mettre à jour le vecteur de bits avec les bits du nombre actuel
            for (int i = 0; i < 32; i++)
            {
                bits[i] += currentBits[i];
            }

            // Mettre à jour la valeur actuelle du sous-tableau en utilisant l'opération OR
            current |= nums[right];

            // Tant que la valeur actuelle du sous-tableau est supérieure ou égale à k
            while (current >= k)
            {
                // Mettre à jour la réponse avec la longueur minimale trouvée
                ans = min(ans, right - left);
                // Déplacer l'indice gauche vers la droite pour réduire la taille du sous-tableau
                left++;
                // Créer un objet bitset à partir du nombre à supprimer
                bitset<32> toDelete = nums[left];

                // Mettre à jour les occurrences des bits et la valeur actuelle
                for (int i = 0; i < 32; i++)
                {
                    if (toDelete[i] == 1)
                    {
                        bits[i]--;
                        // Si le bit devient 0, le supprimer de la valeur actuelle
                        if (bits[i] == 0)
                        {
                            current &= ~(1 << i);
                        }
                    }
                }
            }
        }

        // Si la réponse est toujours la valeur maximale, aucun sous-tableau n'a été trouvé
        return ans == INT_MAX ? -1 : ans;
    }
};