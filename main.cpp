#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main();
int main() {

    

    double balance = 0;
    std::vector<double> transactions;
    std::ifstream file("balance.txt");
    file >> balance;
    file.close();
    std::ifstream transFile("transactions.txt");
    double transaction;
    while (transFile >> transaction) {
        transactions.push_back(transaction);
    }
    transFile.close();
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
        transactions.push_back(income);
        std::ofstream transFile("transactions.txt", std::ios::app);
        transFile << income << std::endl;
        transFile.close();

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
        transactions.push_back(-expense);
        std::ofstream transFile("transactions.txt", std::ios::app);
        transFile << -expense << std::endl;
        transFile.close();

        std::cout << "Expense added!" << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    }
    else if (choice == 3) {
        std::cout << "You chose View Summary." << std::endl;
        
        int summaryChoice = 0;
        
        std::cout << "1. View Balance" << std::endl;
        std::cout << "2. View Transaction History" << std::endl;
        std::cout << "3. Back to Main Menu" << std::endl;
        std::cout << "Choose your option: " << std::endl;
        std::cin >> summaryChoice;
        if (summaryChoice == 1) {
            std::cout << "Current Balance: $" << balance << std::endl;
        }
        else if (summaryChoice == 2) {
            std::cout << "Transaction History:" << std::endl;
            int transactionNumber{1};
            double totalIncome{0};
            double totalExpense{0};
            for (double transaction : transactions) {
                if (transaction > 0) {
                    std::cout << transactionNumber << ". Income: $" << transaction << std::endl;
                    totalIncome += transaction;
                }
                else {
                    std::cout << transactionNumber << ". Expense: $" << std::abs(transaction) << std::endl;
                    totalExpense += std::abs(transaction);
                }
                transactionNumber++;
            }
            std::cout << "Total Income: $" << totalIncome << std::endl;
            std::cout << "Total Expense: $" << totalExpense << std::endl;
            std::cout << "Current Balance: $" << balance << std::endl;
        }
        else if (summaryChoice == 3) {
            std::cout << "Returning to main menu." << std::endl;
        }
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