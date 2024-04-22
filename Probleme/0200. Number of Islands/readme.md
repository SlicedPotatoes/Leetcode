# 200. Number of Islands

## Énoncé

Étant donné une grille binaire 2D de taille `m x n` appelée `grid` , qui représente une carte avec des `'1'` (terre) et des `'0'` (eau), renvoyez le nombre d'îles.

Une **île** est entourée d'eau et est formée en reliant des terres adjacentes horizontalement ou verticalement. Vous pouvez supposer que les quatre bords de la grille sont tous entourés d’eau.

## Exemple

**Exemple 1:**  
**Input:**

```
grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
```

**Output:** 1

**Exemple 2:**  
**Input:**

```
grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
```

**Output:** 3

## Contraintes

`m == grid.length`  
`n == grid[i].length`  
`1 <= m, n <= 300`  
`grid[i][j]` est `'0'` ou `'1'`.

## Note personnelle

Pour aborder ce problème, j'ai choisi d'utiliser une recherche en profondeur (DFS). Cette méthode me permet de parcourir les cases d'une île et de les marquer. Je parcours chaque case de la matrice, et lorsque je rencontre une case d'une île non marquée, j'appelle ma fonction DFS et j'incrémente le compteur du nombre d'îles.

Cette approche présente une complexité temporelle et spatiale de `O(n * m)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
