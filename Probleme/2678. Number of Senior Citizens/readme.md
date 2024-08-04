# 2678. Number of Senior Citizens

## Énoncé

Vous avez un tableau **indexé à partir de 0** de chaînes de caractères `details`. Chaque élément de `details` fournit des informations sur un passager donné, compressées en une chaîne de longueur `15`. Le système est tel que:

- Les dix premiers caractères consistent en le numéro de téléphone des passagers.
- Le caractère suivant indique le sexe de la personne.
- Les deux caractères suivants sont utilisés pour indiquer l'âge de la personne.
- Les deux derniers caractères déterminent le siège attribué à cette personne.

Retournez le nombre de passagers qui ont **strictement plus de 60 ans**.

## Exemple

**Exemple 1:**  
**Input:** details = ["7868190130M7522","5303914400F9211","9273338290F4010"]  
**Output:** 2  
**Explication:** Les passagers aux indices 0, 1 et 2 ont 75, 92 et 40 ans. Ainsi, il y a 2 personnes qui ont plus de 60 ans.

**Exemple 2:**  
**Input:** details = ["1313579440F2036","2921522980M5644"]  
**Output:** 0  
**Explication:** Aucun des passagers n'a plus de 60 ans.

## Contraintes

`1 <= details.length <= 100`  
`details[i].length == 15`  
`details[i]` est composé de chiffres allant de `'0'` à `'9'`.  
`details[i][10]` est soit `'M'`, soit `'F'`, soit `'O'`.  
Les numéros de téléphone et les numéros de siège des passagers sont distincts.

## Note personnelle

Pour résoudre ce problème, il suffit d'extraire l'âge de chaque passager à partir de la chaîne de caractères et d'incrémenter un compteur si cet âge est supérieur à 60 ans.

```cpp
int countSeniors(vector<string>& details) {
  int ans = 0;

  // Parcourir chaque chaîne de caractères dans le vecteur 'details'.
  for(string &s : details){
    // Extraire l'âge.
    int age = ((s[11] - '0') * 10) + s[12] - '0';
    // Vérifier si l'âge est supérieur à 60 ans.
    if(age > 60){
      ans++; // Incrémenter le compteur si l'âge est supérieur à 60.
    }
  }

  return ans; // Retourner le nombre total de personnes âgées de plus de 60 ans.
}
```

l'âge peut également être extrait de cette façon:

```cpp
int age = stoi(s.substr(11, 2));
```

- Complexité Temporelle: `O(n)`.
- Complexité Spatiale: `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
