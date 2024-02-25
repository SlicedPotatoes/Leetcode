# 2092. Find All People With Secret

## Énoncé

Vous recevez un nombre entier `n` indiquant qu'il y a `n` personnes numérotées de `0` à `n - 1`. Vous recevez également un tableau d'entiers 2D `meetings` où `meetings[i] = [xi, yi, timei]` indique que la personne `xi` et la personne `yi` ont une réunion à `timei`. Une personne peut assister à **plusieurs réunions** en même temps. Enfin, vous recevez un entier `firstPerson`.

La personne `0` a un **secret** et partage initialement le secret avec une personne `firstPerson` au moment `0`. Ce secret est ensuite partagé à chaque fois qu’une rencontre a lieu avec une personne qui détient le secret. Plus formellement, pour chaque réunion, si une personne `xi` a le secret à `timei`, alors elle partagera le secret avec la personne `yi`, et vice versa.

Les secrets sont partagés **instantanément**. Autrement dit, une personne peut recevoir le secret et le partager avec des personnes lors d'autres réunions au cours du même laps de temps.

Renvoyez une liste de toutes les personnes qui détiennent le secret après toutes les réunions. Vous pouvez renvoyer la réponse dans **n'importe quel ordre**.

## Exemple

**Example 1:**  
**Input:** n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1  
**Output:** [0,1,2,3,5]  
**Explication:**  
Au moment 0, la personne 0 partage le secret avec la personne 1.  
Au moment 5, la personne 1 partage le secret avec la personne 2.  
Au moment 8, la personne 2 partage le secret avec la personne 3.  
Au moment 10, la personne 1 partage le secret avec la personne 5.​​​​  
Ainsi, les personnes 0, 1, 2, 3 et 5 connaissent le secret après toutes les réunions.

**Example 2:**
**Input:** n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3  
**Output:** [0,1,3]  
**Explication:**  
Au moment 0, la personne 0 partage le secret avec la personne 3.  
Au moment 2, ni la personne 1 ni la personne 2 ne connaissent le secret  
Au moment 3, la personne 3 partage le secret avec la personne 0 et la personne 1.  
Ainsi, les personnes 0, 1 et 3 connaissent le secret après toutes les réunions.

**Example 3:**
**Input:** n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1  
**Output:** [0,1,2,3,4]  
**Explication:**  
Au moment 0, la personne 0 partage le secret avec la personne 1.  
Au moment 1, la personne 1 partage le secret avec la personne 2 et la personne 2 partage le secret avec la personne 3.  
A noter que la personne 2 peut partager le secret en même temps qu'elle le reçoit.  
Au moment 2, la personne 3 partage le secret avec la personne 4.  
Ainsi, les personnes 0, 1, 2, 3 et 4 connaissent le secret après toutes les réunions.

## Contraintes

`2 <= n <= 10^5`  
`1 <= meetings.length <= 10^5`  
`meetings[i].length == 3`  
`0 <= xi, yi <= n - 1`  
`xi != yi`  
`1 <= timei <= 10^5`  
`1 <= firstPerson <= n - 1`

## Note personnelle

Cet exercice présente un défi intéressant, nécessitant plusieurs problèmes à résoudre pour parvenir au résultat final.
Tout d'abord, il est crucial de structurer les données de manière à les exploiter efficacement. J'ai choisi d'utiliser un vecteur de taille `n` contenant des vecteurs de pointeurs. Chaque indice représente une personne avec la liste de ses réunions. Cette approche permet un accès plus efficace aux informations pendant l'exécution de l'algorithme, tout en évitant la duplication d'informations inutiles grâce à l'utilisation de pointeurs.

Une fois que les données sont accessibles de manière efficace, la prochaine étape consiste à obtenir le résultat attendu. J'ai opté pour l'utilisation d'un parcours en profondeur (DFS), bien que le BFS aurait également pu être une option viable. Pour éviter les boucles infinies lors d'un DFS (ou d'un BFS), il est crucial de garder une trace des noeuds déjà explorés. Pour cela, j'ai utilisé un ensemble (unordered_set) avec une fonction de hachage pour vérifier efficacement si un noeud a déjà été exploré.

À chaque itération du DFS, nous prenons en compte les personnes actuelles et examinons leurs relations. Si la relation a un `timei` supérieur ou égal au `timei` actuel, cela signifie que le secret peut être partagé à ce moment-là ou plus tard. Nous ajoutons donc cette relation à la pile du DFS pour une exploration ultérieure, garantissant que nous prenons en compte toutes les possibilités de partage de secrets. Ce processus se répète jusqu'à ce que toutes les relations soient explorées.
Sans optimisation ma solution a mis 1994ms en moyenne sur les différents jeux de test.

En ce qui concerne les optimisations:

Utilisation d'une unordered_map pour stocker le plus petit `timei` actuellement trouvé pour chaque personne : Cette optimisation permet d'éviter de revisiter les mêmes relations déjà explorées. En gardant une trace du plus petit `timei` rencontré pour chaque personne, nous pouvons sauter les itérations inutiles lorsqu'une personne est rencontrée à un `timei` ultérieur avec un secret déjà partagé.
Après cette optimisation ma solution s'exécuter en 1619ms.

Tri du tableau meetings par `timei` décroissant : En triant le tableau meetings dans l'ordre décroissant selon le temps (`timei`), nous traitons en priorité les réunions les plus récentes. Cela signifie que lors du parcours DFS, nous explorons d'abord les réunions qui ont eu lieu plus tard dans le temps, ce qui permet d'arrêter l'itération quand `timei` est inférieur au `timei` courant.
Après cette optimisation ma solution s'exécuter en 524ms.

<img src="../imgs/2092-runtime.png"/>
<img src="../imgs/2092-memory.png"/>
