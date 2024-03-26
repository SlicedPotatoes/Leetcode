# 20. Valid Parentheses

## Énoncé

Étant donné une chaîne `s` contenant uniquement les caractères `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, déterminez si l'entrée la chaîne est valide.

une chaîne d'entrée est valide si:

- Les parenthèses ouvertes doivent être fermées par des parenthèses du même type.
- Les parenthèses ouvertes doivent être fermées dans le bon ordre.
- À chaque parenthèse fermée correspond une parenthèse ouverte du même type.

## Exemple

**Exemple 1:**  
**Input:** s = "()"  
**Output:** true

**Exemple 2:**  
**Input:** s = "()[]{}"  
**Output:** true

**Exemple 3:**  
**Input:** s = "(]"  
**Output:** false

## Contraintes

`1 <= s.length <= 10^4`  
`s` se compose uniquement de parenthèses `'()[]{}'`.

## Note personnelle

Ma méthode repose sur l'utilisation d'une structure de données de type pile (stack) pour suivre les parenthèses ouvertes. Je parcours la chaîne de caractères `s` de la manière suivante:

- Lorsqu'une parenthèse est ouverte, je place dans la pile la parenthèse fermée correspondante.
- Lorsqu'une parenthèse est fermée, je vérifie si elle correspond à l'élément en haut de la pile. Si ce n'est pas le cas, la chaîne est considérée comme invalide.

Cette approche garantit une complexité temporelle et spatiale de `O(n)`, où `n` représente la taille de la chaîne de caractères.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
