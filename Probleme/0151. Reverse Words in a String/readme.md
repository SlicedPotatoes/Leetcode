# 151. Reverse Words in a String

## Énoncé

Étant donné une chaîne d'entrée `s`, inversez l'ordre des **mots**.

Un **mot** est défini comme une séquence de caractères autres que des espaces. Les **mots** dans `s` seront séparés par au moins un espace.

Renvoie une chaîne de mots dans l'ordre inverse concaténés par un seul espace.

**Notez** que `s` peut contenir des espaces de début ou de fin ou plusieurs espaces entre deux mots. La chaîne renvoyée ne doit comporter qu’un seul espace séparant les mots. N’incluez aucun espace supplémentaire.

Si le type de données string est mutable dans votre langage, pouvez-vous le résoudre avec une complexité spatiale de `O(1)` ?

## Exemple

**Exemple 1:**  
**Input:** s = "the sky is blue"  
**Output:** "blue is sky the"

**Exemple 2:**  
**Input:** s = " hello world "  
**Output:** "world hello"  
**Explication:** Votre chaîne inversée ne doit pas contenir d'espaces de début ou de fin.

**Exemple 3:**  
**Input:** s = "a good &nbsp; example"  
**Output:** "example good a"  
**Explication:** Vous devez réduire plusieurs espaces entre deux mots à un seul espace dans la chaîne inversée.

## Contraintes

`1 <= s.length <= 10^4`  
`s` contient des lettres anglaises (majuscules et minuscules), des chiffres et des espaces `' '`.  
Il y a **au moins un** mot dans `s`.

## Note personnelle

Ma méthode repose sur l'utilisation de deux indices, `left` et `right`, que j'itére depuis la fin de la chaîne.  
Mon objectif est de repérer le premier caractère qui n'est pas un espace. Une fois ce caractère trouvé, les indices `left` et `right` on pour valeur la position de cet element.  
Ensuite, je continue à parcourir la chaîne jusqu'à rencontrer un espace. À ce moment-là, `left + 1` marque le début du mot et `right` la fin de celui-ci. Une fois le mot identifié, je l'ajoute à ma chaîne de sortie. Je répète ce processus jusqu'à ce que j'atteigne la fin de la chaîne.

Cette approche présente une complexité temporelle et spatiale de `O(n)`.

J'ai réalisé après coup que la contrainte exigeait une complexité spatiale de `O(1)`, ce que je n'ai pas encore implémenté.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
