class Solution
{
  public:
    string reverseParentheses(string s)
    {
        // Pile pour stocker les indices des parenthèses ouvrantes
        stack<int> sta;
        // Vector pour stocker les indices correspondants des parenthèses
        vector<int> portal(s.size(), -1);

        // Parcours de la chaîne pour trouver les paires de parenthèses
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                sta.push(i);
            }
            else if (s[i] == ')')
            {
                portal[sta.top()] = i;
                portal[i] = sta.top();
                sta.pop();
            }
        }

        // Initialisation de la chaîne de résultat et de la direction
        string ans = "";
        int dir = 1;

        // Parcours de la chaîne pour construire le résultat final
        for (int i = 0; i < s.size(); i += dir)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                // Inverser la direction et sauter à l'indice correspondant
                dir = -dir;
                i = portal[i];
            }
            else
            {
                // Ajouter le caractère à la chaîne de résultat
                ans += s[i];
            }
        }

        return ans;
    }
};