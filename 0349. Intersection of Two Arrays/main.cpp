class Solution
{
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // On détermine quelle est la plus petite et la plus grande des deux listes
        vector<int> &minArr = nums1.size() > nums2.size() ? nums2 : nums1;
        vector<int> &maxArr = nums1.size() > nums2.size() ? nums1 : nums2;

        // On utilise un ensemble non trié pour stocker les éléments de la liste la plus petite
        unordered_set<int> seen;

        // Vecteur de sortie pour stocker les éléments communs
        vector<int> output;

        // On insère tous les éléments de la liste la plus petite dans l'ensemble
        for (int element : minArr)
        {
            seen.insert(element);
        }

        // On parcourt la liste la plus grande pour voir quels éléments sont communs
        for (int element : maxArr)
        {
            // Si l'élément courant est présent dans l'ensemble, il est commun
            if (seen.count(element) > 0)
            {
                // On l'ajoute au vecteur de sortie et on le supprime de l'ensemble pour éviter les doublons
                output.push_back(element);
                seen.erase(element);
            }
        }

        return output; // Retourne le vecteur contenant les éléments communs
    }
};