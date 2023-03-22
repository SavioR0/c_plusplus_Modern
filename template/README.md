# Templates

Em C++, um template é uma ferramenta de programação genérica que permite que funções e classes sejam escritas sem especificar o tipo de dados exato que elas vão manipular. Em vez disso, o tipo de dados é definido como um parâmetro genérico no momento em que a função ou classe é instanciada. Isso permite que um único modelo de função ou classe possa ser usado com vários tipos de dados diferentes, sem a necessidade de reescrever o código.

Por exemplo, podemos criar uma função genérica para calcular o valor absoluto de um número, que pode ser usado com diferentes tipos de dados:

```cpp 
template <typename T>
T abs(T value)
{
  if (value < 0)
    return -value;
  else
    return value;
}
```

Nesse exemplo, typename T é um parâmetro de modelo que representa um tipo de dados genérico. A função abs() pode ser usada com qualquer tipo de dados, desde que o operador de comparação < esteja definido para esse tipo.

Para usar essa função com um tipo de dados específico, como int ou double, podemos instanciar o modelo de função passando o tipo de dados desejado como argumento:

```cpp 
int i = abs(-5);
double d = abs(-3.14);
```

Dessa forma, o modelo de função abs() é instantaneamente transformado em uma função que trabalha com um tipo de dados específico e pode ser usado como tal. Isso permite que os programadores escrevam código mais genérico e reutilizável em C++.

Nesse contexto, a pasta aplicações são exemplos que podem ser usados os templates e na pasta lista_simplesmente_encadeda foi implementada uma lista simplesmente encadeada utilzando os conceito aprendidos sobre template.