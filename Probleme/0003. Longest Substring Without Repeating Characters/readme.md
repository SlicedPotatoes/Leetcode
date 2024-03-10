# 3. Longest Substring Without Repeating Characters

## Énoncé

Étant donné un string s, recherchez la longueur du substring le plus long sans répéter de caractères.

## Exemple

**Exemple 1:**  
**Input:** s = "abcabcbb"  
**Output:** 3  
**Explication:** La réponse est "abc", d'une longueur de 3.

**Exemple 2:**  
**Input:** s = "bbbbb"  
**Output:** 1  
**Explication:** La réponse est "b", d'une longueur de 1.

**Exemple 3:**  
**Input:** s = "pwwkew"  
**Output:** 3  
**Explication:** La réponse est "wke", d'une longueur de 3.

## Contraintes

`0 <= s.length <= 5 * 10^4`  
`s` se compose de lettres anglaises, de chiffres, de symboles et d’espaces.

## Note personnelle

La solution naïve à cet énoncé est relativement simple à implémenter. Ce qui le rend intéressant, c'est d'essayer de développer un algorithme avec une complexité O(n).

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
