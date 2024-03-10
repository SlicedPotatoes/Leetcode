# 349. Intersection of Two Arrays

## Énoncé

Étant donné deux tableaux d'entiers `nums1` et `nums2`, renvoie un tableau de leur intersection. Chaque élément du résultat doit être **unique** et vous pouvez renvoyer le résultat dans n'importe quel ordre.

## Exemple

**Exemple 1:**  
**Input:** nums1 = [1,2,2,1], nums2 = [2,2]  
**Output:** [2]

**Exemple 2:**  
**Input:** nums1 = [4,9,5], nums2 = [9,4,9,8,4]  
**Output:** [9,4]  
**Explication:** [4,9] est également accepté.

## Contraintes

`1 <= nums1.length, nums2.length <= 1000`  
`0 <= nums1[i], nums2[i] <= 1000`

## Note personnelle

Pour cet exercice, j'ai exploré trois approches distinctes.

La première méthode implique l'utilisation de deux pointeurs. Elle commence par trier les deux tableaux, puis initialise un vecteur pour stocker les résultats.

Je parcours ensuite les deux tableaux simultanément, avec les actions suivantes à chaque itération :

- Si `nums1[i] == nums2[j]`: Je vérifie si `nums1` n'est pas déjà dans l'`output`, si ce n'est pas le cas, je l'ajoute. Ensuite, j'incrémente les indices `i` et `j`.
- Si `nums1[i] > nums2[j]`, j'incrémente `j` de `1`.
- Sinon j'incrémente `i` de `1`.

```cpp
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  // Trie les deux vecteurs
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());

  // Vecteur pour stocker les éléments en commun
  vector<int> output;

  // Parcours les deux vecteurs simultanément
  for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
    // Si les éléments sont égaux
    if (nums1[i] == nums2[j]) {
      // Vérifie si l'élément est déjà présent dans le vecteur de sortie
      // Si non, l'ajoute au vecteur de sortie
      if (output.size() == 0 || output[output.size() - 1] != nums1[i]) {
        output.push_back(nums1[i]);
      }
      // Passe au prochain élément dans chaque vecteur
      i++;
      j++;
    }
    else if (nums1[i] > nums2[j]) {
      // Si l'élément dans nums1 est plus grand, avance dans nums2
      j++;
    }
    else {
      // Si l'élément dans nums2 est plus grand, avance dans nums1
      i++;
    }
  }

  // Retourne le vecteur résultant
  return output;
}
```

La complexité temporelle de cette approche est de `O(n log n)`, et la complexité spatiale de `O(min(n, m))`.

La deuxième approche utilise une recherche binaire pour déterminer si un élément se trouve dans l'autre tableau. Elle trie également les tableaux en amont.

Pour chaque élément du tableau le plus court, je vérifie sa présence dans l'autre tableau à l'aide de la recherche binaire. Si l'élément est présent et qu'il n'est pas déjà dans l'output, je l'ajoute.

```cpp
// Fonction de recherche binaire
bool binarySearch(vector<int> &nums, int target) {
  int start = 0;
  int end = nums.size() - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (nums[mid] == target) {
      return true;
    }
    else if (nums[mid] > target) {
      end = mid - 1;
    }
    else {
      start = mid + 1;
    }
  }

  return false;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  // Tri des vecteurs
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());

  // Sélection du vecteur le plus court pour la recherche binaire
  vector<int> &minArr = nums1.size() > nums2.size() ? nums2 : nums1;
  vector<int> &maxArr = nums1.size() > nums2.size() ? nums1 : nums2;
  vector<int> output;

  // Parcourir le vecteur le plus court
  for (int element : minArr) {
    // Vérifier si l'élément est présent dans l'autre vecteur
    if (binarySearch(maxArr, element)) {
      // Vérifier les doublons
      if (output.empty() || output.back() != element) {
        output.push_back(element); // Ajouter à la liste de sortie
      }
    }
  }

  return output;
}
```

Cette approche présente une complexité temporelle de `O(n log n)` et une complexité spatiale de `O(m)`.

La troisième approche utilise un ensemble non ordonné, évitant ainsi le tri des tableaux. Les éléments du tableau le plus petit sont insérés dans l'ensemble. Ensuite, pour chaque élément du tableau le plus grand, je vérifie sa présence dans l'ensemble. Si c'est le cas, je l'ajoute à l'output et le retire de l'ensemble.

Cette approche a une complexité temporelle de `O(n + m)` et une complexité spatiale de `O(n)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
