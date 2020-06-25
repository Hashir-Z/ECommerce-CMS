/*
Name: Hashir Bin Zahid
Degree: BSCS
Roll Num: 005
Fa-2019/BSCS/005
*/

// To use Strcpy function
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>		// Used For I/O
#include <Windows.h>	// Used For Sleep()
#include <iomanip>		// Used For Setw()
#include <fstream>		// Used For File Handling

using namespace std;

// -------------------
// Functions
// -------------------

void WelcomeScreen();
void UserMainMenu();
void BuyItem();
void DisplayData(int index, bool ShouldRun);
void ReBuyItem(int index);
void TotalBill(int *arr, bool Checkout);

// -------------------
// Employee Functions
// -------------------

void Employee_L_S();
void Login();
void SignUp();
void EmployeeMainMenu();
void GroceryDetail();
void DisplayDataCompany(int index, bool run);
void SearchMenu(bool isEmployee);
void AdvancedAnalytics();
void ProfitableItems(bool isStockList, bool isAvg);
void EditItemDetails();
void RevenueReport();

// -------------------
// Find Data
// -------------------

int Find(int input, int *data, bool isEmployee, bool Run, int shown, int Runs);
void Find(char *name, bool isEmployee);
int sort(int *arr, int size);

// -------------------
// File Handling Functions
// -------------------

void SaveCompanyData();
void LoadCompanyData();
void SaveBill();
void ShowBill();
void SaveEmployeeData();
void LoadEmployeeData();

// -------------------
// FUNCTION DECLARATION END
// -------------------

// -------------------
// STRUCTS
// -------------------

struct Product
{
	int ProdID;
	int ProdQty; 
	int ProdPrice;
	char ProdName[30];
	char ProdDescription[120];
}Prod[10];

struct Customer
{
	int ItemsQtyInCart[10];
}CustDetail[100];

struct CompanyData
{
	int OriginalProdQty;
	int ProdBuyPrice;
	int TotSold;
}CompData[10];

struct EmployeeLogin
{
	char Username[100];
	char Password[100];
}EmpLog[100];

// Struct Pointers

int *PtrProd[10];
int *PtrCompData[10];

// INT Variable: DIDN'T USE IN STRUCTS BECAUSE THEY DON'T NEED TO BE DIFFERENT FOR EVERY USER!

int TotUsers = 0;					// Used For Keeping Count Of Total Users In One Run
int done[10] = { -1 };				// Used For Sorting
int counter = 0;					// Used For Getting Total Number Of Employees
int TmpTotPurchased[10] = { 0 };	// Temporarily Stores Customer Order Details

// ======================================
// ---- USE THIS KEY FOR SIGNING UP! ----
// ======================================

char MasterKey[100] = { "12345" };

// =====================================
// ---------------- END ----------------
// =====================================


// -------------------
// PROGRAMS START HERE
// -------------------

int main()
{
	
	//Initialize Pointers To Point At Address of 1st Variable of Struct Objects
	for (int i = 0; i < 10; i++)
	{
		PtrProd[i] = &Prod[i].ProdID;
		PtrCompData[i] = &CompData[i].OriginalProdQty;
	}

	LoadCompanyData();
	LoadEmployeeData();

	WelcomeScreen();

	// Save All Data
	SaveCompanyData();

	return 0;
}

// -------------------
// User/Customer Functions
// -------------------

void WelcomeScreen()
{
	int run = 1, choice = 0;
	do
	{
		system("Color 4");
		cout << "---------------- WELCOME ---------------- " << endl << endl;
		cout << "Press (1) If You're A Customer" << endl;
		cout << "Press (2) If You're A Employee" << endl;
		cout << "Press (3) To Exit" << endl;
		cout << "\nPlease Enter Your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			system("CLS");
			run = 0;
			UserMainMenu();
			break;
		}
		case 2:
		{
			system("CLS");
			run = 0;
			Employee_L_S();
			break;
		}
		case 3:
		{
			system("CLS");
			run = 0;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\------------- PROGRAM MADE BY HASHIR ZAHID ------------- " << endl << endl;
			Sleep(1500);
			break;
		}
		default:
		{
			cout << "Please Enter Valid Choice!" << endl << endl;
			run = 1;
			system("pause");
			system("CLS");
		}
		}
	} while (run);
}

void UserMainMenu()
{
	bool run = 1;
	int choice = 0;
	do
	{
		system("Color C");
		cout << "---------------- MENU SELECTION ---------------- " << endl << endl;
		cout << "Press (1) to Buy item" << endl;
		cout << "Press (2) to Search Items" << endl;
		cout << "Press (3) to Check Cart Details" << endl;
		cout << "Press (4) to Checkout" << endl;
		cout << "Press (5) to Exit Without Buying" << endl;
		cout << "\nPlease Enter Your Choice: ";

		fflush(stdin);	// Used To Clear Input Buffer
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			// -------------------------------------
			// BUY ITEM
			// -------------------------------------
			system("CLS");

			// Call Function to Input Data
			BuyItem();

			system("CLS");
			break;
		}
		case 2:
		{
			// -------------------------------------
			// SEARCH ITEM
			// -------------------------------------

			system("CLS");
			system("Color 3");

			SearchMenu(0);

			break;
		}
		case 3:
		{

			// -------------------------------------
			// CHECK GROCERY DETAIL
			// -------------------------------------

			Sleep(300);
			system("CLS");
			system("Color 3");

			GroceryDetail();

			break;
		}
		case 4:
		{
			// -------------------------------------
			// SHOW TOTAL BILL & EXIT
			// -------------------------------------

			cout << "---------------- THANK YOU ---------------- " << endl << endl;
			TotalBill(&CustDetail[TotUsers].ItemsQtyInCart[0], 1);
			cout << "Thank You For Shopping, Have a Good Day!" << endl << endl;
			system("pause");
			system("CLS");
			run = 0;
			TotUsers++;
			WelcomeScreen();
			break;
		}
		case 5:
		{
			// -------------------------------------
			// EXIT WITHOUT BUYING
			// -------------------------------------
			for (int i = 0; i < 10; i++)
			{
				CompData[i].TotSold -= CustDetail[TotUsers].ItemsQtyInCart[i];
				Prod[i].ProdQty += CustDetail[TotUsers].ItemsQtyInCart[i];
				TmpTotPurchased[i] = 0;
			}
			run = 0;
			system("CLS");
			WelcomeScreen();
			break;
		}
		default:
		{
			// -------------------------------------
			// INVALID CHOICE
			// -------------------------------------

			cout << "Please Enter Valid Choice!\n\n";
			system("pause");
			system("CLS");
		}
		}
	} while (run == 1);
}

