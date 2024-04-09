class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        // Initialiser la taille de la séquence filtrée à 1
        int size = 1;

        // Initialiser le nombre d'occurrences de l'élément actuel à 1
        int current = nums[0];
        int count = 1;

        // Parcourir les éléments restants du vecteur
        for (int i = 1; i < nums.size(); i++)
        {
            // Si l'élément actuel est différent de l'élément précédent ou s'il n'a été rencontré qu'une seule fois
            if (count == 1 || nums[i] != current)
            {
                // Ajouter l'élément courant à la séquence filtrée
                nums[size] = nums[i];
                size++;

                // Si l'élément actuel est identique à l'élément précédent, augmenter le compteur
                if (nums[i] == current)
                {
                    count++;
                }
                // Sinon, mettre à jour l'élément actuel et réinitialiser le compteur
                else
                {
                    current = nums[i];
                    count = 1;
                }
            }
        }

        // Retourner la taille de la séquence filtrée
        return size;
    }
};