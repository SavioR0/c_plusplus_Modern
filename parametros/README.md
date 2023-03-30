# Passagem de parâmetro
O presente repositório possui atividades de passagem de parâmetro a partir dos comandos do terminal, ao rodar o executável. Nesse contexto, foi utilizados os parâmetros int arqc e charr** arqv da função main. Assim, foram feitas duas atividade para colocar em prática os conceitos uaprendidos durante a aula.

## Atv1
A atividade 1 foi uma atividade realizada durante a aula, com o intuito de esplanar o funcionamento do algortimo quando o mesmo recebe os parâmetro pelo terminal. O algoritmo é capaz de escrevero parâmetro passado em um arquivo de texto. Nessa atividade, foi passado como parâmetro uma frase que foi adicionada em um arquivo txt.
A linha de comando utilizada pra criar o arquivo objeto foi:
```
g++ -o main main.cpp
```
O comando utilizado para execução do programa e passagem de parâmetros foi:
```
./main Escrevendo no arquivo de Texto
```

## Atv2
Este é um programa capaz de gerar números aleatórios a partir de parâmetro passados na linha de comando, são eles:

 - -i : se informado, gerar números inteiros.
 - -n x : se informado gerar x números aleatórios. Por padrão, x=1.
 - -r a b : se informado, gerar número no intevalo [a,b]. Por padrã a=0, a=1.
 - -p x : se informado, os numeros devem ser apresentados com X casas decimais. Por padrão x=4.
 - -s S: semente do gerador de números aleatórios se não informado, usar o timestamp.

 Importante salientar que a ordem com que os comandos são passados não deve inteferir no resultado final
 Um exemplo que mostra esse funcionamento, é ilustrado a seguir.

Inicialmente é gerado o arquivo objeto do programa, ou seja o executável através de 
 ```
g++ -o main main.cpp
 ```
 Em seguida, esse programa gerado é executado à seguir

```
./main -n 5 -i -r 10 20 -p 6 -s 16864
```

Esse comando exige que sejam gerados 5 números inteiros em um intevalo de 10 a 20, representado com 6 casas decimais e a semente do gerador de números aleatórios sendo 16864.