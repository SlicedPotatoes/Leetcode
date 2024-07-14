class Solution
{
  public:
    // Fonction pour extraire un nombre de la chaîne, en partant de l'index donné
    int getNumber(string &s, int &i)
    {
        int count = 0;
        int n = 0;

        // Parcours de la chaîne à l'envers pour construire le nombre
        while (s[i] >= '0' && s[i] <= '9')
        {
            n += (s[i--] - '0') * pow(10, count++);
        }
        i++; // Corrige l'index après la boucle

        return n;
    }

    // Fonction pour analyser la formule chimique
    unordered_map<string, int> parse(string &s)
    {
        unordered_map<string, int> mp;

        stack<int> sta;
        sta.push(1); // Initialise la pile avec un coefficient de 1

        int coef = 1;
        string key = "";

        // Parcours de la chaîne à l'envers
        for (int i = s.size() - 1; i >= 0; i--)
        {
            // Détection d'un nombre
            if (s[i] >= '0' && s[i] <= '9')
            {
                coef = getNumber(s, i);
            }
            // Détection d'un élément chimique
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                key += s[i];
                reverse(key.begin(), key.end());

                mp[key] += coef * sta.top();

                coef = 1;
                key = "";
            }
            // Ajout des lettres minuscules éventuelles
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                key += s[i];
            }
            // Détection de la fin d'une sous-formule
            else if (s[i] == ')')
            {
                sta.push(coef * sta.top());
                coef = 1;
            }
            // Détection du début d'une sous-formule s[i] == '('
            else
            {
                sta.pop();
            }
        }

        return mp;
    }

    string countOfAtoms(string formula)
    {
        unordered_map<string, int> mp = parse(formula);
        vector<pair<string, int>> v(mp.begin(), mp.end());

        // Trie des éléments chimiques par ordre alphabétique
        sort(v.begin(), v.end());

        // Construction de la chaîne de sortie
        string ans = "";
        for (pair<string, int> &p : v)
        {
            ans += p.first;
            if (p.second > 1)
            {
                ans += to_string(p.second);
            }
        }

        return ans;
    }
};