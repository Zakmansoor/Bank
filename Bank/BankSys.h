#pragma once

#include <iostream>
#include <string>
#include<fstream>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;
namespace BankSysn{

enum SignOption { login = 1, signin = 2 };
enum enumOperationTransaction { Depsite = 1, Withdraw = 2, Transfer = 3, TotalBalance = 4, GoBack = 5, QiukWithDraw = 6, ShowCheckBalance = 7 };
enum Roles { admin = 1, user = 2 };
string ClientsFileName = "Client.txt";
string UsersFileName = "users.txt";
string FileAction = "action.txt";


//fstream file;
int indexfile = 1;
const int Max_Size = 1024;
struct Users
{
	int ID;
	int AccountNumber;
	string Name = "";
	string Password = "";
	Roles role;
	bool tracke = false;
	bool MarkDeleted = false;
	vector<int> Permission;
	int storpermission;
};
struct Client
{
	int ID = 0;
	string AccountNumber;
	string pinCode;
	string Name;
	string PhoneNumber;
	double Balance = 00.00;
	bool MarkDeleted = false;

};

struct stDate {
	int Day;
	int Month;
	int Year;
};
struct Action
{
	string AccountNumber;
	double amount;
	string op;
	stDate date;
	string stdate;
	bool MarkDeleted = false;
};
	double CurrentBalance(int Id);
	Users CurrectUser;
	Client CurrentClient;
	string CurrntAccountNumber(int Id);
	bool QuickWithDraw();
	void ShowCheckBalanceScreen();
	void Start();
	bool SelectUserIdFromFile(int& Id);
	void TransactonManue();
	void MangeUser();
	void ClientManue();
	void AdminManue();
	string RoleType(Roles role);
	Users ConvertRecordToUsersData(string data);
	int ReadPositiveNumber(string message);
	stDate GetCurrentDate();
	void Pause();
	string ReadString(string message);
	string ConvertRecordToLineString(Client client, string delim = "#//#");


	string ConvertRecordUserToLineString(Users user, string delim = "#//#");

	vector <Client> LoadCleintsDataFromFile(string ClientsFileName);
	vector<string> SplitString(string st, string delim = "#//#");
	Roles RoleType(string role);
	Users ConvertRecordToUsersData(string data);
	string ActionClient(enumOperationTransaction op);
	void HeaderAction(vector<Action>& vaction);
	vector <Users> LoadUsersDataFromFile(string ClientsFileName);
	bool IsUserIsExiting(int  AccountNumber);
	Action ConvertRecordToActionData(string data);
	string FormatDate(stDate date);
	Users SignIN(int role);
	void  showAllAction();
	void printUser(Users user);
	void ShowAllUsers();
	void HeaderUserTable(vector<Users> user);
	vector<Action> DataSearch(string AccountNumber);
	vector <Action> LoadActionClientDataFromFile(string ActionFileName);
	string ActionClient(enumOperationTransaction op);
	Action ConvertRecordToActionData(string data);
	string FormatDate(stDate date);
	bool SaveAction(Action action, string delim = "#//#");
	vector <Action> LoadActionClientDataFromFile(string ActionFileName);
	vector<Action> DataSearch(string AccountNumber);
	void ShowAllUsers();
	void printUser(Users user);
	void HeaderUserTable(vector<Users> user);
	int convertPermissionToMark(vector<int> permission);
	void  showAllAction();
	void SaveUser(vector<Users> vUsers);
	void HeaderAction(vector<Action>& vaction);
	void SaveFile();
	bool CheckCkclientIsFound(string  Number);
	void HeaderTransaction(int choice);
	void HeaderOperation(int choice);
	char ReadChar(string message);
	void SingUsers();
	void ShowAllClients();
	void ShowBalanceClients();
	Client AddClient();
	void PrintClientCard(Client client);
	void Add();
	bool DeleteUser(int AccountNumber);
	void AddUserToFile();
	bool IsUpdate(int AccountNumber);
	bool Login(Roles& role, int& perm, int& ID,double & amount);
	bool MarkedToDeleteUse(vector<Users>& vUsers, int Number);
	Users UpdateUsers(int AccountNumber, int Id);
	Client ConvertRecordToClietData(string data);
	Users SignIN(int role);
	Client UpdateClient(string AccountNumber, int ID);
	bool Search(string AccountNumber);
	bool Update(string AccountNumber);
	bool Delete(string AccountNumber);

	void PrintClientCard(Client client);
	bool FindClientByAccountNumber(string AccountNumber, vector<Client> vClients, Client& client);
	bool MarkClientToAction(string AccountNumber, vector<Client>& vclient);


