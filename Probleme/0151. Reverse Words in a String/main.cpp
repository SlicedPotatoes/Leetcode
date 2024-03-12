class Solution
{
  public:
    string reverseWords(string s)
    {
        // Initialiser les indices de gauche et de droite pour parcourir la chaîne de caractères
        int left = s.size() - 1;  // Indice de départ pour le premier caractère non-espace à droite
        int right = s.size() - 1; // Indice de fin pour le dernier caractère non-espace à droite

        // Chaîne de caractères pour stocker le résultat
        string output;
        output.reserve(s.size());

        // Parcourir la chaîne de caractères de droite à gauche
        while (left >= 0)
        {
            // Ignorer les espaces à la fin
            while (left >= 0 && s[left] == ' ')
            {
                left--; // Décrémenter l'indice de gauche tant que l'on rencontre des espaces
            }
            if (left == -1)
            {
                break; // Si nous avons atteint le début de la chaîne, sortir de la boucle
            }
            right = left; // Mettre à jour l'indice de droite pour marquer le début d'un nouveau mot
            while (left >= 0 && s[left] != ' ')
            {
                left--; // Décrémenter l'indice de gauche tant que l'on rencontre des caractères non-espace
            }
            // Ajouter le mot à la chaîne de sortie en parcourant de gauche à droite
            for (int i = left + 1; i <= right; i++)
            {
                output += s[i];
            }
            output += ' '; // Ajouter un espace entre les mots
        }

        // Supprimer l'espace en trop à la fin si la chaîne de sortie n'est pas vide
        if (output.size() != 0)
        {
            output.pop_back();
        }

        return output;
    }
};