void BuyItem()
{
	bool run = 0;
	char choice = '\0';
	int ItemID = 0, ItemIndex = 0, i = 0;
	cout << "---------------- BUY MENU ---------------- " << endl << endl;

	// Display Details Of All Available Items
	for (int i = 0; i < 10; i++)
	{
		system("Color 6");
		Sleep(250);

		if (TmpTotPurchased[i] > 0 || CustDetail[TotUsers].ItemsQtyInCart[i] > 0)			// If item is already in cart
		{
			cout << "(Item In Cart)" << endl;
		}
		cout << "Product Name: " << Prod[i].ProdName << endl;
		cout << "Product ID: " << Prod[i].ProdID << endl;
		cout << "Available Quantity: " << Prod[i].ProdQty << endl;
		cout << "Product Price: RS " << Prod[i].ProdPrice << endl;
		cout << "Product Description: " << Prod[i].ProdDescription << endl << endl;
	}	// Didn't use DisplayData() function because I wanted data to appear in one go rather than waiting for user input

	// Ask User For Product ID
	do
	{
		cout << "Enter ID Of Item You Want To Buy: ";
		cin >> ItemID;
		i = 0;

		// Search entered ID & store its index if found
		do
		{
			if (ItemID == Prod[i].ProdID)
			{
				ItemIndex = i;

				// Check If The Item Is In Cart
				if (CustDetail[TotUsers].ItemsQtyInCart[ItemIndex] > 0)
				{
					ReBuyItem(ItemIndex);
					return;
				}

				// If Product Is Out Of Stock
				if (Prod[ItemIndex].ProdQty == 0)
				{
					cout << "Sorry Item Is Out Of Stock, Please Try Again" << endl << endl;
					break;
				}

				// If None Of The Previous Checks Have Been Triggered, Entered ID is Correct + Limit Not Exceed, Add Item To Cart 
				else
				{
					run = 1;		// Item found, break out of loop
					ItemIndex = i;	// Store at which index Product ID was found
					break;
				}  
			}

			i++;

			// If [i] has been run to 10 iterations, that means no ID match found
			if (i == 10)
			{
				cout << "No Product Of Specified ID Found! Please Try Again" << endl << endl;
			}

		} while (i < 10);

	} while (!run);

	run = 0;

	// Ask User For Quantity
	do
	{
		cout << "Enter Quantity Of Item You Want To Buy: ";
		cin >> TmpTotPurchased[ItemIndex];

		// If entered amount greater than available amount
		if (TmpTotPurchased[ItemIndex] > Prod[ItemIndex].ProdQty)
		{
			cout << "Sorry We Don't Have That Much. Enter Again" << endl << endl;
			run = 1;
		}

		// Ensure User Has Not Bought More Than 10 Items 
		else if (TmpTotPurchased[ItemIndex] > 10)
		{
			cout << "Sorry, Maximum Amount You Can Buy Is 10" << endl << endl;
			run = 1;
		}
		else if (CustDetail[TotUsers].ItemsQtyInCart[ItemIndex] + TmpTotPurchased[ItemIndex] > 10)
		{
			cout << "Sorry, Maximum Amount You Can Buy Is 10. You Already Have " << CustDetail[TotUsers].ItemsQtyInCart[ItemIndex] << " Item(s) In Your Cart" << endl << endl;
		}
		else
		{
			run = 0;
		}

	} while (run);

	// Ask If User Wants To Buy More
	do
	{
		cout << "Do You Want To Buy More (Y/N): ";
		cin >> choice;

		// Make Uppercase
		choice = toupper(choice);

		// Switch On User Choice
		if (choice == 'Y')
		{
			system("CLS");
			BuyItem();
			return;
		}
		else if (choice == 'N')
		{
			TotalBill(TmpTotPurchased, 0);
			run = 0;
		}
		else
		{
			cout << "Invalid Choice!" << endl << endl;
			run = 1;
		}
	} while (run);

}

void DisplayData(int index, bool ShouldRun)
{
	system("Color 3");
	cout << "Product Name: " << Prod[index].ProdName << endl;
	cout << "Product ID: " << Prod[index].ProdID << endl;
	cout << "Available Quantity: " << Prod[index].ProdQty << endl;
	cout << "Quantity In Your Cart: " << CustDetail[TotUsers].ItemsQtyInCart[index] << endl;
	cout << "Product Price: " << Prod[index].ProdPrice << endl;
	cout << "Product Description: " << Prod[index].ProdDescription << endl << endl;
	if (ShouldRun)
	{
		system("pause");
		system("CLS");
	}
}

void ReBuyItem(int index)
{
	bool run = 0;
	char choice = '\0';
	cout << "Item Is Already In Your Cart, Would You Like To Edit Its Quantity (Y/N): ";
	cin >> choice;

	// Make Uppercase
	choice = toupper(choice);
	do
	{
		switch (choice)
		{
		case 'Y':
		{
			// Remove Existing Items From Cart & Update Available Quantity
			Prod[index].ProdQty += CustDetail[TotUsers].ItemsQtyInCart[index];
			CompData[index].TotSold -= CustDetail[TotUsers].ItemsQtyInCart[index];

			// Ask User For Quantity
			do
			{
				cout << "Enter Quantity Of Item You Want To Buy: ";
				cin >> TmpTotPurchased[index];

				// If entered amount greater than available amount
				if (TmpTotPurchased[index] > Prod[index].ProdQty)
				{
					cout << "Sorry, Maximum Quantity Available: " << Prod[index].ProdQty << endl << endl;
					run = 1;
				}
				else if (TmpTotPurchased[index] > 10)
				{
					cout << "Sorry, Maximum Amount You Can Buy Is 10" << endl << endl;
					run = 1;
				}
				else
				{
					// Update Values & Break Out Of Loop
					CustDetail[TotUsers].ItemsQtyInCart[index] = TmpTotPurchased[index];
					Prod[index].ProdQty -= CustDetail[TotUsers].ItemsQtyInCart[index];
					CompData[index].TotSold += CustDetail[TotUsers].ItemsQtyInCart[index];
					run = 0;
				}
			} while (run);

			// Ask If User Wants To Buy More
			do
			{
				cout << "Do You Want To Buy More (Y/N): ";
				cin >> choice;

				// Make Uppercase
				choice = toupper(choice);

				// Switch On User Choice
				if (choice == 'Y')
				{
					system("CLS");
					BuyItem();
					return;
				}
				else if (choice == 'N')
				{
					TotalBill(TmpTotPurchased, 0);
					return;
				}
				else
				{
					cout << "Invalid Choice!" << endl << endl;
					run = 1;
				}
			} while (run);

			return;
		}
		case 'N':
		{
			BuyItem();
			return;
		}
		default:
		{
			cout << "Please Enter Valid Choice!" << endl << endl;
			run = 1;
			break;
		}
		}
	} while (run);
}

void TotalBill(int *arr, bool Checkout)
{
	bool run = 0;
	int SumTotal = 0;
	char choice = '\0';

	system("CLS");
	system("Color 9");

	cout << "---------------- TOTAL BILL ---------------- " << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > 0)
		{
			cout << "Product Name: " << Prod[i].ProdName << endl;
			cout << "Product ID: " << Prod[i].ProdID << endl;
			cout << "Product Price: " << Prod[i].ProdPrice << endl;
			cout << "Total Quantity In Your Cart: " << arr[i] << endl;
			cout << "Price Of Item(s) In Your Cart: RS " << Prod[i].ProdPrice * arr[i] << endl << endl;
			SumTotal += (Prod[i].ProdPrice * arr[i]);
		}
	}
	cout << "Total Price: RS " << SumTotal << endl;

	do
	{
		if (!Checkout)
		{
			cout << "Are You Sure You Want To Add To Cart (Y/N): ";
			cin >> choice;
		}
		else
		{
			cout << "Are You Sure You Want To Buy & Checkout (Y/N): ";
			cin >> choice;
		}
		// Make Uppercase
		choice = toupper(choice);

		switch (choice)
		{
		case 'Y':
		{

			// Update & Reset Data By Subtracting Buy Amounts Of All Items In Cart
			for (int i = 0; i < 10; i++)
			{
				Prod[i].ProdQty -= TmpTotPurchased[i];
				if (Prod[i].ProdQty < 0)
				{
					TmpTotPurchased[i] = TmpTotPurchased[i] + (Prod[i].ProdQty - TmpTotPurchased[i]);
					Prod[i].ProdQty = 0;
				}
				CompData[i].TotSold += TmpTotPurchased[i];
				CustDetail[TotUsers].ItemsQtyInCart[i] += TmpTotPurchased[i];
			}
			if (!Checkout)
			{
				cout << "Item(s) Added To Your Cart!" << endl << endl;
			}
			else
			{
				SaveBill();
				SaveCompanyData();
				// User Now Leaving, Reset Everything
				for (int i = 0; i < 10; i++)
				{
					TmpTotPurchased[i] = 0;
				}
				return;
			}
			run = 0;
			break;
		}
		case 'N':
		{
			run = 0;
			if (Checkout)
			{
				system("CLS");
				UserMainMenu();
			}
			break;
		}
		default:
		{
			cout << "Please Enter Valid Choice!" << endl << endl;
			run = 1;
			break;
		}
		}
	} while (run);

	// Reset Temp Variable
	for (int i = 0; i < 10; i++)
	{
		TmpTotPurchased[i] = 0;
	}

	system("pause");
	system("CLS");
}

