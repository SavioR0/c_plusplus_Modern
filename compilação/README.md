# Processo de compilação

- O primeiro estágio é o pré-processamento. Ele é responsável por incorporar as diretrizes ****************#include ou #ifndef**************** expande macros e resolve diretivas condicionais.

```cpp
g++ -E -P -o xxx.ii xxx.cpp
```

-p → retira os comentários.

Gera um arquivo contendo todo o código compilado. Tudo aquilo que é incluído das bibliotecas. 

- Em seguida o compilador é responsável por realizar as análises léxicas, sintáticas e semânticas. A saída é um programa assembly (sequência de instruções que representa, operações que devem ser realizadas pelo processador).
    - **Léxica** →identifica as palavras chaves (elementos léxicos).
    - **Sintático** →Identifica a sequencia dos termos léxicos, reconhecendo instruções, classes, expressões funções. Responsável por construir uma árvore de elementos.
    - **Semântica** → verifica as construções identificadas pela análise sintática.
- O assembler é responsável por traduzir esse código assembly gerado pelo compilador. Nesse contexto, gera como saída um arquivo binário chamado arquivo objeto (.o) contendo o código de máquina outras informações relevantes.
    
    ```cpp
    g++ -S -o xxx.s xxx.cpp
    ```
    
- Linker → responsável por combinar arquivos em um único arquivo binário, em um executável por exemplo.

# Regra da Definição Única

A regra da definição única determina uma única definição de determinada classe, função template entre outros.

O ifndef nos arquivos .h servem pra mostrar ao programa que determinada função já foi declarada anteriormente e não é necessário declará-la novamente.

O linker identifica que a função já foi declarada anteriormente e apresenta um erro.

---

Nesse contexto, foram postos em práticas comandos para podermos vizualizar as etapas de compilação e a ordem com que elas acontecem