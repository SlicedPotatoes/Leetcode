# 234. Palindrome Linked List

## Énoncé

Étant donné la `head` d'une liste chaînée simple, retournez `true` si c'est un
**palindrome** ou sinon `false`.

Pourriez-vous le faire avec une compexité temporelle de `O(n)` et complexité spatiale de `O(1)` ?

## Exemple

**Exemple 1:**  
<img src="./imgs/img1.jpg"/>

**Input:** head = [1,2,2,1]  
**Output:** true

**Exemple 2:**  
<img src="./imgs/img2.jpg"/>

**Input:** head = [1,2]  
**Output:** false

## Contraintes

Le nombre de noeuds dans la liste est compris entre `[1, 10^5]`  
`0 <= Node.val <= 9`

## Note personnelle

Pour résoudre ce problème, j'ai d'abord adopté une approche utilisant une pile. L'idée était de parcourir la liste fois, en stockant chaque élément dans une pile, puis de parcourir à nouveau la liste en vérifiant si les éléments au sommet de la pile correspondaient à ceux de la liste d'origine.

```cpp
bool isPalindrome(ListNode* head) {
  stack<int> s;

  // Parcours de la liste chaînée pour empiler ses valeurs
  ListNode* curr = head;
  while(curr){
    s.push(curr->val);
    curr = curr->next;
  }

  // Parcours de la liste chaînée pour comparer ses valeurs avec celles de la pile
  while(head){
    // Comparaison de la valeur actuelle avec celle au sommet de la pile
    if(head->val != s.top()){
      // Si les valeurs diffèrent, la liste n'est pas un palindrome
      return false;
    }
    // Suppression de la valeur comparée de la pile
    s.pop();
    // Passage au prochain noeud dans la liste
    head = head->next;
  }
  return true;
}
```

Cette approche présente une complexité temporelle et spatiale de `O(n)`.

Ensuite, j'ai exploré une autre approche qui n'utilisait pas d'espace de stockage supplémentaire proportionnel à la taille de la liste.
J'ai utilisé la technique des pointeurs lents et rapides pour trouver le centre de la liste. Ensuite, j'ai inversé la deuxième moitié de la liste et comparé les valeurs une par une en parcourant la liste avec deux pointeurs, l'un partant du début et l'autre de la moitié.

Cette solution présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

Enfin, pour approfondir mes compétences, j'ai implémenté une approche récursive similaire à la précédente, mais sans modifier la liste d'origine.

```cpp
ListNode* h;
// Fonction récursive pour vérifier si une liste chaînée est un palindrome
bool recursivePalindrome(ListNode* ptr1) {
  // Si ptr1 ne pointe pas vers le noeud suivant
  if (!ptr1->next) {
    // Vérifie si la valeur du noeud actuel (h) est égale à la valeur du dernier noeud (ptr1)
    return h->val == ptr1->val;
  }

  // Appel récursif pour vérifier si les noeuds suivants sont un palindrome
  bool nextValid = recursivePalindrome(ptr1->next);

  // Avance le pointeur h vers le prochain noeud
  h = h->next;

  // Vérifie si les valeurs actuelles (h et ptr1) sont égales
  return nextValid && h->val == ptr1->val;
}
bool isPalindrome(ListNode* head) {
  // Initialisation des pointeurs ptr1 et ptr2 pour parcourir la moitié de la liste
  ListNode* ptr1 = head;
  ListNode* ptr2 = head->next;

  // Parcours de la moitié de la liste
  while (ptr2 && ptr2->next) {
    ptr2 = ptr2->next->next;
    ptr1 = ptr1->next;
  }

  // Initialisation de h à la tête de la liste pour la fonction récursive
  h = head;

  // Appel de la fonction récursive pour vérifier si la liste est un palindrome
  return recursivePalindrome(ptr1);
}
```

Cette dernière approche présente une complexité temporelle et spatiale de `O(n)` en raison de sa nature récursive.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
