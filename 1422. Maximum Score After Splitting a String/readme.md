# 1422. Maximum Score After Splitting a String

## Énoncé

Étant donné une chaîne `s` de zéros et de uns, renvoie le score maximum après avoir divisé la chaîne en deux sous-chaînes **non vides** (c'est-à-dire la sous-chaîne **gauche** et la sous-chaîne **droite**).

Le score après division d'une chaîne est le nombre de **zéros** dans la sous-chaîne **gauche** plus le nombre de **uns** dans la sous-chaîne **droite**.

## Exemple

**Exemple 1:**  
**Input:** s = "011101"  
**Output:** 5  
**Explication:**  
Toutes les manières possibles de diviser s en deux sous-chaînes non vides sont :  
left = "0" et right = "11101", score = 1 + 4 = 5  
left = "01" et right = "1101", score = 1 + 3 = 4  
left = "011" et right = "101", score = 1 + 2 = 3  
left = "0111" et right = "01", score = 1 + 1 = 2  
left = "01110" et right = "1", score = 2 + 1 = 3

**Exemple 2:**  
**Input:** s = "00111"  
**Output:** 5  
**Explication:** Quand left = "00" et right = "111", on obtient le score maximum = 2 + 3 = 5

**Exemple 3:**  
**Input:** s = "1111"  
**Output:** 3

## Contraintes

`2 <= s.length <= 500`  
La chaîne `s` est constituée uniquement des caractères `'0'` et `'1'`.

## Note personnelle

Ma première approche consistait à suivre le nombre de `0` et `1` rencontrés pour chaque indice de la chaîne. Le nombre de `0` est compté en incrémentant l'indice, et les `1` en le décrémentant.

En itérant ensuite sur les tableaux stockant le calcul décrit précédemment, je pouvais obtenir le score maximum pour une chaîne.

```cpp
int maxScore(string s) {
  // Initialisation des vecteurs pour stocker les préfixes de 0 et les suffixes de 1
  vector<int> prefix0(s.size());
  vector<int> suffix1(s.size());

  // Variables pour compter les 0 dans le préfixe et les 1 dans le suffixe
  int prefix = 0;
  int suffix = 0;

  // Calcul des préfixes de 0 et des suffixes de 1
  for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--) {
    if (s[i] == '0') {
      prefix++;
    }
    if (s[j] == '1') {
      suffix++;
    }
    prefix0[i] = prefix;
    suffix1[j] = suffix;
  }

  // Recherche du maximum de la somme des préfixes de 0 et des suffixes de 1
  int max = 0;

  for(int i = 1; i < s.size(); i++){
    int sum = prefix0[i - 1] + suffix1[i];
    if(sum > max){
      max = sum;
    }
  }

  return max;
}
```

Cette approche s'est révélée plutôt efficace avec une complexité temporelle de `O(n)`, cependant, je pense pouvoir améliorer l'utilisation de la mémoire.

Ma deuxième approche permet de supprimer le tableau `suffix`. Pendant l'itération de la chaîne, je calcule seulement le tableau `prefix`.

Ensuite, j'initialise une variable `suffix` en lui attribuant comme valeur la différence entre la taille de la chaîne et le dernier element de `prefix`.

J'itère une seconde fois sur la chaîne pour calculer le score, et chaque fois que je rencontre un `1`, je décrémente `suffix`.

```cpp
int maxScore(string s) {
  // Vecteur pour stocker les préfixes de 0
  vector<int> prefix0(s.size());

  // Variable pour compter les 0 dans le préfixe
  int prefix = 0;

  // Calcul des préfixes de 0
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      prefix++;
    }
    prefix0[i] = prefix;
  }

  // Calcul du suffixe de 1
  int suffix = s.size() - prefix0[s.size() - 1];
  int max = 0;

  // Parcours pour calculer le score maximal
  for(int i = 0; i < s.size() - 1; i++){
    if(s[i] == '1'){
      suffix--; // Décrémenter le suffixe si le caractère est '1'
    }
    // Calcul de la somme des préfixes de 0 et du suffixe
    int sum = prefix0[i] + suffix;
    if(sum > max){
      max = sum; // Mettre à jour le score maximal si nécessaire
    }
  }

  return max;
}
```

Cette approche reste efficace en termes de complexité temporelle (`O(n)`), cependant, j'ai le sentiment que je pourrais réussir à faire en sorte que la fonction ait une complexité spatiale de `O(1)`

Ma troisième et dernière approche consiste à compter le nombre de `0` sans stocker dans un tableau les étapes intermédiaires.

Une fois cela fait, j'initialise une variable du score actuel avec pour valeur le nombre de zéros **et j'incrémente de 1 si la chaîne se termine par un `1`**.

J'itère sur la chaîne inversée en commençant par l'indice `size - 2` (`size - 1` a déjà été pris en compte à l'initialisation de la variable score)
Si je rencontre un `0` je décrémente le score, si je rencontre un `1` j'incrémente le score.

Cette approche a toujours une complexité temporelle de `O(n)` mais en supprimant le tableau `prefix`, elle a une complexité spatiale de `O(1)`

<img src="../imgs/1422-runtime.png"/>
<img src="../imgs/1422-memory.png"/>
