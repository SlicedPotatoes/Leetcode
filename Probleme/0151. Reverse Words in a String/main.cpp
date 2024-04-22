class Solution
{
  public:
    string reverseWords(string &s)
    {
        // Inverse toute la chaîne de caractères
        reverse(s.begin(), s.end());

        int left = 0;
        int right = 0;

        int rightNS = 0;

        // Parcours de la chaîne de caractères
        while (right < s.size())
        {
            // Ignorer les espaces au début de chaque mot
            while (right < s.size() && s[right] == ' ')
            {
                right++;
            }
            left = right;

            int size = 0;

            // Déplacement des caractères d'un mot vers leur nouvelle position
            while (right < s.size() && s[right] != ' ')
            {
                swap(s[rightNS], s[right]);
                rightNS++;
                right++;
                size++;
            }

            // Inversion du mot pour le remettre dans l'ordre d'origine
            reverse(s.begin() + rightNS - size, s.begin() + rightNS);
            s[rightNS] = ' ';
            rightNS++;
        }

        // Suppression des espaces en trop à la fin de la chaîne
        while (s.back() == ' ')
        {
            s.pop_back();
        }

        return s;
    }
};