# 129. Sum Root to Leaf Numbers

## Énoncé

Vous recevez la `root` d'un arbre binaire contenant uniquement des chiffres de `0` à `9`.

Chaque chemin racine-feuille dans l’arborescence représente un nombre.

Renvoie la somme totale de tous les nombres racine à feuille. Les cas de test sont générés de manière à ce que la réponse tienne dans un entier **32 bits**.

Une **feuille** est un noeud sans enfant.

## Exemple

**Exemple 1:**

<img src="./imgs/img1.jpg"/>

**Input:** root = [1,2,3]  
**Output:** 25  
**Explication:**  
Le chemin racine-feuille `1->2` représente le nombre `12`.  
Le chemin racine-feuille `1->3` représente le nombre `13`.  
Par conséquent, sum = 12 + 13 = `25`.

**Exemple 2:**

<img src="./imgs/img2.jpg"/>

**Input:** root = [4,9,0,5,1]  
**Output:** 1026  
**Explication:**  
Le chemin racine-feuille `4->9->5` représente le nombre `495`.  
Le chemin racine-feuille `4->9->1` représente le nombre `491`.  
Le chemin racine-feuille `4->0` représente le nombre `40`.  
Par conséquent, sum = 495 + 491 + 40 = `1026`.

## Contraintes

Le nombre de noeuds dans l'arborescence est compris entre `[1, 1000]`  
`0 <= Node.val <= 9`  
La profondeur de l'arbre ne dépassera pas `10`.

## Note personnelle

Pour résoudre ce problème, j'ai choisi d'employer une approche basée sur la recherche en profondeur (DFS). Cette méthode parcourt l'arbre de manière récursive, en suivant un chemin de la racine jusqu'à chaque feuille, tout en calculant la somme des nombres formés par ces chemins.

En termes de performance, cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(h)`, où `n` est le nombre total de noeuds dans l'arbre et `h` est la hauteur de l'arbre.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
