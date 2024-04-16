# 404. Sum of Left Leaves

## Énoncé

Étant donné la `root` d'un arbre binaire, renvoie la somme de toutes les feuilles gauches.

Une **feuille** est un noeud sans enfant. Une **feuille gauche** est une feuille qui est l'enfant gauche d'un autre noeud.

## Exemple

**Exemple 1:**

<img src="./imgs/img1.jpg"/>

**Input:** root = [3,9,20,null,null,15,7]  
**Output:** 24  
**Explication:** Il y a deux feuilles gauches dans l’arbre binaire, avec respectivement les valeurs 9 et 15.

**Exemple 2:**  
**Input:** root = [1]  
**Output:** 0

## Contraintes

Le nombre de noeuds dans l'arborescence est compris entre `[1, 1000]`.  
`-1000 <= Node.val <= 1000`

## Note personnelle

Pour résoudre ce problème, j'ai opté pour une méthode simple basée sur la recherche en profondeur (DFS). J'ai également inclus un booléen pour déterminer si le noeud que j'explore actuellement est l'enfant gauche du noeud précédent.

Cette approche garantit une complexité temporelle de `O(n)` et une complexité spatiale de `O(h)`, où `n` représente le nombre d'éléments dans l'arbre et `h` sa hauteur.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
