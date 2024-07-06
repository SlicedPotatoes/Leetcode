class Solution
{
  public:
    int passThePillow(int n, int time)
    {
        int count = time / (n - 1); // Nombre de cycles complets de passage d'oreiller.
        time %= (n - 1);            // Temps restant après les cycles complets.

        if (count % 2 == 0)
        {
            return time + 1; // Position après le temps restant.
        }
        else
        {
            return n - time; // Position après le temps restant en sens inverse.
        }
    }
};