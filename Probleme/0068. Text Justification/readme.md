# 68. Text Justification

## Énoncé

Étant donné un tableau de chaînes de caractères `words` et une largeur `maxWidth`, formatez le texte de telle sorte que chaque ligne ait exactement `maxWidth` caractères et soit justifiée (à gauche et à droite).

Vous devez regrouper vos mots de manière greedy approach; c'est-à-dire, mettez autant de mots que possible dans chaque ligne. Ajoutez des espaces supplémentaires `' '` si nécessaire pour que chaque ligne ait exactement `maxWidth` caractères.

Les espaces supplémentaires entre les mots doivent être répartis aussi uniformément que possible. Si le nombre d'espaces sur une ligne ne se divise pas uniformément entre les mots, les emplacements vides à gauche recevront plus d'espaces que ceux à droite.

Pour la dernière ligne de texte, elle doit être justifiée à gauche, et aucun espace supplémentaire ne doit être inséré entre les mots.

**Note:**

- Un mot est défini comme une séquence de caractères composée uniquement de caractères autres que des espaces.
- EIl est garanti que la longueur de chaque mot est supérieure à `0` et ne dépasse pas `maxWidth`.
- Le tableau d'entrée `words` contient au moins un mot.

## Exemple

**Exemple 1:**  
**Input:** words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16  
**Output:**

```
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

**Exemple 2:**  
**Input:** words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16  
**Output:**

```
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
```

**Exemple 3:**
**Input:** words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20  
**Output:**

```
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
```

## Contraintes

`1 <= words.length <= 300`  
`1 <= words[i].length <= 20`  
`words[i]` se compose uniquement de lettres et de symboles anglais.
`1 <= maxWidth <= 100`  
`words[i].length <= maxWidth`

## Note personnelle

Pour résoudre ce problème, j'ai opté pour une approche gloutonne. La sélection des mots qui vont composer une ligne est effectuée de manière gloutonne, comme indiqué dans l'énoncé, et de même pour le nombre d'espaces entre chaque mot.

Le défi principal de ce problème résidait dans l'organisation correcte du code et la répartition adéquate des espaces entre les mots.

Ma première approche a une complexité temporelle de `O(m * (n + maxWidth))` où `m` est le nombre de mots dans le vecteur `words` et `n` est le nombre moyen de mots par ligne. Elle présente également une complexité spatiale de `O(m * maxWidth)`.

Une optimisation possible pour réduire l'utilisation de la mémoire consiste à ne pas créer le vecteur `curr` qui stocke les pointeurs vers les mots, mais à passer uniquement les indices de début et de fin aux fonctions de construction.

```cpp
class Solution {
public:
    string buildLine(vector<string> &w, int cs, int mw, int start, int end){
        string output = "";

        cs -= end - start;
        int spaceNeeded = end - start;
        int spaceAvailable = mw - cs;
        double spaceSize = ceil(spaceAvailable / (double)spaceNeeded);

        for(int i = start; i <= end; i++){
            output += w[i];

            for(int j = 0; j < spaceSize && spaceAvailable != 0; j++){
                output += ' ';
                spaceAvailable--;
            }

            spaceNeeded--;
            spaceSize = ceil(spaceAvailable / (double)spaceNeeded);
        }

        return output;
    }

    string buildLast(vector<string> &w, int maxWidth, int start){
        string output = "";

        for(int i = start; i < w.size(); i++){
            output += w[i];
            output += ' ';
        }

        while(output.size() < maxWidth){
            output += ' ';
        }
        if(output.size() > maxWidth){
            output.pop_back();
        }

        return output;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int currSize = -1;
        int start = 0;

        for(int i = 0; i < words.size(); i++){
            int nextSize = currSize + 1 + words[i].size();
            if(nextSize <= maxWidth){
                currSize = nextSize;
            }
            else{
                ans.push_back(buildLine(words, currSize, maxWidth, start, i - 1));
                start = i;
                currSize = words[i].size();
            }
        }

        ans.push_back(buildLast(words, maxWidth, start));

        return ans;
    }
};
```

Cette approche présente une complexité temporelle de `O(m)` et une complexité spatiale de `O(m * maxWidth)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
