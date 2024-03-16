# 21. Merge Two Sorted Lists

## Énoncé

Vous recevez les têtes de deux listes chaînées triées `list1` et `list2`.

Fusionnez les deux listes en une seule liste **triée**. La liste doit être établie en réunissant les nœuds des deux premières listes.

Renvoie la tête de la liste chaînée fusionnée.

## Exemple

**Exemple 1:**

<img src="./imgs/img1.jpg"/>

**Input:** list1 = [1,2,4], list2 = [1,3,4]  
**Output:** [1,1,2,3,4,4]

**Exemple 2:**  
**Input:** list1 = [], list2 = []  
**Output:** []

**Exemple 3:**  
**Input:** list1 = [], list2 = [0]  
**Output:** [0]

## Contraintes

Le nombre de nœuds dans les deux listes est compris entre `[0, 50]`.  
`-100 <= Node.val <= 100`  
`list1` et `list2` sont triés par ordre croissant.

## Note personnelle

Ma méthode implique la création d'une nouvelle liste nommée `margedListHead` et de son pointeur d'élément courant `currentML`. Ensuite, je parcours les deux listes simultanément tant qu'elles contiennent des éléments. À chaque itération, j'effectue les actions suivantes :

- Je compare les valeurs de `list1` et `list2`. Si `list1->val <= list2->val`, alors je mets à jour `currentML->next` avec le pointeur `list1` et je progresse dans `list1` de 1.
- Sinon, je fais la même chose avec `list2`
- Ensuite, j'avance de 1 dans `currentML`.

À la sortie de la boucle, je vérifie si l'une des deux listes n'est pas vide pour l'ajouter à la fin de `currentML`.

J'ai également implémenté une approche récursive de ce problème qui suit le même principe que la version itérative. Les deux approches présentent une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

```cpp
ListNode * merged = new ListNode();
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2, ListNode * currentMerged = merged) {
    // Si les deux listes sont vides
    if(!list1 && !list2){
      return nullptr;
    }

    if(!list1){
      // Si list1 est vide, attache directement list2 à la fin du noeud fusionné
      currentMerged->next = list2;
      // Retourne le début de la liste fusionnée
      return merged->next;
    }
    if(!list2){
      // Si list2 est vide, attache directement list1 à la fin du noeud fusionné
      currentMerged->next = list1;
      // Retourne le début de la liste fusionnée
      return merged->next;
    }

    // Si la valeur du noeud de list1 est inférieure ou égale à celle du noeud de list2
    if(list1->val <= list2->val){
      // Attache le noeud de list1 à la liste fusionnée
      currentMerged->next = list1;
      // Avance le pointeur de list1 au noeud suivant
      list1 = list1->next;
    }
    else{
      // Sinon, attache le noeud de list2 à la liste fusionnée
      currentMerged->next = list2;
      // Avance le pointeur de list2 au noeud suivant
      list2 = list2->next;
    }

    // Appel récursif pour continuer la fusion des listes
    return mergeTwoLists(list1, list2, currentMerged->next);
  }
};
```

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
