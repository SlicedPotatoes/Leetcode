# 605. Can Place Flowers

## Énoncé

Vous disposez d’un long parterre de fleurs dans lequel certaines parcelles sont utilisées et d’autres non. La condition pour planter une fleur c'est qu'elle n'est pas d'autre fleur adjacente.

Étant donné un tableau d'entiers `flowerbed` contenant des `0` et des `1`, où `0` signifie vide et `1` non vide, et un entier `n`, renvoie `true` si `n` nouvelles fleurs peuvent être plantées dans le `flowerbed` sans violer la règle d'absence de fleurs adjacentes et `false` dans le cas contraire.

## Exemple

**Exemple 1:**  
**Input:** flowerbed = [1,0,0,0,1], n = 1  
**Output:** true

**Exemple 2:**  
**Input:** flowerbed = [1,0,0,0,1], n = 2  
**Output:** Output: false

## Contraintes

`21 <= flowerbed.length <= 2 * 10^4`  
`flowerbed[i]` et `0` ou `1`.  
Il n'y a pas deux fleurs adjacentes dans `flowerbed`.  
`0 <= n <= flowerbed.length`

## Note personnelle

Exercice pouvent ce résoudre en O(n). Une technique que j'ai observée dans les corrections d'autres personnes consiste à incrémenter directement l'indice (i) lorsqu'une fleur peut être plantée. Cette approche évite de modifier le tableau d'origine et permet de parcourir moins de cases du tableau, améliorant ainsi les performances de l'algorithme.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