// -------------------
// Employee Functions
// -------------------

void Employee_L_S()
{
	bool run = 1;
	int choice = 0;

	do
	{
		cout << "---------------- EMPLOYEE ACCESS ---------------- " << endl << endl;
		cout << "Press (1) to Login" << endl;
		cout << "Press (2) to Sign Up" << endl << endl;
		cout << "Please Enter Your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			system("CLS");
			run = 0;
			fflush(stdin);
			cin.ignore();
			Login();
			system("CLS");
			break;
		}

		case 2:
		{
			system("CLS");
			run = 0;
			SignUp();
			system("CLS");
			break;
		}
		default:
		{
			cout << endl << "Please Enter Valid Choice!" << endl << endl;
			run = 1;
			system("pause");
			system("CLS");
			break;
		}
		}
	} while (run);

	EmployeeMainMenu();
	return;
}

void Login()
{
	system("Color 2");

	char choice = '\0';
	char Username_T[100] = { "\0" }, Password_T[100] = { "\0" };
	bool run = 0;
	do
	{
		cout << "---------------- LOGIN ---------------- " << endl << endl;

		cout << "Username: ";
		cin.getline(Username_T, 100);

		// Make Username lowercase since it isn't case sensitive
		for (int i = 0; i < 100 && Username_T[i] != '\0'; i++)
		{
			Username_T[i] = tolower(Username_T[i]);
		}

		cout << "Password: ";
		cin.getline(Password_T, 100);

		// Search All Indexes Of Stored Usernames/Passwords To See If Match Was Found
		for (int i = 0; i < counter; i++)
		{
			// If Record Found, Go Back To Employee_L_S() Function & Continue Executing Its Code, We Can Call Function Here Directly But It Will Cause This Function To Take Up Space In Memory
			if (!strcmp(Password_T, EmpLog[i].Password) && !strcmp(Username_T, EmpLog[i].Username))
			{
				cout << endl << "Login Successful!" << endl << endl;
				system("pause");
				system("CLS");
				return;
			}
		}

		cout << endl << "Invalid Username Or Password!" << endl;

		do
		{
			// If Match Has Not Been Found, User Entered Wrong Details
			cout << "Would You Like To Try Again (Y/N): ";
			fflush(stdin);
			cin >> choice;

			// Make Uppercase
			choice = toupper(choice);

			switch (choice)
			{
			case 'Y':
			{
				system("CLS");
				run = 0;
				fflush(stdin);
				cin.ignore();
				break;
			}
			case 'N':
			{
				system("CLS");
				WelcomeScreen();
				return;
			}
			default:
			{
				cout << endl << "Please Enter Valid Choice!" << endl;
				run = 1;
				break;
			}
			}
		} while (run);

	} while (true);
}

void SignUp()
{
	system("Color A");

	char TmpMasterKey[100] = { '\0' };

	do
	{
		cout << "---------------- SIGN UP ---------------- " << endl << endl;

		// Made this check so that customer won't be able to sign up as employee and gain access to confidential data
		cout << "Please Enter The Master Key Password (Given By Employer) To Create Account: ";
		cin >> TmpMasterKey;

		if (strcmp(TmpMasterKey, MasterKey))
		{
			cout << endl << "Entered Key Is Invalid, Please Try Again" << endl << endl;
			system("pause");
			system("CLS");
			continue;
		}

		cout << endl << "Success! Please Fill Out The Form Below" << endl << endl;
		break;

	} while (true);

	cout << "Enter Username: ";
	fflush(stdin);
	cin.ignore();
	cin.getline(EmpLog[counter].Username, 100);

	// Make Username lowercase
	for (int i = 0; i < 100 && EmpLog[i].Username != '\0'; i++)
	{
		EmpLog[counter].Username[i] = tolower(EmpLog[counter].Username[i]);
	}

	cout << "Enter Password: ";
	cin.getline(EmpLog[counter].Password, 100);

	SaveEmployeeData();

	counter++;

	cout << endl << "Account Succesfully Created!" << endl << "Please Login To Continue..." << endl << endl;
	system("pause");
	system("CLS");
	Login();
}

void EmployeeMainMenu()
{
	system("Color C");

	bool run = 1;
	int choice = 0;
	do
	{
		system("Color C");
		cout << "---------------- MENU SELECTION ---------------- " << endl << endl;
		cout << "Press (1) to Search Item" << endl;
		cout << "Press (2) to See All Sold Items" << endl;
		cout << "Press (3) to See All Sold Items (In Date Range)" << endl;
		cout << "Press (4) to Edit Product Properties" << endl;
		cout << "Press (5) to Enter Advanced Analytics" << endl;
		cout << "Press (6) to Return To Welcome Screen" << endl;
		cout << "\nPlease Enter Your Choice: ";

		fflush(stdin);	// Used To Clear Input Buffer
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			// -------------------------------------
			// SEARCH ITEM
			// -------------------------------------

			system("CLS");
			system("Color 3");

			SearchMenu(1);

			break;
		}
		case 2:
		{

			// -------------------------------------
			// CHECK ALL SOLD ITEMS
			// -------------------------------------

			Sleep(300);
			system("CLS");
			system("Color 3");

			ShowBill();

			break;
		}
		case 3:
		{

			// -------------------------------------
			// CHECK ALL SOLD ITEMS (GIVEN DATE RANGE)
			// -------------------------------------

			Sleep(300);
			system("CLS");
			system("Color 3");

			RevenueReport();

			break;
		}
		case 4:
		{
			// -------------------------------------
			// UPDATE PRODUCT PROPERTIES
			// -------------------------------------

			system("CLS");

			EditItemDetails();

			break;
		}
		case 5:
		{
			// -------------------------------------
			// ADVANCED ANALYTICS
			// -------------------------------------

			system("CLS");

			AdvancedAnalytics();

			break;
		}
		case 6:
		{
			// -------------------------------------
			// EXIT TO WELCOME SCREEN
			// -------------------------------------

			run = 0;
			system("CLS");
			WelcomeScreen();
			break;
		}
		default:
		{
			// -------------------------------------
			// INVALID CHOICE
			// -------------------------------------

			cout << "Please Enter Valid Choice!\n\n";
			system("pause");
			system("CLS");
		}
		}
	} while (run);
}

void GroceryDetail()
{
	system("CLS");

	bool run = 0;
	int index = -1, TotalProfit = 0, SumTotal = 0, shown = 1;
	char choice = '\0';

	// Reset Done Index (For Sorting)
	for (int i = 0; i < 10; i++)
	{
		done[i] = -1;
	}

	cout << "-------------- CART DETAILS --------------" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		index = sort(CustDetail[TotUsers].ItemsQtyInCart, 1);
		if (index != -1)
		{
			cout << "---------------- Record " << shown << " ----------------" << endl << endl;
			DisplayData(index, 0);
			SumTotal += (Prod[index].ProdPrice * CustDetail[TotUsers].ItemsQtyInCart[index]);
			shown++;
		}
	}

	cout << "---------------- Reched End Of Record After " << shown - 1 << " Results ----------------" << endl << endl;
	do
	{
		cout << "Are You Done (Y/N): ";
		cin >> choice;

		// Make Uppercase
		choice = toupper(choice);

		switch (choice)
		{
		case 'Y':
		{
			cout << endl;
			run = 0;
			system("CLS");
			break;
		}
		case 'N':
		{
			cout << endl;
			run = 1;
			break;
		}
		default:
		{
			cout << "Please Enter Valid Choice!" << endl << endl;
			run = 1;
			break;
		}
		}
	} while (run);
}
  
