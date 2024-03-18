# 1207. Unique Number of Occurrences

## Énoncé

Étant donné un tableau d'entiers `arr`, renvoie `true` si le nombre d'occurrences de chaque valeur dans le tableau est **unique** ou `false` sinon.

## Exemple

**Exemple 1:**  
**Input:** arr = [1,2,2,1,1,3]  
**Output:** true  
**Explication:** La valeur 1 a 3 occurrences, 2 en a 2 et 3 en a 1. Il n'y a pas deux valeurs qui aient le même nombre d'occurrences.

**Exemple 2:**  
**Input:** arr = [1,2]  
**Output:** false

## Contraintes

`1 <= arr.length <= 1000`  
`-1000 <= arr[i] <= 1000`

## Note personnelle

Ma première approche implique le tri du tableau et l'utilisation d'un ensemble appelé `nbOccurrences` pour stocker les occurrences uniques.

Après avoir trié le tableau, je parcours celui-ci en comptant le nombre d'occurrences de chaque élément. Pour chaque élément, je vérifie si ce nombre d'occurrences se trouve déjà dans l'ensemble:

- Si c'est le cas, je renvoie false.
- Sinon, j'ajoute le nombre d'occurrences à l'ensemble et je continue.

Si nous sortons de la boucle sans avoir renvoyé false, alors je renvoie true.

```cpp
bool uniqueOccurrences(vector<int>& arr) {
  // Trie le vecteur d'entrée pour faciliter le comptage des occurrences
  sort(arr.begin(), arr.end());

  // Utilise un ensemble non ordonné pour stocker le nombre d'occurrences
  unordered_set<int> nbOccurrences;

  // Parcourt le vecteur trié pour compter les occurrences de chaque élément
  for(int i = 0; i < arr.size(); i++) {
    int current = arr[i];
    int count = 1;

    // Compte le nombre d'occurrences consécutives du même élément
    while(i + 1 < arr.size() && arr[i + 1] == current) {
      count++;
      i++;
    }

    // Vérifie si le nombre d'occurrences est déjà présent dans l'ensemble
    if(nbOccurrences.find(count) != nbOccurrences.end()) {
      // Si c'est le cas, des occurrences identiques ont été rencontrées plus d'une fois. Donc le nombre d'occurrences n'est pas unique
      return false;
    }

    // Insère le nombre d'occurrences dans l'ensemble
    nbOccurrences.insert(count);
  }

  // Si aucune occurrence n'est rencontrée plus d'une fois, retourne true
  return true;
}
```

La complexité temporelle de cette approche est de `O(n log n)` en raison du tri, tandis que la complexité spatiale est de `O(n)`.

Ma deuxième approche évite de trier le tableau. Elle utilise une HashMap pour compter le nombre d'occurrences de chaque valeur, ainsi qu'un ensemble pour garder une trace des occurrences uniques.

La complexité temporelle et spatiale de cette approche est de `O(n)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
