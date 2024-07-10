# 1598. Crawler Log Folder

## Énoncé

Le système de fichiers de Leetcode garde un journal chaque fois qu'un utilisateur effectue une opération de changement de dossier.

Les opérations sont décrites ci-dessous:

- `"../"`: Déplacez-vous vers le dossier parent du dossier actuel. (Si vous êtes déjà dans le dossier principal, **restez dans le même dossier**).
- `"./"`: Restez dans le même dossier.
- `"x/"`: Déplacez-vous vers le dossier enfant nommé `x` (Ce dossier est **garanti de toujours exister**).

On vous donne une liste de chaînes de caractères `logs` où `logs[i]` est l'opération effectuée par l'utilisateur à l'étape `i`.

Le système de fichiers commence dans le dossier principal, puis les opérations dans `logs` sont effectuées.

Retournez le nombre minimum d'opérations nécessaires pour revenir au dossier principal après les opérations de changement de dossier.

## Exemple

**Exemple 1:**

<img src="./imgs/img1.png"/>

**Input:** logs = ["d1/","d2/","../","d21/","./"]  
**Output:** 2  
**Explication:** Pour revenir au dossier principal, vous devez utiliser l'opération de retour arrière 2 fois.

**Exemple 2:**

<img src="./imgs/img2.png"/>

**Input:** logs = ["d1/","d2/","./","d3/","../","d31/"]  
**Output:** 3

**Exemple 3:**  
**Input:** logs = ["d1/","../","../","../"]  
**Output:** 0

## Contraintes

`1 <= logs.length <= 10^3`  
`2 <= logs[i].length <= 10`  
`logs[i]` contient des lettres anglaises minuscules, des chiffres `'.'`, et `'/'`.  
`logs[i]` suit le format décrit dans l'énoncé.  
Les noms de dossiers sont constitués de lettres et de chiffres anglais minuscules.

## Note personnelle

Pour résoudre ce problème, l'idée est de suivre la profondeur actuelle, laquelle représente le nombre d'opérations de retour en arrière nécessaires pour revenir à la racine.

```cpp
int minOperations(vector<string>& logs) {
  // Initialisation de la profondeur à 0
  int depth = 0;

  // Parcourir chaque log dans le vecteur logs
  for(string &s : logs){
    // Si le log est "../", on remonte d'un dossier (si on n'est pas déjà à la racine)
    if(s == "../"){
      if(depth > 0){
        depth--;
      }
    }
    // Si le log est "./", on reste dans le même dossier, donc rien ne change
    else if(s == "./"){
      continue;
    }
    // Si le log est un nom de dossier, on descend dans ce dossier
    else{
      depth++;
    }
  }

  // Retourner la profondeur finale après traitement de tous les logs
  return depth;
}
```

- Complexité Temporelle `O(n)`.
- Complexité Spatiale: `O(1)`.

Une autre approche consiste à utiliser une pile (Stack), qui peut être utile si l'on doit reconstruire le chemin du dossier courant.

```cpp
int minOperations(vector<string>& logs) {
  // Utilisation d'une pile pour suivre les opérations de navigation dans les dossiers
  stack<string> sta;

  // Parcourir chaque log dans le vecteur logs
  for(string &s : logs){
    // Si le log est "../", on remonte d'un dossier (si la pile n'est pas vide)
    if(s == "../"){
      if(!sta.empty()){
        sta.pop();
      }
    }
    // Si le log est "./", on reste dans le même dossier, donc rien ne change
    else if(s == "./"){
      continue;
    }
    // Si le log est un nom de dossier, on descend dans ce dossier et on empile le nom du dossier
    else{
      sta.push(s);
    }
  }

  // La taille de la pile représente la profondeur finale après traitement de tous les logs
  return sta.size();
}
```

- Complexité Temporelle `O(n)`.
- Complexité Spatiale: `O(n)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
