class Solution
{
  public:
    int pivotIndex(vector<int> &nums)
    {
        // Vérifier si le vecteur a une seule valeur
        if (nums.size() == 1)
        {
            return 0; // Si oui, il n'y a qu'un seul élément, donc le pivot est à l'index 0
        }

        // Calculer la somme cumulative des éléments du vecteur
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1]; // Ajouter chaque élément au précédent pour obtenir la somme cumulative
        }

        int last = nums[nums.size() - 1]; // Stocker la dernière somme cumulative

        // Vérifier si le premier élément est égal à la dernière somme cumulative
        if (nums[0] == last)
        {
            return 0; // Si oui, le pivot est à l'index 0
        }

        // Parcourir les éléments du vecteur (à l'exception du premier et du dernier élément)
        for (int i = 1; i < nums.size() - 1; i++)
        {
            // Vérifier si la somme cumulative à l'index actuel est égale à la dernière somme cumulative
            if (nums[i] + nums[i - 1] == last)
            {
                return i; // Si oui, le pivot est à cet index
            }
        }

        // Vérifier si l'avant-dernier élément est égal à zéro
        if (nums[nums.size() - 2] == 0)
        {
            return nums.size() - 1; // Si oui, le pivot est à l'index du dernier élément
        }

        return -1; // Si aucun pivot n'est trouvé, retourner -1
    }
};