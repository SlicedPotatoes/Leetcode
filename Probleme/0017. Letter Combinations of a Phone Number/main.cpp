class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        // Vérifie si la chaîne de chiffres est vide
        if (digits.size() == 0)
        {
            // Si c'est le cas, retourne un vecteur vide
            return {};
        }

        // Initialise une table de hachage (unordered_map) associant chaque chiffre à ses lettres correspondantes
        unordered_map<char, string> numPad = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                              {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        // Vecteur pour stocker les combinaisons de lettres
        vector<string> output;
        // Initialise une chaîne de la même taille que digits remplie d'espaces
        string currentString(digits.size(), ' ');
        // Initialise une pile pour parcourir toutes les combinaisons possibles
        stack<pair<int, int>> s;

        // Ajoute toutes les combinaisons possibles pour le premier chiffre dans la pile
        for (int i = 0; i < numPad[digits[0]].size(); i++)
        {
            s.push({0, i});
        }

        // Parcourt toutes les combinaisons possibles
        while (!s.empty())
        {
            pair<int, int> current = s.top(); // Récupère la combinaison actuelle
            s.pop();                          // Retire la combinaison actuelle de la pile

            // Ajoute la lettre correspondante à la position actuelle dans la chaîne de sortie
            currentString[current.first] = numPad[digits[current.first]][current.second];

            // Vérifie si toutes les positions ont été remplies dans la chaîne de sortie
            if (current.first + 1 == digits.size())
            {
                output.push_back(currentString); // Si oui, ajoute la chaîne de sortie au vecteur de résultats
                continue;                        // Passe à la prochaine itération
            }

            // Sinon, continue à explorer les combinaisons possibles pour le chiffre suivant
            // Récupère les lettres correspondant au chiffre suivant
            string &nextNumPad = numPad[digits[current.first + 1]];

            // Ajoute toutes les combinaisons possibles pour le chiffre suivant dans la pile
            for (int i = 0; i < nextNumPad.size(); i++)
            {
                s.push({current.first + 1, i});
            }
        }

        return output; // Retourne le vecteur de toutes les combinaisons de lettres possibles
    }
};