# 623. Add One Row to Tree

## Énoncé

Étant donné la `root` d'un arbre binaire et deux entiers `val` et `depth`, ajoutez une ligne de noeuds avec la valeur `val` à la profondeur donnée `depth`.

Notez que le noeud `root` est à la profondeur `1`.

Les règles d'ajout sont les suivantes:

- Pour chaque noeud d'arbre non nul `cur` à la profondeur `depth - 1`, créer deux noeuds d'arbre avec la valeur `val` en tant que racine du sous-arbre gauche et de la racine du sous-arbre droit de `cur`.
- Le sous-arbre gauche d'origine de `cur` devrait être le sous-arbre gauche de la nouvelle racine du sous-arbre gauche.
- Le sous-arbre droit d'origine de `cur` devrait être le sous-arbre droit de la nouvelle racine du sous-arbre droit.
- Si `depth == 1`, cela signifie qu'il n'y a pas de profondeur `depth - 1` du tout, alors créer un noeud d'arbre avec la valeur `val` comme nouvelle racine de tout l'arbre d'origine, et l'arbre d'origine est le sous-arbre gauche de la nouvelle racine.

## Exemple

**Exemple 1:**

<img src="./imgs/img1.jpg" style="width: 500px; height: 231px;"/>

**Input:** root = [4,2,6,3,1,5], val = 1, depth = 2  
**Output:** [4,1,1,2,null,null,6,3,1,5]

**Exemple 2:**

<img src="./imgs/img2.jpg" style="width: 500px; height: 277px;"/>

**Input:** root = [4,2,null,3,1], val = 1, depth = 3  
**Output:** [4,2,null,1,1,3,null,null,1]

## Contraintes

Le nombre de noeuds dans l'arborescence est compris entre `[1, 10^4]`  
La profondeur de l'arbre est comprise entre `[1, 10^4]`  
`-100 <= Node.val <= 100`  
`-10^5 <= val <= 10^5`  
`1 <= depth <= la profondeur de l'arbre + 1`

## Note personnelle

Pour résoudre ce problème, j'ai opté pour une approche BFS (Breadth-First Search).

Dans l'algorithme que j'ai développé, deux boucles sont présentes, la première identifie les noeuds à la profondeur spécifiée, tandis que la seconde insère les nouveaux noeuds à cette profondeur.

```cpp
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
  // Si la profondeur spécifiée est égale à 1, on ajoute une nouvelle racine
  // avec la valeur donnée (val), en faisant pointer son enfant gauche vers
  // l'ancienne racine (root).
  if(depth == 1){
    return new TreeNode(val, root, nullptr);
  }

  // Initialise la profondeur suivante à 2
  int currentNextDepth = 2;
  // Utilise une file pour parcourir les niveaux de l'arbre
  queue<TreeNode*> q;

  // Ajoute la racine à la file pour commencer la traversée
  q.push(root);

  // Boucle jusqu'à ce que la profondeur suivante atteigne la profondeur spécifiée
  while(currentNextDepth != depth){
    int size = q.size(); // Taille actuelle de la file

    // Parcourt tous les noeuds dans la file à ce niveau
    for(int i = 0; i < size; i++){
      // Prend le noeud en tête de la file
      TreeNode* current = q.front();
      // Retire le noeud de la file
      q.pop();

      // Ajoute les fils non-nuls du noeud courant à la file pour les parcourir plus tard
      if(current->left){
        q.push(current->left);
      }
      if(current->right){
        q.push(current->right);
      }
    }

    // Incrémente la profondeur suivante
    currentNextDepth++;
  }

  // À ce stade, la file contient tous les noeuds du niveau juste avant la profondeur spécifiée

  // Parcourt tous les noeuds de ce niveau et ajoute une nouvelle rangée avec la valeur donnée (val)
  while(!q.empty()){
    // Prend le noeud en tête de la file
    TreeNode* current = q.front();
    // Retire le noeud de la file
    q.pop();

    // Ajoute les nouveaux noeuds
    current->left = new TreeNode(val, current->left, nullptr);
    current->right = new TreeNode(val, nullptr, current->right);
  }

  return root;
}
```

Cette méthode présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(h^2)`, où `n` est le nombre de noeuds dans l'arbre et `h` sa hauteur.

Une autre approche possible est d'utiliser un DFS (Depth-First Search) avec une idée similaire, parcourir une branche jusqu'à atteindre la profondeur désirée, puis ajouter un par un les nouveaux noeuds.

Cette méthode a l'avantage de généralement consommer moins de mémoire car seuls les noeuds de la branche sont conservés pendant le parcours. Elle présente la même complexité temporelle mais une complexité spatiale de `O(h)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
