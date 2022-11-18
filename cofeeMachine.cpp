#include <iostream>
struct Prod{
    std::string nameProd;
    int sumProd;
};


class CoffeeMachine{
    public:
        // Փոփոխականների անունները պետք է սկսեն m_, հետո տիպւ նկարագրող մասս ու նոր փոփոխականի անունը։ Օր․՝ m_arrProduct։
        std::string* arrProd;
        int* arrSum;
    
        // Ցանկալի է ունենալ փոփոխական քանակի տարրերով (դինամիկ) զանգված
        CoffeeMachine(std::string listOfProducts[10], int PriceList[10]){
            arrProd = listOfProducts;
            arrSum = PriceList;
        }
    public:
        void printPriceList(){
            std::cout<<"list of products and sums"<<std::endl;
            int num1 = 1;
            for(int i = 0; i<10; i++){

                std::cout<<num1++<<". "<<arrProd[i]<<"----------"<<arrSum[i]<<std::endl;
            }
        }
 
        // Ցանկալի էր վերադարձնել { "նամակ"(Սուրճի անուն, կամ սխալի մասին նամակ), մանր } կառուցվածք
        void toOrder(Prod order){
            for(int j = 0; j<10; j++){
                if(order.nameProd == arrProd[j]){
                    std::cout<<"product found .... "<<std::endl;
                    if(order.sumProd < arrSum[j]){
                        std::cout<< "There is not enough money to complete the order"<<std::endl;

                    }else if(order.sumProd >= arrSum[j]){
                        std::cout<<"place your order ------ "<<arrProd[j]<<std::endl;
                        std::cout<<"put in your change = ------ "<<(order.sumProd - arrSum[j])<<std::endl;

                    }

                }

            }
        }

        ~CoffeeMachine(){

        }
};



int main(){
    std::string start;
    std::cout<<"Hello If you want to see the assortment, write start ";
    std::cin>>start;
    if(start == "start"){
        std::string listOfProducts[10] = {"Arabica", "Robusta", "Decaf", "Espresso", "Latte", "Cappuccino", "Macchiato", "Americano", "Cortado", "Tea"};
        int PriceList[10] = {150, 200, 350, 200, 400, 250, 500, 600, 900, 450};
        CoffeeMachine coffeeObj1(listOfProducts, PriceList);
        coffeeObj1.printPriceList();
        std::string version;
        int sum1;
        std::cout<<"if you want to place an order, write the name of the version you want ";
        std::cin>>version;
        std::cout<<"please enter the appropriate amount ";
        std::cin>>sum1;
        Prod product;
        product.nameProd = version;
        product.sumProd = sum1;
        coffeeObj1.toOrder(product);

        return 0;

    }else{
        // Հաճախորդին կարելի էր մի քիչ նուրբ խնդրել, որ գնա ուրիշ տեղ: Կարող ա օրերից մի օր ուզենա start անել )))
        std::cout<<"go drink from someone else's place"<<std::endl;
        return 1;
    }
}