	void ShowAllClients();
	Client UpdateClient(string AccountNumber, int ID);
	void ShowBalanceClients();
	bool CheckCkclientIsFound(string  Number);
	Client AddClient();
	void HeaderClientTable(vector<Client> client);
	bool ValidateAmoun(double amount, double amountentry);
	double ShowAllBalance();
	void GoToManueTransaction();
	void DataAction(Action& action, Client client, double amount, enumOperationTransaction Operation);
	bool DepositBalanceToClientByAccountNumber(string AccountNumber, double  Amount, vector <Client>& vClients);
	void WithdrawClient(enumOperationTransaction op);
	void Dobsite(enumOperationTransaction op);
	static void TransfertoAnotherClient();
	short GetQuickWithDraw(int QuickWithDrawOption);
	void ManueQiuckWithDraw();
	void StartAdminManue(int Selected);
	void StartClientManue(int Selected);
	bool permissstion(int permission, int select);
	void PrintNotAccess();
	void StartMange(int Selected);
	void StarTransaction(enumOperationTransaction Choice);
	/// <summary>
	/// //end
	/// </summary>

int main()
{
	return 0;
}
void ClientManue()
{
	system("cls");
	cout <<
		"\n_______________________________________________________\n";
	cout << right << setw(10) << "[1]" << "Transaction" << endl;
	cout << right << setw(10) << "[2]" << "Logout" << endl;
	cout << right << setw(10) << "[3]" << "Exit" << endl;
	cout <<
		"\n_______________________________________________________\n";
	StartClientManue(ReadPositiveNumber(" Select Number  from Manue ?"));
}

void AdminManue()
{
	system("cls");
	cout <<
		"\n_______________________________________________________\n";
	cout << right << setw(10) << "[1]" << "Show All Clients" << endl;
	cout << right << setw(10) << "[2]" << "Add New Client" << endl;
	cout << right << setw(10) << "[3]" << "Delete Client" << endl;
	cout << right << setw(10) << "[4]" << "Update Client " << endl;
	cout << right << setw(10) << "[5]" << "Find Client" << endl;
	cout << right << setw(10) << "[6]" << "Transacton" << endl;
	cout << right << setw(10) << "[7]" << "ManageUsers" << endl;
	cout << right << setw(10) << "[8]" << "ShowAllAction" << endl;
	cout << right << setw(10) << "[9]" << "Logout" << endl;
	cout << right << setw(10) << "[10]" << "Exit" << endl;
	cout <<
		"\n_______________________________________________________\n";
	StartAdminManue(ReadPositiveNumber(" Select Number  from Manue ?"));

}

void TransactonManue() {
	system("cls");
	cout <<
		"\n_______________________________________________________\n";
	cout << right << setw(10) << "[1]" << "Deposit" << endl;
	cout << right << setw(10) << "[2]" << "withdraw" << endl;
	cout << right << setw(10) << "[3]" << "Tranfer " << endl;
	cout << right << setw(10) << "[4]" << "Total Balance " << endl;
	cout << right << setw(10) << "[5]" << "ClientManue" << endl;
	cout << right << setw(10) << "[6]" << "Quickwithdraw" << endl;
	cout << right << setw(10) << "[7]" << "CheckBalanceScreen" << endl;
	cout <<
		"\n_______________________________________________________\n";
	StarTransaction((enumOperationTransaction)ReadPositiveNumber("Choice Proccess From Manue?"));
}
void MangeUser() {
	system("cls");
	cout <<
		"\n_______________________________________________________\n";
	cout << right << setw(10) << "[1]" << "ShowAllUsers" << endl;
	cout << right << setw(10) << "[2]" << "Update" << endl;
	cout << right << setw(10) << "[3]" << "Add" << endl;
	cout << right << setw(10) << "[4]" << "Delete" << endl;
	cout << right << setw(10) << "[5]" << "GoToMane" << endl;

	cout <<
		"\n_______________________________________________________\n";
	StartMange(ReadPositiveNumber("Choice Proccess From Manue?"));
}
void Start() {
	system("cls");

	cout <<
		"\n_______________________________________________________\n";
	cout << right << setw(10) << "[1]" << "Login" << endl;
	cout << right << setw(10) << "[2]" << "SignIN" << endl;

	cout <<
		"\n_______________________________________________________\n";
	SingUsers();
}
bool SelectUserIdFromFile(int& Id)
{
	Users user;
	fstream file;
	string Line;
	file.open(UsersFileName, ios::in);
	if (file.is_open())
	{
		while (getline(file, Line))
		{
			if (Line != "") {
				user = ConvertRecordToUsersData(Line);
				if (user.ID == Id)
					return true;

			}
			else {
				cout << "Line is not found Data!!" << endl;
			}
		}

	}
	file.close();
	return false;

}
vector <Client> LoadCleintsDataFromFile(string ClientsFileName)
{
	//Client client;
	string Line = "";
	vector <Client> vClients;
	Client client;

	fstream file;
	file.open(ClientsFileName, ios::in);//read Mode
	if (file.is_open())
	{
		while (getline(file, Line))
		{
			if (Line != "") {
				client = ConvertRecordToClietData(Line);
				vClients.push_back(client);
			}
		}
	}
	file.close();

	return vClients;
}
string CurrntAccountNumber(int Id)
{
	vector<Client> vclient = LoadCleintsDataFromFile(ClientsFileName);
	for (Client& C : vclient)
	{
		if (C.ID == Id)
		{
			return C.AccountNumber;
		}
	}
}
double CurrentBalance(int Id)
{
	vector<Client> vclient = LoadCleintsDataFromFile(ClientsFileName);
	for (Client& C : vclient)
	{
		if (C.ID == Id)
		{
			return C.Balance
				;
		}
	}
}
bool QuickWithDraw()
{
	string AccountNumber = CurrntAccountNumber(CurrectUser.ID);
	vector<Client> vclient = LoadCleintsDataFromFile(ClientsFileName);
	Client client;
	Action action;
	short Select;
	short amount;
	if (FindClientByAccountNumber(AccountNumber, vclient, CurrentClient))
	{
		ManueQiuckWithDraw();
		cout << "Select From Manue :";
		cin >> Select;
		if (Select == 8)
			GoToManueTransaction();
		if (CurrentClient.Balance < 50)
		{
			cout << "Can not WithDraw With Balance less 50...";
			return false;
		}
		amount = GetQuickWithDraw(Select);
		while (ValidateAmoun(CurrentClient.Balance, (double)amount) == false)
		{
			system("pause>0");
			system("cls");
			QuickWithDraw();
		}
		DepositBalanceToClientByAccountNumber(AccountNumber, (double)amount * -1, vclient);
		CurrentClient.Balance -= amount;
		DataAction(action, CurrentClient, amount, enumOperationTransaction::Transfer);
		SaveAction(action);


	}
	return true;
}void 
ShowCheckBalanceScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tCheck Balance Screen\n";
	cout << "===========================================\n";
	cout << "Your Balance is " << CurrentClient.Balance << "\n";

}
stDate GetCurrentDate()
{
	stDate stdate;
	time_t t = time(0);
	tm now;
	localtime_s(&now, &t);
	stdate.Year = now.tm_year + 1900;
	stdate.Month = now.tm_mon + 1;
	stdate.Day = now.tm_mday;

	return stdate;

}
int ReadPositiveNumber(string message) {
	int Number;
	short isvalid = false;
	do {
		cout << message;
		cin >> Number;
		isvalid = 1;
		if (cin.fail() || Number < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a positive number." << endl;
			isvalid = 0;
		}
	} while (Number < 0 || isvalid == 0);
	return Number;
}
void Pause()
{
	cout << "\n\n\nEnter Any Key to Go Home Page?";
	system("pause>0");

}
string ReadString(string message)
{
	string str;
	cout << message << " :" << endl;
	getline(cin >> ws, str);
	return str;
}
vector<string> SplitString(string st, string delim)
{
	rsize_t pos;
	string word = "";
	vector<string> vword;
	while ((pos = st.find(delim)) != std::string::npos) {
		word = st.substr(0, pos);
		if (word != "")
		{
			vword.push_back(word);
		}
		st.erase(0, pos + delim.length());
	}
	if (st != "")
	{
		vword.push_back(st);
	}
	return vword;
}
string RoleType(Roles role)
{
	if (role == Roles::admin)
	{
		return "Admin";
	}
	else {
		return "User";
	}
}
Roles RoleType(string role)
{
	if (role == "Admin")
	{
		return Roles::admin;
	}
	else {
		return Roles::user;

	}
}
Users ConvertRecordToUsersData(string data)
{
	Users user;
	vector<string> vuser = SplitString(data);
	user.ID = stoi(vuser.at(0));
	user.AccountNumber = stoi(vuser.at(1));
	user.Name = vuser.at(2);
	user.Password = vuser.at(3);
	user.role = RoleType(vuser.at(4));
	user.storpermission = stoi(vuser.at(5));
	return user;
}
string ConvertRecordUserToLineString(Users user, string delim)
{
	string Record = "";
	Record = to_string(user.ID) + delim;
	Record = Record + to_string(user.AccountNumber) + delim;
	Record = Record + user.Name + delim;
	Record = Record + user.Password + delim;

	Record = Record + RoleType(user.role) + delim;
	Record = Record + to_string(user.storpermission);

	return  Record;

}
vector <Users> LoadUsersDataFromFile(string ClientsFileName)
{
	//Client client;
	string Line = "";
	vector <Users> vUsers;
	Users user;

	fstream file;
	file.open(ClientsFileName, ios::in);//read Mode
	if (file.is_open())
	{
		while (getline(file, Line))
		{
			if (Line != "") {
				user = ConvertRecordToUsersData(Line);
				vUsers.push_back(user);
			}
			else {
				cout << "Line is not found Data!!" << endl;
			}
		}
	}
	file.close();

	return vUsers;
}
bool IsUserIsExiting(int  AccountNumber)
{
	vector<Users> vuser = LoadUsersDataFromFile(UsersFileName);
	for (Users& user : vuser)
	{
		if (user.AccountNumber == AccountNumber)
			return true;
	}
	return false;
}
string ConvertRecordToLineString(Client client, string delim)
{
	string Record = "";
	Record = to_string(client.ID) + delim;
	Record = Record + client.AccountNumber + delim;
	Record = Record + client.pinCode + delim;
	Record = Record + client.Name + delim;
	Record = Record + client.PhoneNumber + delim;
	Record = Record + to_string(client.Balance);
	return  Record;

}
void HeaderAction(vector<Action>& vaction)
{
	cout << "\n\t\t\t\t\tAction List (" << vaction.size() << ")";
	cout << "\n___________________________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(20) << "Account Number";
	cout << "| " << left << setw(20) << "Amount";
	cout << "| " << left << setw(20) << "Operation";
	cout << "| " << left << setw(20) << "Date";
	cout <<
		"\n_______________________________________________________";
	cout << "_____________________________________________________\n" << endl;
}
string ActionClient(enumOperationTransaction op)

