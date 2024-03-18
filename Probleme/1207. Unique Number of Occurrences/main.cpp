class Solution
{
  public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        // Utilise une unordered_map pour compter le nombre d'occurrences de chaque élément
        unordered_map<int, int> mp;
        // Utilise un unordered_set pour stocker le nombre d'occurrences et vérifier l'unicité
        unordered_set<int> nbOccurences;

        // Compte le nombre d'occurrences de chaque élément du vecteur
        for (int n : arr)
        {
            mp[n]++;
        }

        // Parcourt la map des occurrences
        for (auto &pkv : mp)
        {
            // Vérifie si le nombre d'occurrences est déjà présent dans l'ensemble
            if (nbOccurences.contains(pkv.second))
            {
                // Si c'est le cas, le nombre d'occurrences n'est pas unique, donc retourne false
                return false;
            }
            // Ajoute le nombre d'occurrences dans l'ensemble des occurrences uniques
            nbOccurences.insert(pkv.second);
        }

        // Si aucun nombre d'occurrences n'est rencontré plus d'une fois, retourne true
        return true;
    }
};