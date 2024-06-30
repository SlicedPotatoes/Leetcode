class Solution
{
  public:
    int getNext(int n)
    {
        // Obtenir le bit le plus bas à 1
        int lowestBit = n & -n;
        // Obtenir les bits à gauche
        int leftBits = n + lowestBit;
        // Bits changés entre n et leftBits
        int changedBits = n ^ leftBits;
        // Bits à droites ajustés
        int rightBits = (changedBits / lowestBit) >> 2;

        // Combiner les bits gauche et droite pour obtenir le prochain nombre
        return leftBits | rightBits;
    }

    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        // Si k est 0, retourner le premier élément car seul l'indice 0 a 0 bits à 1
        if (k == 0)
        {
            return nums[0];
        }

        int ans = 0;

        // Initialiser l'index avec les k bits les plus bas à 1
        for (int index = (1 << k) - 1; index < nums.size(); index = getNext(index))
        {
            ans += nums[index]; // Ajouter l'élément au résultat
        }

        // Retourner la somme totale
        return ans;
    }
};