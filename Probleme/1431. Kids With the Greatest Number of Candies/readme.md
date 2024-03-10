# 1431. Kids With the Greatest Number of Candies

## Énoncé

Il y a `n` enfants avec des bonbons. On vous donne un tableau d'entiers `candies`, où chaque `candies[i]` représente le nombre de bonbons que possède le `ieme` enfant, et un entier `extraCandies`, indiquant le nombre de bonbons supplémentaires dont vous disposez.

Renvoie un tableau booléen `result` de longueur `n`, où `result[i]` est `true` si, après avoir donné au `ieme` enfant tous les `extraCandies`, il aura le plus grand nombre de bonbons parmi tous les enfants, ou `false` autrement.

Notez que plusieurs enfants peuvent avoir le plus grand nombre de bonbons.

## Exemple

**Exemple 1:**  
**Input:** candies = [2,3,5,1,3], extraCandies = 3  
**Output:** [true,true,true,false,true]  
**Explication:** Si vous donnez tous les bonbons supplémentaires à :

- Kid 1, Il aura 2 + 3 = 5 bonbons, ce qui est le plus grand parmi les enfants.
- Kid 2, Il aura 3 + 3 = 6 bonbons, ce qui est le plus grand parmi les enfants.
- Kid 3, Il aura 5 + 3 = 8 bonbons, ce qui est le plus grand parmi les enfants.
- Kid 4, Il aura 1 + 3 = 4 bonbons, ce qui n'est pas le plus grand parmi les enfants.
- Kid 5, Il aura 3 + 3 = 6 bonbons, ce qui est le plus grand parmi les enfants.

**Exemple 2:**  
**Input:** candies = [4,2,1,1,2], extraCandies = 1  
**Output:** [true,false,false,false,false]  
**Explication:** Il n'y a qu'un seul bonbon supplémentaire.  
Kid 1 aura toujours le plus grand nombre de bonbons, même si un autre enfant reçois le bonbon supplémentaire.

**Exemple 3:**  
**Input:** candies = [12,1,12], extraCandies = 10  
**Output:** [true,false,true]

## Contraintes

`n == candies.length`  
`2 <= n <= 100`  
`1 <= candies[i] <= 100`  
`1 <= extraCandies <= 50`

## Note personnelle

Il n'y a pas grand-chose à ajouter concernant cet exercice. Bien que l'énoncé ne soit pas très clair, un commentaire sous l'exercice a clarifié les exemples pour mieux comprendre ce que nous devions faire.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
