# 2413. Smallest Even Multiple

## Énoncé

Étant donné un entier **positif** `n`, renvoyez le plus petit entier positif qui est un multiple de `2` et de `n`.

## Exemple

**Exemple 1:**  
**Input:** n = 5  
**Output:** 10  
**Explication:** Le plus petit multiple de 5 et 2 est 10.

**Exemple 2:**  
**Input:** n = 6  
**Output:** 6  
**Explication:** Le plus petit multiple de 6 et 2 est 6. Notez qu'un nombre est un multiple de lui-même.

## Contraintes

`1 <= n <= 150`

## Note personnelle

Si un nombre `n` est impair, il ne peut pas être multiple de `2`. Le plus petit multiple pair de `n` est donc `n * 2`.  
Si un nombre `n` est pair, alors il est déjà un multiple de `2`.

Il existe plusieurs manières de résoudre ce problème, incluant des approches mathématiques et des manipulations binaires.

```cpp
int smallestEvenMultiple(int n)  {
  return n % 2 == 0 ? n : n + n;
}
```

```cpp
int smallestEvenMultiple(int n) {
    return n * (n % 2 + 1);
}
```

```cpp
int smallestEvenMultiple(int n) {
  return n << (n & 1);
}
```

- Complexité Temporelle: `O(1)`
- Complexité Spatiale: `O(1)`

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
