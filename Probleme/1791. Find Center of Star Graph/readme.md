# 1791. Find Center of Star Graph

## Énoncé

Il y a un **graphe en étoile non orienté** composé de `n` noeuds étiquetés de `1` à `n`. Un graphe en étoile est un graphe où il y a un **noeud central** et exactement `n - 1` arêtes qui relient le noeud central à chaque autre noeud.

Vous disposez d'un tableau d'entiers en 2D `edges` où chaque `edges[i] = [ui, vi]` indique qu'il y a une arête entre les noeuds `ui` et `vi`. Retournez le centre du graphe en étoile donné.

## Exemple

**Exemple 1:**

<img src="./imgs/img1.png"/>

**Input:** edges = [[1,2],[2,3],[4,2]]  
**Output:** 2  
**Explication:** Comme le montre la figure ci-dessus, le noeud 2 est connecté à tous les autres noeuds, donc 2 est le centre.

**Exemple 2:**  
**Input:** edges = [[1,2],[5,1],[1,3],[1,4]]  
**Output:** 1

## Contraintes

`3 <= n <= 10^5`  
`edges.length == n - 1`  
`edges[i].length == 2`  
`1 <= ui, vi <= n`  
`ui != vi`  
Les `edges` donnés représentent un graphp en étoile valide.

## Note personnelle

Pour résoudre ce problème, nous utilisons la propriété principale des graphes en étoile : il suffit de réaliser seulement 2 comparaisons.

Si le premier élément de la première arête est égal au premier ou au second élément de la seconde arête, alors il constitue le centre. Sinon, le centre est le second élément de la première arête.

```cpp
int findCenter(vector<vector<int>> &edges) {
  // Vérifie si le premier noeud du premier bord est égal à l'un des deux noeuds du deuxième bord.
  if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
    // Si c'est le cas, le premier noeud du premier bord est le centre de l'étoile.
    return edges[0][0];
  }
  // Sinon, le deuxième noeud du premier bord est le centre de l'étoile.
  return edges[0][1];
}
```

Cette méthode présente une complexité temporelle et spatiale constante de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
