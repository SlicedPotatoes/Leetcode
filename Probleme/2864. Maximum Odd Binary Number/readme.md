# 2864. Maximum Odd Binary Number

## Énoncé

Vous recevez une chaîne **binaire** `s` qui contient au moins un `'1'`.

Vous devez **réorganiser** les bits de telle manière que le nombre binaire résultant soit le **nombre binaire impair maximum** pouvant être créé à partir de cette combinaison.

Renvoie une chaîne représentant le nombre binaire impair maximum pouvant être créé à partir de la combinaison donnée.

**Notez** que la chaîne résultante **peut** contenir des zéros non significatifs.

## Exemple

**Exemple 1:**  
**Input:** s = "010"  
**Output:** "001"  
**Explication:** Puisqu'il n'y a qu'un seul '1', il doit être en dernière position. La réponse est donc "001".

**Exemple 2:**  
**Input:** s = "0101"  
**Output:** "1001"  
**Explication:** L'un des '1' doit être en dernière position. Le nombre maximum pouvant être obtenu avec les chiffres restants est "100". La réponse est donc "1001".

## Contraintes

`1 <= s.length <= 100`  
`s` est composé uniquement de `'0'` et `'1'`.  
`s` contient au moins un `'1'`.

## Note personnelle

Le point commun entre tous les nombres impairs en binaire est que leur dernier élément est toujours 1.  
En tirant parti de ce principe, je peux simplement compter le nombre de 1 dans la chaîne binaire d'origine.  
Ensuite, je peux recréer une chaîne de la même longueur en plaçant `nbDe1 - 1` caractères 1, complétée avec des 0, sauf pour le dernier élément qui est toujours 1.

La solution proposée a une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
