# 83. Remove Duplicates from Sorted List

## Énoncé

Étant donné la `head` d'une liste chaînée triée, supprimez tous les doublons de telle sorte que chaque élément n'apparaisse qu'une seule fois. Renvoie également la liste chaînée **triée**.

## Exemple

**Exemple 1:**

<img src="./imgs/img-1.jpg"/>

**Input:** head = [1,1,2]  
**Output:** [1,2]

**Exemple 2:**

<img src="./imgs/img-2.jpg"/>

**Input:** head = [1,1,2,3,3]  
**Output:** [1,2,3]

## Contraintes

Le nombre de noeuds dans la liste est compris entre `[0, 300]`.  
`-100 <= Node.val <= 100`  
La liste est garantie d'être **triée** par ordre croissant.

## Note personnelle

La méthode est assez directe : étant donné que la liste est déjà triée, il suffit de parcourir les éléments et de vérifier si la valeur suivante est égale à la valeur actuelle. Si c'est le cas, nous la supprimons

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