void DisplayDataCompany(int index, bool run)
{
	system("Color 3");
	cout << "Product Name: " << Prod[index].ProdName << endl;
	cout << "Product ID: " << Prod[index].ProdID << endl << endl;
	cout << "Total Quantity: " << CompData[index].OriginalProdQty << endl;
	cout << "Available Quantity: " << Prod[index].ProdQty << endl;
	cout << "Total Sold: " << CompData[index].TotSold << endl << endl;
	cout << "Product Price: " << Prod[index].ProdPrice << endl;
	cout << "Product Buy Price: " << CompData[index].ProdBuyPrice << endl;
	cout << "Profit Per Item: " << Prod[index].ProdPrice - CompData[index].ProdBuyPrice << endl;
	cout << "Gross Earnings: " << Prod[index].ProdPrice * CompData[index].TotSold << endl;
	cout << "Profit: " << (Prod[index].ProdPrice - CompData[index].ProdBuyPrice) * CompData[index].TotSold << endl << endl;
	if (run)
	{
		system("pause");
		system("CLS");
	}
}

void AdvancedAnalytics()
{
	system("Color F");

	bool run = 1;
	int choice = 0;
	do
	{
		system("Color C");
		cout << "---------------- MENU SELECTION ---------------- " << endl << endl;
		cout << "Press (1) to Display List Of Most Profitable Items (Descending Order)" << endl;
		cout << "Press (2) to Display List Of Items Low On Stock" << endl;
		cout << "Press (3) to Display Average Sale Amount Of Items" << endl;
		cout << "Press (4) to Return To Main Menu" << endl;
		cout << "\nPlease Enter Your Choice: ";

		fflush(stdin);	// Used To Clear Input Buffer
		cin >> choice;

		switch (choice)
		{
		case 1:
		{

			// -------------------------------------
			// MOST PROFITABLE ITEMS
			// -------------------------------------

			Sleep(300);
			system("CLS");

			ProfitableItems(0, 0);

			break;
		}
		case 2:
		{
			// -------------------------------------
			// ITEMS LOW ON STOCK
			// -------------------------------------

			system("CLS");

			ProfitableItems(1, 0);

			break;
		}
		case 3:
		{
			// -------------------------------------
			// AVERAGE SALE AMOUNT
			// -------------------------------------

			system("CLS");
			ProfitableItems(0, 1);
			break;
		}
		case 4:
		{
			// -------------------------------------
			// EXIT TO WELCOME SCREEN
			// -------------------------------------

			run = 0;
			system("CLS");
			break;
		}
		default:
		{
			// -------------------------------------
			// INVALID CHOICE
			// -------------------------------------

			cout << "Please Enter Valid Choice!\n\n";
			system("pause");
			system("CLS");
		}
		}
	} while (run == 1);
}

void ProfitableItems(bool isStockList, bool isAvg)
{
	system("Color 3");

	bool run = 1;
	int ProfitData[2] = { -9999999 }, shown = 1, index = 0;
	int LowToHigh[10] = { 0 };
	char choice = '\0';

	// Reset Done Index (For Sorting)
	for (int i = 0; i < 10; i++)
	{
		done[i] = -1;
	}

	{
		if (isStockList)
		{
			cout << "--------------- STOCK LIST --------------" << endl << endl;
		}
		else if (isAvg)
		{
			cout << "---------- AVERAGE AMOUNT BOUGHT ----------" << endl << endl;
		}
		else
		{
			cout << "--------------- PROFIT LIST --------------" << endl << endl;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (isStockList)
		{
			int *ptr = *PtrProd + 1;

			// PtrProd[0] stores the address of 1st variable (ProdID) in the struct called "Product". 
			// The pointer (ptr) will point to the location that (PtrProd) points to, which is the first variable of the struct called (ProdID).
			// ptr -> PtrProd[i] -> &(*Prod[i].ProdID) -> *(&Prod[i].ProdID) -> ProdID
			// ptr -> PtrProd[i] -> Address Of Pointer (Prod[i].ProdID) -> Which Stores The Address Of (Prod[i].ProdID) -> Which Points To ProdID
			// So I added 1 to the value stored in the pointer (PtrProd), to move to the next address which stores the address ProdQty essentially navigating to the next variable of the struct
			// ptr -> (PtrProd[i]) + 1 -> [&(*Prod[i].ProdID)] + 1 -> *[(&Prod[i].ProdID) + 1] -> ProdQty
			// ptr -> (PtrProd[i]) + 1 -> [Address Of Pointer (Prod[i].ProdID)] + 1 -> Which Stores The Address Of [(Prod[i].ProdID) + 1] -> Which Points To ProdQty
			// Graphical Representation of it shown here: https://raw.githubusercontent.com/Icedwhisper/ECommerce-CMS/master/Explaination.jpg

			LowToHigh[i] = sort(ptr, (sizeof(Prod[0])/4));	// (Size of struct) / (4) [4, because it's an INT pointer and hence moves 4 address spaces when adding 1 to it.
			if (i == 9)
			{
				for (int i = 9; i >= 0; i--)				// Print In Reverse Order
				{
					if (LowToHigh[i] >= 0 && LowToHigh[i] <= 9)
					{
						cout << "---------------- Record " << shown << " ----------------" << endl << endl;
						DisplayDataCompany(LowToHigh[i], 0);
						shown++;
					}
				}
			}
		}
		else if (isAvg)
		{
			if (!TotUsers)
			{
				cout << "No User Has Bought From You Yet!" << endl << endl;
				system("pause");
				system("CLS");
				return;
			}
			int *ptr = *PtrCompData + 2;
			index = sort(ptr, sizeof(CompData[0])/3);

			// Show Only Products That Have Actually Been Bought
			if (!(CompData[index].OriginalProdQty == Prod[index].ProdQty) && index != -1)
			{
				cout << "---------------- Record " << shown << " ----------------" << endl << endl;
				DisplayDataCompany(index, 0);
				cout << "Average Quantity Bought: " << (CompData[index].OriginalProdQty - Prod[index].ProdQty) / (TotUsers + 1.0 - 1.0) << endl;
				cout << "Expected Number Of Days Stock Will Last: " << Prod[index].ProdQty / ((CompData[index].OriginalProdQty - Prod[index].ProdQty) / (TotUsers + 1.0 - 1.0)) << endl << endl;
				shown++;
			}
		}
		else
		{
			ProfitData[0] = -9999999;
			sort(ProfitData, 1);
			if (ProfitData[0] != -1)
			{
				cout << "---------------- Record " << shown << " ----------------" << endl << endl;
				DisplayDataCompany(ProfitData[0], 0);
				shown++;
			}
		}
	}

	do
	{
		cout << "Are You Done (Y/N): ";
		cin >> choice;

		// Make Uppercase
		choice = toupper(choice);

		// Switch On User Choice
		if (choice == 'Y')
		{
			system("CLS");
			run = 0;
		}
		else if (choice == 'N')
		{
			// Dont need to do anything
		}
		else
		{
			cout << "Invalid Choice!" << endl << endl;
			run = 1;
		}
		fflush(stdin);
		cin.ignore();
	} while (run);
}

void EditItemDetails()
{
	system("Color 3");
	int ItemID = 0, ItemIndex = 0, i = 0, choice = 0;
	bool run = 1;

	cout << "---------------- EDIT ITEM DETAILS ---------------- " << endl << endl;

	do
	{
		cout << "Enter ID Of Product To Change It's Properties: ";
		cin >> ItemID;

		for (i = 0; i < 10; i++)
		{
			if (ItemID == Prod[i].ProdID)
			{
				ItemIndex = i;
				i = 10;
			}
		}

		// If [i] has been run to 10 iterations, that means no ID match found
		if (i == 10)
		{
			cout << "No Product Of Specified ID Found! Please Try Again" << endl << endl;
			i = 0;
		}

	} while (i < 10);

	system("CLS");

	do
	{
		cout << "---------------- EDIT ITEM DETAILS ---------------- " << endl << endl;
		cout << "Product Name: " << Prod[ItemIndex].ProdName << endl;
		cout << "Product ID: " << Prod[ItemIndex].ProdID << endl << endl;
		cout << "Total Quantity: " << CompData[ItemIndex].OriginalProdQty << endl;
		cout << "Available Quantity: " << Prod[ItemIndex].ProdQty << endl;
		cout << "Product Buy Price: " << CompData[ItemIndex].ProdBuyPrice << endl;
		cout << "Product Sale Price: " << Prod[ItemIndex].ProdPrice << endl << endl;
		cout << "Press (1) to Change Product Name" << endl;
		cout << "Press (2) to Change Product ID" << endl;
		cout << "Press (3) to Change Product Available Quantity" << endl;
		cout << "Press (4) to Change Product Buy Price" << endl;
		cout << "Press (5) to Change Product Sale Price" << endl;
		cout << "Press (6) to Exit" << endl;
		cout << "\nPlease Enter Your Choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			cout << "Enter New Name: ";
			fflush(stdin);
			cin.getline(Prod[ItemIndex].ProdName, 100);

			Prod[ItemIndex].ProdName[0] = toupper(Prod[ItemIndex].ProdName[0]);

			// Make Input Uppercase
			for (int i = 1; i < 100 && Prod[ItemIndex].ProdName[i] != '\0'; i++)
			{
				if (Prod[ItemIndex].ProdName[i] == ' ' || Prod[ItemIndex].ProdName[i] == '-' || Prod[ItemIndex].ProdName[i] == ':')
				{
					Prod[ItemIndex].ProdName[i + 1] = toupper(Prod[ItemIndex].ProdName[i + 1]);
					i++;
				}
				else
				{
					Prod[ItemIndex].ProdName[i] = tolower(Prod[ItemIndex].ProdName[i]);
				}
			}

			cout << endl << "Name Updated!" << endl << endl;

			system("pause");
			system("CLS");

			SaveCompanyData();

			break;
		}
		case 2:
		{
			int TmpID = 0;
			bool run = 0;

			// Keep asking for ID till user enters one that has not already been taken
			do
			{
				int i = 0;
				cout << "Enter New ID: ";
				cin >> TmpID;
				for (i = 0; i < 10; i++)
				{
					if (Prod[i].ProdID == TmpID)
					{
						cout << "Product ID Already Taken!\n\nPlease Try Again!\n\n";
						run = 1;
						break;
					}
				}
				if (i == 10)
				{
					run = 0;
				}
			} while (run);

			Prod[ItemIndex].ProdID = TmpID;
			cout << endl << "ID Updated!" << endl << endl;

			system("pause");
			system("CLS");

			SaveCompanyData();
			break;
		}
		case 3:
		{
			int TmpProdQty = 0;
			cout << "Enter New Quantity: ";
			cin >> TmpProdQty;

			CompData[ItemIndex].OriginalProdQty += TmpProdQty - Prod[ItemIndex].ProdQty;
			Prod[ItemIndex].ProdQty = TmpProdQty;
			cout << endl << "Quantity Updated!" << endl << endl;

			system("pause");
			system("CLS");

			SaveCompanyData();
			break;
		}
		case 4:
		{
			cout << "Enter New Buy Price: ";
			cin >> CompData[ItemIndex].ProdBuyPrice;
			cout << endl << "Buy Price Updated!" << endl << endl;

			system("pause");
			system("CLS");

			SaveCompanyData();
			break;
		}
		case 5:
		{
			cout << "Enter New Sale Price: ";
			cin >> Prod[ItemIndex].ProdPrice;
			cout << endl << "Sale Price Updated!" << endl << endl;

			system("pause");
			system("CLS");

			SaveCompanyData();
			break;
		}
		case 6:
		{
			run = 0;
			system("CLS");
			break;
		}
		default:
		{
			cout << "Please Enter Number Between 1 - 6!" << endl << endl;
			system("pause");
			system("CLS");
			break;
		}
		}
	} while (run);
}
 
