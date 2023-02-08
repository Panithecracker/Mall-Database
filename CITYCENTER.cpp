#include<iostream>;
#include<vector>;
#include<fstream>;
#include<algorithm>;

using namespace std;
//the following are going to be the different classes and subclasses that we will use througout the program....

//BIGGEST CLASSES:
//CLASS CITY CENTER...
//CLASS EMPLOYEES
//formed by two subclasses : center ones and the store ones...
//Class Product...
class Employee{
	protected :
		string Ename;
		string EmployeeId;
		string phone;
		double salary;
		string EmployeeAddress;
	public :
	//default constructor
		Employee(){
			Ename = "";
			EmployeeId = "";
			phone = "";
			salary = 0;
			EmployeeAddress = "";
		}
   //Parametrized constructor
        Employee( string a, string b, string c, double d, string e){
        	Ename = a;
			EmployeeId = b;
			phone = c;
			salary = d;
			EmployeeAddress = e;
		}
 //Getters & Setters:
		string getName(){
			return Ename;
		}
		string getId(){
			return EmployeeId;
		}
		string getPhone(){
			return phone;
		}
		double getSalary(){
			return salary;
		}
		string getEmployeeAddress(){
			return EmployeeAddress;
		}
		void setName(string n){
			Ename = n;
		}
		void setId(string i){
			EmployeeId = i;
		}
		void setPhone(string p){
			phone = p;
		}
		void setSalary(double s){
			salary = s;
		}
		void setAddress(string t){
			EmployeeAddress = t;
		}	
		
};
class CenterEmployee : public Employee {
	
	private :
		char type;
		string job; //make sure it is one of these -> cleaning. admin. security, c.service or OTHER...
	public :
		//default cons plus inheritance too
		CenterEmployee() : Employee(){
			type = 'C';
			job = "";
		}
		//parametrized const plus inheritance from employee too
		CenterEmployee(string Ename, string EmployeeId, string phone, double salary, string EmployeeAddress, char f, string g ) : Employee(Ename, EmployeeId, phone, salary, EmployeeAddress){
			type = f;
			job = g;
		}
		//setters and getters...(the ones for the special center employee)
		void setJob( string j ){
			job = j;
		}
		char getType(){
			return type;
		}
		string getJob(){
			return job;
		}

};
class StoreEmployee : public Employee{
	private :
		char type = 'S';
		string role; //either manager or staff .. make sure nothing else...
	public : 
	   //Default cons
	   StoreEmployee() : Employee(){
	   	type = 'S';
	   	role = "";
	   }
	   //Parametrized constructor...
	   StoreEmployee(string Ename, string EmployeeId, string phone, double salary, string EmployeeAddress, char f, string g) : Employee(Ename, EmployeeId, phone, salary, EmployeeAddress){
	   	type = f;
	   	role = g;
	   }
	   //getters and setters(for special store employee attributes...
	   char getType(){
	   	return type;
	   }
	   string getRole(){
	   	return role;
	   }
	   void setRole(string r){
	   	if((r !="manager") && (r!="staff")){
	   		cout << "Invalid role for this employee" << endl;
	   		role = "";
		   }else{
		   	role = r;
		   }
	   }
};
class Product{
	private :
		string product_id;
		string pname;
		double price;
	public :
		//default constr...
		Product(){
			product_id = "";
			pname = "";
			price = 0;
		}
		//parametrized constructor...
		Product( string a, string b, double c){
			product_id = a;
			pname = b;
			price = c;
		}	
		//setters and getters for the product class
		void setProductId(string a){
			product_id = a;
		}
		void setName(string b){
			pname = b;
		}
		void setPrice( double c){
			price = c;
		}
		string getProductId(){
			return product_id;
		}
		string getName(){
			return pname;
		}
		double getPrice(){
			return price;
		}
};
class Store{
	private:
		string Sname;
		string S_id;
		string area;
		vector <class StoreEmployee> EmployeesInStore;
		vector <class Product> Catalogue;
		char status; //O or C... //we will need to make sure that nothing else is inserted before or at the time somebody tries to modify it...
	public :
		//DEFAULT CONSTRUCTOR...
		Store(){
			Sname = "";
			S_id = "";
			area = "";
			vector <class StoreEmployee> EmployeesInStore;
			vector <class Product> Catalogue;
			status = 'C';
		}
		//PARAMETRIZED CONSTRUCTOR...
		Store( string a, string b, string c, vector<StoreEmployee> d, vector<Product> e, char f ){
			Sname = a;
			S_id = b;
			area = c;
			vector <StoreEmployee> EmployeeInStore = d;
			vector <Product> Catalogue = e;
			status = f;
	}
		//setters and getters...
		void setName( string a){
			Sname = a;
		}
		void setId(string i){
			S_id = i;
		}
		void setArea( string a){
			area = a;
		}
		void setEmployee(class StoreEmployee emp){
			//put emp inisde vector...
			EmployeesInStore.push_back(emp);
		}
		void setCatalogue(class Product prod){
			Catalogue.push_back(prod); // we put inside of the catalogue, the product...
		}

