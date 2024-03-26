class Solution
{
  public:
    bool isValid(string &s)
    {
        // Déclarer une pile de caractères
        stack<char> stack;

        // Parcourir chaque caractère dans la chaîne s
        for (char c : s)
        {
            switch (c)
            {
            // Si le caractère est une ouverture de parenthèse, crochets ou accolades
            // Empiler le caractère de fermeture correspondant
            case '(':
                stack.push(')');
                break;
            case '[':
                stack.push(']');
                break;
            case '{':
                stack.push('}');
                break;
            // Pour tout autre caractère (fermeture de parenthèse, etc.)
            default:
                // Vérifier si la pile est vide ou le caractère ne correspond pas au sommet de la pile
                if (stack.empty() || c != stack.top())
                {
                    // Retourner false car la séquence est invalide
                    return false;
                }
                // Retirer le caractère de la pile
                stack.pop();
            }
        }
        // Retourner true si la pile est vide (toutes les ouvertures sont correctement fermées)
        return stack.empty();
    }
};