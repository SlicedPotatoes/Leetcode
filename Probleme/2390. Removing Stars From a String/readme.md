# 2390. Removing Stars From a String

## Énoncé

Vous avez une chaîne de caractères `s`, qui contient des étoiles `*`.

En une opération, vous pouvez:

- Choisir une étoile dans `s`.
- Supprimer le caractère **non-étoile** le plus proche à sa **gauche**, ainsi que supprimer l'étoile elle-même.

Retournez la chaîne après que **toutes** les étoiles ont été supprimées.

**Note:**

- L'entrée sera générée de manière à ce que l'opération soit toujours possible.
- Il peut être démontré que la chaîne résultante sera toujours unique.

## Exemple

**Exemple 1:**  
**Input:** s = `"leet**cod*e"`  
**Output:** "lecoe"  
**Explication:**

Effectuer les suppressions de gauche à droite:

- Le caractère le plus proche de la 1ère étoile est 't' dans `"leet**cod*e"`. s devient `"lee*cod*e"`.
- Le caractère le plus proche de la 2nd étoile est 'e' dans `"lee*cod*e"`. s devient `"lecod*e"`.
- Le caractère le plus proche de la 3rd étoile est 'd' dans `"lecod*e"`. s devient `"lecoe"`.

Il n'y a plus d'étoiles, donc nous retournons "lecoe".

**Exemple 2:**  
**Input:** s = `"erase*****"`  
**Output:** ""  
**Explication:** La chaîne entière est supprimée, nous renvoyons donc une chaîne vide.

## Contraintes

`1 <= s.length <= 10^5`  
`s` se compose de lettres anglaises minuscules et d'étoiles `*`.  
L'opération ci-dessus peut être effectuée sur `s`.

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