{
	switch (op)
	{
	case enumOperationTransaction::Depsite:return "Deposit";
		break;
	case enumOperationTransaction::Withdraw:return "Withdraw";
		break;
	case enumOperationTransaction::Transfer:return "Transfer";
		break;
		break;
	}
}
Action ConvertRecordToActionData(string data)
{
	Action action;
	vector<string> vaction = SplitString(data);
	action.AccountNumber = vaction[0];
	action.amount = stod(vaction[1]);
	action.op = vaction[2];
	action.stdate = vaction[3];
	return action;
}
string FormatDate(stDate date)
{
	return to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);
}
bool SaveAction(Action action, string delim)
{

	// get time now


	// convert in string form
	string Dataline = action.AccountNumber + delim;
	Dataline = Dataline + to_string(action.amount) + delim;
	Dataline = Dataline + action.op + delim;
	Dataline = Dataline + FormatDate(action.date);
	bool save = false;
	// Convert to local time (struct tm)

	fstream file;
	file.open(FileAction, ios::out | ios::app);
	if (file.is_open())
	{
		file << Dataline << endl;
		save = true;
	}
	file.close();
	return save;
}
vector <Action> LoadActionClientDataFromFile(string ActionFileName)
{
	//Client client;
	string Line = "";
	vector <Action> vaction;
	Action action;

	fstream file;
	file.open(ActionFileName, ios::in);//read Mode
	if (file.is_open())
	{
		while (getline(file, Line))
		{
			if (Line != "") {
				action = ConvertRecordToActionData(Line);
				vaction.push_back(action);
			}

		}
	}
	file.close();

	return vaction;
}
vector<Action> DataSearch(string AccountNumber)
{
	vector<Action> vactionData;


	vector<Action> vaction = LoadActionClientDataFromFile(FileAction);

	if (AccountNumber != "")
	{
		for (Action action : vaction)
		{
			if (action.AccountNumber == AccountNumber)
			{
				vactionData.push_back(action);
			}

		}
	}
	else {
		cout << "Account Number is not found!" << endl;
	}
	return vactionData;
}
void  showAllAction() {
	vector<Action> vactionData;


	vector<Action> vaction = LoadActionClientDataFromFile(FileAction);


	HeaderAction(vaction);

	for (Action& action : vaction)
	{


		cout << "| " << setw(20) << left << action.AccountNumber;
		cout << "| " << setw(20) << left << action.amount;
		cout << "| " << setw(20) << left << action.op;
		cout << "| " << setw(20) << left << action.stdate;
		cout << "\n";

	}
}
int convertPermissionToMark(vector<int> permission)
{
	int per = 0;
	int counter = 0;
	while (counter < permission.size())
	{
		per = (per * 10) + permission[counter];
		counter++;
	}
	return per;
}
void printUser(Users user)
{
	cout << "\n======================\n";

	cout << "\nAccountNumber :" << user.AccountNumber << endl;
	cout << "Name :" << user.Name << endl;
	cout << "Password :" << user.Password << endl;
	cout << "Permission :" << user.storpermission << endl;
	cout << "\n======================\n";

}
void HeaderUserTable(vector<Users> user)
{
	cout << "\n\t\t\t\t\tUsers List (" << user.size() << ")";
	cout <<
		"\n_________________________________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "ID";
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Name";
	cout << "| " << left << setw(40) << "Password";
	cout << "| " << left << setw(8) << "Role";
	cout << "| " << left << setw(10) << "Permission";
	cout <<
		"\n______________________________________________________________";
	cout << "_____________________________________________________\n" << endl;

}
void ShowAllUsers()
{
	vector<Users> vuser = LoadUsersDataFromFile(UsersFileName);

	HeaderUserTable(vuser);
	for (Users user : vuser)
	{
		cout << "| " << setw(15) << left << user.ID;
		cout << "| " << setw(15) << left << user.AccountNumber;
		cout << "| " << setw(10) << left << user.Name;
		cout << "| " << setw(40) << left << user.Password;
		cout << "| " << setw(10) << left << user.role;
		cout << "| " << setw(10) << left << user.storpermission;
		cout << "\n";
	}
}
Users SignIN(int role)
{
	Users users;
	char permission;
	cout << "\n======================\n";
	cout << "Add Users \n";
	cout << "\n======================\n\n";
	cout << endl;
	cout << "Enter Id User:";
	cin >> users.ID;
	cout << "Enter AccountNumber:";
	cin >> users.AccountNumber;
	while (IsUserIsExiting(users.AccountNumber))
	{
		cout << "This Accout is Exsiting...." << endl;
		users.AccountNumber = ReadPositiveNumber("Enter Another AccountNumber:");
	}
	cin >> users.Name;
	cout << "Enter Password:";
	cin >> users.Password;
	users.role = (Roles)role;

	cout << "Can You Set All Pervlige [n/y]" << endl;
	cin >> permission;
	if (permission == 'y' || permission == 'Y') {
		role = Roles::admin;
		users.Permission = { 1,2,3,4,5,6,7,8 };
	}
	else {
		cout << "Show All Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(1);
		cout << "Add New Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(2);
		cout << "Delete Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(3);
		cout << "Update Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(4);
		cout << "Search Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(5);
		cout << "Transaction Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(6);
		cout << "Manage Users [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(7);
		cout << "showAllAction  [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(8);
	}


	users.storpermission = convertPermissionToMark(users.Permission);
	return users;
}
Client ConvertRecordToClietData(string data)
{
	Client client;
	vector<string> vclient = SplitString(data);
	client.ID = stoi(vclient[0]);
	client.AccountNumber = vclient[1];
	client.pinCode = vclient[2];
	client.Name = vclient[3];
	client.PhoneNumber = vclient[4];
	client.Balance = stod(vclient[5]);
	return client;
}
bool MarkedToDeleteUse(vector<Users>& vUsers, int Number)
{
	for (Users& user : vUsers)
	{
		if (user.AccountNumber == Number)
		{
			user.MarkDeleted = true;
			return true;
		}
	}
	return false;
}
void SaveFile()
{
	vector<Users> vUsers = LoadUsersDataFromFile(UsersFileName);
	string Dataline;
	fstream file;
	file.open(UsersFileName, ios::out | ios::app);
	if (file.is_open())
	{
		for (Users user : vUsers)
		{
			Dataline = ConvertRecordUserToLineString(user);
			if (Dataline != "")
			{
				file << Dataline << endl;
			}


		}
	}
	file.close();


}
void SaveUser(vector<Users> vUsers)
{
	string Dataline;
	fstream file;
	file.open(UsersFileName, ios::out);
	if (file.is_open())
	{
		for (Users user : vUsers)
		{
			Dataline = ConvertRecordUserToLineString(user);
			if (Dataline != "" && user.MarkDeleted == false)
			{
				file << Dataline << endl;
			}


		}
	}
	file.close();

}
void AddUserToFile()
{
	string Dataline;
	fstream file;
	char answer = 'n';
	file.open(UsersFileName, ios::out | ios::app);
	if (file.is_open())
	{
		cout << "Are You Sure Sign Up   [n/y]";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Dataline = ConvertRecordUserToLineString(SignIN((Roles)ReadPositiveNumber("Select Role -> Admin:1 User:2 ?")));
			file << Dataline << endl;
			cout << "Successfuly Regisres>" << endl;

		}
	}
	file.close();

}
bool IsFindUserAccounNumber(vector<Users>& vUsers, Users& User, int Number);
bool IsFindUserAccounNumber(vector<Users>& vUsers, Users& User, int Number)
{
	for (Users& user : vUsers)
	{
		if (user.AccountNumber == Number)
		{
			User = user;
			return true;
		}
	}
	return false;
}
Users UpdateUsers(int AccountNumber, int Id)
{
	Users users;
	users.ID = Id;
	users.AccountNumber = AccountNumber;
	char permission;

	cout << "\n======================\n\n";

	cout << "Enter User Name:";
	cin >> users.Name;
	cout << "Enter Password:";
	cin >> users.Password;

	cout << "Can You Set All Pervlige [n/y]" << endl;
	cin >> permission;
	if (permission == 'y' || permission == 'Y') {
		users.role = Roles::admin;
		users.Permission = { 1,2,3,4,5,6,7,8 };
	}
	else {
		cout << "Show All Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(1);
		cout << "Add New Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(2);
		cout << "Delete Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(3);
		cout << "Update Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(4);
		cout << "Search Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(5);
		cout << "Transaction Client [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(6);
		cout << "Manage Users [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(7);
		cout << "showAllAction  [n/y]";
		cin >> permission;
		if (permission == 'y' || permission == 'Y')
			users.Permission.push_back(8);
	}


	users.storpermission = convertPermissionToMark(users.Permission);
	return users;
}
bool IsUpdate(int AccountNumber)
{
	vector<Users> vUsers = LoadUsersDataFromFile(UsersFileName);
	Users user;
	char answer = 'n';
	if (IsFindUserAccounNumber(vUsers, user, AccountNumber))
	{
		printUser(user);
		cout << "Are You Sure Update this User [n/y]";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			for (Users& vuser : vUsers)
			{
				if (vuser.AccountNumber == AccountNumber)
				{
					vuser = UpdateUsers(AccountNumber, vuser.ID);
					break;
				}
			}
		}
		SaveUser(vUsers);
		return true;
	}
	return true;
}
bool DeleteUser(int AccountNumber)
{
	vector<Users> vUsers = LoadUsersDataFromFile(UsersFileName);
	Users user;
	char answer = 'n';
	if (IsFindUserAccounNumber(vUsers, user, AccountNumber))
	{
		printUser(user);

		cout << "Are you sure you want Delete this client? y/n ? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			MarkedToDeleteUse(vUsers, AccountNumber);
			SaveUser(vUsers);
			cout << "Successfully Delete:";
			return true;
		}
	}
	else {
		cout << "\nUser with Account Number (" << AccountNumber
			<< ") is Not Found!";
	}
	return false;
}
bool Login(Roles& role, int& perm, int& ID, double& balance)
{
	string Password;
	int AccountNumber;
	bool track = false;
	char choice = 'n';
	do {
		system("cls");
		cout << "\n======================\n";
		cout << "Login \n";
		cout << "\n======================\n";
		AccountNumber = ReadPositiveNumber("Enter AccountNumber:");
		Password = ReadString("Enter Password:");
		vector<Users> vusers = LoadUsersDataFromFile(UsersFileName);
		for (Users user : vusers)
		{
			if (user.AccountNumber == AccountNumber && user.Password == Password)
			{
				role = user.role;
				perm = user.storpermission;
				ID = user.ID;
				balance = CurrentBalance(user.ID);


				cout << "Successfuly Login>" << endl;

				return true;
			}
		}
		cout << "Invalid User Or Passowrd" << endl;
		cout << "Enter any key to Try again...." << endl;
		system("pause>0");
		track = false;
	}

	while (track == false);
}
void SingUsers() {
	int select = ReadPositiveNumber("Choice Action From Manue?");
	while (select != (SignOption::login) && select != (SignOption::signin))
	{
		cout << "Choice  correct Action From Manue?" << endl;
		cin >> select;

	}
	SignOption Choice = (SignOption)select;

	Roles role;
	switch (Choice)
	{
	case SignOption::login: Login(role, CurrectUser.storpermission, CurrectUser.ID, CurrentClient.Balance);
		AdminManue();
		break;
	case SignOption::signin:  AddUserToFile();
		Pause();
		Start();
		break;
	}
}
void HeaderOperation(int choice)
{
	switch (choice) {
	case 1:cout << right << setw(70) << " | Page Show All Clients |" << "\n\n\n";
		break;
	case 2:cout << right << setw(70) << " | Page Add  Client |" << "\n\n\n";
		break;
	case 3:cout << right << setw(70) << " | Page  Update Client |" << "\n\n\n";
		break;
	case 4:cout << right << setw(70) << " | Page  Delete Client |" << "\n\n\n";
		break;
	case 5:cout << right << setw(70) << " | Page  Search  Client |" << "\n\n\n";
		break;
	case 6:cout << right << setw(70) << " | Page ShowAllAction |" << "\n\n\n";
		break;

	}
}
void HeaderTransaction(int choice)
{
	switch (choice) {
	case 1:cout << right << setw(70) << " | Deposite Page |" << "\n\n\n";
		break;
	case 2:cout << right << setw(70) << " | Withdraw Page |" << "\n\n\n";
		break;
	case 3:cout << right << setw(70) << " | Total Balance |" << "\n\n\n";
		break;

	}
}
char ReadChar(string message)
{
	char letter;
	cout << message << " :" << endl;
	cin >> letter;
	while (!(letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'));
	{
		cout << "Invalid input. Please enter a charachter letter." << endl;
		cin >> letter;

	}
	return letter;
}
void HeaderClientTable(vector<Client> client)
{
	cout << "\n\t\t\t\t\tClient List (" << client.size() << ")";
	cout <<
		"\n_________________________________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "ID";
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(8) << "Phone";
	cout << "| " << left << setw(10) << "Balance";
	cout <<
		"\n______________________________________________________________";
	cout << "_____________________________________________________\n" << endl;

}
void ShowAllClients()
{
	vector<Client> vClients = LoadCleintsDataFromFile(ClientsFileName);

	HeaderClientTable(vClients);
	for (Client client : vClients)
	{
		cout << "| " << setw(15) << left << client.ID;
		cout << "| " << setw(15) << left << client.AccountNumber;
		cout << "| " << setw(10) << left << client.pinCode;
		cout << "| " << setw(40) << left << client.Name;
		cout << "| " << setw(10) << left << client.PhoneNumber;
		cout << "| " << setw(10) << left << client.Balance;
		cout << "\n";
	}
}
void ShowBalanceClients()
{
	double Sum = 0.0;
	vector<Client> vClients = LoadCleintsDataFromFile(ClientsFileName);
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")";
	cout << "\n___________________________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(16) << "Accout Number";
	cout << "| " << left << setw(40) << "Pin Code";

	cout << "| " << left << setw(16) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_____________________________________________________\n" << endl;

	for (Client client : vClients)
	{
		cout << "| " << setw(16) << left << client.AccountNumber;
		cout << "| " << setw(40) << left << client.pinCode;
		cout << "| " << setw(16) << left << client.Balance;
		cout << "\n";
		Sum += client.Balance;
	}

	cout <<
		"\n_______________________________________________________";
	cout << "_____________________________________________________\n" << endl;
	cout << right << setw(60) << " Total BALANCE = " << Sum;
}
bool CheckCkclientIsFound(string  Number)
{
	vector<Client> vclient = LoadCleintsDataFromFile(ClientsFileName);
	for (Client& client : vclient) {
		if (client.AccountNumber == Number)
			return true;
	}
	return false;
}
bool CheckCkclientIDIsFound(int  ID)
{
	vector<Client> vclient = LoadCleintsDataFromFile(ClientsFileName);
	for (Client& client : vclient) {
		if (client.ID == ID)
			return true;
	}
	return false;
}
Client AddClient()
{
	Client client;
	cout << "Enter The ID:";
	cin >> client.ID;
	while (CheckCkclientIDIsFound(client.ID))
	{
		cout << " The ID(" << client.ID << ")is exsit in Users Table:" << endl;
		cout << "Enter Again The ID:";

		cin >> client.ID;
	}
	while (SelectUserIdFromFile(client.ID) == false)
	{
		cout << " The ID(" << client.ID << ")is Not Fount in Users Table:" << endl;
		cout << "Enter Again The ID:";

		cin >> client.ID;
	}
	
	cout << "Enter The AccountNumber:";
	cin >> client.AccountNumber;

	cout << "Enter The Pin Code:";
	getline(cin >> ws, client.pinCode);
	cout << "Enter The Name:";
	getline(cin >> ws, client.Name);
	cout << "Enter The PhoneNumber:";
	getline(cin >> ws, client.PhoneNumber);
	cout << "Enter The Balance:";
	cin >> client.Balance;
	return client;
}
Client UpdateClient(string AccountNumber, int ID)
{

	Client client;

	client.ID = ID;
	client.AccountNumber = AccountNumber;
	cout << "Enter The Pin Code:";
	getline(cin >> ws, client.pinCode);
	cout << "Enter The Name:";
	getline(cin >> ws, client.Name);
	cout << "Enter The PhoneNumber:";
	getline(cin >> ws, client.PhoneNumber);
	cout << "Enter The Balance:";
	cin >> client.Balance;
	return client;
}
void PrintClientCard(Client client)
{
	cout << "\nClient Details:\n"
		<< "----------------------------------------\n"
		<< "ID: " << client.ID << "\n"
		<< "Account Number: " << client.AccountNumber << "\n"
		<< "PIN Code:       " << client.pinCode << "\n"
		<< "Name:           " << client.Name << "\n"
		<< "Phone:          " << client.PhoneNumber << "\n"
		<< "Balance:        " << fixed << setprecision(2) << client.Balance << "\n"
		<< "----------------------------------------\n";
}
void Add()
{
	Client  client;
	char add = 'n';
	fstream file;
	do {
		client = AddClient();
		string Record = "";
		Record = ConvertRecordToLineString(client, "#//#");
		file.open(ClientsFileName, ios::out | ios::app);
		if (file.is_open())
		{
			if (Record != "") {
				file << Record << endl;
				cout << "The Client saved Succussfully!" << endl;


			}

			else
			{
				cout << "Error Saved Client!" << endl;
			}
		}
		file.close();
		cout << "Do you Add another Client ? y/n :";
		cin >> add;

	} while (add == 'y' || add == 'Y');

}
bool FindClientByAccountNumber(string AccountNumber, vector<Client> vClients, Client& client)
{
	for (Client& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			client = C;
			return true;
		}
	}
	cout << "\nClient with Account Number (" << AccountNumber
		<< ") is Not Found!";
	return false;
}
bool MarkClientToAction(string AccountNumber, vector<Client>& vclient)

{
	for (Client& C : vclient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkDeleted = true;
			return true;
		}

	}
	return false;
}
vector <Client>SaveCleintsDataToFile(string ClientsFileName, vector<Client>vClients)
{
	fstream file;
	file.open(ClientsFileName, ios::out);//overwrite
	string DataLine;
	if (file.is_open())
	{
		for (Client C : vClients)
		{
			if (C.MarkDeleted == false)
			{
				DataLine = ConvertRecordToLineString(C);
				file << DataLine << endl;
			}
		}
		file.close();
	}
	return vClients;
}
vector <Client>SaveCleintsDataToFile(string ClientsFileName, vector<Client>vClients);
bool Delete(string AccountNumber)

