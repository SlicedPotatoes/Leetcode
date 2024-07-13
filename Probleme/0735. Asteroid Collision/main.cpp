class Solution
{
  public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;

        // Parcourir tous les astéroïdes dans la liste
        for (int n : asteroids)
        {
            // Si l'astéroïde se déplace vers la droite, on l'ajoute au résultat
            if (n > 0)
            {
                ans.push_back(n);
            }
            // Si l'astéroïde se déplace vers la gauche
            else
            {
                n = -n; // Récupérer la taille de l'astéroïde

                // Tant que le dernier astéroïde dans 'ans' se déplace vers la droite et est plus petit que l'actuel
                // astéroïde se déplaçant vers la gauche
                while (ans.size() >= 1 && ans.back() > 0 && ans.back() < n)
                {
                    ans.pop_back(); // On supprime le dernier astéroïde car il est détruit
                }

                // Si 'ans' est vide ou si le dernier astéroïde se déplace vers la gauche, on ajoute l'astéroïde actuel
                // se déplaçant vers la gauche
                if (ans.empty() || ans.back() < 0)
                {
                    ans.push_back(-n);
                }
                // Si les deux astéroïdes sont de même taille mais opposés, ils explosent
                else if (ans.back() == n)
                {
                    ans.pop_back();
                }
                // Si ans.back() > n, le dernier astéroïde dans 'ans' détruit l'actuel astéroïde donc on n'a rien à
                // faire dans ce cas
            }
        }

        return ans;
    }
};