		//getters...
		string getName(){
			return Sname;
		}
		string getStoreId(){
			return S_id;
		}
		string getArea(){
			return area;
		}
		char getStatus(){
			return status;
		}
		//SPECIAL FUNCTIONS FOR STORE OBJECTS...
		class StoreEmployee grabemployee(int n){ //to obtain a specific store employee from the list of employees of this store
			return EmployeesInStore[n];
		}
		class Product grabproduct(int n){
			return Catalogue[n]; //this function allows us to get the product of a store object inside its whole catalogue....
		}
		int countemployees(){ //tells you the amount of employees in the store
			return EmployeesInStore.size();
		}
		int countproducts(){
			return Catalogue.size();
		}
		int ishere(string ID){//this function returns the index where the product who has the id given is inside the catalogue, and -1 if no product has that id in this store ctalogue
		  int Bfound = 0;
		  int pos = -1;
		  int i = 0;
		  while((Bfound == 0) && (i<countproducts())){
		  	if(grabproduct(i).getProductId() == ID){
		  		Bfound = 1;
		  		pos = i;
			  }else{
			  	i++;
			  }
		  }
		  return pos;
		}
		void removeProduct(int p){
			//this removes the pth product from the Catalogue of a Store object
			Catalogue.erase(Catalogue.begin()+p);
		}
};
class CityCenter{
	
	public :
		string name;
		string address;
		int parkings;
		vector< class Store> StoreList;
		vector< class CenterEmployee> EmployeeList;
	//public :
		//DEFAULT CONSTRUCTOR ...
		CityCenter(){
		name = "";
		address = "";
		parkings = 0;
		vector <class Store> StoreList;
		vector <class CenterEmployee> EmployeeList;
		}
		//PARAMETRIZED CONSTRUCTOR...	
		CityCenter( string a, string b, int c, vector<Store> d, vector<CenterEmployee> e){
			name = a;
			address = b;
			parkings = c;
			StoreList = d;
			EmployeeList = e;
		}
		//getters and setters....
		string getName(){
			return name;
		}
		string getAddress(){
			return address;
		}
		int getParkings(){
			return parkings;
		}
	
		void setName(string a){
			name = a;
		}
		void setAddress(string b){
			address = b;
		}
		void setParkings( int p){
			parkings = p;
		}
		void setStore(class Store st){
			StoreList.push_back(st); // we put the store inside the vector of stores...
		}
		void setEmployee(class CenterEmployee cemp){
			EmployeeList.push_back(cemp); // we put the given center employee to the vector of center employees, namely, EmployeesList
		}
		
		void setInStore(int n,class Product p ){
			//this function is used to add at the nth store of StoreList vector, a product to its catalogue
			StoreList[n].setCatalogue(p);
		}
		
