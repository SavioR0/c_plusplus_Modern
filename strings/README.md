## Strings Literais

O C++11 possibilita a criação de literais baseados em tipos inteiros, ponto-flutuante, caractere e string que
produzem objetos de tipos definidos pelo usuário. Para isso, é necessário sobrecarregar o operador de sufixo.
É realizado da seguinte forma: 
```C++
Weight operator"" _g(long double value) {
    return Weight(value);
}
```
Em que Weight é uma classe, ao qual o constutor chamado é classificado como construtor cópia e possui uma representação interna de número ponto-flutuante.

Nesse contexto, foi desenvolvida uma atividade para aplicar os conceitos aprendidos durante a aula, sobre literais criada pelo usuário.

```
 esquema://domínio:porta/caminho/recurso?query_string#fragmento
```

Criar uma classe com o nome URL que represente uma URL. A classe deverá
ter os atributos: <b>esquema, dominio, porta e caminho</b>. Nessa classe, o atributo caminho será uma única string
com os dados de caminho, recurso, query string e fragmento. Os atributos esquema e dominio também deverão
ser do tipo string. Já o atributo porta deverá ser um valor de tipo inteiro.

Nesse sentido, foram testados as seguintes url exemplos:

- https://cefetplusplus.github.io/
- https://www.cefetmg.br/
- https://www.cefetmg.br:443/
- https://pt.wikipedia.org/wiki/URL
- https://pt.wikipedia.org/wiki/URL#cite_note-4
