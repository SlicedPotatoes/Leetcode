# 1110. Delete Nodes And Return Forest

## Énoncé

Étant donné la racine `root` d'un arbre binaire, chaque noeud de l'arbre a une valeur distincte.

Après avoir supprimé tous les noeuds avec une valeur dans `to_delete`, il nous reste une forêt (une union disjointe d'arbres).

Retournez les racines des arbres dans la forêt restante. Vous pouvez retourner le résultat dans n'importe quel ordre.

## Exemple

**Exemple 1:**

<img src="./imgs/img1.png" width="237px" height="150px"/>

**Input:** root = [1,2,3,4,5,6,7], to_delete = [3,5]  
**Output:** [[1,2,null,4],[6],[7]]

**Exemple 2:**  
**Input:** root = [1,2,4,null,3], to_delete = [3]  
**Output:** [[1,2,4]]

## Contraintes

Le nombre de noeuds dans l'arbre donné est au maximum de `1000`  
Chaque noeud a une valeur distincte entre `1` et `1000`  
`to_delete.length <= 1000`  
`to_delete` contient des valeurs distinctes entre `1` et `1000`

## Note personnelle

Dans chaque approche proposée, une partie du code est commentée, celui-ci permet de libérer la mémoire des noeuds supprimés pour éviter les fuites de mémoires.

### Approche 1: Trouver et Supprimer les Éléments dans les Forêts

Cette approche consiste à stocker les racines des forêts dans un ensemble `unordered_set`. Pour chaque élément à supprimer, nous effectuons une recherche en profondeur (DFS) dans chaque forêt jusqu'à trouver l'élément à supprimer. À chaque suppression, nous créons les forêts résultantes que nous ajoutons à l'ensemble.

```cpp
// Fonction DFS pour trouver le noeud et son parent
pair<TreeNode*, TreeNode*> dfs(TreeNode* root, int value){
  // Si la racine est le noeud recherché
  if(root->val == value){
    return {nullptr, root};
  }

  stack<TreeNode*> sta;
  sta.push(root);

  while(!sta.empty()){
    TreeNode* curr = sta.top();
    sta.pop();

    // Vérification du sous-arbre gauche
    if(curr->left){
      if(curr->left->val == value){
        return {curr, curr->left};
      }
      sta.push(curr->left);
    }
    // Vérification du sous-arbre droit
    if(curr->right){
      if(curr->right->val == value){
        return {curr, curr->right};
      }
      sta.push(curr->right);
    }
  }

  // Si le noeud avec la valeur donnée n'est pas trouvé
  return {nullptr, nullptr};
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
  unordered_set<TreeNode*> forests;
  forests.insert(root); // Initialiser la forêt avec la racine

  // Parcours de chaque élément a supprimé
  for(int element : to_delete){
    // Parcours de chaque forêt
    for(TreeNode* f : forests){
      pair<TreeNode*, TreeNode*> r = dfs(f, element);

      // Si le noeud à supprimer n'est pas trouvé
      if(!r.second){
        continue;
      }

      // Si le noeud à supprimer est la racine
      if(!r.first){
        forests.erase(r.second);
      }
      else{
        // Détache le noeud à supprimer de son parent
        if(r.first->left == r.second){
          r.first->left = nullptr;
        }
        else if(r.first->right == r.second){
          r.first->right = nullptr;
        }
      }

      // Ajouter les sous-arbres du noeud supprimé à la forêt
      if(r.second->left){
        forests.insert(r.second->left);
      }
      if(r.second->right){
        forests.insert(r.second->right);
      }

      // Libérer la mémoire du noeud supprimé
      // delete r.second;

      break;
    }
  }

  // Retourner les racines des sous-arbres restants
  return vector<TreeNode*>(forests.begin(), forests.end());
}
```

- Complexité Temporelle: `O(n * m)`
- Complexité Spatiale: `O(m + h)`
- `n` est le nombre de noeuds dans l'arbre, `m` est le nombre d'éléments à supprimer, et `h` est la hauteur de l'arbre.

### Approche 2: Utiliser une HashMap pour Stocker les Éléments et Procéder à la Suppression

Cette approche consiste à stocker chaque noeud et son parent dans une HashMap avec la valeur du noeud comme clé, permettant une recherche efficace de l'élément à supprimer. La gestion des forêts reste la même que dans l'approche précédente.

```cpp
// Fonction DFS pour remplir la map avec les noeuds et leurs parents
void dfs(TreeNode* root, unordered_map<int, pair<TreeNode*, TreeNode*>> &mp){
  if(root->left){
    mp[root->left->val] = {root, root->left}; // Ajouter le noeud gauche et son parent
    dfs(root->left, mp); // Appel récursif sur le noeud gauche
  }
  if(root->right){
    mp[root->right->val] = {root, root->right}; // Ajouter le noeud droit et son parent
    dfs(root->right, mp); // Appel récursif sur le noeud droit
  }
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
  unordered_map<int, pair<TreeNode*, TreeNode*>> mp; // Map pour stocker les noeuds et leurs parents
  unordered_set<TreeNode*> set; // Ensemble pour stocker les racines des sous-arbres

  mp[root->val] = {nullptr, root}; // La racine n'a pas de parent
  set.insert(root); // Ajouter la racine à l'ensemble

  dfs(root, mp); // Remplir la map avec les noeuds de l'arbre

  // Traiter chaque élément à supprimer
  for(int element: to_delete){
    pair<TreeNode*, TreeNode*> curr = mp[element];

    // Détache le noeud à supprimer de son parent
    if(curr.first){
      if(curr.first->left == curr.second){
        curr.first->left = nullptr;
      }
      else if(curr.first->right == curr.second){
        curr.first->right = nullptr;
      }
    }

    set.erase(curr.second); // Retire le noeud à supprimer de l'ensemble

    // Ajouter les sous-arbres du noeud supprimé à l'ensemble
    if(curr.second->left){
      set.insert(curr.second->left);
    }
    if(curr.second->right){
      set.insert(curr.second->right);
    }
  }

  // Libérer la mémoire des noeuds supprimés
  // for(int element: to_delete){
  //   delete mp[element].second;
  // }

  // Retourner les racines des sous-arbres restants
  return vector<TreeNode*>(set.begin(), set.end());
}
```

- Complexité Temporelle: `O(n + m)`
- Complexité Spatiale: `O(n + m + h)`
- `n` est le nombre de noeuds dans l'arbre, `m` est le nombre d'éléments à supprimer, et `h` est la hauteur de l'arbre.

### Approche 3: Parcourir l'Arbre et Supprimer les Éléments Simultanément

Cette approche parcourt l'arbre en profondeur tout en supprimant les éléments.

Chaque itération retourne `true` ou `false`pour indiquer si le noeud enfant concerné doit être supprimé ou non. La liste `to_delete` est convertie en un ensemble `unrodered_set` pour faciliter la vérification.

```cpp
// Fonction pour supprimer un noeud et ajuster l'arbre en conséquence
void deleteNode(TreeNode* parent, TreeNode* child, bool isLeft, vector<TreeNode*> &ans, unordered_set<int> &toDelete){
  toDelete.erase(child->val); // Supprimer le noeud du set toDelete

  // Ajouter les enfants du noeud supprimé à la liste des résultats
  if(child->left){
    ans.push_back(child->left);
  }
  if(child->right){
    ans.push_back(child->right);
  }

  // Détacher le noeud supprimé de son parent
  if(isLeft){
    parent->left = nullptr;
  }
  else{
    parent->right = nullptr;
  }

  // Libérer la mémoire des noeuds supprimés
  // delete child;
}

// Fonction DFS pour explorer et marquer les noeuds à supprimer
bool dfs(TreeNode* root, vector<TreeNode*> &ans, unordered_set<int> &toDelete){
  if(root->left && dfs(root->left, ans, toDelete)){
    deleteNode(root, root->left, true, ans, toDelete);
  }
  if(root->right && dfs(root->right, ans, toDelete)){
    deleteNode(root, root->right, false, ans, toDelete);
  }

  // Retourne true si le noeud actuel doit être supprimé
  return toDelete.find(root->val) != toDelete.end();
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
  vector<TreeNode*> ans;
  unordered_set<int> toDelete(to_delete.begin(), to_delete.end());

  // Si la racine doit être supprimée, ajouter ses enfants à la liste des résultats
  if(dfs(root, ans, toDelete)){
    if(root->left){
      ans.push_back(root->left);
    }
    if(root->right){
      ans.push_back(root->right);
    }

    // Libérer la mémoire des noeuds supprimés
    // delete root;
  }
  // Sinon, ajouter la racine à la liste des résultats
  else{
    ans.push_back(root);
  }

  // Retourner les racines des sous-arbres restants
  return ans;
}
```

- Complexité Temporelle: `O(n + m)`
- Complexité Spatiale: `O(m + h)`
- `n` est le nombre de noeuds dans l'arbre, `m` est le nombre d'éléments à supprimer, et `h` est la hauteur de l'arbre.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
