# 997. Find the Town Judge

## Énoncé

Dans une ville, il y a `n` personnes étiquetées de `1` à `n`. Une rumeur court selon laquelle l'une de ces personnes serait secrètement juge de la ville.

Si le juge municipal existe, alors :

1. Le juge municipal ne fait confiance à personne.
2. Tout le monde (sauf le juge municipal) fait confiance au juge municipal.
3. Il y a exactement une personne qui satisfait les règles **1** et **2**.

Vous recevez un tableau `trust` où `trust[i] = [ai, bi]` représentant que la personne étiquetée `ai` ait confiance à la personne étiquetée `bi`. Si une relation de confiance n'existe pas dans le tableau `trust`, alors une telle relation de confiance n'existe pas.

Renvoie l'étiquette du juge municipal si le juge municipal existe et peut être identifié, ou renvoie `-1` dans le cas contraire.

## Exemple

**Exemple 1:**  
**Input:** n = 2, trust = [[1,2]]  
**Output:** 2

**Exemple 2:**  
**Input:** n = 3, trust = [[1,3],[2,3]]  
**Output:** 3

**Exemple 3:**  
**Input:** n = 3, trust = [[1,3],[2,3],[3,1]]  
**Output:** -1

## Contraintes

`1 <= n <= 1000`  
`0 <= trust.length <= 10^4`  
`trust[i].length == 2`  
Toutes les paires de `trust` sont uniques.  
`ai != bi`  
`1 <= ai, bi <= n`

## Note personnelle

Pour résoudre ce problème, j'ai opté pour une approche utilisant une structure pour représenter chaque individu, comportant deux compteurs : l'un pour le nombre de personnes en qui il a confiance, et l'autre pour le nombre de personnes qui lui font confiance.

J'ai créé un vecteur contenant ces structures, et lors du parcours des paires de confiance, j'ai incrémenté les compteurs correspondants.

Pour une petite optimisation, j'ai augmenté la taille du conteneur lors de son initialisation de 1, car les étiquettes sont indexées à partir de 1. Cela m'a évité de devoir soustraire 1 à chaque itération.

De plus, j'ai initialisé `trustedOf` à 1 pour les mêmes raisons, ce qui m'a permis de gagner environ 15 ms en temps d'exécution."

<img src="../imgs/0997-runtime.png"/>
<img src="../imgs/0997-memory.png"/>
