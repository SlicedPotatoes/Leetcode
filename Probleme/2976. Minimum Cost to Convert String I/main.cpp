class Solution
{
  public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed,
                          vector<int> &cost)
    {
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));

        // Initialiser la distance de chaque lettre à elle-même à 0
        for (int i = 0; i < 26; i++)
        {
            dist[i][i] = 0;
        }

        // Mettre à jour les distances directes selon les transformations données
        for (int i = 0; i < cost.size(); i++)
        {
            int source = original[i] - 'a';
            int dest = changed[i] - 'a';
            int c = cost[i];

            dist[source][dest] = min(dist[source][dest], (long long)c);
        }

        // Appliquer l'algorithme de Floyd-Warshall pour trouver les plus courts chemins entre toutes les paires de
        // nœuds
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;

        // Calculer le coût total pour transformer chaque caractère de `source` en `target`
        for (int i = 0; i < source.size(); i++)
        {
            int s = source[i] - 'a';
            int d = target[i] - 'a';

            int result = dist[s][d];

            // Si une transformation est impossible, retourner -1
            if (result == INT_MAX)
            {
                return -1;
            }

            ans += result;
        }

        return ans;
    }
};