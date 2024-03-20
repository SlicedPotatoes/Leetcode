# 2390. Removing Stars From a String

## Énoncé

You are given a string `s`, which contains stars `*`.

In one operation, you can:

- Choose a star in `s`.
- Remove the closest **non-star** character to its **left**, as well as remove the star itself.

Return the string after **all** stars have been removed.

**Note:**

- The input will be generated such that the operation is always possible.
- It can be shown that the resulting string will always be unique.

## Exemple

**Exemple 1:**  
**Input:** s = `"leet**cod*e"`  
**Output:** "lecoe"  
**Explication:**

Performing the removals from left to right:

- The closest character to the 1st star is 't' in `"leet**cod*e"`. s becomes `"lee*cod*e"`.
- The closest character to the 2nd star is 'e' in `"lee*cod*e"`. s becomes `"lecod*e"`.
- The closest character to the 3rd star is 'd' in `"lecod*e"`. s becomes `"lecoe"`.
  There are no more stars, so we return "lecoe".

**Exemple 2:**  
**Input:** s = `"erase*****"`  
**Output:** ""  
**Explication:** The entire string is removed, so we return an empty string.

## Contraintes

`1 <= s.length <= 10^5`  
`s` consists of lowercase English letters and stars `*`.  
The operation above can be performed on `s`.

## Note personnelle

Pour aborder initialement le problème, j'ai opté pour une méthode itérative qui parcourt la chaîne depuis la fin. J'ai utilisé une variable nommée `count` pour suivre le nombre d'étoiles à traiter et une autre nommée `output` pour stocker la chaîne résultante.
À chaque itération, si une étoile est rencontrée, j'incrémente le compteur. Sinon, je vérifie si `count` est égal à `0`. Si c'est le cas, j'ajoute le caractère à la fin de `output`. Sinon, je décrémente `count` de `1`.

Avant de renvoyer la chaîne `output` j'inverse tous ses caractères.

En examinant les catégories associées à l'exercice, j'ai repéré l'étiquette `stack`, ce qui m'a incité à essayer une implémentation utilisant une pile, comme illustré ci-dessous :

```cpp
string removeStars(string &s) {
  stack<char> sta;

  for(int i = 0; i < s.size(); i++){
    sta.push(s[i]);
  }

  string output;

  int n = 0;

  while(!sta.empty()){
    char current = sta.top();
    sta.pop();
    if(current == '*'){
      n++;
    }
    else if(n != 0){
      n--;
    }
    else{
      output += current;
    }
  }

  reverse(output.begin(), output.end());

  return output;
}
```

Les deux approches présentent une complexité spatiale et temporelle de `O(n)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
