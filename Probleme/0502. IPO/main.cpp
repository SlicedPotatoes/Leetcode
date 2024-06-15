class Solution
{
  public:
    // Échange les éléments aux indices indexA et indexB dans les deux vecteurs arr1 et arr2
    void swapArr(vector<int> &arr1, vector<int> &arr2, int indexA, int indexB)
    {
        swap(arr1[indexA], arr1[indexB]);
        swap(arr2[indexA], arr2[indexB]);
    }

    // Effectue un tri par insertion sur les vecteurs arr1 et arr2 du début à la fin spécifiés
    void insertionSort(vector<int> &arr1, vector<int> &arr2, int start, int end)
    {
        for (int i = start + 1; i <= end; i++)
        {
            int key1 = arr1[i];
            int key2 = arr2[i];
            int j = i - 1;
            while (j >= start && arr1[j] > key1)
            {
                arr1[j + 1] = arr1[j];
                arr2[j + 1] = arr2[j];
                j--;
            }
            arr1[j + 1] = key1;
            arr2[j + 1] = key2;
        }
    }

    // Partitionne les vecteurs arr1 et arr2 en utilisant un pivot et renvoie l'indice du pivot final
    int partition(vector<int> &arr1, vector<int> &arr2, int start, int end, int pivot)
    {
        swapArr(arr1, arr2, pivot, end);
        int j = start;

        for (int i = start; i < end; i++)
        {
            if (arr1[i] <= arr1[end])
            {
                swapArr(arr1, arr2, i, j);
                j++;
            }
        }
        swapArr(arr1, arr2, end, j);

        return j;
    }

    // Trouve la médiane de trois éléments dans le vecteur arr
    int medianOfThree(vector<int> &arr, int a, int b, int c)
    {
        if ((arr[a] < arr[b] && arr[b] < arr[c]) || (arr[c] < arr[b] && arr[b] < arr[a]))
        {
            return b;
        }
        if ((arr[a] < arr[c] && arr[c] <= arr[b]) || (arr[b] < arr[c] && arr[c] <= arr[a]))
        {
            return c;
        }
        return a;
    }

    // Effectue un tri rapide sur les vecteurs arr1 et arr2 du début à la fin spécifiés
    void quickSort(vector<int> &arr1, vector<int> &arr2, int start, int end)
    {
        int size = end - start;

        if (size < 16)
        {
            insertionSort(arr1, arr2, start, end);
            return;
        }

        int pivot = medianOfThree(arr1, start, start + size / 2, end);

        pivot = partition(arr1, arr2, start, end, pivot);

        quickSort(arr1, arr2, start, pivot - 1);
        quickSort(arr1, arr2, pivot + 1, end);
    }

    // Trouve le capital maximisé après k projets en utilisant les vecteurs profits et capital
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // Trie les vecteurs capital et profits en fonction de capital
        quickSort(capital, profits, 0, capital.size() - 1);

        priority_queue<int> pq;
        int last = 0;

        for (int i = 0; i < k; i++)
        {
            // Ajoute tous les profits possibles à la file de priorité tant que le capital le permet
            while (last < profits.size() && capital[last] <= w)
            {
                pq.push(profits[last]);
                last++;
            }

            // Si la file de priorité est vide, on ne peut plus entreprendre de projets
            if (pq.size() == 0)
            {
                break;
            }

            // Ajoute le profit du projet le plus rentable au capital
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};