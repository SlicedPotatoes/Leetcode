class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        // Vérifie si le vecteur ne contient qu'un seul élément
        if (nums.size() == 1)
        {
            // Dans ce cas, retourne simplement cet élément
            return nums[0];
        }

        // Initialise deux variables pour stocker les gains maximaux possibles
        int a = nums[0];         // Gain maximal précédent
        int b = max(a, nums[1]); // Gain maximal courant

        // Parcourt le reste du vecteur pour calculer les gains maximaux possibles
        for (int i = 2; i < nums.size(); i++)
        {
            // Stocke temporairement le gain maximal entre (le gain précédent + l'élément actuel) et le gain courant
            int temp = max(b, a + nums[i]);
            // Met à jour les variables pour le prochain calcul
            a = b;    // Le gain précédent devient le gain courant
            b = temp; // Le gain courant est mis à jour avec le gain maximal temporaire
        }

        // Retourne le gain maximal obtenu
        return b;
    }
};