void RevenueReport()
{
	fstream ReadFile;

	char TmpData[100] = { '\0' };
	char * ptr = NULL;
	bool run = 1;
	int TotalPrice = 0, TotalProfit = 0, choice = 0;
	int Day = 0, Month = 0, Year = 0, TmpTotUsers = 0, UserDay = 0, UserMonth = 0, UserYear = 0;
	int * ReqDay = &Day, *ReqMonth = &Month, *ReqYear = &Year;

	do
	{
		cout << "---------------- REVENUE REPORT ---------------- " << endl << endl;
		cout << "Press (1) to Search Specific Day" << endl;
		cout << "Press (2) to Search Specific Month" << endl;
		cout << "Press (3) to Search Specific Year" << endl;
		cout << "\nPlease Enter Your Choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
		{
			ReqDay = &UserDay, ReqMonth = &UserMonth, ReqYear = &UserYear;

			cout << "Enter Day (xx): ";
			cin >> UserDay;
			cout << "Enter Month Of Day (xx): ";
			cin >> UserMonth;
			cout << "Enter Year Of Month (xxxx): ";
			cin >> UserYear;
			run = 0;
			break;
		}
		case 2:
		{
			ReqMonth = &UserMonth, ReqYear = &UserYear;
			cout << "Enter Month: ";
			cin >> UserMonth;
			cout << "Enter Year Of Month: ";
			cin >> UserYear;
			run = 0;
			break;
		}
		case 3:
		{
			ReqYear = &UserYear;
			cout << "Enter Year: ";
			cin >> UserYear;
			run = 0;
			break;
		}
		default:
		{
			cout << "Please Enter Valid Choice!" << endl << endl;
			system("pause");
			system("CLS");
			break;
		}
		}
	} while (run);

	{
		ReadFile.open("PastPurchase.txt");
		int Profit = 0;

		if (ReadFile.is_open())
		{
			while (!ReadFile.eof())
			{
				ReadFile.getline(TmpData, 100);					// Read first 100 characters of a line

				ptr = strtok(TmpData, ":");						// Colon is separater

				if (ptr != NULL)
				{
					if (!strcmp(ptr, "Date"))
					{
						ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon
						Day = atoi(ptr);
						Month = atoi(ptr + 4);					// Move 3 Index To Right
						if (Month > 9)
						{
							Year = atoi(ptr + 7);				// If Month Is 2 Digit, Move 6 Index To The Right
						}
						else
						{
							Year = atoi(ptr + 6);				// If Month Is 1 Digit, Move 5 Index To The Right
						}
						ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon
					}
				}
				if (*ReqDay == Day && *ReqMonth == Month && *ReqYear == Year)
				{
					run = 1;
					break;
				}
			}
			if (run)
			{
				system("CLS");
				cout << "---------------- REVENUE REPORT ---------------- " << endl << endl;
				cout << TmpData << ": ";
				ptr = strtok(TmpData + 6, ":");						// Colon is separater
				cout << ptr << endl;
				ReadFile.getline(TmpData, 100);						// Read first 100 characters of a line
				while (run && !ReadFile.eof())
				{
					cout << TmpData << endl;
					ptr = strtok(TmpData, ":");
					if (!strcmp(TmpData, "Profit"))
					{
						ptr = strtok(NULL, ":");					// Go to next index, because required data comes AFTER Colon
						Profit += atoi(ptr + 3);
					}
					ReadFile.getline(TmpData, 100);					// Read first 100 characters of a line

					// Extra Check Added To Ensure Only Specified Date Range Gets Displayed!
					if (TmpData[0] == 'D')							// Because Date Starts With D!
					{
						char tmp[100] = { '\0' };
						strcpy(tmp, TmpData);
						ptr = strtok(TmpData, ":");					// First Will Show Word Date
						ptr = strtok(NULL, ":");					// Now Shows Actual Date
						if (ptr != NULL)
						{
							Day = atoi(ptr);						// Store Day
							Month = atoi(ptr + 4);					// Move 4 Index To Right
							if (Month > 9)
							{
								Year = atoi(ptr + 7);				// If Month Is 2 Digit, Move 7 Index To The Right
							}
							else
							{
								Year = atoi(ptr + 6);				// If Month Is 1 Digit, Move 6 Index To The Right
							}
						}
						if (*ReqDay == Day && *ReqMonth == Month && *ReqYear == Year)
						{
							cout << tmp << endl;
							run = 1;
							ReadFile.getline(TmpData, 100);						// Read first 100 characters of a line
						}
						else
						{
							run = 0;
						}
					}
				}

				//while (TmpData[0] != 'D')							// Because Date Starts With D!
				//{
				//	cout << TmpData << endl;
				//	ptr = strtok(TmpData, ":");
				//	if (!strcmp(TmpData, "Profit"))
				//	{
				//		ptr = strtok(NULL, ":");					// Go to next index, because required data comes AFTER Colon
				//		Profit += atoi(ptr + 3);
				//	}
				//	ReadFile.getline(TmpData, 100);					// Read first 100 characters of a line
				//}

				cout << "Total Profit: RS " << Profit << endl << endl;
			}
			else
			{
				cout << endl;
				cout << "No Data Found In Specified Date Range!" << endl << endl;
			}
		}
		ReadFile.close();
	}

	system("pause");
	system("CLS");
}

