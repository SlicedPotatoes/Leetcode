# 141. Linked List Cycle

## Énoncé

Étant donné `head`, la tête d'une liste chaînée, déterminez si la liste chaînée contient un cycle.

Il y a un cycle dans une liste chaînée s'il existe un noeud dans la liste qui peut être atteint à nouveau en suivant continuellement le pointeur `next`. En interne, `pos` est utilisé pour indiquer l'index du noeud auquel le pointeur `next` de la queue est connecté. **Notez que `pos` n'est pas passé en tant que paramètre.**

Renvoie `true` s'il y a un cycle dans la liste chaînée. Sinon, renvoyez `false`.

Pouvez-vous le résoudre avec une complexité spatialle de `O(1)` ?

## Exemple

**Exemple 1:**  
<img src="../imgs/0141-img1.png"/>

**Input:** head = [3,2,0,-4], pos = 1  
**Output:** true

**Exemple 2:**  
<img src="../imgs/0141-img2.png"/>

**Input:** head = [1,2], pos = 0  
**Output:** true

**Exemple 3:**  
<img src="../imgs/0141-img3.png"/>

**Input:** head = [1], pos = -1  
**Output:** false

## Contraintes

Le nombre de noeuds dans la liste est compris dans la plage `[0, 10^4]`.  
`-10^5 <= Node.val <= 10^5`  
`pos` est `-1` ou un **index valide** dans la liste chaînée.

## Note personnelle

Ma première approche pour résoudre ce problème impliquait de parcourir la liste chaînée en modifiant ses valeurs. J'ai eu cette idée en remarquant la contrainte spécifiée: `-10^5 <= Node.val <= 10^5`.  
En attribuant une valeur en dehors de cet intervalle, si je rencontrais cette valeur lors de mon parcours, je pourrais détecter la présence d'une boucle dans la liste chaînée.

```cpp
bool hasCycle(ListNode *head) {
  while (head != nullptr) {
    // Si la valeur du noeud actuel est égale à 100001,
    // cela signifie que nous avons déjà visité ce noeud,
    // donc il y a un cycle dans la liste chaînée.
    if (head->val == 100001) {
      return true;
    }
    // Marquer le noeud actuel comme visité en changeant sa valeur à 100001.
    head->val = 100001;
    // Passer au noeud suivant.
    head = head->next;
  }
  // Si nous sortons de la boucle while, cela signifie que nous avons parcouru
  // toute la liste sans rencontrer une valeur de 100001, donc il n'y a pas de cycle.
  return false;
}
```

Bien que cette approche soit efficace avec une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`, elle n'est pas pratique dans un cas réel car elle altère les valeurs de la liste chaînée.

Une autre approche consiste à créer un ensemble pour stocker les nœuds visités pendant le parcours. Son implémentation est assez similaire à celle de l'approche précédente, mais elle ne modifie pas les valeurs des noeuds.

```cpp
bool hasCycle(ListNode *head) {
  // Déclaration d'un ensemble non ordonné pour stocker les noeuds déjà visités
  unordered_set<ListNode *> seen;
  // Parcourir la liste tant que le pointeur actuel n'est pas nul
  while (head != nullptr) {
    // Si le noeud actuel est déjà dans l'ensemble, cela signifie qu'il y a un cycle
    if (seen.count(head) != 0) {
      return true;
    }
    seen.insert(head); // Insérer le nœud actuel dans l'ensemble
    head = head->next; // Déplacer le pointeur actuel vers le prochain nœud
  }
  return false; // Si la boucle se termine sans trouver de cycle, renvoyer faux
}
```

Cette approche a une efficacité avec une complexité temporelle et spatiale de `O(n)`, mais elle ne satisfait pas la contrainte de maintenir une complexité spatiale de `O(1)`.

Ma dernière approche consiste à utiliser deux pointeurs, `slow` et `fast`. Je parcours la liste tant que `fast` ou `fast->next` ne sont pas des `nullptr`.
À chaque itération, je fais avancer `fast` de deux pas et `slow` d'un pas. Ensuite, je vérifie si `fast == next`. Si c'est le cas, il y a un cycle dans la liste.

Cette approche a une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`, respectant ainsi la contrainte de l'exercice. Elle a l'avantage de ne pas modifier la liste d'origine ce qui est plus exploitable dans un cas plus concret.

<img src="../imgs/0141-runtime.png"/>
<img src="../imgs/0141-memory.png"/>
