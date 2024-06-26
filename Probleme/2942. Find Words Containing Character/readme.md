# 2942. Find Words Containing Character

## Énoncé

Vous avez un tableau de chaînes de caractères `words` **indexé à partir de 0** et un caractère `x`.

Retournez un **tableau d'indices** représentant les mots qui contiennent le caractère `x`.

**Notez** que le tableau retourné peut être dans n'importe quel ordre.

## Exemple

**Exemple 1:**  
**Input:** words = ["leet","code"], x = "e"  
**Output:** [0,1]  
**Explication:** "e" apparaît dans les deux mots : "leet" et "code". Par conséquent, nous retournons les indices 0 et 1.

**Exemple 2:**  
**Input:** words = ["abc","bcd","aaaa","cbc"], x = "a"  
**Output:** [0,2]  
**Explication:** "a" apparaît dans "abc" et "aaaa". Par conséquent, nous retournons les indices 0 et 2.

**Exemple 3:**  
**Input:** words = ["abc","bcd","aaaa","cbc"], x = "z"  
**Output:** []  
**Explication:** "z" n'apparaît dans aucun des mots. Par conséquent, nous retournons un tableau vide.

## Contraintes

`1 <= words.length <= 50`  
`1 <= words[i].length <= 50`  
`x` est une lettre minuscule de l'alphabet anglais.  
`words[i]` ne contient que des lettres minuscules de l'alphabet anglais.

## Note personnelle

Pour résoudre ce problème, il suffit d'itérer sur chaque mot du tableau, et pour chaque mot, itérer sur chaque caractère. Si un caractère est égal à `x`, on ajoute l'indice du mot au tableau des résultats et on passe au mot suivant.

```cpp
vector<int> findWordsContaining(vector<string> &words, char x) {
  vector<int> ans; // Vecteur pour stocker les indices des mots contenant le caractère x

  // Parcourt chaque mot dans le vecteur de mots
  for (int i = 0; i < words.size(); i++) {
    // Parcourt chaque caractère du mot courant
    for (char c : words[i]) {
      // Si le caractère courant est égal à x
      if (c == x) {
        ans.push_back(i); // Ajoute l'indice du mot à la liste des résultats
        break;            // Sort de la boucle interne pour passer au mot suivant
      }
    }
  }

return ans; // Retourne le vecteur des indices
}
```

On peut également remplacer la boucle sur les caractères par le code suivant pour simplifier l'implémentation:

```cpp
if(words[i].find(x) != string::npos){
  ans.push_back(i);
}
```

Cette solution présente une complexité temporelle de `O(n * m)` et une complexité spatiale de `O(1)`, où `n` est le nombre de mots dans le tableau et `m` est la longueur moyenne des mots.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
