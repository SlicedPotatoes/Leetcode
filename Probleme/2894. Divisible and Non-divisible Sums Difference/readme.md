# 2894. Divisible and Non-divisible Sums Difference

## Énoncé

Vous disposez de deux entiers positifs `n` et `m`.

Définissez deux entiers, `num1` et `num2`, comme suit:

`num1`: La somme de tous les entiers dans l'intervalle `[1, n]` qui ne sont **pas divisibles** par `m`.  
`num2`: La somme de tous les entiers dans l'intervalle `[1, n]` qui sont **divisibles** par `m`.

Retournez l'entier `num1 - num2`.

## Exemple

**Exemple 1:**  
**Input:** n = 10, m = 3  
**Output:** 19  
**Explication:**

- Les entiers dans l'intervalle [1, 10] qui ne sont pas divisibles par 3 sont [1,2,4,5,7,8,10], num1 est la somme de ces entiers = 37.
- Les entiers dans l'intervalle [1, 10] qui sont divisibles par 3 sont [3,6,9], num2 est la somme de ces entiers = 18.

Nous retournons 37 - 18 = 19 comme réponse.

**Exemple 2:**  
**Input:** n = 5, m = 6  
**Output:** 15  
**Explication:**

- Les entiers dans l'intervalle [1, 5] qui ne sont pas divisibles par 6 sont [1,2,3,4,5], num1 est la somme de ces entiers = 15.
- Les entiers dans l'intervalle [1, 5] qui sont divisibles par 6 sont [], num2 est la somme de ces entiers = 0.

Nous retournons 15 - 0 = 15 comme réponse.

**Exemple 3:**  
**Input:** n = 5, m = 1  
**Output:** -15

- Les entiers dans l'intervalle [1, 5] qui ne sont pas divisibles par 1 sont [], num1 est la somme de ces entiers = 0.
- Les entiers dans l'intervalle [1, 5] qui sont divisibles par 1 sont [1,2,3,4,5], num2 est la somme de ces entiers = 15.

Nous retournons 0 - 15 = -15 comme réponse.

## Contraintes

`1 <= n, m <= 1000`

## Note personnelle

Pour résoudre ce problème, j'ai exploré plusieurs approches.

### Approche 1: Brute Force

L'idée initiale était d'itérer sur chaque nombre de `1` à `n` inclus et de calculer `num1` et `num2`.

```cpp
int differenceOfSums(int n, int m) {
  int num1 = 0; // Somme des nombres de 1 à n non multiples de m
  int num2 = 0; // Somme des nombres de 1 à n multiples de m

  for(int i = 1; i <= n; i++){
    // Si i n'est pas un multiple de m, ajouter i à num1
    if(i % m){ num1 += i; }
    // Sinon, ajouter i à num2
    else{ num2 += i; }
  }

  return num1 - num2; // Retourner la différence entre num1 et num2
}
```

- **Complexité temporelle**: `O(n)`
- **Complexité spatiale**: `O(1)`

### Approche 2: Mélange de Brute Force et de Mathématiques

Cette approche consiste à calculer la somme cumulée des éléments de `1` à `n` inclus et à itérer uniquement sur les nombres divisibles par `m` en les soustrayant deux fois de la somme cumulée.

```cpp
int differenceOfSums(int n, int m) {
  // Calcul de la somme totale des entiers de 1 à n
  int ans = (n * (n + 1)) / 2;

  // Soustraction de deux fois la somme des multiples de m dans la plage de 1 à n
  for(int i = m; i <= n; i += m){
    ans -= i * 2; // Soustraire deux fois le multiple de m
  }

  return ans; // Retourner la différence calculée
}
```

- **Complexité temporelle**: `O(n / m)`
- **Complexité spatiale**: `O(1)`

### Approche 3: Purement Mathématique

Cette approche repose uniquement sur des calculs mathématiques.

```cpp
int differenceOfSums(int n, int m) {
  // Calcul de la somme totale des entiers de 1 à n
  int sommeCumuler = (n * (n + 1)) / 2;

  // Calcul de la somme des multiples de m jusqu'à n
  int nbMultiple = n / m;
  int sumMultiple = m * (nbMultiple * (nbMultiple + 1)) / 2;

  // Calcul de la différence entre la somme totale et deux fois la somme des multiples de m
  return sommeCumuler - (sumMultiple * 2);
}
```

La formule de la somme cumulative est bien connue en mathématiques, je ne vais donc pas la détailler. Cependant, il y a une astuce intéressante utilisée pour la somme des multiples, que je vais illustrer par un exemple:

Pour `n` = 10 et `m` = 3, l'idée est de calculer combien de fois `m` se trouve dans `n` avec le résultat de la division entière `n / m`.
Ensuite, je calcule la somme cumulative de `1` jusqu'à ce résultat précédent ; dans notre cas `n / m = 3`, la somme cumulative est `1 + 2 + 3 = 6`.
En multipliant ce résultat par `m` cela revient à faire `3 + 6 + 9 = 18`, où chaque terme est un multiple de `m` dans la plage de `1` à `n`.

- **Complexité temporelle**: `O(1)`
- **Complexité spatiale**: `O(1)`

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
