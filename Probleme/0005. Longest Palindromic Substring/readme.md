# 5. Longest Palindromic Substring

## Énoncé

Étant donné une chaîne `s`, renvoie la **sous-chaîne palindromique la plus longue** dans `s`.

## Exemple

**Exemple 1:**  
**Input:** s = "babad"  
**Output:** "bab"  
**Explication:** "aba" est également une réponse valable.

**Exemple 2:**  
**Input:** s = "cbbd"  
**Output:** "bb"

## Contraintes

`1 <= s.length <= 1000`  
`s` se compose uniquement de chiffres et de lettres anglaises.

## Note personnelle

J'ai déjà résolu un exercice similaire sur le site [France-IOI](https://www.france-ioi.org/algo/chapters.php)

Par conséquent, j'ai rapidement eu l'intuition d'utiliser une approche basée sur un pivot et deux indices pour représenter le début et la fin de la sous-chaîne explorée.

Cette méthode me permet de vérifier avec une complexité constante si ma sous-chaîne est un palindrome.

La complexité temporelle est de `O(n^2)` et la complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
