# 2469. Convert the Temperature

## Énoncé

On vous donne un nombre à virgule flottante non négatif arrondi à deux décimales `celsius`, qui représente la **température en Celsius**.

Vous devez convertir la température en Celsius en **Kelvin** et **Fahrenheit** et retourner ces valeurs sous forme de tableau `ans = [kelvin, fahrenheit]`.

Retournez le tableau `ans`. Les réponses dont la précision est dans une marge de `10^-5` par rapport à la réponse réelle seront acceptées.

**Noter que**:

`Kelvin = Celsius + 273.15`  
`Fahrenheit = Celsius * 1.80 + 32.00`

## Exemple

**Exemple 1:**  
**Input:** celsius = 36.50  
**Output:** [309.65000,97.70000]

**Exemple 2:**  
**Input:** celsius = 122.11  
**Output:** [395.26000,251.79800]

## Contraintes

`0 <= celsius <= 1000`

## Note personnelle

Je n'ai rien à ajouter de plus. J'ai même hésité à partager la solution tellement que je n'avais rien à dire.

```cpp
vector<double> convertTemperature(double celsius) {
  return { celsius + 273.15, celsius * 1.8 + 32 };
}
```

- Complexité Temporelle: `O(1)`
- Complexité Spatiale: `O(1)`

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
