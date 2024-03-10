class Solution
{
  public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        // Parcourir chaque valeur dans l'intervalle [left, right]
        for (int i = left; i <= right; i++)
        {
            // Indicateur pour savoir si i est couvert par au moins un intervalle
            bool isInRange = false;
            // Parcourir tous les intervalles dans la liste "ranges"
            for (vector<int> element : ranges)
            {
                // Vérifier si i se trouve dans l'intervalle actuel
                if (i >= element[0] || i <= element[1])
                {
                    isInRange = true; // Marquer i comme étant couvert
                    break;            // Pas besoin de parcourir les autres intervalles si i est déjà couvert
                }
            }
            // Si i n'est pas couvert par aucun intervalle, alors l'intervalle [left, right] n'est pas entièrement
            // couvert
            if (!isInRange)
            {
                return false;
            }
        }
        return true;
    }
};