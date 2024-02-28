# 1854. Maximum Population Year

## Énoncé

Vous recevez un tableau d'entiers 2D `logs` où chaque `logs[i] = [birthi, deathi]` indique les années de naissance et de décès de la `ith` personne.

La **population** d'une année `x` est le nombre de personnes vivantes au cours de cette année. La `ith` personne est comptée dans la population de l'année `x` si `x` est dans la plage **incluse** `[birthi, deathi - 1]`. Notez que la personne n’est pas comptée l’année de son décès.

Renvoie l'année **la plus ancienne** avec la **population maximale**.

## Exemple

**Exemple 1:**  
**Input:** logs = [[1993,1999],[2000,2010]]  
**Output:** 1993  
**Explication:** La population maximale est de 1, et 1993 est la première année avec cette population.

**Exemple 2:**  
**Input:** logs = [[1950,1961],[1960,1971],[1970,1981]]  
**Output:** 1960  
**Explication:** La population maximale est de 2 personnes, et cela s'est produit dans les années 1960 et 1970.  
L’année la plus ancienne entre eux est 1960.

## Contraintes

`1 <= logs.length <= 100`  
`1950 <= birthi < deathi <= 2050`

## Note personnelle

Ma première approche pour aborder ce problème était assez naïve. J'ai parcouru chaque élément de `logs`, puis j'ai itéré sur la plage `[birthi, deathi]` pour incrémenter un compteur pour chaque année.

Cette approche avait une complexité de `O(n*m)`, où `n` est le nombre d'éléments dans le tableau et `m` représente la plage des années.

```cpp
const int MIN_YEARS = 1950;
int maximumPopulation(vector<vector<int>>& logs) {
  vector<int> years(100);
  int max = 0;
  int maxYears;

  for(vector<int>& person : logs){
    for(int i = person[0] - MIN_YEARS; i < person[1] - MIN_YEARS; i++){
      years[i]++;
      if(years[i] > max || (years[i] == max && i < maxYears)){
        max = years[i];
        maxYears = i;
      }
    }
  }

  return maxYears + MIN_YEARS;
}
```

Je trouvais cela peu optimal et donc j'ai essayé de l'optimiser, même si l'exercice ne le demandait pas explicitement.  
En examinant les tags de l'exercice, j'ai remarqué **Prefix Sum** et j'ai cherché un moyen de résoudre le problème avec ce principe en tête.

L'idée qui m'est venue était de parcourir les éléments de `logs` et d'incrémenter un compteur uniquement pour l'année de naissance et de décrémenter le compteur pour l'année de décès.

En adoptant cette approche, le compteur ne représente plus la population totale pour l'année, mais seulement les changements qui ont eu lieu cette année-là.

En parcourant ensuite les compteurs et en les additionnant au fur et à mesure, j'obtiens pour `years[i]` le nombre d'habitants pour l'année `i`.

<img src="../imgs/1854-runtime.png"/>
<img src="../imgs/1854-memory.png"/>