// -------------------
// Data Finding
// -------------------

void SearchMenu(bool isEmployee)
{
	system("Color 2");

	bool run = 1;
	do
	{
		int choice = 0;

		cout << "---------------- SEARCH SELECTION ---------------- " << endl << endl;
		if (isEmployee)
		{
			cout << "Press (1) to Search Product By ID" << endl;
			cout << "Press (2) to Search Product By Name" << endl;
			cout << "Press (3) to Search Product By Sold Amount" << endl;
			cout << "Press (4) to Search Product By Available Quantity" << endl;
			cout << "Press (5) to Search Product By Price" << endl;
			cout << "Press (6) to Return to Main Menu" << endl;
			cout << "\nPlease Enter Your Choice: ";
		}
		else
		{
			cout << "Press (1) to Search Product By ID" << endl;
			cout << "Press (2) to Search Product By Name" << endl;
			cout << "Press (3) to Search Product By Quantity In Your Cart" << endl;
			cout << "Press (4) to Search Product By Price" << endl;
			cout << "Press (5) to Return to Main Menu" << endl;
			cout << "\nPlease Enter Your Choice: ";
		}
		cin >> choice;

		// Increase By 1 Because Employees Have 1 More Option
		if (!isEmployee && choice > 2)
		{
			choice++;
		}

		switch (choice)
		{
		case 1:
		{
			// -------------------------------------
			// FIND BY ID
			// -------------------------------------

			int shown = 0;
			int FindID = 0;
			system("CLS");

			cout << "Enter Product ID To Find: ";
			cin >> FindID;
			system("CLS");
			int Shown = 0;
			for (int i = 0; i < 10; i++)
			{
				if (i == 9)
				{
					Shown = Find(FindID, PtrProd[i], isEmployee, 1, Shown, i);
				}
				else
				{
					Shown = Find(FindID, PtrProd[i], isEmployee, 0, Shown, i);
				}
			}

			break;
		}
		case 2:
		{
			// -------------------------------------
			// FIND BY PRODUCT NAME
			// -------------------------------------

			char name[100] = { '0' };

			system("CLS");

			cout << "Enter Product Name To Find: ";
			fflush(stdin);
			cin.ignore();
			cin.getline(name, 100);

			// Make Entered Data Lowercase
			for (int i = 0; i < strlen(name); i++)
			{
				name[i] = tolower(name[i]);
			}

			Find(name, isEmployee);

			break;
		}
		case 3:
		{
			// -------------------------------------
			// FIND BY TOTAL PURCHASE
			// -------------------------------------

			int TotBuy = 0;

			system("CLS");

			cout << "Enter Total Purchase To Find: ";
			cin >> TotBuy;
			if (isEmployee)
			{
				int Shown = 0;
				for (int i = 0; i < 10; i++)
				{
					if (i == 9)
					{
						Shown = Find(TotBuy, (PtrCompData[i] + 2), isEmployee, 1, Shown, i);
					}
					else
					{
						Shown = Find(TotBuy, (PtrCompData[i] + 2), isEmployee, 0, Shown, i);
					}
				}
			}
			else
			{
				Find(TotBuy, CustDetail[TotUsers].ItemsQtyInCart, isEmployee, 1, 0, TotUsers);
			}
			break;
		}
		case 4:
		{
			// -------------------------------------
			// FIND BY QUANTITY
			// -------------------------------------

			int SearchQty = 0;

			system("CLS");

			if (isEmployee)
			{
				cout << "Enter Available Quantity Amount To Find: ";
				cin >> SearchQty;

				int Shown = 0;
				for (int i = 0; i < 10; i++)
				{
					if (i == 9)
					{
						Shown = Find(SearchQty, (PtrProd[i] + 1) , isEmployee, 1, Shown, i);
					}
					else
					{
						Shown = Find(SearchQty, (PtrProd[i] + 1), isEmployee, 0, Shown, i);
					}
				}
			}
			else
			{
				int Shown = 0;

				cout << "Enter Quantity To Find: ";
				cin >> SearchQty;

				for (int i = 0; i < 10; i++)
				{
					if (i == 9)
					{
						Shown = Find(SearchQty, &CustDetail[TotUsers].ItemsQtyInCart[i], isEmployee, 1, Shown, i);
					}
					else
					{
						Shown = Find(SearchQty, &CustDetail[TotUsers].ItemsQtyInCart[i], isEmployee, 0, Shown, i);
					}
				}
			}

			break;
		}
		case 5:
		{
			// -------------------------------------
			// FIND BY PRICE
			// -------------------------------------

			int SearchPrice = 0;

			system("CLS");

			cout << "Enter Product Price To Find: ";
			cin >> SearchPrice;

			int Shown = 0;
			for (int i = 0; i < 10; i++)
			{
				if (i == 9)
				{
					Shown = Find(SearchPrice, (PtrProd[i] + 2), isEmployee, 1, Shown, i);
				}
				else
				{
					Shown = Find(SearchPrice, (PtrProd[i] + 2), isEmployee, 0, Shown, i);
				}
			}

			break;
		}
		case 6:
		{
			// -------------------------------------
			// EXIT
			// -------------------------------------

			run = 0;
			system("CLS");
			break;
		}
		default:
		{
			// -------------------------------------
			// INVALID CHOICE
			// -------------------------------------

			cout << "Invalid Choice Entered!" << endl << endl;
			run = 1;
			system("pause");
			system("CLS");
		}
		}
	} while (run);
}

// INPUT TYPE: INT
int Find(int input, int *data, bool isEmployee, bool Run, int shown, int Runs)
{
	system("CLS");
	if (input == *data)
	{
		cout << "---------------------------- Record " << shown + 1 << " ----------------------------" << endl << endl;
		if (isEmployee)
		{
			DisplayDataCompany(Runs, 1);
		}
		else
		{
			DisplayData(Runs, 1);
		}
		shown++;
	}
	// If not found
	if (Run)
	{
		if (!shown)	// Didn't run
		{
			cout << endl << "Search Result Not Found!" << endl << endl;
			system("pause");
			system("CLS");
		}
		else			// Ran, In which case print End Of Record Reached
		{
			cout << endl << "End Of Record Reached!" << endl << endl;
			system("pause");
			system("CLS");
		}
	}
	return shown;
}

