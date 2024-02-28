# 1071. Greatest Common Divisor of Strings

## Énoncé

Pour deux chaînes `s` et `t`, nous disons "`t` divise `s`" si et seulement si `s = t + t + t + ... + t + t` (c'est-à-dire que `t` est concaténé avec lui-même une ou plusieurs fois).

Étant donné deux chaînes `str1` et `str2`, renvoie la plus grande chaîne `x` telle que `x` divise à la fois `str1` et `str2`.

## Exemple

**Exemple 1:**  
**Input:** str1 = "ABCABC", str2 = "ABC"  
**Output:** "ABC"

**Exemple 2:**  
**Input:** str1 = "ABABAB", str2 = "ABAB"  
**Output:** "AB"

**Exemple 3:**  
**Input:** str1 = "LEET", str2 = "CODE"  
**Output:** ""

## Contraintes

`1 <= str1.length, str2.length <= 1000`  
`str1` et `str2` se composent de lettres majuscules anglaises.

## Note personnelle

Exercice intéressant. Initialement, j'ai adopté une approche avec une complexité de O(n^2), ce qui était loin d'être optimal. J'ai pu l'optimiser à O(n).

Pour parvenir à la solution optimale, j'ai trouvé l'inspiration en examinant les "Tags" associés à l'exercice, notamment celui mentionnant "Math". Cela m'a amené à réfléchir à une approche plus mathématique, et c'est ainsi que l'algorithme d'Euclide pour trouver le PGCD m'est venu à l'esprit.

<img src="../imgs/1071-runtime.png"/>
<img src="../imgs/1071-memory.png"/>
