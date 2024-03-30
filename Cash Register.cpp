#include <iostream>
#include <vector>
#include <iomanip> // For setting decimals
using namespace std;

struct Product {
    string name;
    double price;
};

void displayMenu(const vector<Product>& products) {
    cout << "Welcome to our cafe!\n";
    cout << "Available products:\n";
    for (int i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i].name << " - " << fixed << setprecision(2) << products[i].price << " EUR\n";
    }
    cout << products.size() + 1 << ". Exit\n";
}

double addTotal(const vector<Product>& bill) {
    double total = 0;
    for (const auto& product : bill) {
        total += product.price;
    }
    return total;
}

void displayBill(const vector<Product>& bill) {
    cout << "\nYour bill:\n";
    for (const auto& product : bill) {
        cout << product.name << " - " << fixed << setprecision(2) << product.price << " EUR\n";
    }
    cout << "Total: " << addTotal(bill) << " EUR\n";
    cout << "Thank you, come again!\n";
}

int main() {
    vector<Product> products = {
        {"Coffee", 10.00},
        {"Tea", 8.00},
        {"Juice", 15.00},
        {"Water", 5.00}
    };

    vector<Product> bill;
    int choice;

    do {
        displayMenu(products);
        cin >> choice;

        if (choice > 0 && choice <= products.size()) {
            bill.push_back(products[choice - 1]);
            cout << "Added: " << products[choice - 1].name << "\n\n";
        }
        else if (choice == products.size() + 1) {
            displayBill(bill);
            break;
        }
        else {
            cout << "Invalid input. Please try again.\n";
        }

    } while (true);

    return 0;
}
