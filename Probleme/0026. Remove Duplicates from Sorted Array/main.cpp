class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        // Initialisation de la taille du tableau résultant
        int size = 0;

        // Parcours de la liste des éléments
        for (int i = 0; i < nums.size(); i++)
        {
            // Si l'élément actuel est différent du dernier élément du nouveau tableau
            if (nums[i] != nums[size])
            {
                // On incrémente la taille
                size++;
                // Et ajoute cet nouvel élément à la fin du nouveau tableau
                nums[size] = nums[i];
            }
        }

        // On retourne la nouvelle taille du tableau
        return size + 1;
    }
};