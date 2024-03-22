// Structure définissant un caractère et son nombre d'occurrences
struct pkv
{
    char c;    // Caractère
    int count; // Nombre d'occurrences
};

// Foncteur pour comparer les structures pkv
struct comparePKV
{
    // Trie d'abord par le nombre d'occurrences, puis par ordre alphabétique
    bool operator()(pkv const &a, pkv const &b)
    {
        if (a.count == b.count)
        {
            return a.c > b.c;
        }
        return a.count > b.count;
    }
};

class Solution
{
  public:
    string minimizeStringValue(string s)
    {
        // Vecteur pour compter les occurrences de chaque caractère
        vector<int> frequency(26, 0);
        // Compteur pour le nombre de '?' dans la chaîne
        int nbQuestionMarks = 0;

        // Compter les occurrences de chaque caractère et le nombre de '?'
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c != '?')
            {
                // Incrémenter le compteur d'occurrences du caractère
                frequency[c - 'a']++;
            }
            else
            {
                // Incrémenter le compteur de '?'
                nbQuestionMarks++;
            }
        }

        // Créer une file de priorité pour stocker les structures pkv
        priority_queue<pkv, vector<pkv>, comparePKV> pq;

        // Remplir la file de priorité avec les caractères et leur nombre d'occurrences
        for (int i = 0; i < frequency.size(); i++)
        {
            char c = 'a' + i;
            pq.push({c, frequency[i]});
        }

        // Réinitialiser le vecteur de fréquence
        for (int i = 0; i < frequency.size(); i++)
        {
            frequency[i] = 0;
        }

        // Trouver les caractères à utiliser pour remplacer les '?'
        for (int i = 0; i < nbQuestionMarks; i++)
        {
            // Récupérer le caractère avec le plus petit nombre d'occurrences
            pkv current = pq.top();
            // Retirer le caractère de la file de priorité
            pq.pop();

            // Incrémenter le compteur d'occurrences pour le caractère
            frequency[current.c - 'a']++;

            // Réinsérer le caractère avec un nombre d'occurrences incrémenté
            pq.push({current.c, current.count + 1});
        }

        // Indice pour parcourir le vecteur de fréquence
        int j = 0;

        // Remplacer les '?' dans la chaîne par les caractères appropriés en utilisant le vecteur de fréquence
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                // Trouver le prochain caractère disponible
                while (frequency[j] == 0)
                {
                    j++;
                }
                // Remplacer le '?' par le caractère approprié
                s[i] = 'a' + j;
                // Décrémenter le compteur d'occurrences pour le caractère utilisé
                frequency[j]--;
            }
        }

        // Retourner la chaîne modifiée
        return s;
    }
};
