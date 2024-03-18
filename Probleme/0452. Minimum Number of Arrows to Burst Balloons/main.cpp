struct customSort
{
    // Opérateur de comparaison pour trier les vecteurs en fonction de leur première valeur
    inline bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0] > b[0];
    }
};

class Solution
{
  public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // Trie les intervalles
        sort(points.begin(), points.end(), customSort());

        // Compteur pour le nombre de flèches nécessaires pour percer les ballons
        int count = 0;

        for (int i = 0; i < points.size();)
        {
            int start = points[i][0]; // Début de l'intervalle actuel
            int end = points[i][1];   // Début de l'intervalle actuel
            i++;

            // Parcourt les intervalles qui se chevauchent
            while (i < points.size() && !(points[i][1] < start || end < points[i][0]))
            {
                start = max(points[i][0], start); // Mise à jour du début de l'intervalle factice
                end = min(points[i][1], end);     // Mise à jour de la fin de l'intervalle factice
                i++;
            }
            count++; // Incrémente le compteur pour chaque intervalle qui n'est pas couvert par les flèches précédentes
        }

        return count; // Retourne le nombre minimum de flèches nécessaires pour percer tous les ballons
    }
};