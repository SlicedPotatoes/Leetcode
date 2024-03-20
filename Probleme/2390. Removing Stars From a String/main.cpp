class Solution
{
  public:
    string removeStars(string s)
    {
        // Déclarer une chaîne de caractères pour stocker le résultat final
        string output;

        // Initialiser un compteur pour suivre le nombre d'étoiles rencontrées
        int count = 0;

        // Parcourir la chaîne de caractères de la fin au début
        for (int i = s.size() - 1; i >= 0; i--)
        {
            // Vérifier si le caractère actuel est une étoile
            if (s[i] == '*')
            {
                count++; // Incrémenter le compteur d'étoiles
            }
            // Si le caractère actuel n'est pas une étoile mais il y a des étoiles en attente à supprimer
            else if (count != 0)
            {
                count--; // Décrémenter le compteur d'étoiles en attente
            }
            // Si le caractère actuel n'est pas une étoile et il n'y a pas d'étoiles en attente à supprimer
            else
            {
                output.push_back(s[i]); // Ajouter le caractère actuel à la chaîne de sortie
            }
        }

        // Inverser la chaîne de sortie pour obtenir l'ordre correct des caractères
        reverse(output.begin(), output.end());

        return output;
    }
};