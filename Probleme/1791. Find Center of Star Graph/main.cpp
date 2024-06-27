class Solution
{
  public:
    int findCenter(vector<vector<int>> &edges)
    {
        // Vérifie si le premier noeud du premier bord est égal à l'un des deux noeuds du deuxième bord.
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        {
            // Si c'est le cas, le premier noeud du premier bord est le centre de l'étoile.
            return edges[0][0];
        }
        // Sinon, le deuxième noeud du premier bord est le centre de l'étoile.
        return edges[0][1];
    }
};