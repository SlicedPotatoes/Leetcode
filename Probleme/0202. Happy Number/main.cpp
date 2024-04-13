class Solution
{
  public:
    // Fonction pour calculer le prochain nombre dans la séquence
    int next(int n)
    {
        int _n = 0; // Variable pour stocker le résultat

        // Boucle tant que le nombre n'est pas égal à zéro
        while (n != 0)
        {
            int digit = n % 10;  // Obtient le dernier chiffre du nombre
            n -= digit;          // Soustrait le dernier chiffre de n
            n /= 10;             // Supprime le dernier chiffre de n
            _n += digit * digit; // Ajoute le carré du chiffre à _n
        }

        // Retourne la somme des carrés des chiffres
        return _n;
    }

    // Fonction pour vérifier si un nombre est "heureux"
    bool isHappy(int n)
    {
        // Initialise deux pointeurs, un lent et un rapide
        int slow = next(n);       // Pointeur lent, avance d'une étape à la fois
        int fast = next(next(n)); // Pointeur rapide, avance de deux étapes à la fois

        // Boucle jusqu'à ce que les pointeurs se rencontrent
        while (slow != fast)
        {
            slow = next(slow);       // Avance le pointeur lent d'une étape
            fast = next(next(fast)); // Avance le pointeur rapide de deux étapes
        }

        // Si slow atteint 1, le nombre est heureux, sinon, il n'est pas heureux
        return slow == 1;
    }
};