class Solution
{
  public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // Vecteur pour stocker les duplicatas trouvés
        vector<int> answer;

        // Parcours de chaque élément du vecteur nums
        for (int x : nums)
        {
            // Si l'élément à la position abs(x) - 1 est négatif
            if (nums[abs(x) - 1] < 0)
            {
                // Alors x est un doublon, l'ajouter au vecteur answer
                answer.push_back(abs(x));
            }
            else
            {
                // Marquer l'élément correspondant à x comme vu en le rendant négatif
                nums[abs(x) - 1] *= -1;
            }
        }
        // Retourner le vecteur answer contenant les doublons trouvés
        return answer;
    }
};