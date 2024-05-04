# 33. Search in Rotated Sorted Array

## Énoncé

Il y a un tableau d'entiers `nums` trié par ordre croissant avec des valeurs **distinctes**.

Avant d'être passé à votre fonction, `nums` est **peut-être pivoté** à un index de pivot inconnu `k` (`1 <= k < nums.length`) de telle sorte que le tableau résultant soit `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**indexé à partir de 0**). Par exemple, `[0,1,2,4,5,6,7]` pourrait être pivoté à l'index de pivot `3` et devenir `[4,5,6,7,0,1,2]`.

Étant donné le tableau `nums` **après** la rotation possible et un entier `target`, retournez l'index de `target` s'il est dans `nums`, ou `-1` s'il n'est pas dans `nums`.

Vous devez écrire un algorithme avec une complexité temporelle de `O(log n)`.

## Exemple

**Exemple 1:**  
**Input:** nums = [4,5,6,7,0,1,2], target = 0  
**Output:** 4

**Exemple 2:**  
**Input:** nums = [4,5,6,7,0,1,2], target = 3  
**Output:** -1

**Exemple 2:**  
**Input:** nums = [1], target = 0  
**Output:** -1

## Contraintes

`1 <= nums.length <= 5000`  
`-10^4 <= nums[i] <= 10^4`  
Toutes les valeurs de `nums` sont **uniques**.  
`nums` est un tableau croissant qui est éventuellement pivoté.
`-10^4 <= target <= 10^4`

## Note personnelle

Pour résoudre ce problème, une méthode naïve implique de parcourir le tableau et de comparer chaque valeur avec la cible à atteindre.

```cpp
int search(vector<int>& arr, int target) {
  for(int i = 0; i < arr.size(); i++){
    if(arr[i] == target){
      return i;
    }
  }

  return -1;
}
```

Cette approche a une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`, ne répondant ainsi pas à l'exigence d'un algorithme avec une complexité temporelle de `O(log n)`.

Ma première approche respectant cette exigence consiste à effectuer trois recherches binaires.

J'ai commencé par mettre en œuvre une fonction pour trouver le décalage `k` avec une complexité de `O(log n)`. L'idée est de localiser d'abord un point de rotation, c'est-à-dire un intervalle dans le tableau où le début est inférieur ou égal à la fin. Pendant cette recherche, je conserve la dernière position de départ valide dans une variable `lastStart`.
Ensuite, je trouve l'élément le plus petit dans l'intervalle `(lastStart, start)`, dont l'indice représente le décalage `k`.

Maintenant que le décalage `k` est identifié, nous savons que les sous-tableaux `(0, k - 1)` et `(k, arr.size() - 1)` sont triés. Je réalise simplement une recherche binaire sur les deux sous-tableaux.

```cpp
// Fonction pour la recherche binaire standard
int bs(int target, vector<int> &arr, int start, int end){
  while(start <= end){
    int mid = (start + end) / 2; // Calcul de l'indice médian

    if(arr[mid] == target){
      return mid; // La valeur cible est trouvée, renvoyer l'indice
    }

    if(arr[mid] > target){
      end = mid - 1; // Mettre à jour la fin pour rechercher dans la moitié inférieure
    }
    else{
      start = mid + 1; // Mettre à jour le début pour rechercher dans la moitié supérieure
    }
  }

  return -1;
}

// Fonction pour trouver l'indice du plus petit élément dans un tableau pivoté
int findK(vector<int> &arr) {
  int start = 0;            // Indice du début du vecteur
  int end = arr.size() - 1; // Indice de fin du vecteur

  int lastStart = 0;  // Stocke la dernière position valide de 'start'

  // Recherche du point de rotation dans le vecteur
  while (arr[start] > arr[end]) {
    lastStart = start;  // Met à jour la dernière position valide de 'start'
    start = ((start + end) / 2) + 1;  // Déplacement de 'start' vers la droite
  }

  int m = arr[start];  // Récupération du plus petit élément potentiel

  end = start;        // Réinitialisation de 'end' autour du point de rotation
  start = lastStart;  // Réinitialisation de 'start' autour du point de rotation

  // Recherche de l'index exact du plus petit élément
  while (start <= end) {
    int mid = (start + end) / 2;  // Calcul de l'indice médian

    if (arr[mid] > m) {
      start = mid + 1;  // Déplacement de 'start' vers la droite
    }
    else {
      m = min(m, arr[mid]);  // Mise à jour du minimum potentiel
      end = mid - 1;  // Déplacement de 'end' vers la gauche
    }
  }

  return start;  // Retourne l'index du plus petit élément
}

// Fonction principale pour la recherche dans un tableau pivoté
int search(vector<int>& nums, int target) {
  // Trouver l'indice du plus petit élément
  int k = findK(nums);
  // Recherche binaire dans la première partie
  int targetIndex = bs(target, nums, 0, k - 1);

  if(targetIndex == -1){
    // Recherche binaire dans la deuxième partie
    targetIndex = bs(target, nums, k, nums.size() - 1);
  }

  return targetIndex;
}
```

Cette méthode présente une complexité temporelle de `O(log n)` et une complexité spatiale de `O(1)`.

Après avoir implémenté cette méthode, j'ai remarqué dans les commentaires que certaines personnes avaient résolu le problème en utilisant une seule recherche binaire. J'ai donc essayé de mettre en œuvre cette approche.

J'ai dû considérer plusieurs cas spécifiques pour mettre à jour correctement les bornes inférieures et supérieures:

- Lorsque `arr[start] <= arr[mid]`, indiquant que la première partie du tableau est triée:
  - Si `arr[start] <= target && arr[mid] > target`, cela signifie que notre cible se trouve dans la première partie du tableau.
  - Sinon, elle se trouve dans la seconde partie.
- Sinon, c'est la seconde partie du tableau qui est triée:
  - Si `arr[mid] < target && arr[end] >= target`, cela indique que notre cible se trouve dans la seconde partie du tableau.
  - Sinon, elle se trouve dans la première.

Cette approche conserve la même complexité temporelle et spatiale que la précédente, mais utilise une seule recherche binaire au lieu de trois.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
