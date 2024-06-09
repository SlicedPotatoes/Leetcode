class Solution
{
  public:
    // Fonction pour construire une ligne justifiée
    string buildLine(vector<string *> &curr, int currSize, int maxWidth)
    {
        string output = "";

        currSize -= curr.size() - 1;              // Taille totale des mots sans les espaces entre eux
        int spaceNeeded = curr.size() - 1;        // Nombre d'espaces nécessaires
        int spaceAvailable = maxWidth - currSize; // Espaces disponibles à distribuer
        double spaceSize = ceil(spaceAvailable / (double)spaceNeeded); // Taille des espaces calculés

        // Parcourt chaque mot de la ligne actuelle
        for (string *s : curr)
        {
            {
                output += (*s); // Ajoute le mot à la ligne

                // Ajoute des espaces après le mot, sauf après le dernier mot
                for (int i = 0; i < spaceSize && spaceAvailable != 0; i++)
                {
                    output += ' ';
                    spaceAvailable--;
                }
                spaceNeeded--;

                // Recalcule la taille des espaces restants à distribuer
                spaceSize = ceil(spaceAvailable / (double)spaceNeeded); // Recalcule la taille des espaces restants
            }

            return output; // Retourne la ligne justifiée
        }

        // Fonction pour construire la dernière ligne (non justifiée à droite)
        string buildLast(vector<string *> & curr, int maxWidth)
        {
            string output = "";

            // Ajoute chaque mot suivi d'un espace
            for (string *s : curr)
            {
                output += (*s);
                output += ' ';
            }

            // Ajoute des espaces à la fin pour atteindre maxWidth
            while (output.size() < maxWidth)
            {
                output += ' ';
            }

            // Si la taille dépasse maxWidth, retire le dernier caractère
            if (output.size() > maxWidth)
            {
                output.pop_back();
            }

            // Retourne la ligne non justifiée
            return output;
        }

        // Fonction principale pour justifier le texte
        vector<string> fullJustify(vector<string> & words, int maxWidth)
        {
            vector<string> ans; // Vecteur pour stocker les lignes justifiées

            vector<string *> curr; // Vecteur pour stocker les mots de la ligne actuelle
            int currSize = -1;     // Taille actuelle de la ligne (initialisée à -1 pour le premier espace)

            for (string &s : words)
            {
                int nextSize = currSize + 1 + s.size(); // Taille potentielle de la ligne si le mot actuel est ajouté

                if (nextSize <= maxWidth)
                {
                    currSize = nextSize; // Met à jour la taille actuelle de la ligne
                    curr.push_back(&s);  // Ajoute le mot à la ligne actuelle
                }
                else
                {
                    // Si la ligne dépasse maxWidth, justifie la ligne actuelle
                    ans.push_back(buildLine(curr, currSize, maxWidth));

                    curr.clear();        // Vide la ligne actuelle
                    curr.push_back(&s);  // Commence une nouvelle ligne avec le mot actuel
                    currSize = s.size(); // Réinitialise currSize avec la taille du nouveau mot
                }
            }

            // Ajoute la dernière ligne non justifiée à droite
            ans.push_back(buildLast(curr, maxWidth));

            // Retourne le vecteur de lignes justifiées
            return ans;
        }
    };