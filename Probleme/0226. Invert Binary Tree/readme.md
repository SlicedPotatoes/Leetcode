# 226. Invert Binary Tree

## Énoncé

Étant donné la `root` d'un arbre binaire, inversez l'arbre et renvoyez sa racine.

## Exemple

**Exemple 1:**

<img src="./imgs/img1.jpg"/>

**Input:** root = [4,2,7,1,3,6,9]  
**Output:** [4,7,2,9,6,3,1]

**Exemple 2:**

<img src="./imgs/img2.jpg"/>

**Input:** root = [2,1,3]  
**Output:** [2,3,1]

**Exemple 3:**

**Input:** root = []  
**Output:** []

## Contraintes

Le nombre de noeuds dans l'arborescence est compris entre `[0, 100]`  
`-100 <= Node.val <= 100`

## Note personnelle

J'ai opté pour une solution utilisant une approche DFS (Depth-First Search) récursive. À chaque étape, je permute les enfants du noeud actuel et effectue un appel récursif pour chaque enfant.

Cette méthode présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(h)`, où `n` désigne le nombre d'éléments dans l'arbre tandis que `h` représente sa hauteur maximale.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
