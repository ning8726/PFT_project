#include <iostream>

int main();
int main() {

    std::cout << "-------------------------" << std::endl;
    std::cout << "Personal Finance Tracker" << std::endl;
    std::cout << "-------------------------\n" << std::endl;
    std::cout << "1. Add Income" << std::endl;
    std::cout << "2. Add Expense" << std::endl;
    std::cout << "3. View Summary" << std::endl;
    std::cout << "4. Exit\n" << std::endl;
    std::cout << "Choose your option: " << std::endl;

    double balance = 0;
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "You chose Add Income." << std::endl;
        double income;
        std::cout << "Enter income amount: " << std::endl;
        std::cin >> income;

        balance = balance + income;

        std::cout << "Income added!" << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;

    }
    else if (choice == 2) {
        std::cout << "You chose Add Expense." << std::endl;
        double expense;
        std::cout << "Enter expense amount: " << std::endl;
        std:: cin >> expense;

        balance = balance - expense;

        std::cout << "Expense added!" << std::endl;\
        std::cout << "Current Balance: $" << balance << std::endl;
    }
    else if (choice == 3) {
        std::cout << "You chose View Summary." << std::endl;
    }
    else if (choice == 4) {
        std::cout << "You chose Exit. Goodbye!" <<std::endl;
    }
    
  





    return 0;
}