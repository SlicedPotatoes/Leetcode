class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temps;  // Vecteur temporaire pour stocker les éléments mal placés de nums1
        int indexNums2 = 0; // Index actuel de nums2
        int indexTemps = 0; // Index actuel de temps

        // Parcours de chaque élément de nums1
        for (int indexNums1 = 0; indexNums1 < n + m; indexNums1++)
        {
            // Variable pour stocker le plus petit élément entre nums2[indexNums2] et temps[indexTemps]
            int smaller = INT_MAX;
            // true si la valeur la plus petite est dans temps, sinon false si elle est dans nums2
            bool isInTemp = false;

            // Récupération de la valeur de nums2[indexNums2] si l'index est inférieur à sa taille
            if (indexNums2 < nums2.size())
            {
                smaller = nums2[indexNums2];
            }
            // Récupération de la valeur de temps[indexTemps] si elle est inférieure à smaller
            // et que indexTemps est inférieur à temps.size()
            if (indexTemps < temps.size() && temps[indexTemps] < smaller)
            {
                smaller = temps[indexTemps];
                isInTemp = true;
            }

            // Si on est avant les valeurs non initialisées de nums1[] (les zéros)
            // et que la valeur de nums1[indexNums1] est supérieure à smaller
            // On ajoute la valeur de nums1[indexNums1] au vecteur temporaire
            if (indexNums1 < m && nums1[indexNums1] > smaller)
            {
                temps.push_back(nums1[indexNums1]);
            }
            // Si on est dans la partie des valeurs non initialisées de nums1[]
            // ou que la valeur de nums1[indexNums1] est supérieure à smaller
            // On attribue à nums1[indexNums1] la valeur de smaller
            // et on incrémente l'index de provenance de smaller
            if (indexNums1 >= m || nums1[indexNums1] > smaller)
            {
                nums1[indexNums1] = smaller;
                if (isInTemp)
                {
                    indexTemps++;
                }
                else
                {
                    indexNums2++;
                }
            }
        }
    }
};