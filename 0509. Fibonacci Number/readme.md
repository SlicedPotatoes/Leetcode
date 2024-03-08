# 509. Fibonacci Number

## Énoncé

Les **nombres de Fibonacci**, communément notés `F(n)` orment une séquence, appelée **séquence de Fibonacci**, telle que chaque nombre est la somme des deux précédents, en commençant par `0` et `1`.

F(0) = 0, F(1) = 1  
F(n) = F(n - 1) + F(n - 2), pour n > 1.

Étant donné `n`, calculez `F(n)`.

## Exemple

**Exemple 1:**  
**Input:** n = 2  
**Output:** 1  
**Explication:** F(2) = F(1) + F(0) = 1 + 0 = 1.

**Exemple 2:**  
**Input:** n = 3  
**Output:** 2  
**Explication:** F(3) = F(2) + F(1) = 1 + 1 = 2.

**Exemple 3:**  
**Input:** n = 4  
**Output:** 3  
**Explication:** F(4) = F(3) + F(2) = 2 + 1 = 3.

## Contraintes

`0 <= n <= 30`

## Note personnelle

Ma première approche utilise une fonction récursive avec de la mémoïsation. Elle traite les cas de base pour `n == 0` ou `n == 1`. Ensuite, elle vérifie si le résultat pour `n` a déjà été calculé grâce à une hashmap. Si ce n'est pas le cas, elle calcule le résultat avec un appel récursif `cache[n] = fib(n - 1) + fib(n - 2)`

```cpp
// Utilisation d'une unordered_map pour stocker les résultats déjà calculés de la suite de Fibonacci
unordered_map<int, int> cache;

// Fonction récursive pour calculer le n-ième nombre de Fibonacci
int fib(int n) {
  // Cas de base : les deux premiers nombres de Fibonacci sont 0 et 1
  if(n == 0 || n == 1){
    return n;
  }

  // Vérifie si le résultat pour la valeur 'n' est déjà dans le cache
  if(cache.find(n) == cache.end()){
    // Si 'n' n'est pas dans le cache, calcule récursivement fib(n - 1) + fib(n - 2)
    cache[n] = fib(n - 1) + fib(n - 2);
  }

  // Retourne le résultat pour 'n' (calculé ou récupéré depuis le cache)
  return cache[n];
}
```

Cette fonction a une complexité temporelle de `O(2^n)` . Cependant, grâce à l'utilisation de la mémoïsation, elle a une complexité temporelle de `O(n)`, avec une complexité spatiale également de `O(n)`.

Ma seconde approche est itérative, utilisant un tableau d'entiers `dp` de taille `n + 1` pour stocker les résultats intermédiaires.
Elle gère les cas de base pour `n == 0` ou `n == 1`. Ensuite, elle initialise `dp[1] = 1` et itère de `2` jusqu'à `n` inclus, utilisant la formule `dp[i] = dp[i - 1] + dp[i - 2]` pour calculer le terme `i`.

```cpp
int fib(int n) {
  // Si n est 0 ou 1, retourne n car la suite de Fibonacci commence à 0, 1, ...
  if (n == 0 || n == 1) {
    return n;
  }

  // Initialise un vecteur pour stocker les valeurs de la suite de Fibonacci jusqu'à n
  vector<int> dp(n + 1);
  dp[1] = 1; // La deuxième valeur de la suite est 1

  // Remplis le vecteur avec les valeurs de la suite de Fibonacci
  for (int i = 2; i <= n; i++) {
    // La valeur courante est la somme des deux précédentes
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  // Retourne la valeur de la suite de Fibonacci à l'index n
  return dp[n];
}
```

Cette approche a une complexité temporelle et spatiale de `O(n)`.

La dernière approche consiste à se passer de tableaux pour stocker les résultats intermédiaires, utilisant simplement des variables qui gardent une trace des 2 derniers termes de la suite calculée.

La complexité temporelle est de `O(n)` et la complexité spatiale de `O(1)`.

<img src="../imgs/0509-runtime.png"/>
<img src="../imgs/0509-memory.png"/>
