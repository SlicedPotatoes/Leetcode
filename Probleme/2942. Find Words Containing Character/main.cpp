class Solution
{
  public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> ans; // Vecteur pour stocker les indices des mots contenant le caractère x

        // Parcourt chaque mot dans le vecteur de mots
        for (int i = 0; i < words.size(); i++)
        {
            // Parcourt chaque caractère du mot courant
            for (char c : words[i])
            {
                // Si le caractère courant est égal à x
                if (c == x)
                {
                    ans.push_back(i); // Ajoute l'indice du mot à la liste des résultats
                    break;            // Sort de la boucle interne pour passer au mot suivant
                }
            }
        }

        return ans; // Retourne le vecteur des indices
    }
};