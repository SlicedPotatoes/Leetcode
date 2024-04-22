class Solution
{
  public:
    // Fonction utilitaire pour obtenir l'index d'une chaîne de 4 chiffres
    int getIndex(string &s)
    {
        int index = 0;
        for (int i = 0; i < 4; i++)
        {
            index *= 10;
            index += (s[i]) - '0';
        }
        return index;
    }

    // Fonction principale pour résoudre le problème de verrouillage
    int openLock(vector<string> &deadends, string target)
    {
        // Initialisation d'un vecteur booléen pour marquer les combinaisons déjà visitées
        vector<bool> visited(10000, false);

        // Marquer les combinaisons interdites comme visitées
        for (string &s : deadends)
        {
            visited[getIndex(s)] = true;
        }

        // Vérifier si la combinaison initiale est interdite
        if (visited[0])
        {
            // Retourner -1 si la combinaison initiale est interdite
            return -1;
        }

        // Marquer la combinaison initiale comme visitée
        visited[0] = true;

        queue<string> q;
        // Ajouter la combinaison initiale à la file d'attente
        q.push("0000");

        // Initialiser la réponse
        int ans = 0;

        // Parcourir toutes les combinaisons possibles jusqu'à ce que la cible soit atteinte
        while (!q.empty())
        {
            int size = q.size();
            for (int _ = 0; _ < size; _++)
            {
                string current = q.front();
                q.pop();

                if (current == target)
                {
                    return ans; // Retourner le nombre de mouvements nécessaires si la cible est atteinte
                }

                // Générer les combinaisons voisines en incrémentant et en décrémentant chaque chiffre
                for (int i = 0; i < 4; i++)
                {
                    string next = current;
                    string prev = current;

                    next[i] = (current[i] + 1); // Incrémenter le chiffre actuel
                    prev[i] = current[i] - 1;   // Décrémenter le chiffre actuel

                    // Gérer les dépassements de limite en ajustant les chiffres de 0 à 9
                    if (next[i] > '9')
                    {
                        next[i] = '0';
                    }
                    else if (prev[i] < '0')
                    {
                        prev[i] = '9';
                    }

                    // Obtenir les index des combinaisons voisines
                    int nextIndex = getIndex(next);
                    int prevIndex = getIndex(prev);

                    // Ajouter les combinaisons voisines à la file d'attente si elles ne sont pas encore visitées
                    if (!visited[nextIndex])
                    {
                        q.push(next);
                        visited[nextIndex] = true;
                    }
                    if (!visited[prevIndex])
                    {
                        q.push(prev);
                        visited[prevIndex] = true;
                    }
                }
            }
            // Incrémenter le nombre de mouvements après avoir exploré toutes les combinaisons à une distance donnée
            ans++;
        }

        // Retourner -1 si la cible n'est pas atteignable
        return -1;
    }
};