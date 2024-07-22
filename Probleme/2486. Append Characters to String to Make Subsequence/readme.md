# 2486. Append Characters to String to Make Subsequence

## Énoncé

On vous donne deux chaînes de caractères `s` et `t` composées uniquement de lettres minuscules anglaises.

Retournez le nombre minimum de caractères à ajouter à la fin de `s` pour que `t` devienne une **sous-séquence** de `s`.

Une **sous-séquence** est une chaîne de caractères qui peut être dérivée d'une autre chaîne en supprimant certains ou aucun caractères sans changer l'ordre des caractères restants.

## Exemple

**Exemple 1:**  
**Input:** s = "coaching", t = "coding"  
**Output:** 4  
**Explication:** Ajoutez les caractères "ding" à la fin de `s` pour que `s` devienne "coachingding".  
Maintenant, `t` est une sous-séquence de `s` ("<u>**co**</u>aching<u>**ding**</u>").

**Exemple 2:**  
**Input:** s = "abcde", t = "a"  
**Output:** 0  
**Explication:** `t` est déjà une sous-séquence de `s` ("<u>**a**</u>bcde")

**Exemple 3:**  
**Input:** s = "z", t = "abcde"  
**Output:** 5  
**Explication:** Ajoutez les caractères "abcde" à la fin de `s` pour que `s` devienne "zabcde".  
Maintenant, `t` est une sous-séquence de `s` ("z<u>**abcde**</u>").

## Contraintes

`1 <= s.length, t.length <= 10^5`  
`s` et `t` se composent uniquement de lettres anglaises minuscules.

## Note personnelle

Pour résoudre ce problème, j'ai opté pour la méthode des deux pointeurs. L'idée est d'itérer sur la chaîne `s` tout en vérifiant si le caractère actuel de `t` correspond au caractère actuel de `s` (`s[i] == t[j]`). Si c'est le cas, on incrémente `j`. De cette manière, si à la fin de l'itération sur `s`, on ajoute les éléments restants de `t` à la chaîne, alors `t` sera une **sous-séquence** de `s`.

```cpp
int appendCharacters(string s, string t) {
  int j = 0; // Index pour parcourir la chaîne t

  // Parcours de chaque caractère de s
  for(int i = 0; i < s.size(); i++){
    // Si le caractère actuel de s correspond au caractère actuel de t
    if(s[i] == t[j]){
      // Si tous les caractères de t ont été trouvés dans s
      if (++j == t.size()) {
        return 0; // Aucun caractère à ajouter
      }
    }
  }

  // Calculer le nombre de caractères restants à ajouter pour que t devienne une sous-séquence de s
  return t.size() - j;
}
```

- Complexité Temporelle: `O(n)`
- Complexité Spatiale: `O(1)`

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
