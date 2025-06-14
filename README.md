# Online Trading System (Moda)

Moda is a C++ project that simulates an online shopping system. It brings together three main user roles — Buyers, a Seller, and an Administrator — each with a unique set of responsibilities, all coordinated by a central System class.

Buyers can explore a product catalog, sort items by price, rating, or name, and manage their shopping cart. They can place orders, apply discounts and redeem digital checks. After making purchases, buyers can track orders, request refunds, and leave product ratings. The system also keeps detailed records of their purchase history and spending insights.

The Seller have tools to manage their inventory by adding or removing products. They handle incoming orders — approving, shipping, or rejecting them — and can also process refund requests. Additionally, the seller can track their best-selling items and monitor their overall revenue.

The Administrator oversees the entire platform. They can send digital checks to buyers, view customer behavior, and monitor all transactions taking place within the system. This role ensures smooth operation and provides insight into user and financial activity.

The core of the project is built using custom classes like Transaction, Product, Order, Cart, and Check, along with hand-crafted data structures such as Vector, String and Pair. Data persistence is supported through save and load functions, allowing the system to maintain state across sessions.


Design Patterns and SOLID principles:

Singleton Pattern: 
The System class is implemented as a singleton, ensuring only one global instance manages all core operations. This centralizes control and simplifies coordination between users and resources.

Separation of Concerns: 
System operations are broken down into separate classes to keep user-specific logic modular and maintainable.

Command Pattern: 
By systematically applying the Command Pattern, Moda gains a highly organized and flexible structure for managing its complex array of user interactions and internal operations.

Strategy Pattern:
Changes the sorting algorithm at runtime. Adding a new sorting algorithm simply requires creating a new strategy class without any need of modifying the existing code, adhering to the Open/Closed Principle.

Data Persistence and Serialization:
Each major class (such as Buyer, Seller, Administrator) implements its own save and load methods, allowing the system to store and restore its state. This acts as a basic custom serialization layer and separates data storage from business logic.

Polymorphism and Inheritance: 
The base User class is extended by Buyer, Seller, and Administrator, allowing shared functionality and enabling dynamic behavior depending on the user type.
