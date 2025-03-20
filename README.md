# GameCafeManagement.
This system empowers café staff with a user-friendly interface, handling key tasks like customer management, billing, and discounts based on membership and playtime.
Imagine a bustling gaming café, filled with customers eager to dive into their favorite games. To manage everything smoothly — from tracking customers to calculating bills — you decide to build a Gaming Café Management System in C.

This system empowers café staff with a user-friendly interface, handling key tasks like customer management, billing, and discounts based on membership and playtime.

🔒 1. Secure Login System
When the system starts, it prompts the café admin to enter a username and password.

If the login details are correct (admin/admin123), access is granted.
If they’re wrong, the system denies access and exits.
📋 2. Main Menu
Once logged in, the admin sees a menu with the following options:
1️⃣ Add a new customer
2️⃣ Show all customers
3️⃣ Search for a customer by name
4️⃣ Calculate the bill
5️⃣ Exit the system

The admin can select an option by entering its corresponding number.

👥 3. Customer Management
Add a New Customer: The admin inputs the customer's name, hours played, and membership type (VIP or Regular).
Show All Customers: Displays a neatly formatted list of all customers, their hours, and membership status.
Search for a Customer: The admin can search for a specific customer by name. If found, the system displays the customer’s details. If not, it informs the admin that the customer wasn’t found.
💰 4. Billing System with Smart Discounts
The café charges a base rate of $5 per hour. But customers can unlock discounts based on their status and playtime:

✅ VIP Discount:

VIP members get 30% off the total bill — loyalty pays off!
✅ Playtime Discounts:

Customers who play for 5 to 10 hours get 10% off.
Customers who play for 10+ hours get 20% off — rewarding the hardcore gamers!
✅ Weekend Special:

If a customer visits on Saturday or Sunday, they get an additional 15% off.
✨ The system calculates the final total, showing the subtotal, total discounts, and final amount due.

🔍 5. Search System (String Matching)
The admin can search for a customer by name.

If found, the system shows their name, hours played, and membership type.
If not found, it displays "Customer not found"
