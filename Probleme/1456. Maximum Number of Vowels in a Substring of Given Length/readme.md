# 1456. Maximum Number of Vowels in a Substring of Given Length

## Énoncé

Étant donné une chaîne `s` et un entier `k`, envoie le nombre maximum de lettres de voyelles dans toute sous-chaîne de `s` de longueur `k`.

**Les voyelles** en anglais sont `'a'`, `'e'`, `'i'`, `'o'`, et `'u'`.

## Exemple

**Exemple 1:**  
**Input:** s = "abciiidef", k = 3  
**Output:** 3  
**Explication:** La sous-chaîne "iii" contient 3 voyelles.

**Exemple 2:**  
**Input:** s = "aeiou", k = 2  
**Output:** 2  
**Explication:** Toute sous-chaîne de longueur 2 contient 2 voyelles.

**Exemple 3:**  
**Input:** s = "leetcode", k = 3  
**Output:** 2  
**Explication:** "lee", "eet" et "ode" contiennent 2 voyelles.

## Contraintes

`1 <= s.length <= 10^5`  
`s` se compose de lettres anglaises minuscules.  
`1 <= k <= s.length`

## Note personnelle

Pour résoudre ce problème, j'ai adopté une approche similaire à celle des **PrefixSum** mais avec une différence importante : chaque voyelle est évaluée à `1` tandis que chaque consonne est évaluée à `0`.

Mon algorithme parcourt la chaîne pour remplir les valeurs de mon tableau `prefixSum` en appliquant ce concept. Ensuite, une variable `output` est créée pour stocker le résultat final du programme, initialement défini sur `prefixSum[k]`.

Je parcours ensuite la chaîne depuis `k+1` jusqu'à `s.size()` inclus. En utilisant la formule `prefixSum[i] - prefixSum[i - k]`, je peux obtenir le nombre de caractères voyelles dans la plage donnée.

```cpp
// Fonction pour vérifier si un caractère est une voyelle
bool isVowels(char c){
	return c  == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int maxVowels(string s, int k) {
  // Initialisation du vecteur prefixSum
	vector<int> prefixSum = {0};

  // Calcul de la somme de préfixe des voyelles pour chaque caractère de la chaîne
	for(char c : s){
		prefixSum.push_back(dp[dp.size() - 1] + isVowels(c));
	}

  // Initialise la sortie avec la somme de préfixe pour la première sous-chaîne de longueur k
	int output = prefixSum[k];

  // Parcours de la chaîne à partir de la position k + 1
	for(int i = k + 1; i <= s.size(); i++){
    // Mise à jour de la sortie avec la différence entre les sommes de préfixe actuelle et précédente
		output = max(output, prefixSum[i] - prefixSum[i - k]);
	}

	return output;
}
```

Cette approche présente une complexité temporelle et spatiale de `O(n)`.

Une optimisation consiste à se débarrasser du tableau `prefixSum`. Pour cela, j'initialise une variable `sum` à la valeur de la première sous-chaîne de longueur `k`. Ensuite, je parcours de `k` jusqu'à `s.size()`, j'ajoute `1` à `sum` si `s[i]` est une voyelle et je lui enlève `1` si `s[i - k]` est une voyelle.

Cette optimisation maintient une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
