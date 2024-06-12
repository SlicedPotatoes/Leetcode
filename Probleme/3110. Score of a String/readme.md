# 3110. Score of a String

## Énoncé

On vous donne une chaîne de caractères `s`. Le **score** d'une chaîne de caractères est défini comme la somme des différences absolues entre les valeurs **ASCII** des caractères adjacents.

Retournez le **score** de `s`.

## Exemple

**Exemple 1:**  
**Input:** s = "hello"  
**Output:** 13  
**Explication:** Les valeurs **ASCII** des caractères dans `s` sont: `'h' = 104`, `'e' = 101`, `'l' = 108`, `'o' = 111`. Donc, le score de `s` serait `|104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13`.

**Exemple 2:**  
**Input:** s = "zaz"  
**Output:** 50  
**Explication:** Les valeurs **ASCII** des caractères dans `s` sont: `'z' = 122`, `'a' = 97`. Donc, le score de `s` serait `|122 - 97| + |97 - 122| = 25 + 25 = 50`.

## Contraintes

`2 <= s.length <= 100`  
`s` se compose uniquement de lettres anglaises minuscules.

## Note personnelle

Cet exercice ne nécessite pas l'utilisation d'algorithmes complexes. Une simple boucle suffit pour calculer les différences absolues entre les valeurs ASCII des caractères consécutifs d'une chaîne de caractères.

```cpp
int scoreOfString(string &s) {
  int ans = 0;

  for(int i = 1; i < s.size(); i++){
    ans += abs(s[i] - s[i - 1]);
  }

  return ans;
}
```

Cette solution présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
