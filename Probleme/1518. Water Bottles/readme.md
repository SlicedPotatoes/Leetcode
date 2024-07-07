# 1518. Water Bottles

## Énoncé

Il y a `numBottles` bouteilles d'eau qui sont initialement pleines d'eau. Vous pouvez échanger `numExchange` bouteilles d'eau vides au marché contre une bouteille d'eau pleine.

L'action de boire une bouteille d'eau pleine la transforme en une bouteille vide.

Étant donné les deux entiers `numBottles` et `numExchange`, retournez le **nombre maximum** de bouteilles d'eau que vous pouvez boire.

## Exemple

**Exemple 1:**

<img src="./imgs/img1.png" width="500px" height="245px"/>

**Input:** numBottles = 9, numExchange = 3  
**Output:** 13  
**Explication:** Vous pouvez échanger 3 bouteilles vides contre 1 bouteille d’eau pleine.
Nombre de bouteilles d'eau que vous pouvez boire: 9 + 3 + 1 = 13.

**Exemple 2:**

<img src="./imgs/img2.png" width="500px" height="183px"/>

**Input:** numBottles = 15, numExchange = 4  
**Output:** 19  
**Explication:** Vous pouvez échanger 4 bouteilles vides contre 1 bouteille d’eau pleine.
Nombre de bouteilles d'eau que vous pouvez boire: 15 + 3 + 1 = 19.

## Contraintes

`1 <= numBottles <= 100`  
`2 <= numExchange <= 100`

## Note personnelle

### Approche 1: Simulation

L'idée de cette approche est de simuler chaque étape jusqu'à ce qu'il ne reste plus de bouteilles pleines.

```cpp
int numWaterBottles(int numBottles, int numExchange) {
  int ans = 0; // Total des bouteilles bues

  // Tant qu'il y a assez de bouteilles pour les échanger contre de nouvelles
  while(numBottles >= numExchange){
    int r = numBottles % numExchange; // Bouteilles restantes après échange (pleine)
    ans += numBottles - r; // Ajouter les bouteilles bues

    numBottles /= numExchange; // Mettre à jour le nombre de bouteilles après échange
    numBottles += r; // Ajouter les bouteilles restantes pour le prochain échange
  }

  return ans + numBottles; // Retourner le nombre total de bouteilles bues
}
```

- Complexité Temporelle: `O(log_numExchange numBottles)`.
- Complexité Spatiale: `O(1)`.

### Approche 2 Mathématique:

Cette approche n'est pas la mienne, elle a été publiée par [jthunder](https://leetcode.com/u/jthunder/) sur LeetCode [ici](https://leetcode.com/problems/water-bottles/solutions/745231/python-1-liner-with-math-explained/).

```cpp
int numWaterBottles(int numBottles, int numExchange) {
  return (numBottles * numExchange - 1) / (numExchange - 1);
}
```

```cpp
int numWaterBottles(int numBottles, int numExchange) {
  return numBottles + (numBottles - 1) / (numExchange - 1);
}
```

- Complexité Temporelle: `O(1)`.
- Complexité Spatiale: `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
