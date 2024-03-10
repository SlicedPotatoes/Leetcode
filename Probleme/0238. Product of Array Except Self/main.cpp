class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // Création d'un vecteur pour stocker les résultats
        vector<int> output(nums.size());

        // Calcul des produits des éléments précédents (Prefix Product Array) et stockage dans le vecteur de sortie
        output[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            output[i] = output[i - 1] * nums[i];
        }

        // Calcul des produits des éléments suivants (Suffix Product Array)
        int last = 1;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            output[i] = output[i - 1] * last; // Multiplication du produit suffixe avec le produit préfixe
            last *= nums[i];                  // Mise à jour du produit suffixe pour l'élément suivant
        }
        output[0] = last;

        return output;
    }
};