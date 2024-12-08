#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;
class Node
{
public:
	int info;
	Node* left;
	Node* right;
	Node(int data)
	{
		info = data;
		left = nullptr;
		right = nullptr;
	}
};
int getValidInput()
{
	int data;
	while (true)
	{
		if (cin >> data)
		{
			break;
		}
		else
		{
			cout << "Enter a valid integer: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
	}
	return data;
}
Node* buildTree(Node* root)
{
	int data;
	cout << "Enter data(-1 for null): ";
	data = getValidInput();
	root = new Node(data);
	//check if null
	if (data == -1)
	{
		return nullptr;
	}
	cout << "Enter data for left of: " << data << endl;
	root->left = buildTree(root->left);
	cout << "Enter data for right of: " << data << endl;
	root->right = buildTree(root->right);
	//when done return root
	return root;
}
void inorderTraverse(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	inorderTraverse(root->left);
	cout << root->info << " ";
	inorderTraverse(root->right);
}
void preorderTraverse(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->info << " ";
	preorderTraverse(root->left);
	preorderTraverse(root->right);
}
void postorderTraverse(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	postorderTraverse(root->left);
	postorderTraverse(root->right);
	cout << root->info << " ";
}
void clearScreen()
{
#ifdef _WIN32
	 system("cls"); 
#endif
}

void displayMenu() 
{
	cout << "\nEnter \n "<< "1. To Build Tree.\n"<< "2. To Traverse by Preorder.\n"<< "3. To Traverse by PostOrder.\n"<< "4. To Traverse by Inorder.\n"<< "x/X to exit\n"<< "Enter Your Choice: ";
}

int main()
{
	Node* root = nullptr;
	string option;
	do
	{
		clearScreen();
		displayMenu();
		getline(cin, option);
		if (option == "1") {
			if (root != nullptr) 
		   {
				cout << "Tree has already been built. Enter Y/y to build again!"<<endl;
				getline(cin, option);

			}

			if (option == "y" || option == "Y" || root == nullptr) {

				root = buildTree(root);
				cout << "Tree is successfully built!" << endl;
			}
		}
		else if (option == " 2")
		{
			if (root == nullptr)
			{
				
				cout << " Tree has not been built yet!. Please build the tree first." << endl;
			}
			else 
			{
				cout << " \n PreOrder Traversal of current Tree:  ";
				preorderTraverse(root);
				cout << endl;

			}
		}
		else if (option == "3")
		{
			if (root == nullptr)
			{
				cout << " Tree has not been built yet!. Please build the tree first." << endl;
			
			}
			else
			{
				cout << "\nPostOrder Traversal of current Tree: ";

				postorderTraverse(root);
				cout << endl;
			}
		}
		else if (option == "4")
		{
			if (root == nullptr)
			{
				cout << " Tree has not been built yet!. Please build the tree first." << endl;
			}
			else
			{
				cout << "\nInOrder Traversal of current Tree: ";
				inorderTraverse(root);
				cout << endl;
			}
		}
		else if( option == "x" || option  == "X")
		{
			cout << " Exiting program..." << endl;
			break;
		}
		else
		{
			cout << "Invalid Choice! Please try again. " << endl;
		}

		cout << "\nPress Enter to continue...";

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, option);


	} while (option!="x" && option!="X");
}