{
	vector<Client> vClients = LoadCleintsDataFromFile(ClientsFileName);

	char answer;

	Client client;
	if (FindClientByAccountNumber(AccountNumber, vClients, client))
	{
		PrintClientCard(client);
		cout << "Are you sure you want Delete this client? y/n ? ";

		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			MarkClientToAction(AccountNumber,
				vClients);
			SaveCleintsDataToFile(ClientsFileName, vClients);
			vClients = LoadCleintsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";

			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber
			<< ") is Not Found!";
	}
	return false;


}
bool Update(string AccountNumber)
{
	vector<Client> vClients = LoadCleintsDataFromFile(ClientsFileName);

	char answer;
	Client client;
	if (FindClientByAccountNumber(AccountNumber, vClients, client))
	{
		PrintClientCard(client);
		cout << "Are you sure you want Update this client? y/n ? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			for (Client& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = UpdateClient(AccountNumber, C.ID);
					break;
				}
			}
			SaveCleintsDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	return true;


}
bool Search(string AccountNumber)
{
	vector<Client> vClients = LoadCleintsDataFromFile(ClientsFileName);
	Client client;
	for (Client C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			client = C;
			PrintClientCard(C);
			return true;
		}
	}
	cout << "\nClient with Account Number (" << AccountNumber
		<< ") is Not Found!";
	return false;
}
void GoToManueTransaction()

