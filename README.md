# 🛒 E-Commerce CLI Platform (C++)

A simple **Command Line Interface (CLI) based E-Commerce Platform** built in **C++**.  
It allows users to browse products, add them to a cart, and view the total bill.  
The project demonstrates **Object-Oriented Programming (OOP)**, **STL**, and **Exception Handling**.

---

## ✨ Features

- 📂 **Product Catalog** – Browse all available products with ID, name, and price.  
- 🛍 **Shopping Cart** – Add products with quantity and manage cart.  
- 💰 **Billing System** – Shows detailed bill with subtotals and total.  
- ⚡ **Custom Exception Handling** – Handles invalid product IDs gracefully.  
- 🏗 **OOP & STL** – Uses classes, `vector`, `map`, and `find_if`.

---

## 🏗 Project Structure

- **Product Class** → Represents individual products (ID, name, price).  
- **Cart Class** → Manages cart items (product ID → quantity, display cart).  
- **ECommercePlatform Class** → Connects catalog and cart, adds/list products.  
- **ProductNotFoundException** → Custom exception for invalid product lookups.  
- **Main Function (CLI)** → Interactive menu-driven interface.

---

## 📜 Menu Options

1️⃣ List Products  
2️⃣ Add to Cart  
3️⃣ Show Cart  
4️⃣ Exit  

---

## 🖥 Example Run

====== E-Commerce CLI ======

List Products

Add to Cart

Show Cart

Exit
Enter your choice: 1

Product Catalog:
ID: 1 | Name: Laptop | Price: 50000
ID: 2 | Name: Smartphone | Price: 20000
ID: 3 | Name: Headphones | Price: 2000
ID: 4 | Name: Keyboard | Price: 1500

Copy code
Enter your choice: 2
Enter Product ID: 2
Enter Quantity: 2
Added to cart: Smartphone x 2

Copy code
Enter your choice: 3

Your Cart:
Product: Smartphone | Qty: 2 | Price: 20000 | Subtotal: 40000
Total Amount: 40000