// INPUT TYPE: CHAR
void Find(char *name, bool isEmployee)
{
	int shown = 0;
	for (int i = 0; i < 10; i++)
	{
		// If Found
		if (strstr(Prod[i].ProdName, name))
		{
			system("CLS");
			cout << "---------------------------- Record " << shown + 1 << " ----------------------------" << endl << endl;
			if (isEmployee)
			{
				DisplayDataCompany(i, 1);
			}
			else
			{
				DisplayData(i, 1);
			}
			shown++;
		}

		// If no result has been found, we're going to make everything Sentence Case as product names are capital for every first word after space
		if (i == 9 && shown == 0)
		{

			// Check if input has already been turned into Sentence Case
			if (isupper(name[0]))
			{
				// Only need to check 0 index as we make it uppercase by default
				break;
			}
			// Capitalize First Leter Of Search Words & Turn Other Into Lowercase
			{
				name[0] = toupper(name[0]);
				for (i = 1; i < strlen(name); i++)
				{

					// If a space/dash/semi-colon has been encountered, that means new word has begun. Capitalize first letter of that as well
					if (name[i] == ' ' || name[i] == '-' || name[i] == ':')
					{
						name[i + 1] = toupper(name[i + 1]);
						// Increment so that next iteration of loop doesn't make first letter after space small again
						i++;
					}

					// If it isn't first letter, then make it lowercase
					else
					{
						name[i] = tolower(name[i]);
					}
				}
			}
			i = -1;	// Start Searching Again
		}
	}	// For Loop End

	// If name was not found
	{
		if (!shown)	// Didn't run
		{
			cout << endl << "Search Result Not Found!" << endl << endl;
			system("pause");
			system("CLS");
		}
		else		// Ran, In which case print End Of Record Reached
		{
			cout << endl << "End Of Record Reached!" << endl << endl;
			system("pause");
			system("CLS");
		}
	}
}

// Sort Data
int sort(int *arr, int size)
{
	bool IsDone = 0, run = 0, CalledByPI = 0;
	int Max = -1, MaxIndex = -1;
	int temp[10] = { 0 };	// Only Used For ProfitableItems() Function
	int * address = arr;	// Store Old Address Of array. Only Used For ProfitableItems() Function

	// If ProfitableItems() Function Calls Sort() Function 
	if (arr[0] == -9999999)
	{
		for (int i = 0; i < 10; i++)
		{
			temp[i] = Prod[i].ProdPrice - CompData[i].ProdBuyPrice;
		}
		arr = temp;	// Point To Temp Instead Of Passed Array
		CalledByPI = 1;
	}

	for (int i = 0; i < size * 10; i += size)
	{
		IsDone = 0;
		if (*(arr + i) > Max && *(arr + i) != 0)
		{
			// Check If Index Has Already Been Done
			for (int j = 0; j < 10; j++)
			{
				if (i / size == done[j])
				{
					IsDone = 1;
					break;
				}
			}

			// If Value Not Done
			if (!IsDone)
			{
				Max = *(arr + i);
				MaxIndex = i / size;
				run = 1;
			}
		}
	}
	if (run)
	{
		done[MaxIndex] = MaxIndex;
	}
	if (CalledByPI)
	{
		address[0] = MaxIndex;
		address[1] = temp[MaxIndex];
	}
	return MaxIndex;
}

// -------------------
// Saving & Loading
// -------------------

void SaveCompanyData()
{
	ofstream myfile;
	time_t now = time(0);
	myfile.open("InventoryDetails.txt");

	// Get Current Date
	// Learning Source: https://linux.die.net/man/3/gmtime
	{
		time_t curr_time;
		curr_time = time(NULL);
		tm *tm_gmt = gmtime(&curr_time);

		// tm_mon - The number of months since January, in the range 0 to 11.
		// tm_year- The number of years since 1900.

		myfile << "Date: " << tm_gmt->tm_mday << "/" << tm_gmt->tm_mon + 1 << "/" << 1900 + tm_gmt->tm_year << endl << endl;
	}

	for (int index = 0; index < 10; index++)
	{
		myfile << "Product Name: " << Prod[index].ProdName << endl;
		myfile << "Product ID: " << Prod[index].ProdID << endl;
		myfile << "Product Description: " << Prod[index].ProdDescription << endl;
		myfile << "Total Quantity: " << CompData[index].OriginalProdQty << endl;
		myfile << "Available Quantity: " << Prod[index].ProdQty << endl;
		myfile << "Product Buy Price: " << CompData[index].ProdBuyPrice << endl;
		myfile << "Product Sale Price: " << Prod[index].ProdPrice << endl;
		myfile << "Total Sold: " << CompData[index].TotSold << endl << endl;
		myfile << "-----------------------" << endl << endl;
	}
	myfile.close();
}

void LoadCompanyData()
{
	ifstream ReadFile;

	char TmpStore[500] = { '\0' };
	char *ptr = NULL;
	int index = 0;

	ReadFile.open("InventoryDetails.txt");

	if (ReadFile.is_open())
	{
		while (!ReadFile.eof())
		{
			ReadFile.getline(TmpStore, 500);				// Read first 500 characters of a line
			ptr = strtok(TmpStore, ":");					// Colon is separater

			if (TmpStore[0] == '-')
			{
				index++;
				continue;
			}

			if (ptr != NULL)
			{
				if (!strcmp(ptr, "Product Name")) 
				{
					ptr = strtok(NULL, ":");						// Go to next index, because required data comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(Prod[index].ProdName, (ptr + 1));	// First character after Colon is space, ignore that and go to next address/coloumn
					}
				}
				else if (!strcmp(ptr, "Product ID"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(TmpStore, ptr + 1);			// First character after Colon is space, ignore that and go to next address/coloumn
						Prod[index].ProdID = atoi(TmpStore);
					}
				}
				else if (!strcmp(ptr, "Product Description"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(Prod[index].ProdDescription, (ptr + 1));	// First character after Colon is space, ignore that and go to next address/coloumn
					}
				}
				else if (!strcmp(ptr, "Total Quantity"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(TmpStore, ptr + 1);			// First character after Colon is space, ignore that and go to next address/coloumn
						CompData[index].OriginalProdQty = atoi(TmpStore);
					}
				}
				else if (!strcmp(ptr, "Available Quantity"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(TmpStore, ptr + 1);			// First character after Colon is space, ignore that and go to next address/coloumn
						Prod[index].ProdQty = atoi(TmpStore);
					}
				}
				else if (!strcmp(ptr, "Product Buy Price"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(TmpStore, ptr + 1);			// First character after Colon is space, ignore that and go to next address/coloumn
						CompData[index].ProdBuyPrice = atoi(TmpStore);
					}
				}
				else if (!strcmp(ptr, "Product Sale Price"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(TmpStore, ptr + 1);			// First character after Colon is space, ignore that and go to next address/coloumn
						Prod[index].ProdPrice = atoi(TmpStore);
					}
				}
				else if (!strcmp(ptr, "Total Sold"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(TmpStore, ptr + 1);			// First character after Colon is space, ignore that and go to next address/coloumn
						CompData[index].TotSold = atoi(TmpStore);
					}
				}
				else
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data not found
				}
			}
		}
		ReadFile.close();
	}
}

