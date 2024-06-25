# 538. Convert BST to Greater Tree

## Énoncé

Étant donné la racine `root` d'un arbre binaire de recherche (ABR), convertissez-le en un Greater Tree de telle sorte que chaque clé de l'ABR original soit modifiée en la clé originale plus la somme de toutes les clés supérieures à la clé originale dans l'ABR.

Pour rappel, un arbre binaire de recherche est un arbre qui satisfait les contraintes suivantes:

- Le sous-arbre gauche d'un noeud ne contient que des noeuds avec des clés inférieures à la clé du noeud.
- Le sous-arbre droit d'un noeud ne contient que des noeuds avec des clés supérieures à la clé du noeud.
- Les sous-arbres gauche et droit doivent également être des arbres binaires de recherche.

## Exemple

**Exemple 1:**

<img width=400px height=273px src="./imgs/img1.png"/>

**Input:** root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]  
**Output:** [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

**Exemple 2:**  
**Input:** root = [0,null,1]  
**Output:** [1,null,1]

## Contraintes

Le nombre de noeuds dans l'arbre est compris entre `[1, 10^4]`  
`-10^4 <= Node.val <= 10^4`  
Toutes les valeurs dans l'arbre son **uniques**.  
Il est garanti que `root` est un arbre de recherche binaire valide.

## Note personnelle

Cette question est exactement la même que [1038](../1038.%20Binary%20Search%20Tree%20to%20Greater%20Sum%20Tree/).

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
