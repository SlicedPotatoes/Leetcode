class Solution
{
  public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        long long ans = nums.size(); // Initialisation de la réponse avec la taille du vecteur nums
        int left = 0;                // Initialisation de l'indice du début du sous-tableau alternant actuel

        for (int i = 1; i < nums.size(); i++)
        {
            // Vérifier si l'élément actuel est différent de l'élément précédent
            if (nums[i - 1] != nums[i])
            {
                // Ajouter la longueur du sous-tableau alternant à la réponse
                ans += i - left;
            }
            else
            {
                // Mettre à jour l'indice du début du sous-tableau alternant
                left = i;
            }
        }

        // Renvoyer le nombre total de sous-tableaux alternants
        return ans;
    }
};