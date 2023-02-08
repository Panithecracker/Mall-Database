# Project Description:
The “City Center” is a shopping place where people go to make all kinds of purchases in stores that offer
different products that are sold by its employees. The city center is composed of a set of the following
properties: name, address, number of parking spaces, a vector of stores, and a vector of the center own
employees.
A store is characterized by a number of properties such as; name, store identifier, area, a vector of
employees of the store, a catalogue of different products they sell, and the status of the store (O: open
or C: closed).
A catalogue consists of a vector of products, each product identified by; identifier, name and price.
There are two types of employees, those who work for the center and those who work for the shopping
stores. For each employee we want to know the following; name, identifier number, address, telephone,
salary, type (C or S; C if the employee is a center employee, S if he/she is a shopping store employee).
More information about the employees is shown as follows;
− For the center employees we want to save his/her occupation such as: Cleaning, administration,
security, customer service, or OTHER.
− Store employees do NOT have a defined occupation, but they have an associated status within
the store (store manager or staff).

# To do:
Develop a program for the management of "City Center" performing the following requirements:
* Implement the classes and subclasses that are needed to handle the previous information.
* All the classes must contain default constructors and parametrized constructors.
* The program must display a menu of options (contained in the showMenu function) and execute
those selected by the user repeatably until the “end program” option is selected.
* The program must have the necessary error control to ensure its stability.

# **Functions**
The following functions must be implemented:
* `readInitialData`: this function is used to return an object of Center. The center consists of at least three stores. Each store consists of at least four employees, and at least five products. The center has at least five own employees. You can invent all the information related to the center, stores, employees, products, etc. This function must read this information from external files. You can use one file with all the information or several files with specific information. The function
readInitialData is executed at the beginning of the main function. It does not receive any parameters.
* `getAllEmployees`: the function receives a center object as input parameter. The function returns
a list of all the employees working in the center (both the center employees and the employees
in its stores). The function returns a list of pairs (employee name and workplace), the list must
be ordered alphabetically.
* `showAllEmployees`: the function receives a list of pairs employee-workplace and prints the content on the screen as shown in the following example:

EMPLOYEE NAME WORKPLACE

--------------------------------------------------

ANA GARCIA STORE

ANA SANCHEZ CENTER

ANTONIO PEREZ STORE

CARMEN MARTINEZ STORE

......

* `showStorePriceGivenProduct`: It receives a Center object as parameter and asks a product’s
name. It prints the names of the stores that contain the product and its price. The function does
not return anything. For example, if the user introduces “Blue jeans” then the function prints
the following list:
BLUE JEANS

STORE PRICE

------------------------------------

ATHLETIC YOUTH 19.99

FASHION CLOTHES 19.99

* `addProductInStore`: the function receives a reference of an object of Center and adds a new
product in the catalogue of a store. To do this, the function must ask the store and the
information of the new product. It is necessary to check that the product does not already exist
in the catalogue. The function does not return anything.
* `removeProductInStore`: the function receives a reference to a Center object and removes a
product from a store's catalogue. To do this, the function must ask for the store and for the
product identifier. It is necessary to check that the product already exists in the catalogue. The
function does not return anything.
* `showAllInformation`: this function prints on the screen all the information related to the center,
stores, employees, products. The function receives an object of center, and it does not return
anything. There are no style restrictions to display the information, but understandability will be
taken into account.
* `saveAllInformation`: the function receives an object of center and all the information related to
the center, stores, employees, products must be stored in a text file ‘Output.txt’. The function
does not return anything. There are no style restrictions to display the information, but
understandability will be taken into account.
* `showMenu`: this function prints the following menu on the screen and returns the option
selected by the user:
* 1. Show all employees
* 2. Get store and price of a given product
* 3. Add products in store
* 4. Remove product in store
* 5. Show all information
* 6. Save all information
* 7. End program

It must be controlled that the user cannot choose another option.
