class Solution
{
  public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int i = 0;               // Index actuel
        int a = bits.size() - 1; // Avant-dernier index du tableau

        // Parcours du tableau jusqu'à l'avant-dernier élément
        while (i < a)
        {
            // Avance d'un ou deux indices selon la valeur de bits[i]
            i += 1 + bits[i];
        }

        // Si i est égal à l'avant-dernier index, alors le dernier caractère est un bit unique
        return i == a;
    }
};