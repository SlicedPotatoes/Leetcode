class Solution
{
  public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        // Initialisation des indices pour parcourir les deux vecteurs
        int i = 0;
        int j = 0;

        // Parcours des deux vecteurs jusqu'à ce que l'un d'eux soit épuisé
        while (i < nums1.size() && j < nums2.size())
        {
            // Si les éléments actuels sont égaux, nous avons trouvé un élément commun
            if (nums1[i] == nums2[j])
            {
                // Retourne l'élément commun trouvé
                return nums1[i];
            }

            // Si l'élément dans nums1 est plus grand, avançons dans nums2
            if (nums1[i] > nums2[j])
            {
                j++;
            }
            // Sinon, avançons dans nums1
            else
            {
                i++;
            }
        }

        // Si nous avons parcouru les deux vecteurs sans trouver d'élément commun, retourne -1
        return -1;
    }
};