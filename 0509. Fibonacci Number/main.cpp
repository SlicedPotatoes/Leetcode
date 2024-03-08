class Solution
{
  public:
    int fib(int n)
    {
        // Cas de base : si n est 0 ou 1, le résultat est n lui-même
        if (n == 0 || n == 1)
        {
            return n;
        }

        // Initialisation des deux premiers termes de la suite
        int a = 0; // Le premier terme est 0
        int b = 1; // Le deuxième terme est 1

        // Calcul des termes suivants de la suite jusqu'à atteindre le terme n
        for (int i = 2; i <= n; i++)
        {
            swap(a, b);
            b += a; // Calculer le terme suivant de la suite en ajoutant les valeurs précédentes
        }

        // Retourner le terme n de la suite de Fibonacci
        return b;
    }
};