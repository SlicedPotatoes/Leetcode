class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0; // Index pour parcourir le vecteur
        int j = 0; // Index pour trouver le prochain élément non nul à échanger

        // Parcours du vecteur jusqu'à ce que l'un des indices atteigne la fin du vecteur
        while (i < nums.size() && j < nums.size())
        {
            // Si l'élément actuel est zéro
            if (nums[i] == 0)
            {
                // Trouver le prochain élément non nul à partir de l'indice j
                while (j < nums.size() && nums[j] == 0)
                {
                    j++;
                }
                // Si j pointe toujours vers un élément valide, effectuer l'échange
                if (j < nums.size())
                {
                    swap(nums[i], nums[j]);
                }
            }
            // Avancer les deux indices pour continuer à parcourir le vecteur
            i++;
            j++;
        }
    }
};