		//USEFUL FUNCTIONS FOR OBJECTS OF THE CLASS CITY CENTER :
		class CenterEmployee grabemployee(int n){ //returns center employee from list at index n
				return EmployeeList[n];
			}
		int countemployees(){ //return the amount of center employees
			return EmployeeList.size();
		}
		int countstores(){ // returns the amount of stores inside our object of the class City center
			return StoreList.size();
		}
		class Store grabstore(int n){ //returns the nth store in the city center object
			return StoreList[n]; 
		}
		int ishere(string s){
			//this function will return the ith position where the store is inside the vector of store of the city center object and -1(since this is never a valid index) otherwise...
			int Bfound = 0;
			int pos = -1;
			int i = 0;
			while((Bfound == 0) && (i<countstores())){
				if(grabstore(i).getName() == s){ //found it
				  Bfound = 1;
				  pos = i;
				}else{
					i++;
				}
			}
			return pos;
		}
		void removeProdFrom(int p, int s){
			//this function removes the pth product from the sth store of the CityCenter object...
			StoreList[s].removeProduct(p); //we erase the pth product from the sth store catalogue
		}
};

//FUNCTION TO READ INFORMATION AND CREATE CITY CENTER OBJECT
class CityCenter ReadinitialData();
//FUNTION THAT DISPLAY MENU AND RETURNS OPTION
int showMenu();
//FUNCTION THAT RETURNS LIST OF ALL EMPLOYEES IN  PAIRS NAME & WORKPLACE SORTED IN ORDE
vector<pair <string,string> > getAllEmployees(class CityCenter Mall);
void showAllEmployees(vector <pair<string,string> > Allemployees){
	cout << "NAME _________ WORKPLACE" << endl;
	for(int l = 0; l<Allemployees.size(); l++){
		cout << Allemployees[l].first << " " << Allemployees[l].second << endl;
	}
}
//FUNCTION THAT RETURNS AN AVAILABILITY LIST ABOUT AN SPECIFIC PRODUCT IN A CITY CENTER OBJECT----
void showStorePriceGivenProduct(class CityCenter Mall){
	int counter = 0;
	cout << "SEARCH BY PRODUCT NAME ________" << endl;
	cout << "What is the name of the product that you are looking for ?" << endl;
	cout << "Name of product > ";
	string target; //this is a variable of type string that will contain the name we are looking for..
	cin >> target;
	cout << target << endl;
	cout << "STORE        PRICE" << endl;
	cout << "------------------" << endl;
	for(int i = 0; i<Mall.countstores(); i++){
		//we need to check in every store catalogue...
		for(int j = 0; j<Mall.grabstore(i).countproducts(); j++){
			//we proceed and compare the targeted name with the name of jth product on the ith store 
			if(Mall.grabstore(i).grabproduct(j).getName() == target){ //then we increment the counter and print the info simultaneously...
			counter++;
			cout << Mall.grabstore(i).getName() << "    " << Mall.grabstore(i).grabproduct(j).getPrice();
			cout << endl;
			}
		}
	}
	if(counter == 0){ //check if we havent found any coincidences with that name,,,
		cout << "That product is not available here, sorry. " << endl;
	}
}
//////////////////////
//FUNCTION THAT ADDS A PRODUCT INSIDE A CERTAIN STORE BY USING ITS ID
void addProductInStore(class CityCenter &Mall){
	//we pass by reference
	// we first ask for the product id the user wants to add and the store where it is destined to...
	//Step 1: Check that the store exists...
	cout << "NEW PRODUCT IN STORE REGISTER " << endl;
	string store;
	cout << "Enter the name of the store where the new product is going to be in : " << endl;
	cin >> store; //we check that it exists an store with this name inside our object called Mall
	if(Mall.ishere(store) >= 0){ //store exists in the cityc enbter object, since index >=0
		cout << "Store was found!" << endl;
		cout << "Enter the id of the new product here : ";
		string t_id;
		cin >> t_id;
		//for efficiency, we use the function that returns us, the index where the store is located inside the vector of stores..
		int index = Mall.ishere(store);
		//now we look inside the catalogue of the ith store in the object of city center we have...
		if(Mall.grabstore(index).ishere(t_id) >=0){
			cout << "Sorry but that product is already in that store " << endl;
			//for sick of specification, we also let the user know about the product descripotion,,,
			int k = Mall.grabstore(index).ishere(t_id);
			cout <<"Name >> " <<  Mall.grabstore(index).grabproduct(k).getName() << endl;
			cout << "Price >> " << Mall.grabstore(index).grabproduct(k).getPrice() << endl;
			cout << "Id >> " << Mall.grabstore(index).grabproduct(k).getProductId() << endl;
		}
		else{
			cout << "That product is not inside " << store << " store !" << endl;
			//so we declare an object of the class product to store it inside the store
			class Product p;
			p.setProductId(t_id); //its id given previously,,,
			cout << "Specify the info about the new product below please : " << endl;
			cout << "Name :";
			string n;
			cin >> n;
			p.setName(n);
			cout << endl;
			cout << "Price : ";
			double pr;
			cin >> pr;
			p.setPrice(pr);
			cout << "The new product was successfully added to the store " << endl;
			//now that we have filled our new product completely, we put it inside the suitable store whose index was gotten before...
			Mall.setInStore(index,p);
			}
		}
		else{
			cout << "That store does not belong to this company, sorry" << endl;
		}
	}
