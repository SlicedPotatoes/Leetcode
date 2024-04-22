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

Date: 12-03-2024

Ma méthode repose sur l'utilisation de deux indices, `left` et `right`, que j'itére depuis la fin de la chaîne.  
Mon objectif est de repérer le premier caractère qui n'est pas un espace. Une fois ce caractère trouvé, les indices `left` et `right` on pour valeur la position de cet element.  
Ensuite, je continue à parcourir la chaîne jusqu'à rencontrer un espace. À ce moment-là, `left + 1` marque le début du mot et `right` la fin de celui-ci. Une fois le mot identifié, je l'ajoute à ma chaîne de sortie. Je répète ce processus jusqu'à ce que j'atteigne la fin de la chaîne.

```cpp
string reverseWords(string s) {
  // Initialiser les indices de gauche et de droite pour parcourir la chaîne de caractères
  int left = s.size() - 1;  // Indice de départ pour le premier caractère non-espace à droite
  int right = s.size() - 1; // Indice de fin pour le dernier caractère non-espace à droite

  // Chaîne de caractères pour stocker le résultat
  string output;
  output.reserve(s.size());

  // Parcourir la chaîne de caractères de droite à gauche
  while (left >= 0) {
    // Ignorer les espaces à la fin
    while (left >= 0 && s[left] == ' ') {
      left--; // Décrémenter l'indice de gauche tant que l'on rencontre des espaces
    }
    if (left == -1) {
      break; // Si nous avons atteint le début de la chaîne, sortir de la boucle
    }
    right = left; // Mettre à jour l'indice de droite pour marquer le début d'un nouveau mot
    while (left >= 0 && s[left] != ' ') {
      left--; // Décrémenter l'indice de gauche tant que l'on rencontre des caractères non-espace
    }
    // Ajouter le mot à la chaîne de sortie en parcourant de gauche à droite
    for (int i = left + 1; i <= right; i++) {
      output += s[i];
    }
    output += ' '; // Ajouter un espace entre les mots
  }

  // Supprimer l'espace en trop à la fin si la chaîne de sortie n'est pas vide
  if (output.size() != 0) {
    output.pop_back();
  }

  return output;
}
```

Cette approche présente une complexité temporelle et spatiale de `O(n)`.

J'ai réalisé après coup que la contrainte exigeait une complexité spatiale de `O(1)`, ce que je n'ai pas encore implémenté.

UPDATE 22-04-2024

Après avoir revisité cet exercice, j'ai mis en œuvre une méthode avec une complexité spatiale de `O(1)`.

Tout d'abord, je commence par inverser la chaîne d'origine, puis j'initialise trois pointeurs:

- `left`, qui marque le début d'un mot dans la chaîne d'origine.
- `right`, qui marque la fin d'un mot dans la chaîne d'origine.
- `rightNS`, qui représente la taille de la nouvelle chaîne.

Ensuite, je parcours la chaîne inversée grâce à une boucle while imbriquée avec deux autres:

- La première boucle permet de passer les espaces.
- La deuxième parcourt le mot tout en décalant les caractères à leur place pour former une chaîne qui sépare les mots avec seulement un espace. À la fin des deux boucles, j'inverse les caractères du mot actuel et j'ajoute un espace à l'indice de fin de la nouvelle chaîne.

À la fin de la boucle principale, je supprime tous les espaces qui se trouvent à la fin de celle-ci et je la renvoie comme réponse.

Cette nouvelle approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`, ce qui respecte les contraintes de l'exercice.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
