class Solution
{
  public:
    long long maximumImportance(long long n, vector<vector<int>> &roads)
    {
        // Tableau pour stocker le nombre de routes connectées à chaque ville
        vector<int> arr(n, 0);

        // Incrémenter le nombre de routes pour chaque ville connectée
        for (vector<int> &road : roads)
        {
            arr[road[0]]++;
            arr[road[1]]++;
        }

        // Tri du tableau en ordre décroissant pour donner plus de valeur aux villes avec plus de routes
        sort(arr.begin(), arr.end(), [](int &a, int &b) { return a > b; });

        long long ans = 0;

        // Calcul de l'importance totale en assignant les valeurs décroissantes
        for (int &a : arr)
        {
            ans += a * n--; // Multiplier le nombre de routes par l'importance
        }

        return ans;
    }
};