class Solution
{
  public:
    string reverseVowels(string s)
    {
        // Définition d'un ensemble non ordonné pour stocker les voyelles
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        // Vecteur pour stocker les indices des voyelles dans la chaîne de caractères
        vector<int> indexVowelsInString;

        // Recherche des indices des voyelles dans la chaîne de caractères
        for (int i = 0; i < s.size(); i++)
        {
            if (vowels.count(s[i]) != 0)
            {
                indexVowelsInString.push_back(i);
            }
        }

        // Inversion des voyelles dans la chaîne de caractères
        for (int i = 0; i < indexVowelsInString.size() / 2; i++)
        {
            // Récupération des indices de la première et de la dernière voyelle
            int firstIndex = indexVowelsInString[i];
            int lastIndex = indexVowelsInString[indexVowelsInString.size() - 1 - i];

            // Échange des voyelles
            char temp = s[lastIndex];
            s[lastIndex] = s[firstIndex];
            s[firstIndex] = temp;
        }

        return s;
    }
};