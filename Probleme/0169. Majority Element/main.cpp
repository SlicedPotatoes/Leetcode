class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        // Initialisation de la réponse avec le premier élément du vecteur
        int ans = nums[0];
        // Initialisation du compteur à 1 car le premier élément est déjà considéré comme rencontré une fois
        int count = 1;

        // Parcours du vecteur à partir du deuxième élément
        for (int i = 1; i < nums.size(); i++)
        {
            // Si l'élément actuel est égal à la réponse actuelle, on incrémente le compteur
            if (nums[i] == ans)
            {
                count++;
            }
            // Si le compteur est nul, on remplace la réponse par l'élément actuel et on réinitialise le compteur à 1
            else if (count == 0)
            {
                ans = nums[i];
                count = 1;
            }
            // Si l'élément actuel est différent de la réponse et que le compteur n'est pas nul, on décrémente le
            // compteur
            else
            {
                count--;
            }
        }

        // Une fois le parcours terminé, la variable 'ans' contient l'élément majoritaire
        return ans;
    }
};