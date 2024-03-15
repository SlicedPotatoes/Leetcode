# 17. Letter Combinations of a Phone Number

## Énoncé

Étant donné une chaîne contenant des chiffres de `2-9` inclus, renvoie toutes les combinaisons de lettres possibles que le nombre pourrait représenter. Renvoyez la réponse dans **n'importe quel ordre**.

Un mappage des chiffres aux lettres (tout comme sur les boutons du téléphone) est donné ci-dessous. Notez que 1 ne correspond à aucune lettre.

<img style="width: 300px; height: 243px;" src="./imgs/img1.png"/>

## Exemple

**Exemple 1:**  
**Input:** digits = "23"  
**Output:** ["ad","ae","af","bd","be","bf","cd","ce","cf"]

**Exemple 2:**  
**Input:** digits = ""  
**Output:** []

**Exemple 2:**  
**Input:** digits = "2"  
**Output:** ["a","b","c"]

## Contraintes

`0 <= digits.length <= 4`  
`digits[i]` est un chiffre compris dans la plage `['2', '9']`.

## Note personnelle

Pour aborder ce problème, ma première approche a été d'utiliser une fonction récursive pour générer la liste de toutes les combinaisons possibles.

Cette fonction utilise les paramètres suivants :

- Un pointeur vers un vecteur de chaînes de caractères nommé `output`, servant à stocker les combinaisons possibles.
- Un pointeur vers une chaîne de caractères `digits`, représentant la séquence de chiffres passée en entrée.
- Un entier `currentDigit`, indiquant l'indice actuellement traité dans `digits`
- Un pointeur vers une chaîne de caractères `current`, stockant la combinaison actuelle.

La fonction commence par une condition d'arrêt, vérifiant si `currentDigit` est égal à `digits.size()` (ce qui signifie que tous les chiffres ont été traités).
Dans ce cas, la combinaison actuelle est ajoutée à `output` , puis la fonction se termine.

Si la condition d'arrêt n'est pas remplie, la fonction itère sur chaque caractère associé au chiffre actuel dans la chaîne `digits`: (représenté par `digits[currentDigit]`).  
À chaque itération, les actions suivantes sont effectuées:

- La modification de la chaîne `current` en remplaçant le caractère à l'indice `currentDigit`
- Un appel récursif avec `currentDigit + 1` comme unique paramètre modifié.

```cpp
class Solution {
private:
    unordered_map<char, string> numPad = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    // Fonction récursive pour générer les combinaisons de lettres
    void getCombinations(vector<string>&output, string &digits, int currentDigit, string &current){
        // Condition d'arrêt : si nous avons traité tous les chiffres
        if(currentDigit == digits.size()){
            // Ajoute la combinaison actuelle au vecteur de sortie
            output.push_back(current);
            return;
        }
        // Parcourt toutes les lettres associées au chiffre actuel
        for(char c : numPad[digits[currentDigit]]){
            // Fixe la lettre actuelle dans la chaîne en cours de construction
            current[currentDigit] = c;
            // Appel récursif pour le prochain chiffre
            getCombinations(output, digits, currentDigit + 1, current);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            // Si la chaîne de chiffres est vide, retourne un vecteur vide
            return {};
        }

        // Vecteur pour stocker les combinaisons de lettres
        vector<string> output;
        // Chaîne temporaire pour stocker une combinaison de lettres
        string current(digits.size(), ' ');

        // Appelle la fonction récursive pour générer les combinaisons de lettres
        getCombinations(output, digits, 0, current);

        return output;
    }
};
```

J'ai également développé une version itérative de cette approche, suivant le même principe que la version récursive. Bien que sa complexité temporelle et spatiale soit exponentielle, de l'ordre de `O(4^n * 3^n)`, où `n` représente le nombre de chiffres associés à 4 lettres et `m` le nombre de chiffres associés à 3 lettres, cette version itérative est généralement plus efficace, car elle évite la gestion de la pile d'appels récursifs.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
