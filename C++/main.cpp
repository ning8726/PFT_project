#include <iostream>
#include <fstream>

int main();
int main() {

    

    double balance = 0;
    std::ifstream file("balance.txt");
    file >> balance;
    file.close();
    double choice = 0;
    while (choice != 4) {
        std::cout << "-------------------------" << std::endl;
        std::cout << "Personal Finance Tracker" << std::endl;
        std::cout << "-------------------------\n" << std::endl;
        std::cout << "1. Add Income" << std::endl;
        std::cout << "2. Add Expense" << std::endl;
        std::cout << "3. View Summary" << std::endl;
        std::cout << "4. Exit\n" << std::endl;
        std::cout << "Choose your option: " << std::endl;

        std::cin >> choice;

    if (choice == 1) {
        std::cout << "You chose Add Income." << std::endl;
        double income = 0;
        while (income <= 0) {
            std::cout << "Enter income amount: " << std::endl;
            std::cin >> income;
            if (income <= 0) {
                std::cout << "Invalid amount. Please enter a positive value." << std::endl;
        }
    }
        balance = balance + income;

        std::cout << "Income added!" << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;

    }
    else if (choice == 2) {
        std::cout << "You chose Add Expense." << std::endl;
        double expense = 0;
        while (expense <= 0) {
            std::cout << "Enter expense amount: " << std::endl;
            std::cin >> expense;
            if (expense <= 0) {
                std::cout << "Invalid amount. Please enter a positive value." << std::endl;
            }
        }

        balance = balance - expense;

        std::cout << "Expense added!" << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    }
    else if (choice == 3) {
        std::cout << "You chose View Summary." << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    
    }
    else if (choice == 4) {

        std::cout << "Are you sure you want to exit? (y/n): " << std::endl;
        char exitChoice;
        std::cin >> exitChoice;
        if (exitChoice == 'y') {
            std::ofstream file ("balance.txt");
            file << balance;
            file.close();
            std::cout << "You chose Exit. Goodbye!" << std::endl;
            choice = 4;
        }
        else if (exitChoice == 'n') {
            std::cout << "Returning to main menu" << std::endl;
            choice = 0;
        }
        else {
            std::cout << "Invalid input. Returning to main menu" << std::endl;
            choice = 0;
        }
    }
    else {
        std::cout << "Invalid choice. Please choose 1-4." << std::endl;
    }
}
  




    return 0;
}