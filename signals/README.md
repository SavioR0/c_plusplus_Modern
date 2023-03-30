# Captura de Sinais
O exercicio busca explanar o funcionamento de capturas de sinais em C++. Assim, a proposta é a modificação do código inicial a seguir :
``` c++
#include <iostream>

int main() {
    std::cout << "Tente encerrar esse processo..." << std::endl;
    while (true) {}
    return 0;
}
```

É preciso fazer com que o programa se encerre quando o usuário enviar um sinal para o sistema. Foi feito com o sinal SIGIT (sinal enviado quando precionar o Ctrl+C no terminal) que já possui a função de finalizar a tarefa. Porém, é necessário que o usuário pressione uma vez, e a seguinte mensagem é exibida "Para encerrar, pressione Ctrl + C novamente". O programa fica aguardando até que a combinação dessas teclas sejam pressionada novamente e em seguinda o programa é encerrado.