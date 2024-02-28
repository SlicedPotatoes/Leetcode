# 345. Reverse Vowels of a String

## Énoncé

Étant donné une chaîne `s`, inversez uniquement toutes les voyelles de la chaîne et renvoyez-la.

Les voyelles sont `'a'`, `'e'`, `'i'`, `'o'`, et `'u'`, et ils peuvent apparaître plusieurs fois en minuscules et en majuscules.

## Exemple

**Exemple 1:**  
**Input:** s = "hello"  
**Output:** "holle"

**Exemple 2:**  
**Input:** s = "leetcode"  
**Output:** "leotcede"

## Contraintes

`1 <= s.length <= 3 * 10^5`  
`s` se composent de caractères ASCII imprimables.

## Note personnelle

J'ai opté pour l'utilisation d'un unordered_set afin de bénéficier de la complexité constante pour vérifier si un caractère est une voyelle.

Cependant, après avoir examiné les réponses proposées par la communauté, j'aurais pu envisager une approche utilisant une boucle avec deux indices représentant la fin et le début de la chaîne. Cette alternative aurait potentiellement amélioré à la fois le temps d'exécution et l'utilisation de la mémoire.

<img src="../imgs/0345-runtime.png"/>
<img src="../imgs/0345-memory.png"/>