void SaveBill()
{
	fstream ReadFile;
	time_t now = time(0);
	time_t curr_time;
	curr_time = time(NULL);
	tm *tm_gmt = gmtime(&curr_time);

	char TmpData[100] = { '\0' };
	char * ptr = NULL;
	bool run = 1;
	int TotalPrice = 0;
	int TotalProfit = 0;

	// Get Current Date
	// Learning Source: https://linux.die.net/man/3/gmtime
	{
		int Day = 0, Month = 0, Year = 0, TmpTotUsers = 0;
		ReadFile.open("PastPurchase.txt", fstream::in);

		if (ReadFile.is_open())
		{
			while (!ReadFile.eof())
			{
				ReadFile.getline(TmpData, 100);					// Read first 100 characters of a line

				ptr = strtok(TmpData, ":");						// Colon is separater

				if (ptr != NULL)
				{
					if (!strcmp(ptr, "Date"))
					{
						ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon
						Day = atoi(ptr);
						Month = atoi(ptr + 4);					// Move 3 Index To Right
						if (Month > 9)
						{
							Year = atoi(ptr + 7);				// If Month Is 2 Digit, Move 6 Index To The Right
						}
						else
						{
							Year = atoi(ptr + 6);				// If Month Is 1 Digit, Move 5 Index To The Right
						}
						ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon
					}
				}

				// If Date Is The Same, Don't Add The Date Again
				if (tm_gmt->tm_mday == Day && (tm_gmt->tm_mon + 1) == Month && (1900 + tm_gmt->tm_year) == Year)
				{
					run = 0;
					break;
				}
			}
		}
		ReadFile.close();

		ReadFile.open("PastPurchase.txt", fstream::in);
		do
		{
			ReadFile.getline(TmpData, 100);
			ptr = strtok(TmpData, ":");
			if ((!strcmp(TmpData, "Customer Number")))
			{
				ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon
				TmpTotUsers = atoi(ptr);
			}

		} while (!ReadFile.eof());
		TotUsers = TmpTotUsers;
		ReadFile.close();
	}

	ReadFile.open("PastPurchase.txt", fstream::app);

	if (run)
	{
		ReadFile << "Date: " << tm_gmt->tm_mday << "/" << tm_gmt->tm_mon + 1 << "/" << 1900 + tm_gmt->tm_year << endl << endl;
		// tm_mon - The number of months since January, in the range 0 to 11.
		// tm_year- The number of years since 1900.
	}

	ReadFile << "Customer Number: " << TotUsers + 1 << endl << endl;

	for (int index = 0; index < 10; index++)
	{
		if (CustDetail[TotUsers].ItemsQtyInCart[index])	// If ItemsQtyInCart > 0
		{
			ReadFile << "Product Name: " << Prod[index].ProdName << endl;
			ReadFile << "Product ID: " << Prod[index].ProdID <<	endl;
			ReadFile << "Quantity Bought: " << CustDetail[TotUsers].ItemsQtyInCart[index] << endl;
			ReadFile << "Product Buy Price: RS " << CompData[index].ProdBuyPrice << endl;
			ReadFile << "Product Sale Price: RS " << Prod[index].ProdPrice << endl << endl;
			TotalPrice += Prod[index].ProdPrice * CustDetail[TotUsers].ItemsQtyInCart[index];
			TotalProfit += (Prod[index].ProdPrice - CompData[index].ProdBuyPrice) * CustDetail[TotUsers].ItemsQtyInCart[index];
		}
	}
	ReadFile << "Gross Earning: RS " << TotalPrice << endl;
	ReadFile << "Profit: RS " << TotalProfit << endl << endl;

	ReadFile << "-----------------------" << endl << endl;

	ReadFile.close();
}

void ShowBill()
{
	char TmpData[100] = { '\0' };
	char * ptr = TmpData;
	int Qty = 0, BuyPrice = 0, SalePrice = 0;
	ifstream ReadFile;
	ReadFile.open("PastPurchase.txt");
	int Profit = 0;

	cout << "---------------- PAST BILLS ---------------- " << endl << endl;

	if (ReadFile.is_open())
	{
		while (!ReadFile.eof())
		{
			ReadFile.getline(TmpData, 100);					// Read first 100 characters of a line

			cout << TmpData << endl;

			ptr = strtok(TmpData, ":");						// Colon is separater

			if (ptr != NULL)
			{
				if (!strcmp(ptr, "Quantity Bought"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon
					Qty = atoi(ptr);
				}
				else if (!strcmp(ptr, "Product Buy Price"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon
					BuyPrice = atoi(ptr + 3);
				}
				else if (!strcmp(ptr, "Product Sale Price"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon
					SalePrice = atoi(ptr + 3);
				}
				else if (!strcmp(ptr, "Profit"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because required data comes AFTER Colon
					Profit += atoi(ptr + 3);
				}
			}
		}
		ReadFile.close();
	}
	cout << "Total Profit: RS " << Profit << endl << endl;
	system("pause");
	system("CLS");
}

void SaveEmployeeData()
{
	ofstream myfile;
	myfile.open("EmployeeLoginDetails.txt", ios::app);
	myfile << "Username: " << EmpLog[counter].Username << endl;
	myfile << "Password: " << EmpLog[counter].Password << endl;
	myfile << "-----------------------" << endl;
	myfile.close();
}

void LoadEmployeeData()
{
	ifstream ReadFile;

	char TmpStore[100] = { '\0' };
	char TmpPassword[100] = { '\0' };
	char *ptr = NULL;

	ReadFile.open("EmployeeLoginDetails.txt");
	if (ReadFile.is_open())
	{
		while (!ReadFile.eof())
		{
			ReadFile.getline(TmpStore, 100);				// Read first 100 characters of a line
			ptr = strtok(TmpStore, ":");					// Colon is separater

			if (ptr != NULL)
			{
				if (!strcmp(ptr, "Username"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because the username/password comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(TmpStore, (ptr + 1));		// First character after Colon is space, ignore that and go to next address/coloumn
						strcpy(EmpLog[counter].Username, TmpStore);
					}
				}
				else if (!strcmp(ptr, "Password"))
				{
					ptr = strtok(NULL, ":");				// Go to next index, because the username/password comes AFTER Colon

					if (ptr != NULL)
					{
						strcpy(TmpStore, (ptr + 1));		// First character after Colon is space, ignore that and go to next address/coloumn
						strcpy(EmpLog[counter].Password, TmpStore);
						counter++;
					}
				}
				else
				{
					ptr = strtok(NULL, ":");				// Go to next index, because the username/password not found
				}
			}
		}
		ReadFile.close();
	}
}

/*
Extra Functionality:
1) Separate Portal for Employees and Customers

2) FOR CUSTOMERS
	1) Shows which items are in cart (In the buy menu)
	2) Option to edit item quantity that you already have in the cart (From the buy menu screen)
	3) Menu to see cart details
	4) Search items according to their quantity in your cart
	5) Checkout Screen
	6) Option to exit without buying
	7) Pretty Colors

3) FOR EMPLOYEES
	1) Separate (working) Login & Sign Up page for employees
	2) Sign up page requires Master password (Hard coded into the code: 8531F1C0 ) to sign up so that anyone who doesn't have the source code can't sign up
	3) Advanced Analytics menu which shows extra data about how products are performing, such as:
			=> List of most profitable items
			=> List of items low on stock
			=> Average Sale Amount of a specific product, i.e, average buy rate by the customers
			=> Know how long your stock will last in the Advanced Analytics menu -> Average Sale Amount
	4) Pretty Colors

4) Extensive Error Handling to ensure user does not encounter any bugs

Challenges I Made For Myself
	1) Learn how to navigate through a stuct using address manipulation
	2) Implement a function that allows different structs to be passed to it, and access variables of the struct

What I've Learnt Through This Project:
	1) Uses of structs
	2) Passing & Navigation of structs through different functions using pointers

Questions At The End Of The Project:
	1) Why is there STILL no way to pass entire structs BY REFERENCE!? 
	2) Why can't we pass struct objects as variables!?

I HAVE ALSO UPLOADED THE PROJECT TO GITHUB, CHECK IT OUT HERE: https://github.com/Icedwhisper/ECommerce-CMS
*/
