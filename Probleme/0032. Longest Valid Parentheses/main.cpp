class Solution
{
  public:
    int longestValidParentheses(string &s)
    {
        // dp[i] représente la longueur de la séquence valide se terminant à l'indice i
        vector<int> dp(s.size(), 0);
        // Une pile pour stocker les indices des parenthèses ouvrantes
        stack<int> stack;
        // La longueur maximale trouvée jusqu'à présent
        int best = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                // Si on trouve une parenthèse ouvrante, on ajoute son index à la pile
                stack.push(i);
            }
            // Si on trouve une parenthèse fermante et que la pile n'est pas vide
            else if (!stack.empty())
            {
                // Calculer la longueur de la séquence valide courante
                int value = i - stack.top() + 1;
                // On enlève l'index correspondant de la pile car la séquence est maintenant fermé
                stack.pop();

                // Vérifier si la sous-séquence précédant la séquence courante est également valide
                if (i - value >= 0)
                {
                    // Si oui, ajouter la longueur de la sous-séquence à la longueur courante
                    value += dp[i - value];
                }

                // Stocker la longueur de la séquence valide se terminant à l'index i
                dp[i] = value;

                // Mettre à jour la longueur maximale trouvée jusqu'à présent
                best = max(value, best);
            }
        }

        return best;
    }
};