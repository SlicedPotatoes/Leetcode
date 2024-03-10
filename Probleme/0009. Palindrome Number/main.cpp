class Solution
{
  public:
    bool isPalindrome(int x)
    {
        // Si x est négatif, il ne peut pas être un palindrome
        if (x < 0)
        {
            return false;
        }
        // Copie de x dans _x pour ne pas modifier l'original
        int _x = x;
        // Utilisation d'un long pour stocker la valeur inversée de x
        long __x = 0;

        // Boucle pour inverser les chiffres de x
        while (_x != 0)
        {
            // Obtention du dernier chiffre de _x
            int r = _x % 10;
            // Suppression du dernier chiffre de _x
            _x = (_x - r) / 10;

            // Construction de la valeur inversée
            __x *= 10;
            __x += r;
        }

        // Si la valeur inversée est égale à x, alors x est un palindrome
        return x == __x;
    }
};