class Solution
{
  public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<int> indexs(names.size()); // Vecteur pour stocker les indices des personnes

        // Initialiser le vecteur d'indices avec les valeurs 0 à names.size() - 1
        for (int i = 0; i < names.size(); i++)
        {
            indexs[i] = i;
        }

        // Tri des indices selon les hauteurs en ordre décroissant
        sort(indexs.begin(), indexs.end(), [&heights](int a, int b) { return heights[a] > heights[b]; });

        // Vecteur pour stocker les noms triés
        vector<string> ans;

        // Ajouter les noms dans l'ordre des indices triés
        for (int n : indexs)
        {
            ans.push_back(names[n]);
        }

        // Retourner le vecteur des noms triés
        return ans;
    }
};