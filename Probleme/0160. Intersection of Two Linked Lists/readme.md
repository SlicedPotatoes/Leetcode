# 160. Intersection of Two Linked Lists

## Énoncé

Étant donné les têtes de deux listes chaînées `headA` et `headB`, renvoie le nœud auquel les deux listes se croisent. Si les deux listes chaînées n'ont aucune intersection, renvoyez `null`.

Par exemple, les deux listes chaînées suivantes commencent à se croiser au niveau du nœud `c1`:

<img src="./imgs/img1.png"/>

Les cas de test sont générés de telle sorte qu'il n'y a aucun cycle.

**Notez** que les listes chaînées doivent **conserver leur structure d'origine** après le retour de la fonction.

**Juge:**

Les entrées du **juge** sont données comme suit (votre programme ne reçoit pas ces entrées):

- `intersectVal` - La valeur du nœud où se produit l'intersection. Elle vaut `0` s'il n'y a aucun nœud intersecté.
- `listA` - La première liste chaînée.
- `listB` - La deuxième liste chaînée.
- `skipA` - Le nombre de nœuds à sauter dans `listA` (en commençant par la tête) pour accéder au nœud intersecté.
- `skipB` - Le nombre de nœuds à sauter dans `listB` (en commençant par la tête) pour accéder au nœud intersecté.

Le juge créera ensuite les listes basée sur ces entrées et transmettra les deux têtes `headA` et `headB` à votre programme. Si vous renvoyez correctement le nœud intersecté, alors votre solution sera **acceptée**.

Pourriez-vous écrire une solution qui a une complexité temporelle de `O(m + n)` et une complexité spatiale de `O(1)`.

## Exemple

**Exemple 1:**

<img src="./imgs/img2.png"/>

**Input:** intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3  
**Output:** Intersection à '8'.

**Exemple 2:**

<img src="./imgs/img3.png"/>

**Input:** intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1  
**Output:** Intersection à '2'.

**Exemple 3:**

<img src="./imgs/img4.png"/>

**Input:** intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2  
**Output:** Aucune intersection.

## Contraintes

Le nombre de nœuds de `listA` est `m`.  
Le nombre de nœuds de `listB` est `n`.  
`1 <= m, n <= 3 * 10^4`  
`1 <= Node.val <= 10^5`  
`0 <= skipA < m`  
`0 <= skipB < n`  
`intersectVal` est `0` si `listA` et `listB` ne se croisent pas.  
`intersectVal` == `listA[skipA]` == `listB[skipB]` si `listA` et `listB` se croisent.

## Note personnelle

Pour aborder ce problème, j'ai initialement opté pour l'utilisation d'un ensemble. J'ai inséré tous les nœuds de `listA` dans celui-ci, puis parcouru `listB` en vérifiant si le nœud actuel se trouvait dans l'ensemble. Si tel était le cas, nous avions notre intersection.

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  unordered_set<ListNode*> seen;

  while(headA){
    seen.insert(headA);
    headA = headA->next;
  }

  while(headB){
    if(seen.contains(headB)){
      return headB;
    }
    headB = headB->next;
  }

  return nullptr;
}
```

Cette approche présente une complexité temporelle de `O(m + n)` et une complexité spatiale de `O(m)`, où `m` est le nombre d'éléments de `listA` et `n` le nombre d'éléments dans `listB`.

Cependant, cette approche ne respecte pas la contrainte d'avoir une complexité spatiale constante de `O(1)`.

Après plusieurs tentatives pour trouver une technique permettant d'utiliser un espace constant, je suis parvenu à la solution que je vais décrire ci-dessous. Je ne pense pas que ce soit la plus optimale, mais je suis globalement fier de l'avoir trouvée.

L'idée est de compter le nombre d'éléments dans chacune des listes. Une fois arrivé au dernier nœud des listes, je vérifie s'il s'agit des mêmes. Si c'est le cas, il y a une intersection, sinon je renvoie `null`.

Je réinitialise les pointeurs qui me permettent de parcourir les listes et itère sur celui qui correspond à la liste ayant le plus d'éléments. J'arrête l'itération quand j'ai un nœud ayant la même distance de la fin de la liste que le nœud de départ de l'autre liste.

Il ne me reste plus qu'à itérer sur les deux listes en même temps et trouver le premier nœud commun.

Cette approche présente une complexité temporelle de `O(m + n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
