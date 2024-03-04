# 19. Remove Nth Node From End of List

## Énoncé

Étant donné la `head` d'une liste chaînée, supprimez le `n ième` noeud de la fin de la liste et renvoyez sa tête.

Pourriez-vous faire cela en un seul passage ?

## Exemple

**Exemple 1:**  
<img src="../imgs/0019-img1.jpg"/>  
**Input:** head = [1,2,3,4,5], n = 2  
**Output:** [1,2,3,5]

**Exemple 2:**  
**Input:** head = [1], n = 1  
**Output:** []

**Exemple 3:**  
**Input:** head = [1, 2], n = 1  
**Output:** [1]

## Contraintes

Le nombre de noeuds dans la liste est `sz`.  
`1 <= sz <= 30`  
`0 <= Node.val <= 100`  
`1 <= n <= sz`

## Note personnelle

Ma méthode repose sur l'utilisation d'une fonction récursive. En exploitant sa nature de pile, je suis capable de compter le nombre d'éléments depuis la fin. Cette fonction récursive parcourt la liste jusqu'à rencontrer le `n ième` élément, puis procède à sa suppression en réaffectant les pointeurs.

Si, à la fin de tous les appels récursifs la taille est `==n`, alors nous renvoyons `head->next`.

Cette approche présente une complexité temporelle et spatiale de `O(n)`.

Une autre approche que j'ai observée dans les solutions proposées par la communauté consiste à utiliser deux pointeurs, un `fast` et un `slow`.  
L'idée est d'itérer `n` fois sur `fast`. Si après cette opération `fast == nullptr`, alors nous retournons `head->next` car le `n ième` élément est le début de notre liste.

Sinon, nous continuons à itérer sur `fast` et `slow` simultanément jusqu'à ce que `fast` soit nul. Ainsi, `slow` aura la valeur du `n-1 ième` élément et il nous suffira de supprimer l'élément suivant puis retourner le début de notre liste.

```cpp
//Crédit @DevOgabek sur Leetcode
ListNode* removeNthFromEnd(ListNode* head, int n) {
  // Pointeur rapide pour parcourir la liste en avance
  ListNode* fast = head;
  // Pointeur lent pour suivre n positions derrière le pointeur rapide
  ListNode* slow = head;

  // Faire avancer le pointeur rapide de n positions dans la liste
  for (int i = 0; i < n; i++) {
    fast = fast->next;
  }

  //Si fast est devenu NULL, cela signifie que la position à supprimer est la première élément de la liste, donc on renvoie head->next
  if (fast == NULL) {
    return head->next;
  }

  // Parcourir la liste jusqu'à ce que le pointeur rapide atteigne la fin
  // Maintenant, le pointeur lent sera à la position précédant l'élément à supprimer
  while (fast->next) {
    fast = fast->next;
    slow = slow->next;
  }
  // Une fois que le pointeur rapide est à la fin, le pointeur lent est juste avant  l'élément à supprimer. Ainsi, on le supprime en ajustant les pointeurs.

  slow->next = slow->next->next;

  return head;
}
```

Complexité temporelle `O(n)`  
Complexité spatiale `O(1)`

<img src="../imgs/0019-runtime.png"/>
<img src="../imgs/0019-memory.png"/>
