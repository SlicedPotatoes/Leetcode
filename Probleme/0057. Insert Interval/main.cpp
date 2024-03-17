class Solution
{
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int i = 0;

        // Parcourir les intervalles existants jusqu'à ce qu'on atteigne un intervalle dont la fin est avant le début du
        // nouvel intervalle
        while (i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        // Si tous les intervalles sont parcourus, le nouvel intervalle ce trouve a la fin
        if (i >= intervals.size())
        {
            ans.push_back(newInterval);
            return ans;
        }

        // Déterminer le début et la fin de l'intervalle fusionné
        int startInterval = min(newInterval[0], intervals[i][0]);
        int endInterval = newInterval[1];

        // Fusionner les intervalles qui se chevauchent
        while (i < intervals.size() && newInterval[1] >= intervals[i][0])
        {
            endInterval = max(endInterval, intervals[i][1]);
            i++;
        }

        // Ajouter l'intervalle fusionné à la liste des intervalles
        ans.push_back({startInterval, endInterval});

        // Ajouter les intervalles restants qui ne se chevauchent pas
        while (i < intervals.size())
        {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};