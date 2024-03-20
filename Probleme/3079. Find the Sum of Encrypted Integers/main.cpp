class Solution
{
  public:
    // Fonction pour chiffrer un entier
    int encrypt(int x)
    {
        // Initialise la variable maxElement pour stocker le chiffre maximal
        int maxElement = 0;
        // Initialise la variable size pour compter le nombre de chiffres dans x
        int size = 0;

        // Boucle pour extraire chaque chiffre de x et trouver le maximum
        while (x != 0)
        {
            // Obtient le dernier chiffre de x
            int element = x % 10;

            // Met à jour le maximum
            maxElement = max(maxElement, element);
            // Incrémente le compteur de chiffres
            size++;

            // Soustrait le dernier chiffre de x
            x -= element;
            // Supprime le dernier chiffre de x
            x /= 10;
        }

        // Construit un entier où chaque chiffre est égal au chiffre maximal
        int e = 0;
        for (; size > 0; size--)
        {
            // Décale les chiffres précédents vers la gauche
            e *= 10;
            // Ajoute le chiffre maximal à l'entier chiffré
            e += maxElement;
        }

        // Retourne l'entier chiffré
        return e;
    }
    int sumOfEncryptedInt(vector<int> &nums)
    {
        // Initialise la somme à zéro
        int sum = 0;
        // Parcourt chaque nombre dans le vecteur
        for (int n : nums)
        {
            // Ajoute le chiffrement de chaque nombre à la somme
            sum += encrypt(n);
        }
        // Retourne la somme des entiers chiffrés
        return sum;
    }
};