class Solution
{
  public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        // Initialisation des indices de début et de fin de la recherche binaire
        int start = 0;
        int end = letters.size() - 1;

        // Incrémentez le caractère cible pour trouver le caractère suivant le plus grand
        target++;

        // Recherche binaire
        while (start <= end)
        {
            // Calcul de l'indice médian
            int mid = (start + end) / 2;

            // Si la lettre à la position médiane est supérieure à la cible, réduire la recherche à gauche
            if (letters[mid] > target)
            {
                end = mid - 1;
            }
            // Si la lettre à la position médiane est inférieure à la cible, réduire la recherche à droite
            else if (letters[mid] < target)
            {
                start = mid + 1;
            }
            // Si la lettre à la position médiane est égale à la cible, retourner la lettre
            else
            {
                return letters[mid];
            }
        }

        // Si la cible n'est pas trouvée, renvoie le caractère à l'indice de départ s'il est dans la plage, sinon
        // renvoie le premier caractère dans le vecteur.
        return start < letters.size() ? letters[start] : letters[0];
    }
};