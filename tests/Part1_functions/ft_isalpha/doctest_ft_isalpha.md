# Lista de testes cobertos por esta main

Ao somar os blocos originais com os blocos adicionais, este tester cobre os seguintes cenários por argumento:

- **arg 1 (0 a 47):** caracteres de controle iniciais, espaço e símbolos ASCII anteriores aos dígitos; todos devem retornar falso para `ft_isalpha`
- **arg 2 (48 a 57 / '0' a '9'):** todos os dígitos numéricos; devem retornar falso
- **arg 3 (58 a 64):** símbolos de pontuação e separadores como `: ; < = > ? @`; devem retornar falso
- **arg 4 (65 a 90 / 'A' a 'Z'):** todo o alfabeto ASCII em letras maiúsculas; deve retornar verdadeiro
- **arg 5 (91 a 96):** símbolos como `[ \ ] ^ _ \`` entre os blocos alfabéticos; devem retornar falso
- **arg 6 (97 a 122 / 'a' a 'z'):** todo o alfabeto ASCII em letras minúsculas; deve retornar verdadeiro
- **arg 7 (123 a 127):** símbolos finais ASCII como `{ | } ~` e o caractere `DEL`; devem retornar falso
- **arg 8 (-128 a -1):** valores negativos fora do domínio ASCII clássico; esse bloco testa robustez da implementação, mas parte desses valores cai em comportamento indefinido pela especificação de `ctype` quando não forem `EOF` nem representáveis como `unsigned char`
- **arg 9 (128 a 255):** toda a faixa representável por `unsigned char` acima do ASCII básico; em uma implementação `libft` estilo unit, esses valores normalmente não são tratados como letras ASCII e devem retornar falso
- **arg 10 (-1000 e 1000):** valores inteiros extremos e fora do domínio garantido de `isalpha`; servem para teste de robustez, mas estão fora do comportamento definido pela especificação padrão
- **arg 11 (-1):** teste explícito do valor usado como `EOF`; deve retornar falso
- **arg 12 (`char c = (char)-1`, convertido com `(unsigned char)c`):** valida entrada originalmente armazenada em `char` assinado e normalizada para `unsigned char` antes da chamada; o resultado esperado é falso
- **arg 13 (`unsigned char c = 255`):** testa o maior valor típico de `unsigned char`; o resultado esperado é falso em uma implementação ASCII de `ft_isalpha`
- **arg 14 (`unsigned char c = 0`):** testa o menor valor de `unsigned char`; o resultado esperado é falso
- **arg 15 (`unsigned char c = 127`):** testa o limite superior do ASCII padrão (`DEL`); o resultado esperado é falso
- **arg 16 (`unsigned char c = 'A'`):** valida que um valor alfabético continua sendo reconhecido mesmo quando passado explicitamente via `unsigned char`; o resultado esperado é verdadeiro

## Observações importantes

A especificação de `isalpha` define comportamento válido apenas para valores `int` que sejam iguais a `EOF` ou representáveis como `unsigned char`.

Por isso, os blocos `8` e `10` são úteis como teste de robustez prática do seu `ft_isalpha`, mas não representam casos totalmente portáveis segundo a especificação da família `ctype`.

Se a implementação da sua `libft` segue o comportamento clássico da unit, então o conjunto realmente esperado como verdadeiro continua sendo apenas `A-Z` e `a-z` no intervalo ASCII básico.