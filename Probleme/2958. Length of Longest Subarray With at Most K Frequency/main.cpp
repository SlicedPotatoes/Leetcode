class Solution
{
  public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        // Dictionnaire pour compter les occurrences des éléments
        unordered_map<int, int> mp;

        // Longueur maximale du sous-tableau avec les contraintes spécifiées
        int ans = 0;

        // Pointeur gauche de la fenêtre glissante
        int left = 0;

        // Parcours de la fenêtre avec le pointeur droit
        for (int right = 0; right < nums.size(); right++)
        {
            // Trouver l'élément actuel dans la map
            auto it = mp.find(nums[right]);

            if (it == mp.end())
            {
                // Si l'élément n'est pas trouvé, l'ajouter avec une occurrence de 1
                it = mp.insert({nums[right], 1}).first;
            }
            else
            {
                // Si l'élément est déjà présent, augmenter son compteur
                it->second++;
            }

            // Réduire la taille de la fenêtre si la condition n'est pas validé
            while (it->second > k)
            {
                mp[nums[left++]]--;
            }

            // Mettre à jour la longueur maximale trouvée
            ans = max(ans, right - left);
        }

        return ans + 1;
    }
};