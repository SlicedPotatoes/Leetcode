# 75. Sort Colors

## Énoncé

Étant donné un tableau `nums` contenant `n` objets colorés en rouge, blanc ou bleu, trie-les **sur place** de sorte que les objets de même couleur soient adjacents, avec les couleurs dans l'ordre rouge, blanc et bleu.

Nous utiliserons les entiers `0`, `1`, et `2` pour représenter les couleurs rouge, blanc et bleu, respectivement.

Vous devez résoudre ce problème sans utiliser la fonction de tri de la bibliothèque.

Pourriez-vous proposer un algorithme en un seul passage utilisant uniquement un espace supplémentaire constant ?

## Exemple

**Exemple 1:**  
**Input:** nums = [2,0,2,1,1,0]  
**Output:** [0,0,1,1,2,2]

**Exemple 2:**  
**Input:** nums = [2,0,1]  
**Output:** [0,1,2]

## Contraintes

`n == nums.length`  
`1 <= n <= 300`  
`nums[i]` est soit `0`, `1` ou `2`.

## Note personnelle

Dans la première approche, on utilise la fonction de tri, mais cela ne respecte pas les contraintes de l'exercice et manque de stimulation.

```cpp
void sortColors(vector<int>& nums) {
  sort(nums.begin(), nums.end());
}
```

Cette méthode a une complexité temporelle de `O(n log n)` et une complexité spatiale de `O(1)`.

Une seconde approche consiste à compter les occurrences de chaque élément et à réattribuer ces valeurs dans le tableau.

```cpp
void sortColors(vector<int>& nums) {
  // Initialisation d'un tableau pour compter les occurrences de chaque couleur
  vector<int> arr(3, 0);

  // Compter le nombre d'occurrences de chaque couleur
  for(int n : nums){
    arr[n]++;
  }

  int curr = 0; // Couleur actuelle

  // Remplir le vecteur de couleurs triées en fonction des occurrences
  for(int i = 0; i < nums.size(); i++){
    // Trouver la prochaine couleur non nulle
    while(arr[curr] == 0){
      curr++;
    }

    // Mettre la couleur actuelle dans la position i du vecteur
    nums[i] = curr;
    // Décrémenter le compteur de cette couleur
    arr[curr]--;
  }
}
```

Cette approche a une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`, mais elle ne respecte pas la contrainte d'un seul passage.

La dernière approche, connue sous le nom de [**Dutch National Flag Algorithme**](https://fr.wikipedia.org/wiki/Probl%C3%A8me_du_drapeau_hollandais), utilise la technique des deux pointeurs pour suivre la dernière occurrence de `0` et `2`, notés respectivement `left` et `rigth`.

Pendant la traversée du tableau par un troisième pointeur `i`, des échanges sont effectués en fonction des valeurs des éléments. Ces échanges se produisent uniquement lorsque la valeur de l'élément est `0` ou `2`.
Lorsque la valeur est `0`, elle est placée à la position `left` et `left` est incrémenté pour suivre le prochain `0`. De même, lorsque la valeur est `2`, elle est placée à la position `right` et `right` est décrémenté.

Lorsque `nums[i]` est `0` ou `1`, `i` est incrémenté. Cependant, lorsqu'un échange est effectué avec la valeur `2` à l'index `right`, `i` n'est pas incrémenté. Cela est dû au risque que la valeur à l'index `right` soit un `0`, nécessitant ainsi un traitement lors de la prochaine itération.

En revanche, lorsqu'un `0` est rencontré, l'index `left` est toujours inférieur ou égal à `i`, donc un `2` ne peut y être présent car il aurait déjà été traité.

```cpp
void sortColors(vector<int>& nums) {
  // Index ou déplacé un 0
  int left = 0;
  // Index ou déplacé un 2
  int right = nums.size() - 1;

  // Index de parcours du tableau
  int i = 0;

  while(i <= right){
    if(nums[i] == 0){
      swap(nums[left++], nums[i++]);
    }
    else if(nums[i] == 2){
      swap(nums[right--], nums[i]);
    }
    else{
      i++;
    }
  }
}
```

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`, elle respecte egalement la contrainte d'effectue le tri en un seul passage.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
