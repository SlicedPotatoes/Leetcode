# 3096. Minimum Levels to Gain More Points

## Énoncé

On vous donne un tableau binaire `possible` de longueur `n`.

Alice et Bob jouent à un jeu qui consiste en `n` niveaux. Certains des niveaux du jeu sont **impossibles** à terminer tandis que d'autres peuvent **toujours** être terminés. En particulier, si `possible[i] == 0`, alors le `ième` niveau est **impossible** à terminer pour **les deux** joueurs. Un joueur gagne `1` point en terminant un niveau et perd `1` point s'il échoue à le terminer.

Au début du jeu, Alice jouera certains niveaux dans l' **ordre donné** en commençant par le niveau `0`, après quoi Bob jouera pour les niveaux restants.

Alice veut savoir le nombre **minimum** de niveaux qu'elle doit jouer pour obtenir plus de points que Bob, si les deux joueurs jouent de manière optimale pour **maximiser** leurs points.

Retournez le **nombre minimum** de niveaux qu'Alice doit jouer pour obtenir plus de points. Si cela n'est pas possible, retournez `-1`.

**Note** ue chaque joueur doit jouer au moins `1` niveau.

## Exemple

**Exemple 1:**  
**Input:** possible = [1,0,1,0]  
**Output:** 1  
**Explication:**

- Si Alice ne joue que le niveau 0 et que Bob joue le reste des niveaux, Alice a 1 point, tandis que Bob a -1 + 1 - 1 = -1 point.
- Si Alice joue jusqu'au niveau 1 et que Bob joue le reste des niveaux, Alice a 1 - 1 = 0 point, tandis que Bob a 1 - 1 = 0 point.
- Si Alice joue jusqu'au niveau 2 et que Bob joue le reste des niveaux, Alice a 1 - 1 + 1 = 1 point, tandis que Bob a -1 point.

Alice doit jouer au minimum 1 niveau pour obtenir plus de points.

**Exemple 2:**  
**Input:** possible = [1,1,1,1,1]  
**Output:** 3  
**Explication:**

- Si Alice joue uniquement au niveau 0 et que Bob joue aux autres niveaux, Alice a 1 point, tandis que Bob en a 4.
- Si Alice joue jusqu'au niveau 1 et que Bob joue aux autres niveaux, Alice a 2 points, tandis que Bob en a 3.
- Si Alice joue jusqu'au niveau 2 et que Bob joue aux autres niveaux, Alice a 3 points, tandis que Bob en a 2.
- Si Alice joue jusqu'au niveau 3 et que Bob joue aux autres niveaux, Alice a 4 points, tandis que Bob en a 1.

Alice doit jouer au minimum à 3 niveaux pour obtenir plus de points.

**Exemple 3:**  
**Input:** possible = [0,0]  
**Output:** -1  
**Explication:**  
La seule façon possible est que les deux joueurs jouent 1 niveau chacun. Alice joue au niveau 0 et perd 1 point. Bob joue au niveau 1 et perd 1 point. Comme les deux joueurs ont le même nombre de points, Alice ne peut pas gagner plus de points que Bob.

## Contraintes

`2 <= n == possible.length <= 10^5`  
`possible[i]` vaut soit `0` soit `1`.

## Note personnelle

Pour résoudre ce problème, j'utiliserai le principe des sommes préfixées avec une légère subtilité:  
Lorsque je rencontre un `0`, je le considère comme `-1`.

L'idée est assez simple. Tout d'abord, je calcule la somme cumulée totale des éléments que je stocke dans une variable `sum`.

Ensuite, je parcours le tableau une seconde fois en calculant également la somme cumulée, que je stocke dans la variable `current`, tout en décrémentant `sum`. Si, à un moment donné, `current` devient supérieur à `sum`, alors l'indice actuel `i + 1` représente le nombre minimum de jeux qu'Alice doit jouer pour obtenir plus de points que Bob.

Si cette condition n'est jamais remplie, cela signifie qu'Alice ne peut pas gagner, et nous retournons donc `-1`.

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
