# 67. Add Binary

## Énoncé

Étant donné deux chaînes binaires `a` et `b`, renvoie leur somme sous forme de chaîne binaire.

## Exemple

**Exemple 1:**  
**Input:** a = "11", b = "1"  
**Output:** "100"

**Exemple 2:**  
**Input:** a = "1010", b = "1011"  
**Output:** "10101"

## Contraintes

`1 <= a.length, b.length <= 10^4`  
`a` et `b` sont constitués uniquement de caractères `'0'` ou `'1'`  
Chaque chaîne ne contient pas de zéros non significatifs, à l'exception du zéro lui-même.

## Note personnelle

Ma méthode consiste à parcourir simultanément les deux chaînes à partir de leur fin. J'utilise une variable booléenne pour suivre la retenue

À chaque itération, je commence par initialiser un compteur à 0 que j'incrémente en fonction du nombre de 1 rencontrés durant cette itération, en ajoutant également 1 si une retenue est présente.

En fonction de la valeur du compteur, je réalise différentes actions:

- Si elle est égale à 0, j'ajoute 0 à ma chaîne de sortie.
- Si elle est égale à 1, j'ajoute 1 à ma chaîne de sortie.
- Si elle est égale à 2, j'ajoute 0 à ma chaîne de sortie et je positionne la retenue à true.
- Si elle est égale à 3, j'ajoute 1 à ma chaîne de sortie et je positionne la retenue à true.

Complexité temporelle: `O(n)`  
Complexité spatiale: `O(n)`

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
