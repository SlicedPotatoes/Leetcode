# 2485. Find the Pivot Integer

## Énoncé

Étant donné un entier positif `n`, trouvez le **entier pivot** `x` tel que:

La somme de tous les éléments entre `1` et `x` inclusivement est égale à la somme de tous les éléments entre `x` et `n` inclusivement.

Renvoie l'entier pivot `x`. Si aucun entier de ce type n'existe, renvoyez `-1`. Il est garanti qu'il y aura au plus un index pivot pour l'entrée donnée.

## Exemple

**Exemple 1:**  
**Input:** n = 8  
**Output:** 6  
**Explication:** 6 est l’entier pivot puisque : 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

**Exemple 2:**  
**Input:** n = 1  
**Output:** 1  
**Explication:** 1 est l’entier pivot puisque : 1 = 1.

**Exemple 3:**  
**Input:** n = 4  
**Output:** -1  
**Explication:** On peut prouver qu’un tel entier n’existe pas.

## Contraintes

`1 <= n <= 1000`

## Note personnelle

La méthode naïve pour résoudre ce problème consiste à itérer sur chaque valeur de `1` jusqu'à `n` et à calculer le préfixe et le suffixe pour les comparer.

Une implémentation de cette approche pourrait ressembler à ceci:

```cpp
int pivotInteger(int n) {
  for(int i = 1; i <= n; i++){
    // Initialise la somme des chiffres avant le pivot à 0.
    int prefix = 0;
    // Parcours les entiers de 1 à i inclusivement pour calculer la somme des chiffres avant le pivot.
    for(int j = 1; j <= i; j++){
      prefix += j;
    }

    // Initialise la somme des chiffres après le pivot à 0.
    int suffix = 0;
    // Parcours les entiers de i à n inclusivement pour calculer la somme des chiffres après le pivot.
    for(int j = i; j <= n; j++){
      suffix += j;
    }

    // Si la somme des chiffres avant le pivot est égale à la somme des chiffres après le pivot, retourne la position du pivot.
    if(suffix == prefix){
      return i;
    }
  }

  // Si aucun point de pivot n'est trouvé, retourne -1.
  return -1;
}
```

Cette méthode présente une complexité temporelle de `O(n^2)` et une complexité spatiale de `O(1)`.

Cependant, en analysant de plus près, on se rend compte que les préfixes et suffixes sont recalculés à chaque itération, ce qui entraîne beaucoup de calculs redondants pouvant être évités.

Une méthode permettant d'éviter ces calculs redondants consiste à utiliser le principe de prefixSum. Grâce à ce principe, on peut récupérer avec une complexité constante la somme `prefix` avec `prefixSum[i]` et `suffix` avec `prefixSum[n] - prefixSum[i - 1]`.

```cpp
int pivotInteger(int n) {
  // Déclaration d'un vecteur pour stocker les sommes préfixes
  vector<int> prefixSum(n + 1);
  // Initialisation de la première valeur du vecteur à zéro
  prefixSum[0] = 0;

  // Calcul des sommes préfixes pour les entiers de 1 à n
  for(int i = 1; i <= n; i++){
    // La somme préfixe actuelle est la somme préfixe précédente plus i
    prefixSum[i] = prefixSum[i - 1] + i;
  }

  // Recherche du pivot
  for(int i = 1; i <= n; i++){
    // Si la somme préfixe à l'indice i est égale à la différence entre la somme totale et la somme préfixe précédente, alors i est le pivot
    if(prefixSum[i] == prefixSum[n] - prefixSum[i - 1]){
      return i;
    }
  }

  return -1;
}
```

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(n)`.

Dans la majorité des problèmes que j'ai résolus grâce à prefixSum, il existe un moyen de ne pas utiliser de tableau et d'obtenir le même résultat.

L'idée est de calculer le `prefixSum` en le stockant dans une simple variable. Ensuite, j'initialise une variable `suffixSum` à 0. J'itère depuis `n` jusqu'à `1` en ajoutant `i` à `suffixSum`, puis je compare si `suffixSum == prefixSum`, Si ce n'est pas le cas, je soustrais `i` à `prefixSum`.

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
