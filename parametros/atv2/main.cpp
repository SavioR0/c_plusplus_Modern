#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <cmath>
#include <string>
#include <iomanip>
//properties[5] = [i, n, r, p, s]
// inputs[4] = [x número aleatorios, começo do intervalo, final do intervalo, x casas decimais]
class Properties{
    private:
        std::vector<bool> properties;
        std::vector<int> inputs;
        std::mt19937 generator; // Gerador de numetos aleatórios
    public:
        Properties(){ 
            properties = std::vector(5,false);
            inputs = {1,0,1,4};
            generator = std::mt19937(std::time(nullptr)); 
        }

        std::vector<bool> getProperties(){return properties;}
        std::vector<int> getInputs(){return inputs;}
        int getInputIndex(int x){return inputs[x];}

        void setPropertie(int index) {properties[index] = true;}
        void setInput(int index, int value) {inputs[index] = value;}
        void setGenerator(int value) {generator = std::mt19937(value); }

        double returnRand(int value1, int value2){
            std::uniform_real_distribution<double> distribution(value1, value2);
            return distribution(generator);
        }

        std::vector<double> generateNumbers(){
            std::vector<double> vec;
            for (int i = 0; i < inputs[0]; i++){
                if(properties[0] == 1) vec.push_back(std::round(returnRand(inputs[1],inputs[2])));
                else vec.push_back(returnRand(inputs[1],inputs[2]));
            };  
            return vec;         
        }


};



template<typename T>
void printVector(std::vector<T> properties, int decimals = 4){
    std::cout<<"Valores : "<<std::endl;
    for (auto x: properties){
        std::cout<<std::fixed<<std::setprecision(decimals)<<x<<" ";
    }
    std::cout<<std::endl;
}

void loadCommand(int argc, char** argv, Properties *properties){
    for (int i=1; i<argc;i++){
        if(argv[i][0] == '-') {
            switch (argv[i][1]){
            case 'i':
                properties->setPropertie(0);
                //std::cout<<" -- Gerar números inteiros Selecionado"<<std::endl;
                break;
            case 'n':
                properties->setPropertie(1);
                properties->setInput(0, std::stoi(argv[i+1]));
                //std::cout<<" -- Número definido de números aleatórios"<<std::endl;
                break;
            case 'r':
                properties->setPropertie(2);
                properties->setInput(1, std::stoi(argv[i+1]));
                properties->setInput(2, std::stoi(argv[i+2]));
                //std::cout<<" -- Intervalo de Geração definido"<<std::endl;
                break;
            case 'p':
                properties->setPropertie(3);
                properties->setInput(3, std::stoi(argv[i+1]));
                //std::cout<<" -- Definição do número de casa decimais"<<std::endl;
                break;
            case 's':
                properties->setPropertie(4);
                properties->setGenerator(std::stoi(argv[i+1]));
                //std::cout<<" -- Semente deinida."<<std::endl;
                break;
            default:
                break;
            }
        }
    }
}



int main(int argc, char** argv){
    Properties* properties = new Properties();

    loadCommand(argc, argv, properties);

    //printVector(properties->getProperties());
    //printVector(properties->getInputs());

    std::vector<double> vec (properties->generateNumbers());
    printVector(vec, properties->getInputIndex(3));


    return 0;
}