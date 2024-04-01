class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Tri des intervalles selon le début de chaque intervalle
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        // Vector qui va contenir les intervalles fusionnés
        vector<vector<int>> ans;

        int currentStart = intervals[0][0]; // Début de l'intervalle actuel
        int currentEnd = intervals[0][1];   // Fin de l'intervalle actuel

        // Parcourir tous les intervalles
        for (vector<int> &i : intervals)
        {
            // Si les intervalles se chevauchent
            if (currentEnd >= i[0])
            {
                // Fusionner les intervalles en mettant à jour la fin de l'intervalle actuel
                currentEnd = max(currentEnd, i[1]);
            }
            else
            {
                // Si les intervalles ne se chevauchent pas, ajouter l'intervalle actuel à la réponse et mettre à jour
                // le début et la fin de l'intervalle actuel
                ans.push_back({currentStart, currentEnd});
                currentStart = i[0];
                currentEnd = i[1];
            }
        }
        // Ajouter le dernier intervalle fusionné
        ans.push_back({currentStart, currentEnd});

        // Retourner les intervalles fusionnés
        return ans;
    }
};