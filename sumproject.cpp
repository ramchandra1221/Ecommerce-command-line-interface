
//Online CLI Plateform
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include <algorithm>  // for find_if
using namespace std;

// Custom exception for invalid product ID
class ProductNotFoundException : public exception {
    string message;
public:
    ProductNotFoundException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Product class
class Product {
public:
    int id;
    string name;
    double price;

     Product(int id, const string& name, double price)
        : id(id), name(name), price(price) {}
   
};

// Cart class
class Cart {
    map<int, int> items; // product ID -> quantity
 
public:
    void addProduct(int productId, int quantity) {
        items[productId] += quantity;
    }

    void showCart(const vector<Product>& catalog) {
        double total = 0.0;
        cout << "\n Your Cart:\n";
        cout << "-----------------------------------\n";
        for (const auto& item : items) {
            int productId = item.first;
            int qty = item.second;

            auto it = find_if(catalog.begin(), catalog.end(),
                              [productId](const Product& p) { return p.id == productId; });
            if (it != catalog.end()) {
                double subtotal = it->price * qty;
                cout << "Product: " << it->name 
                     << " | Qty: " << qty 
                     << " | Price: " << it->price 
                     << " | Subtotal: " << subtotal << endl;
                total += subtotal;
            }
        }
        cout << "-----------------------------------\n";
        cout << "Total Amount: " << total << endl;
    }
};

// ECommercePlatform class
class ECommercePlatform {
    vector<Product> catalog;
    Cart cart;

public:
    void addProductToCatalog(const Product& product) {
        catalog.push_back(product);
    }

    void listProducts() {
        cout << "\n Product Catalog:\n";
        cout << "-----------------------------------\n";
        for (const auto& p : catalog) {
            cout << "ID: " << p.id 
                 << " | Name: " << p.name 
                 << " | Price: " << p.price << endl;
        }
    }

    void addToCart(int productId, int quantity) {
        auto it = find_if(catalog.begin(), catalog.end(),
                          [productId](const Product& p) { return p.id == productId; });
        if (it == catalog.end()) {
            throw ProductNotFoundException(" Product ID " + to_string(productId) + " not found.");
        }
        cart.addProduct(productId, quantity);
        cout << " Added to cart: " << it->name << " x " << quantity << endl;
    }

    void showCart() {
        cart.showCart(catalog);
    }
};

// Main function (CLI)
int main() {
    ECommercePlatform platform;

    // Add products to catalog
    platform.addProductToCatalog(Product(1, "Laptop", 50000));
    platform.addProductToCatalog(Product(2, "Smartphone", 20000));
    platform.addProductToCatalog(Product(3, "Headphones", 2000));
    platform.addProductToCatalog(Product(4, "Keyboard", 1500));

    int choice;
    while (true) {
        cout << "\n====== E-Commerce CLI ======\n";
        cout << "1. List Products\n";
        cout << "2. Add to Cart\n";
        cout << "3. Show Cart\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                platform.listProducts();
            } else if (choice == 2) {
                int productId, qty;
                cout << "Enter Product ID: ";
                cin >> productId;
                cout << "Enter Quantity: ";
                cin >> qty;
                platform.addToCart(productId, qty);
            } else if (choice == 3) {
                platform.showCart();
            } else if (choice == 4) {
                cout << " Thank you for using the platform.\n";
                break;
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
