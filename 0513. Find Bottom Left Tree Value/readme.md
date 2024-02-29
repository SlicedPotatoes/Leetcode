# 513. Find Bottom Left Tree Value

## Énoncé

Compte tenu de la `root` d'un arbre binaire, renvoyez la valeur la plus à gauche dans la profondeur de l'arbre.

## Exemple

**Exemple 1:**  
**Input:** root = [2,1,3]  
**Output:** 1

**Exemple 2:**  
**Input:** root = [1,2,3,4,null,5,6,null,null,7]  
**Output:** 7

## Contraintes

Le nombre de noeuds dans l'arborescence est compris entre `[1, 104]`.  
`-2^31 <= Node.val <= 2^31 - 1`

## Note personnelle

Pour résoudre le problème consistant à trouver la valeur du noeud le plus profond à gauche, j'ai opté pour l'implémentation d'une recherche en largeur (BFS).

Ma méthode utilise deux files : une principale et une temporaire pour déterminer à partir de quand je dois changer de profondeur. Lorsque la file principale est vide, j'échange les deux files pour continuer le processus.

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(n)`.

<img src="../imgs/0513-runtime.png"/>
<img src="../imgs/0513-memory.png"/>