///////////////////////////////////////////////////
//FUNCTION THAT RETURNS EVERY SINGLE PIECE OF INFORMATION  STORED INSIDE AN OBJECT OF THE CLASS CITY CENTER...
void showAllInformation(class CityCenter Mall){
	//STEP 1 : CREDENTIALS INFORMATION
	cout << "_______CREDENTIALS INFORMATION__________" << endl;
	cout << "Name >> " << Mall.getName() << endl;
	cout << "Address >> " << Mall.getAddress() << endl;
	cout << "Parking spaces  >> " << Mall.getParkings() << endl;
	cout << "__________________________________________" << endl;
	//STEP 2 : CITY CENTER EMPLOYEES 
	cout << "_____LIST OF CITY CENTER EMPLOYEES _______" << endl;
	for(int i = 0; i<Mall.countemployees();i++){
		cout << "Employee # " << i+1 << " information :" << endl;
		cout << "Name > " << Mall.grabemployee(i).getName() << endl;
		cout << "Id   > " << Mall.grabemployee(i).getId() << endl;
		cout << "Phone > " << Mall.grabemployee(i).getPhone() << endl;
		cout << "Salary > " << Mall.grabemployee(i).getSalary() << endl;
		cout << "Type > " << Mall.grabemployee(i).getType() << endl;
		cout << "Occupation > " << Mall.grabemployee(i).getJob() << endl;
	}
	//STEP 2: LIST OF STORES WITH EMPLOYEES AND CATALOGUE
	cout << "______________LIST OF STORES_______________" << endl;
	for(int j = 0;  j<Mall.countstores(); j++){
		cout << "---STORE # " << j+1 << endl;
		cout << " Name > " << Mall.grabstore(j).getName() << endl;
		cout << "Area > " << Mall.grabstore(j).getArea() << endl;
		cout << "Store Id > " << Mall.grabstore(j).getStoreId() << endl;
		cout << "Store status > " << Mall.grabstore(j).getStatus() << endl;
		//now the employees 
		for(int k = 0; k<Mall.grabstore(j).countemployees();k++){
			cout << "Employee # " << k+1 << " information : " << endl;
			cout << "Name > " << Mall.grabstore(j).grabemployee(k).getName() << endl;
			cout << "Id   > " << Mall.grabstore(j).grabemployee(k).getId() << endl;
			cout << "Phone > " << Mall.grabstore(j).grabemployee(k).getPhone() << endl;
			cout << "Salary > " << Mall.grabstore(j).grabemployee(k).getSalary() << endl;
			cout << "Type  > " << Mall.grabstore(j).grabemployee(k).getType() << endl;
			cout << "Role > " << Mall.grabstore(j).grabemployee(k).getRole() << endl;
		}
		//now the catalogue of the store 
		for(int l = 0; l<Mall.grabstore(j).countproducts(); l++){
			cout << "---Catalogue inside the store ---" << endl;
			cout << "-Product " << l+1 << " information-" << endl;
			cout << "Name >> " << Mall.grabstore(j).grabproduct(l).getName() << endl;
			cout << "Product id >> " << Mall.grabstore(j).grabproduct(l).getProductId() << endl;
			cout << "Price >> " << Mall.grabstore(j).grabproduct(l).getPrice() << "$"<< endl;
		}
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	cout<<"#############################################################"<<endl;
	cout<<"#                    _                                      #"<<endl;  
	cout<<"#                  -=\\`\\                                    #"<<endl;  
	cout<<"#              |\\ ____\\_\\__                                 #"<<endl;  
	cout<<"#            -=\\c`""""""" "`)                                        #"<<endl;  
	cout<<"#               `~~~~~/ /~~`\                                #"<<endl;  
	cout<<"#                 -==/ /                                    #"<<endl;  
	cout<<"#                   '-'                                     #"<<endl;  
	cout<<"#                  _  _                                     #"<<endl;  
	cout<<"#                 ( `   )_                                  #"<<endl;  
	cout<<"#                (    )    `)                               #"<<endl;  
	cout<<"#              (_   (_ .  _) _)                             #"<<endl;  
	cout<<"#                                             _             #"<<endl;  
	cout<<"#                                            (  )           #"<<endl;  
	cout<<"#             _ .                         ( `  ) . )        #"<<endl;  
	cout<<"#           (  _ )_                      (_, _(  ,_)_)      #"<<endl;  
	cout<<"#         (_  _(_ ,)                                        #"<<endl;  
	cout<<"#############################################################"<<endl;
	cout << endl;
	cout << endl;
	cout << endl;

}
//FUNCTION THAT IS USED TO REMOVE A SPECIFIC PRODUCT FROM SPECIFIC STORE...
void removeProductInStore(class CityCenter &Mall){
	//STEP 1 : ask for the name of the store where the product is and check that the store exists by using our useful ishere function on the inputted CityCenter object
	cout << "_____PRODUCT DELETION BY NAME ________" <<endl;
	cout << "Enter the name of the store where the product will be removed from : " << endl;
	string store;
	cin >> store;
	int index = Mall.ishere(store); //we store the result o ishere function here, if is negative, then there is no store with that name ,,,
	if(index >=0){
		//the store exists and is at position "index" on the vector of stores, so that is where we search for the name of the product...
		cout << "Perfect.Now, insert below the id of the product " << endl;
		string target; //we will look inside the catalogue of the store for a product with this namw. Then, we just check if now the product exists in  the store...
		cin >> target;
		int product_index; //this contains the position where the product is inside the catalogue of our desired store...
		product_index = Mall.grabstore(index).ishere(target);
		if(product_index >=0){
			//then the product exists inside the given store, so we just use our function to remove a product from a catalogue of a certain store of our vector of stores..
			Mall.removeProdFrom(product_index,index);
			cout << "The product was successfully removed from the data base of the City Center " << Mall.getName() << endl;
			cout << "-----------------------------------------------------------------------------" << endl;
		}else{
			cout << "We are sorry but there is no product with that id" << endl;
		}
	}
	else{
		cout << "Sorry, but there is no store with that name here" << endl;
	}
}
///////////////////////////////
//FUNCTION THAT RECEIVES AN OBJECT FROM CITY CENTER CLASS AND PRINTS ALL THE INFORMATION ABOUT IT INSIDE THE SAME 3 FILES USED TO OBTAIN THE ORIGINAL INFO RIGHT AFTER THE EXECUTION OF MAIN FUNCTION....
void saveAllInformation(class CityCenter Mall){
	//STEP 1 : PRINT CREDENTIALS INFORMATION
	ofstream OutFile1;
	OutFile1.open("Credentials.txt");
	if(!OutFile1){
		cout << "Error when printing on file 1 " << endl;
	}else{
		OutFile1 << Mall.getName() << endl;
		OutFile1 << Mall.getAddress() << endl;
		OutFile1 << Mall.getParkings() << endl;
		OutFile1.close();
	}
	//STEP 2 : PRINT THE LIST OF STORES IN THE SECOND FILE WE USED INITIALLY
	ofstream OutFile2;
	OutFile2.open("Stores.txt");
	if(!OutFile2){
		cout << "Error when printing on the second file" << endl;
	}
	else{
		for(int i = 0; i<Mall.countstores(); i++){
			OutFile2 << "STORE " << i+1 <<endl;
			OutFile2 << Mall.grabstore(i).getName() << endl;
			OutFile2 << Mall.grabstore(i).getStoreId() << endl;
			OutFile2 << Mall.grabstore(i).getArea() << endl;
			//print number of employees in store .. int
			OutFile2 << Mall.grabstore(i).countemployees() << endl;
			//Print all the list of this store employees 
			for(int j= 0; j<Mall.grabstore(i).countemployees(); j++){
				OutFile2 << Mall.grabstore(i).grabemployee(j).getName() << endl;
				OutFile2 << Mall.grabstore(i).grabemployee(j).getId() << endl;
				OutFile2 << Mall.grabstore(i).grabemployee(j).getPhone() << endl;
				OutFile2 << Mall.grabstore(i).grabemployee(j).getEmployeeAddress() << endl;
				OutFile2 << Mall.grabstore(i).grabemployee(j).getSalary() << endl;
				OutFile2 << Mall.grabstore(i).grabemployee(j).getRole() << endl;
				OutFile2 << Mall.grabstore(i).grabemployee(j).getType() << endl;
			}
			//Print number of products in the catalogue of this store
			OutFile2 << Mall.grabstore(i).countproducts() << endl;
			//Print all the list of products in this ith store
			for(int k = 0; k<Mall.grabstore(i).countproducts(); k++){
				OutFile2 << Mall.grabstore(i).grabproduct(k).getName() << endl;
				OutFile2 << Mall.grabstore(i).grabproduct(k).getProductId() << endl;
				OutFile2 << Mall.grabstore(i).grabproduct(k).getPrice() << endl;
			}
		}
		OutFile2.close();
	}
	//STEP 3 : PRINT THE LIST OF CENTER EMPLOYEES INSIDE THE THIRD FILE WE USED INITIALLY
	ofstream OutFile3;
	OutFile3.open("centeremployees.txt");
	if(!OutFile3){
		cout << "Error when trying to print the information inside the file three" << endl;
	}else{
		//print the number of center employees at thetop first.-..
		OutFile3 << Mall.countemployees() << endl;
		//now print info about each center employees;
		for(int l = 0; l<Mall.countemployees(); l++){
			OutFile3 << "EMPLOYEE " << l+1 << endl;
			OutFile3 << Mall.grabemployee(l).getName() << endl;
			OutFile3 << Mall.grabemployee(l).getId() << endl;
			OutFile3 << Mall.grabemployee(l).getPhone() << endl;
			OutFile3 << Mall.grabemployee(l).getEmployeeAddress() << endl;
			OutFile3 << Mall.grabemployee(l).getSalary() << endl;
			OutFile3 << Mall.grabemployee(l).getJob() << endl;
			OutFile3 << Mall.grabemployee(l).getType() << endl;
		}
		OutFile3.close();
	}
}
int main(){
	CityCenter Mall;
	Mall = ReadinitialData();
	int answer;
	answer = showMenu();
	while(answer!=7){
		if(answer == 1){
			//we use the function that returns a list of the employees and then the other one to just prtint them...
			vector <pair <string,string> > Allemployees;
			Allemployees = getAllEmployees(Mall);
			showAllEmployees(Allemployees);
		}
		else if(answer == 2){
			//on this option, we basically need to search for the price and name pf the store in our city center object that contains an specific product targeted by its name....
			showStorePriceGivenProduct(Mall);
			cout << endl;
		}
		else if(answer == 3){
			//we basically have to use the function that does all of this...
			addProductInStore(Mall); 
		}
		else if(answer == 4){
			// we implement the function needed to deal with this case
			removeProductInStore(Mall);
		}
		else if(answer == 5){
			//display all the information about the city center object
			showAllInformation(Mall);
		}
		else if(answer == 6){
			//SAVE ALL THE INFORMATION FROM CURRENT INFORMATION ON OUR CITYCENTER OBJECT
			//FOR THAT, we just need to use the function 
			saveAllInformation(Mall);
			cout << "All the information from the CityCenter and new changes(if any), has been saved successfully in the text files." << endl;
		}
		
		
		
		answer = showMenu();
	}

	
	return 0;
}

//FUNCTION DEFINITION
///FUNCTION TO READ INFORMATION AND CREATE CITY CENTER OBJECT
class CityCenter ReadinitialData(){
	// STEP 1: we declare the object from CityCenter class to later on fill it...
	class CityCenter Mall;
////////////////////////////////////////////////////////////////////////////////////////

//STEP 2 : USE FILES INFORMATION
	//USE OF THE FIRST FILE THAT CONTAINS THE NAME ,ADDRESS AND PARKING SLOTS:
	ifstream MyFile1;
	MyFile1.open("Credentials.txt");
	if(!MyFile1){
		cout << "Error when opening the file named Credentials.txt!" << endl;
	}else{
	string a,b; //name and address of mall
	int p; //parking slots of mall
	getline(MyFile1,a);
	Mall.setName(a);
	getline(MyFile1,b); 
	Mall.setAddress(b);
	MyFile1 >> p;
	Mall.setParkings(p);
	MyFile1.close();
	 }
	//USE OF THE SECOND FILE THAT CONTAINS THE INFORMATION ABOUT THE STORES...
		ifstream MyFile2;
	MyFile2.open("Stores.txt");
	if(!MyFile2){
		cout << "Error when finding the file Stores.txt" << endl;
	}else{
		string line;
		while(getline(MyFile2,line)){ // then we have a store to read ... 
		class Store store;
			//Read the name, area and id of this store...
			string name;
			getline(MyFile2,name);
			store.setName(name);
			string id;
			getline(MyFile2,id);
			store.setId(id);
			string area;
			getline(MyFile2,area);
			store.setArea(area);
			int n; 
			MyFile2 >> n; //this denotes the number of employees inside this store..
			MyFile2.ignore();
			for( int i = 0; i<n ; i++){
				class StoreEmployee employee;
				string name, emp_id, phone, address, role;
				double salary;
				char type;
				getline(MyFile2, name);
				employee.setName(name);
				getline(MyFile2, emp_id);
				employee.setId(emp_id);
				getline(MyFile2, phone);
				employee.setPhone(phone);
				getline(MyFile2,address);
				employee.setAddress(address);
				MyFile2 >> salary;
				employee.setSalary(salary);
				MyFile2.ignore();
				getline(MyFile2, role);
				employee.setRole(role);
				MyFile2 >> type; //already predefined by default constructor(S)so dont even need to access this member for any store emp
				MyFile2.ignore();
				//now that we filled this employee, we put it inside the vector of employees on this store,,,
				store.setEmployee(employee);
			}
			int r; //this next integer denotes the number of products in this store,...
			MyFile2 >> r;
			MyFile2.ignore();
			string a,b;
			double c;
			for(int j = 0; j<r;  j++){ //we read as many products there are in the store...
			 class Product product;
				getline(MyFile2, a);
				product.setName(a);
				getline(MyFile2,b);
				product.setProductId(b);
				MyFile2 >> c;
				product.setPrice(c);
				MyFile2.ignore();
				//now that we have filled up the product object, we bring it to the catalogue...
				store.setCatalogue(product);	
			}
			//now, we have completely filled our store object, so we put it inside the vector of stores of our mall of city center class
			Mall.setStore(store);
		}
		MyFile2.close();}
	  //USE OF THE THIRD FILE THAT CONTAINS THE INFORMATION ABOUT THE CENTER EMPLOYEES:
	  ifstream MyFile3;
	MyFile3.open("centeremployees.txt");
	if(!MyFile3){
		cout << "Error when finding the file number 3" << endl;
	}else{
		int x;
		MyFile3 >> x;
		MyFile3.ignore();
		string name, id,phone,address,job;
		char t;
		double salary;
		string line;
		for(int k = 0; k<x; k++){
		   class CenterEmployee cemp;
			getline(MyFile3,line); //employee header... dont need this... "EMPLOYEE #N"
			getline(MyFile3,name);
			cemp.setName(name);
			getline(MyFile3,id);
			cemp.setId(id);
			getline(MyFile3,phone);
			cemp.setPhone(phone);
			getline(MyFile3,address);
			cemp.setAddress(address);
			MyFile3 >> salary;
			cemp.setSalary(salary);
			MyFile3.ignore();
			getline(MyFile3,job);
			cemp.setJob(job);
			MyFile3 >> t; //type, which is always 'C' so we dont need it .. the defaul cnstructor set it like that already for any center employee object...
			MyFile3.ignore();
			//NOW that the object of the class center employee has been completrely filled up, we just need to add it to the vector for the city center obeject attribute
			Mall.setEmployee(cemp);
		}
		MyFile3.close();
	}
	//ALL FILES WERE READ NOW. NOW, WE RETURN OUR DESIRED OBJECT FROM CITY CENTER CLASS
	return Mall;
}
//FUNTION THAT DISPLAY MENU AND RETURNS OPTION
int showMenu(){
	cout << "1.Show all employees " << endl;
	cout << "2.Get store and price of a given product " << endl;
	cout << "3.Add products in store " << endl;
	cout << "4.Remove product in store " << endl;
	cout << "5.Show all information " << endl;
	cout << "6.Save all information " << endl;
	cout << "7.End the program " << endl;
	int choice;
	cout << "INSERT YOUR OPTION HERE >> " ;
	cin >> choice;
	while((choice >7) || (choice <1)){
		cout << "Incorrect choice " << endl;
		cout << "Please, choose a correct option below" << endl;
		cin >> choice;
	}
}
//FUNCTION THAT RETURNS LIST/VECTOR OF PAIRS NAME, WORKPLACE ALPHABETICALLY ORDERED
vector<pair <string,string> > getAllEmployees(class CityCenter Mall){
	//STEP 1: DECLARE VECTOR OF PAIRS AND FILL IT UP
	vector <pair<string,string> > Allemployees;
	//first we put all the center employees inside
	for(int i = 0; i<Mall.countemployees() ; i++){
		pair <string,string> p;
		p.first = Mall.grabemployee(i).getName();
		p.second = "CENTER";
		Allemployees.push_back(p);
	}
	//now we neeed to finish it up with the ones in each store
	for( int j = 0; j<Mall.countstores(); j++){
		//for each store in this city center object, we need to look for each list of employees of the store...
		//we get the corresponding store:
		Store current_store;
		current_store = Mall.grabstore(j);
		for( int k = 0; k<current_store.countemployees(); k++){
			pair <string,string> p;
			p.first = current_store.grabemployee(k).getName();
			p.second = "STORE";
			Allemployees.push_back(p);
		}
	}
	//NOW THAT WE FINALLY HAVE OUR VECTOR OF PAIRS FILLED UP, WE JUST NEED TO SORT IT ALPHABETICALLY;
	sort(Allemployees.begin(),Allemployees.end());
	return Allemployees;
}
