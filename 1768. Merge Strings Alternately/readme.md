# 1768. Merge Strings Alternately

## Énoncé

On vous donne deux chaînes `word1` et `word2`. Fusionnez les chaînes en ajoutant des lettres dans un ordre alterné, en commençant par `word1`. Si une chaîne est plus longue que l’autre, ajoutez les lettres supplémentaires à la fin de la chaîne fusionnée.

Renvoie la chaîne fusionnée.

## Exemple

**Exemple 1:**  
**Input:** word1 = "abc", word2 = "pqr"  
**Output:** "apbqcr"  
**Explication:** La chaîne fusionnée sera fusionnée comme suit:  
word1: &nbsp; a &nbsp;&nbsp; b &nbsp;&nbsp; c  
word2: &nbsp;&nbsp; &nbsp; p &nbsp;&nbsp; q &nbsp;&nbsp; r  
merged: a p b q c r

**Exemple 2:**  
**Input:** word1 = "ab", word2 = "pqrs"  
**Output:** "apbqrs"  
**Explication:** Notez que comme word2 est plus long, "rs" est ajouté à la fin.  
word1: &nbsp; a &nbsp;&nbsp; b  
word2: &nbsp;&nbsp; &nbsp; p &nbsp;&nbsp; q &nbsp;&nbsp; r &nbsp;&nbsp; s  
merged: a p b q &nbsp;&nbsp; r &nbsp;&nbsp; s

**Exemple 3:**  
**Input:** word1 = "abcd", word2 = "pq"  
**Output:** "apbqcd"  
**Explication:** Notez que comme word1 est plus long, "cd" est ajouté à la fin.  
word1: &nbsp; a &nbsp;&nbsp; b &nbsp;&nbsp; c &nbsp;&nbsp; d  
word2: &nbsp;&nbsp; &nbsp; p &nbsp;&nbsp; q  
merged: a p b q c &nbsp; d

## Contraintes

`1 <= word1.length, word2.length <= 100`  
`word1` et `word2` sont constitués de lettres anglaises minuscules.

## Note personnelle

Pour cet exercice relativement simple, j'ai exploré diverses méthodes de concaténation de chaînes en C++.  
Après plusieurs tests et en calculant la moyenne du temps d'exécution pour chaque méthode avec les mêmes paramètres d'entrée, j'ai conclu que l'opérateur `+=` était la méthode la plus efficace pour résoudre ce problème.

<img src="../imgs/1768-runtime.png"/>
<img src="../imgs/1768-memory.png"/>
