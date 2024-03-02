class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int maxSize = -1; // Taille maximale actuelle du palindrome
        int left;         // Indice de début du palindrome le plus long

        int pivot = 0;        // Indice utilisé comme pivot pour vérifier les sous-chaînes
        int currentLeft = 0;  // Indice de début actuel de la sous-chaîne en cours d'évaluation
        int currentRight = 0; // Indice de fin actuel de la sous-chaîne en cours d'évaluation
        bool isEven = false;  // Indique si la longueur de la sous-chaîne est paire

        // Boucle tant que le pivot n'atteint pas la fin de la chaîne
        while (pivot != s.size())
        {
            // Vérifie si la sous-chaîne actuelle est valide
            if (currentLeft < 0 || currentRight >= s.size() || s[currentLeft] != s[currentRight])
            {
                // Incrémente les indices en conséquence
                if (isEven)
                {
                    pivot++;
                    currentRight = pivot;
                }
                else
                {
                    currentRight = pivot + 1;
                }
                isEven = !isEven;
                currentLeft = pivot;
                continue; // Passe à l'itération suivante de la boucle
            }

            // Calcule la taille de la sous-chaîne
            int currentSize = currentRight - currentLeft + 1;
            // Met à jour le palindrome le plus long trouvé jusqu'à présent
            if (currentSize > maxSize)
            {
                maxSize = currentSize;
                left = currentLeft;
            }
            // Élargit la sous-chaîne pour vérifier si elle forme un palindrome plus long
            currentLeft--;
            currentRight++;
        }
        // Retourne le palindrome le plus long trouvé
        return s.substr(left, maxSize);
    }
};