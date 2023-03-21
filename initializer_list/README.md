
# Sintaxes de inicialização uniforme

Antes da inicialização uniforme existiam várias formas de se inicializar os tipos.

- Inicialização por cópia

```cpp
T objeto = outro_objeto 
```

- Inicialização direta.

Invocar algum construtor viável definindo os seus argumentos de forma explícita

```cpp
string str1("Hello") 
string str2(10, 'a')  
```

- Inicialização padrão

```cpp
T objeto;
```

- Inicialização agregada

```cpp
Struct bar {
  Int a ;
  Int b;
} ;

bar b={42, 3.14} ;
Int a[] = {1,2,3,4} ;
```

## Initializer_list

O std::initializer_list<T> funciona basicamente como um proxy sobre um array de elemento do tipo T const.

O funcionamento do construtor que recebe std::initializer_list<T> como argumento ocorre assim:

- o compilador resolve quais são os tipos dos elementos especificados na lista de inicialização (precisam ser do mesmo tipo).
- Cria um array com os elementos da lista de iniciaização.
- Encapsula o array dentro do objeto initializer_list<T> e o objeto é passado como argumento para o construtor.

Para tanto, foram realizadas duas atividades para aplicar os conceitos e estruturas comentados durante à aula.

## Atividade 1
A primeira atividade foi a seguinte:

Inicializar um objeto que represente uma matriz com a seguinte sintáxe 
```cpp
Matriz m{{{1,2,3},{1,2,3},{1,2,3}}};
```

## Atividade 2
A segunda atividade foi implementar três funções : soma, minímo e máximo de um array de elementos que é passado como parâmetro.