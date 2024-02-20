# 605. Can Place Flowers

## Énoncé

Vous disposez d’un long parterre de fleurs dans lequel certaines parcelles sont utilisées et d’autres non. La condition pour planter une fleur c'est qu'elle n'est pas d'autre fleur adjacente.

Étant donné un tableau d'entiers `flowerbed` contenant des `0` et des `1`, où `0` signifie vide et `1` non vide, et un entier `n`, renvoie `true` si `n` nouvelles fleurs peuvent être plantées dans le `flowerbed` sans violer la règle d'absence de fleurs adjacentes et `false` dans le cas contraire.

## Exemple

**Example 1:**  
**Input:** flowerbed = [1,0,0,0,1], n = 1  
**Output:** true

**Example 2:**  
**Input:** flowerbed = [1,0,0,0,1], n = 2  
**Output:** Output: false

## Contraintes

`21 <= flowerbed.length <= 2 * 10^4`  
`flowerbed[i]` et `0` ou `1`.
Il n'y a pas deux fleurs adjacentes dans `flowerbed`.
`0 <= n <= flowerbed.length`

## Note personnelle

<img src="../imgs/0605-runtime.png"/>
<img src="../imgs/0605-memory.png"/>
