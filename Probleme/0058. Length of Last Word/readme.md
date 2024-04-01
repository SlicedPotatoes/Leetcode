# 58. Length of Last Word

## Énoncé

Étant donné une chaîne `s` composée de mots et d'espaces, renvoie la longueur du **dernier** mot de la chaîne.

Un **mot** est une sous-chaîne composée uniquement de caractères autres que des espaces.

## Exemple

**Exemple 1:**  
**Input:** s = "Hello World"  
**Output:** 5  
**Explication:** Le dernier mot est "World" d'une longueur de 5.

**Exemple 2:**  
**Input:** s = " fly me to the moon "  
**Output:** 4  
**Explication:** Le dernier mot est "moon" d'une longueur de 4.

**Exemple 3:**  
**Input:** s = "luffy is still joyboy"  
**Output:** 6  
**Explication:** Le dernier mot est "joyboy" d'une longueur de 6.

## Contraintes

`1 <= s.length <= 10^4`  
`s` se compose uniquement de lettres anglaises et d'espaces `' '`.  
Il y aura au moins un mot dans `s`.

## Note personnelle

La méthode adoptée est simple : je commence par initialiser un pointeur `i` qui représente l'indice actuellement parcouru, sa valeur étant définie à `s.size() - 1`.

JJe parcours la chaîne `s` tant que `s[i] == ' '` , ce qui me permet d'ignorer les espaces à la fin de la chaîne, tout en décrémentant `i` à chaque itération.

Ensuite, je continue à parcourir tant que `i >= 0` et `s[i] != ' '`, ce qui me permet de trouver la longueur du dernier mot. À chaque itération, je décrémente `i` et j'incrémente un compteur pour la longueur.

Cette méthode présente une complexité temporelle de `O(n)`, où `n` représente la longueur de `s`, et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
