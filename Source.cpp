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
void GroceryDetail(bool isEmployee);
void DisplayDataCompany(int index, bool run);
void SearchMenu(bool isEmployee);
void AdvancedAnalytics();
void ProfitableItems(bool Reverse, bool isAvg);

// -------------------
// Find Data
// -------------------

void Find(int input, int *data, bool isEmployee);
void Find(char *name, bool isEmployee);
int sort(int *arr);

// -------------------
// FUNCTION DECLARATION END
// -------------------

// INT Variable
int TotUsers = 0;
int done[10] = { -1 };
int counter = 0;
int ProdID[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int ProdQty[10] = { 9, 8, 6, 7, 4, 100, 25, 4, 7, 2 };
int OriginalProdQty[10] = { 0 };
int TotPurchased[10] = { 0 };
int TmpTotPurchased[10] = { 0 };
int UserTotPurchased[10] = { 0 };
int ProdPrice[10] = { 549, 1599, 799, 549, 1269, 2799, 249, 99, 159, 729 };
int ProdBuyPrice[10] = { 100, 500, 320, 178, 751, 1278, 67, 15, 65, 150 };

// CHAR Variable
char Username[100][100] = { '\0' };
char Password[100][100] = { '\0' };

// ======================================
// ---- USE THIS KEY FOR SIGNING UP! ----
// ======================================

char MasterKey[100] = { "8531F1C0" };

// =====================================
// ---------------- END ----------------
// =====================================

char ProdName[10][30] = {
	{"Half-Life"},
	{"Half-Life 2"},
	{"Half-Life 2: Episode 1"},
	{"Half-Life 2: Episode 2"},
	{"Half-Life 2: Lost Coast"},
	{"Half-Life: Alyx"},
	{"Half-Life: Opposing Force"},
	{"Half-Life: Blue Shift"},
	{"Half-Life 2: Deathmatch"},
	{"Black Mesa"}
};		// Name Of My Favorite Games Series: Half Life
char ProdDescription[10][120] = {
	{"Half-Life is a first-person shooter game developed by Valve. It was Valve's first game."},
	{"Half-Life 2 is a first-person shooter and it combines shooting, puzzles, and storytelling."},
	{"Gordon Freeman alongside his companion Alyx Vance, must escape City 17 before it explodes."},
	{"Following Episode 1, it was the second in a planned trilogy that continue the story of Half-Life"},
	{"The player is tasked to travel up a coastal cliff to destroy a Combine headcrab artillery."},
	{"Taking place between events of HL1 and HL2, Alyx is on a mission to seize a Combine superweapon."},
	{"Adrian is sent to neutralize the Black Mesa scientists when a scientific mishap happens."},
	{"After a mishap causes Black Mesa to be invaded by aliens, Calhoun must fight his way to safety."},
	{"Half-Life 2: Deathmatch is a multiplayer first-person shooter video game developed by Valve."},
	{"Black Mesa is a fan remake of the original Half-Life with graphics that match todays standards."}
};

// -------------------
// PROGRAMS START HERE
// -------------------

int main()
{
	// Initialize Arrays
	for (int i = 0; i < 10; i++)
	{
		done[i] = -1;
		OriginalProdQty[i] = ProdQty[i];
		TotPurchased[i] = 0;
		TmpTotPurchased[i] = 0;
		UserTotPurchased[i] = 0;
	}

	WelcomeScreen();

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

			GroceryDetail(0);

			break;
		}
		case 4:
		{
			// -------------------------------------
			// SHOW TOTAL BILL & EXIT
			// -------------------------------------

			cout << "---------------- THANK YOU ---------------- " << endl << endl;
			TotalBill(UserTotPurchased, 1);
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
				TotPurchased[i] -= UserTotPurchased[i];
				ProdQty[i] += UserTotPurchased[i];
				TmpTotPurchased[i] = 0;
				UserTotPurchased[i] = 0;
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

		if (TmpTotPurchased[i] > 0 || UserTotPurchased[i] > 0)			// If item is already in case
		{
			cout << "(Item In Cart)" << endl;
		}
		cout << "Product Name: " << ProdName[i] << endl;
		cout << "Product ID: " << ProdID[i] << endl;
		cout << "Available Quantity: " << ProdQty[i] << endl;
		cout << "Product Price: RS " << ProdPrice[i] << endl;
		cout << "Product Description: " << ProdDescription[i] << endl << endl;
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
			if (ItemID == ProdID[i])
			{
				ItemIndex = i;

				// Check If The Item Is In Cart
				if (UserTotPurchased[ItemIndex] > 0)
				{
					ReBuyItem(ItemIndex);
					return;
				}

				// If Product Is Out Of Stock
				if (ProdQty[ItemIndex] == 0)
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
		if (TmpTotPurchased[ItemIndex] > ProdQty[ItemIndex])
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
		else if (UserTotPurchased[ItemIndex] + TmpTotPurchased[ItemIndex] > 10)
		{
			cout << "Sorry, Maximum Amount You Can Buy Is 10. You Already Have " << UserTotPurchased[ItemIndex] << " Item(s) In Your Cart" << endl << endl;
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
	cout << "Product Name: " << ProdName[index] << endl;
	cout << "Product ID: " << ProdID[index] << endl;
	cout << "Available Quantity: " << ProdQty[index] << endl;
	cout << "Quantity In Your Cart: " << UserTotPurchased[index] << endl;
	cout << "Product Price: " << ProdPrice[index] << endl;
	cout << "Product Description: " << ProdDescription[index] << endl << endl;
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
			ProdQty[index] += UserTotPurchased[index];
			TotPurchased[index] -= UserTotPurchased[index];

			// Ask User For Quantity
			do
			{
				cout << "Enter Quantity Of Item You Want To Buy: ";
				cin >> TmpTotPurchased[index];

				// If entered amount greater than available amount
				if (UserTotPurchased[index] > OriginalProdQty[index])
				{
					cout << "Sorry, Maximum Amount You Can Buy Is: " << ProdQty[index] << endl << endl;
					run = 1;
				}
				else if (TotPurchased[index] > 10)
				{
					cout << "Sorry, Maximum Amount You Can Buy Is 10" << endl << endl;
					run = 1;
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
			cout << "Product Name: " << ProdName[i] << endl;
			cout << "Product ID: " << ProdID[i] << endl;
			cout << "Product Price: " << ProdPrice[i] << endl;
			cout << "Total Quantity In Your Cart: " << arr[i] << endl;
			cout << "Price Of Item(s) In Your Cart: RS " << ProdPrice[i] * arr[i] << endl << endl;
			SumTotal += (ProdPrice[i] * arr[i]);
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

			// Update Data By Subtracting Buy Amounts Of All Items In Cart
			for (int i = 0; i < 10; i++)
			{
				TotPurchased[i] += TmpTotPurchased[i];
				UserTotPurchased[i] += TmpTotPurchased[i];
				ProdQty[i] -= TmpTotPurchased[i];
			}
			if (!Checkout)
			{
				cout << "Item(s) Added To Your Cart!" << endl << endl;
			}
			else
			{
				// User Now Leaving, Reset Everything
				for (int i = 0; i < 10; i++)
				{
					TmpTotPurchased[i] = 0;
					UserTotPurchased[i] = 0;
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
			if (!strcmp(Password_T, Password[i]) && !strcmp(Username_T, Username[i]))
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
	cin.getline(Username[counter], 100);

	// Make Username lowercase
	for (int i = 0; i < 100 && Username[i] != '\0'; i++)
	{
		Username[counter][i] = tolower(Username[counter][i]);
	}

	cout << "Enter Password: ";
	cin.getline(Password[counter], 100);

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
		cout << "Press (1) to Check All Sold Items (Descending Order)" << endl;
		cout << "Press (2) to Search Item" << endl;
		cout << "Press (3) to Enter Advanced Analytics" << endl;
		cout << "Press (4) to Return To Welcome Screen" << endl;
		cout << "\nPlease Enter Your Choice: ";

		fflush(stdin);	// Used To Clear Input Buffer
		cin >> choice;

		switch (choice)
		{
		case 1:
		{

			// -------------------------------------
			// CHECK ALL SOLD ITEMS
			// -------------------------------------

			Sleep(300);
			system("CLS");
			system("Color 3");

			GroceryDetail(1);

			break;
		}
		case 2:
		{
			// -------------------------------------
			// SEARCH ITEM
			// -------------------------------------

			system("CLS");
			system("Color 3");

			SearchMenu(1);

			break;
		}
		case 3:
		{
			// -------------------------------------
			// ADVANCED ANALYTICS
			// -------------------------------------

			system("CLS");
			run = 0;
			AdvancedAnalytics();
			break;
		}
		case 4:
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
	} while (run == 1);
}

void GroceryDetail(bool isEmployee)
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

	if (isEmployee)
	{
		cout << "------------ SOLD ITEM DETAIL ------------" << endl << endl;
		for (int i = 0; i < 10; i++)
		{
			index = sort(TotPurchased);
			if (index != -1)
			{
				cout << "---------------- Record " << shown << " ----------------" << endl << endl;
				DisplayDataCompany(index, 0);
				SumTotal += (ProdPrice[index] * TotPurchased[index]);
				TotalProfit += (ProdPrice[index] - ProdBuyPrice[index]) * TotPurchased[index];
				shown++;
			}
		}

		cout << "---------------- Reched End Of Record After " << shown - 1 << " Results ----------------" << endl << endl;
		cout << "Gross Total: RS " << SumTotal << endl;						// Earnings Before Deducting Purchase Amount
		cout << "Total Profit: RS " << TotalProfit << endl << endl;			// Earnings After Deducting Purchase Amount
	}
	else
	{
		cout << "-------------- CART DETAILS --------------" << endl << endl;
		for (int i = 0; i < 10; i++)
		{
			index = sort(UserTotPurchased);
			if (index != -1)
			{
				cout << "---------------- Record " << shown << " ----------------" << endl << endl;
				DisplayData(index, 0);
				SumTotal += (ProdPrice[index] * UserTotPurchased[index]);
				shown++;
			}
		}

		cout << "---------------- Reched End Of Record After " << shown - 1 << " Results ----------------" << endl << endl;
	}
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
	cout << "Product Name: " << ProdName[index] << endl;
	cout << "Product ID: " << ProdID[index] << endl << endl;
	cout << "Total Quantity: " << OriginalProdQty[index] << endl;
	cout << "Available Quantity: " << ProdQty[index] << endl;
	cout << "Total Sold: " << TotPurchased[index] << endl << endl;
	cout << "Product Price: " << ProdPrice[index] << endl;
	cout << "Profit Per Item: " << ProdPrice[index] - ProdBuyPrice[index] << endl;
	cout << "Gross Earnings: " << ProdPrice[index] * TotPurchased[index] << endl;
	cout << "Profit: " << (ProdPrice[index] - ProdBuyPrice[index]) * TotPurchased[index] << endl << endl;
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
			EmployeeMainMenu();
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

void ProfitableItems(bool Reverse, bool isAvg)
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
		if (Reverse)
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
		if (Reverse)
		{
			LowToHigh[i] = sort(ProdQty);
			if (i == 9)
			{
				for (int i = 9; i >= 0; i--)
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
			index = sort(TotPurchased);

			// Show Only Products That Have Actually Been Bought
			if (!(OriginalProdQty[index] == ProdQty[index]) && index != -1)
			{
				cout << "---------------- Record " << shown << " ----------------" << endl << endl;
				DisplayDataCompany(index, 0);
				cout << "Average Quantity Bought: " << (OriginalProdQty[index] - ProdQty[index]) / (TotUsers + 1.0 - 1.0) << endl;
				cout << "Expected Number Of Days Stock Will Last: " << ProdQty[index] / ((OriginalProdQty[index] - ProdQty[index]) / (TotUsers + 1.0 - 1.0)) << endl << endl;
				shown++;
			} 
		}
		else
		{
			ProfitData[0] = -9999999;
			sort(ProfitData);
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

			int FindID = 0;
			system("CLS");

			cout << "Enter Product ID To Find: ";
			cin >> FindID;

			Find(FindID, ProdID, isEmployee);

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
				Find(TotBuy, TotPurchased, isEmployee);
			}
			else
			{
				Find(TotBuy, UserTotPurchased, isEmployee);
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

			cout << "Enter Available Quantity Amount To Find: ";
			cin >> SearchQty;
			if (isEmployee)
			{
				Find(SearchQty, ProdQty, isEmployee);
			}
			else
			{
				Find(SearchQty, UserTotPurchased, isEmployee);
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

			Find(SearchPrice, ProdPrice,isEmployee);

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
void Find(int input, int *data, bool isEmployee)
{
	system("CLS");
	int shown = 0;
	for (int i = 0; i < 10; i++)
	{
		if (input == data[i])
		{
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
	}
	// If not found
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
}

// INPUT TYPE: CHAR
void Find(char *name, bool isEmployee)
{
	int shown = 0;
	for (int i = 0; i < 10; i++)
	{
		// If Found
		if (strstr(ProdName[i], name))
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
int sort(int *arr)
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
			temp[i] = ProdPrice[i] - ProdBuyPrice[i];
		}
		arr = temp;	// Point To Temp Instead Of Passed Array
		CalledByPI = 1;
	}

	for (int i = 0; i < 10; i++)
	{
		IsDone = 0;
		// Find max value stored in array
		if (arr[i] > Max && arr[i] != 0)
		{
			// Check If Index Has Already Been Done
			for (int j = 0; j < 10; j++)
			{
				if (i == done[j])
				{
					IsDone = 1;
					break;
				}
			}

			// If Value Not Done
			if (!IsDone)
			{
				Max = arr[i];
				MaxIndex = i;
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
	1) Main() should only call only ONE function, and do nothing else
	2) Remove all unnecessary code 
	3) Play with addresses as much as possible
	4) Reuse functions by repurposing them in a manner that allows the same task with slight modifications to be done using them
	5) Try to use Function Overloading for atleast one thing. Verdict: It is only useful in bigger programs when you run out of names, and confusing 

What I've Learnt Through This Project:
	1) Importance of documentation
	2) How Recursions work and what happens when you call a function within a function, and how to properly terminate recursion in a manner that doesn't break the program/cause unwanted code execution
	3) How to reduce code by modifying existing functions
	4) How to work with global variables
	5) How to work with pointers and addresses
	6) How passing by reference reduces code and decreases complexity of code
	7) How to make sort function work with most input types

Questions At The End Of The Project:
	 1) How to do file-handling to save variables for later use (TAUGHT IN LATEST LAB)
	 2) How safe global variables are and is it better to use them or should I create local variables and pass a reference to them?
	 3) Why does cin sometimes not work? This is expecially true when trying to take in input with space. I have to use fflush() and cin.ignore(), 
		but if not used correctly, it can cause the first letter to get ignored, a big no no if you have a login system! 
		Another problem I've noticed is that if the user enters a character where the input is to be stored in an INT variable, it causes the input system
		to completely break. You will run into infinite loop of automatic input and error messages running on screen unless you terminate the program.
	 4) When I point a pointer to an address stored in another pointer which stores the address of an array (i.e, another pointer), 
		it only shows the first value stored in the array, but not the rest of it. e.g:

		int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int * ptr = arr;
		int * ptr2 = ptr;

		If I try to access ptr2, it will only show the first value stored in arr in the debugger (auto watch variable), i.e, arr[0] = 0, whereas the array arr
		in the debugger shows all of its indexes.
		I assume it has something to do with the program not being able to tell where the array ends, but if that is the case, then how do dynamic arrays work? 
		I mean I understand that they are created and allotted memory dynamically at run time, but what if that array uses all the continous memory locations 
		available, will the array get copied to a new address with more space available? How will the programmer access the new elements of it then?

I HAVE ALSO UPLOADED THE PROJECT TO GITHUB, CHECK IT OUT HERE: https://github.com/Icedwhisper/ECommerce-CMS
*/
