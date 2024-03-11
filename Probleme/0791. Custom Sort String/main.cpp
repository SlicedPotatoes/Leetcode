class Solution
{
  public:
    string customSortString(string order, string s)
    {
        // Map pour stocker le nombre d'occurrences de chaque caractère dans 's'
        unordered_map<char, uint8_t> _s;
        // Set pour stocker les caractères dans 'order'
        unordered_set<char> _order;

        // Insérer les caractères de 'order' dans le set 'orderSet'
        for (char c : order)
        {
            _order.insert(c);
        }

        // Calculer le nombre d'occurrences de chaque caractère dans 's' et stocker dans 'charCount'
        for (char c : s)
        {
            _s[c]++;
        }

        // Initialiser la chaîne de sortie
        string output;
        output.reserve(s.size());

        // Parcourir les caractères dans l'ordre spécifié par 'order'
        for (char c : order)
        {
            // Si le caractère existe dans 's'
            if (_s.find(c) != _s.end())
            {
                // Ajouter le caractère 'c' autant de fois qu'il apparaît dans 's'
                for (int i = 0; i < _s[c]; i++)
                {
                    output += c;
                }
            }
        }

        // Ajouter les caractères restants de 's' qui ne sont pas dans 'order' à la sortie
        for (char c : s)
        {
            if (_order.find(c) == _order.end())
            {
                output += c;
            }
        }

        // Retourner la chaîne de sortie
        return output;
    }
};