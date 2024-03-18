class Solution
{
  public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        // Initialiser le vecteur réponse avec deux vecteurs vides
        vector<vector<int>> answer = {{}, {}};

        // Créer des ensembles non ordonnés à partir des vecteurs pour une recherche plus efficace
        unordered_set<int> _nums1(nums1.begin(), nums1.end());
        unordered_set<int> _nums2(nums2.begin(), nums2.end());

        // Parcourir tous les éléments de _nums1
        for (auto n : _nums1)
        {
            // Vérifier si l'élément n'est pas présent dans _nums2
            if (!_nums2.contains(n))
            {
                // Si l'élément est unique à nums1, l'ajouter au premier vecteur de la réponse
                answer[0].push_back(n);
            }
        }
        // Parcourir tous les éléments de _nums2
        for (auto n : _nums2)
        {
            // Vérifier si l'élément n'est pas présent dans _nums1
            if (!_nums1.contains(n))
            {
                // Si l'élément est unique à nums2, l'ajouter au deuxième vecteur de la réponse
                answer[1].push_back(n);
            }
        }

        // Retourner les vecteurs contenant les différences
        return answer;
    }
};