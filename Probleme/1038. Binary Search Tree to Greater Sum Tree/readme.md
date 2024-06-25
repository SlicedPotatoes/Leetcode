# 1038. Binary Search Tree to Greater Sum Tree

## Énoncé

Étant donné la racine `root` d'un arbre binaire de recherche (ABR), convertissez-le en un Greater Tree de telle sorte que chaque clé de l'ABR original soit modifiée en la clé originale plus la somme de toutes les clés supérieures à la clé originale dans l'ABR.

Pour rappel, un arbre binaire de recherche est un arbre qui satisfait les contraintes suivantes:

- Le sous-arbre gauche d'un noeud ne contient que des noeuds avec des clés inférieures à la clé du noeud.
- Le sous-arbre droit d'un noeud ne contient que des noeuds avec des clés supérieures à la clé du noeud.
- Les sous-arbres gauche et droit doivent également être des arbres binaires de recherche.

## Exemple

**Exemple 1:**

<img width=400px height=273px src="./imgs/img1.png"/>

**Input:** root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]  
**Output:** [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

**Exemple 2:**  
**Input:** root = [0,null,1]  
**Output:** [1,null,1]

## Contraintes

Le nombre de noeuds dans l'arbre est compris entre `[1, 100]`  
`0 <= Node.val <= 100`  
Toutes les valeurs dans l'arbre son **uniques**.

## Note personnelle

Pour résoudre ce problème, l'idée est de parcourir l'Arbre Binaire de Recherche (ABR) en utilisant un parcours en profondeur "InOrder". Cela signifie que pour chaque noeud, on traite d'abord son sous-arbre droit, ensuite le noeud lui-même, puis son sous-arbre gauche.

En procédant ainsi, nous parcourons les valeurs de l'arbre dans l'ordre décroissant.

```cpp
// Fonction récursive pour convertir un BST en Greater Sum Tree
void convertToGreaterTree(TreeNode *root, int &currSum) {
  // Si le noeud actuel est nul, on retourne
  if (!root) {
    return;
  }

  // Appel récursif sur le sous-arbre droit (les valeurs plus grandes)
  convertToGreaterTree(root->right, currSum);

  // Mise à jour de la valeur du noeud actuel en ajoutant la somme courante
  root->val += currSum;
  // Mise à jour de la somme courante avec la nouvelle valeur du noeud
  currSum = root->val;

  // Appel récursif sur le sous-arbre gauche (les valeurs plus petites)
  convertToGreaterTree(root->left, currSum);
}

// Fonction principale pour convertir un BST en Greater Sum Tree
TreeNode *bstToGst(TreeNode *root) {
  int currSum = 0; // Initialisation de la somme courante à 0

  // Appel de la fonction récursive pour effectuer la conversion
  convertToGreaterTree(root, currSum);

  // Retourner la racine de l'arbre modifié
  return root;
}
```

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(h)`, où `h` est la hauteur de l'arbre.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