{
	cout << "\n\n\nEnter Any Key to Go Home Page?";
	system("pause>0");
	TransactonManue();



}
bool ValidateAmoun(double amount, double amountentry) {
	if (amount < amountentry)
	{

		cout << "\nThe amount exceeds your balance, make another choice.\n";
		cout << "Press Anykey to continue...";
		return false;
	}
	return true;
}
double ShowAllBalance()
{
	double Sum = 0.0;
	vector<Client> vclient = LoadCleintsDataFromFile(ClientsFileName);

	for (Client& client : vclient)
	{
		Sum += client.Balance;
	}
	return Sum;
}
void DataAction(Action& action, Client client, double amount, enumOperationTransaction Operation)
{
	action.AccountNumber = client.AccountNumber;
	action.amount = amount;
	action.op = ActionClient(Operation);
	action.date = GetCurrentDate();
}
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double  Amount, vector <Client>& vClients)
{

	char Answer = 'n';

	cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{

		for (Client& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{

				C.Balance += Amount;
				SaveCleintsDataToFile(ClientsFileName, vClients);
				cout << "\n\nDone Successfully. New balance is: " << C.Balance << endl;

				return true;
			}

		}


		return false;
	}

}
void WithdrawClient(enumOperationTransaction op)
{
	Action action;
	cout << "-----------------------------------" << endl;
	cout << "Page Transaction Client" << endl;
	cout << "-------------------------------------" << endl;
	vector<Client> vclient = LoadCleintsDataFromFile(ClientsFileName);
	Client client;
	short amount;
	string AccountNumber = CurrntAccountNumber(CurrectUser.ID);
	if (op == enumOperationTransaction::Withdraw) {
		if (FindClientByAccountNumber(AccountNumber, vclient, client))
		{

			PrintClientCard(client);
			amount = ReadPositiveNumber("Enter amount to transfer :");
			while (!ValidateAmoun(client.Balance, (double)amount))
			{
				amount = ReadPositiveNumber("Enter another amount to  transfer :");

			}
			DepositBalanceToClientByAccountNumber(AccountNumber, (double)amount * -1, vclient);
			CurrentClient.Balance -= amount;
			DataAction(action, client, amount, enumOperationTransaction::Withdraw);
			SaveAction(action);


		}
	}
}
void Dobsite(enumOperationTransaction op)
{
	Action action;
	cout << "-----------------------------------" << endl;
	cout << "Dobsite Page do Client" << endl;
	cout << "-------------------------------------" << endl;
	vector<Client> vclient = LoadCleintsDataFromFile(ClientsFileName);
	Client client;
	short amount;
	string AccountNumber = CurrntAccountNumber(CurrectUser.ID);
	if (op == enumOperationTransaction::Depsite) {
		if (FindClientByAccountNumber(AccountNumber, vclient, client))
		{
			PrintClientCard(client);
			amount = ReadPositiveNumber("Enter amount to transfer :");
			DepositBalanceToClientByAccountNumber(AccountNumber, (double)amount, vclient);
			CurrentClient.Balance += amount;
			DataAction(action, client, amount, enumOperationTransaction::Depsite);
			SaveAction(action);
		}
	}

}
static void TransfertoAnotherClient()
{
	Action action;
	cout << "-----------------------------------" << endl;
	cout << "Page Trasfer To Client" << endl;
	cout << "-------------------------------------" << endl;
	vector<Client> vclient = LoadCleintsDataFromFile(ClientsFileName);
	Client client;
	short amount;
	string AccountNumber = CurrntAccountNumber(CurrectUser.ID);
	if (FindClientByAccountNumber(AccountNumber, vclient, client))
	{
		PrintClientCard(client);
		amount = ReadPositiveNumber("Enter amount to transfer :");
		while (!ValidateAmoun(client.Balance, (double)amount))
		{
			amount = ReadPositiveNumber("Enter amount to transfer :");

		}
		DepositBalanceToClientByAccountNumber(AccountNumber, (double)amount * -1, vclient);
		CurrentClient.Balance -= amount;

		DataAction(action, client, amount, enumOperationTransaction::Transfer);
		SaveAction(action);

	}

	string AccountNumber1 = ReadString("Enter AccountNumber To Transfer ");
	while (AccountNumber == AccountNumber1)
	{
		cout << "This User Is Exsiting ..." << endl;

		string AccountNumber1 = ReadString("Enter Another AccountNumber To Transfer ");

	}
	if (FindClientByAccountNumber(AccountNumber1, vclient, client))
	{
		PrintClientCard(client);

		DepositBalanceToClientByAccountNumber(AccountNumber1, (double)amount, vclient);
		DataAction(action, client, amount, enumOperationTransaction::Transfer);
		SaveAction(action);
	}
}
short GetQuickWithDraw(int QuickWithDrawOption)
{
	switch (QuickWithDrawOption)
	{
	case 1: return 50;
		break;
	case 2: return 100;
		break;
	case 3: return 200;
		break;
	case 4: return 400;
		break;
	case 5: return 600;
		break;
	case 6: return 800;
		break;
	case 7: return 100;
		break;
	default: return 0;
		break;
	}
}
void ManueQiuckWithDraw()
{
	cout << "===========================================\n";
	cout << "\t1- 50\t\t 2- 100\n";
	cout << "\t3- 200\t\t 4- 400\n";
	cout << "\t5- 600\t\t 6- 800\n";
	cout << "\t7- 100\t\t 8- back\n";
	cout << "===========================================\n";
	cout << "Your Balance is " << CurrentClient.Balance << endl;
	cout << "===========================================\n";

}
void StarTransaction(enumOperationTransaction Choice)
{

	system("cls");
	HeaderTransaction(Choice);



	switch (Choice)
	{
	case enumOperationTransaction::Depsite:
		system("cls");
		Dobsite(Choice);
		GoToManueTransaction();



		break;
	case enumOperationTransaction::Withdraw:
		system("cls");

		WithdrawClient(Choice);
		GoToManueTransaction();

		break;

	case  enumOperationTransaction::TotalBalance:
		system("cls");

		ShowBalanceClients();
		GoToManueTransaction();
		break;
	case  enumOperationTransaction::Transfer:
		system("cls");
		TransfertoAnotherClient();
		GoToManueTransaction();
		break;
	case  enumOperationTransaction::GoBack:
		AdminManue();
		break;
	case  enumOperationTransaction::QiukWithDraw:
		QuickWithDraw();
		GoToManueTransaction();

		break;
	case  enumOperationTransaction::ShowCheckBalance:
		ShowCheckBalanceScreen();
		GoToManueTransaction();

		break;
	default:
		system("cls");

		AdminManue();
	}
}
void StartClientManue(int Selected)
{
	system("cls");


	string ReadAccountNumber;

	switch (Selected)
	{
	case 1: TransactonManue();
		Pause();
		system("cls");
		ClientManue();
		break;

	case 2:
		system("cls");
		Start();
		break;
	case 3:
		system("cls");
		cout << "Thank you for using the Bank System. Goodbye!" << endl;
		exit(0);

		break;
	}
}
bool permissstion(int permission, int select)
{
	int allper[8];
	int index = 0;

	int Remainder = 0;
	while (permission > 0) {


		Remainder = permission % 10;
		permission = permission / 10;
		allper[index] = Remainder;
		if (select == allper[index])
			return true;

		index++;

	}
	return false;



}
void PrintNotAccess()
{
	cout << "\n Not Access To this page\n you must Call Admin\n";
}
void StartMange(int Selected) {
	system("cls");

	int ReadAccountNumber;


	HeaderOperation(Selected);


	switch (Selected)
	{
	case 1: ShowAllUsers();
		Pause();
		system("cls");
		MangeUser();
		break;
	case 2: IsUpdate(ReadAccountNumber = ReadPositiveNumber("Enter The Account Number:"));
		Pause();
		system("cls");
		MangeUser();
		break;
	case 3:
		AddUserToFile();
		Pause();
		system("cls");
		MangeUser();
		break;

	case 4:DeleteUser(ReadAccountNumber = ReadPositiveNumber("Enter The Account Number:"));
		Pause();
		system("cls");
		MangeUser();


	default:
		AdminManue();
	}
}
void StartAdminManue(int Selected)
{
	system("cls");


	string ReadAccountNumber;
	if (permissstion(CurrectUser.storpermission, Selected))
	{
		HeaderOperation(Selected);


		switch (Selected)
		{
		case 1: ShowAllClients();
			Pause();
			system("cls");
			AdminManue();
			break;
		case 2: Add();
			Pause();
			system("cls");
			AdminManue();
			break;
		case 3: Delete(ReadAccountNumber = ReadString("Enter The Account Number:"));
			Pause();
			system("cls");
			AdminManue();

			break;
		case 4: Update(ReadAccountNumber = ReadString("Enter The Account Number:"));
			Pause();
			system("cls");
			AdminManue();

			break;


		case 5: Search(ReadAccountNumber = ReadString("Enter The Account Number:"));
			Pause();
			system("cls");
			AdminManue();

			break;

		case 6:
			TransactonManue();
			Pause();
			system("cls");
			AdminManue();
			break;
		case 7:
			MangeUser();
			Pause();
			AdminManue();
			break;
		case 8:
			showAllAction();
			Pause();
			system("cls");
			AdminManue();
			break;

		}
	}
	else {
		if (Selected > 0 && Selected < 9)
		{
			PrintNotAccess();

			Pause();
		}
	}

	switch (Selected)
	{
	case 9:
		system("cls");
		Start();
		break;
	case 10:
		system("cls");
		cout << "Thank you for using the Bank System. Goodbye!" << endl;
		exit(0);

		break;

	default:
		system("cls");
		AdminManue();
	}

}
};