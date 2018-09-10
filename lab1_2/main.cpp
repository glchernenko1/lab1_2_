//
// Лабораторная работа №2. Деревья
// main.cpp
//
#include <iostream>
#include "tree.h"
#include <clocale>
#include <cstdlib>
#include "crtdynmem.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    tree *root = nullptr;
	tree *new_root = nullptr;
   // print_tree(root);
  /*  cout << "Количество листьев: " << leaves_count(root) << endl;
	cout << "Глубина " << depth_tree(root)<< " "<<endl;
	cout << "Количество узлов " << knot_tree(root,2) << " " << endl;
	cout << "Ширина " << fat_tree(root) << " " << endl;
	cout << "Результат копирования "   << endl;
	coppy(root, new_root);
	print_tree(new_root);
	cout << "Первый равен второму "<< equally(root, new_root) << endl;
	delete_tree(new_root);
	
	new_root = get_tree(4);
	cout << "Первый равен второму " << equally(root, new_root) << endl;
	delete_tree(root);
	delete_tree(new_root);
	*/
	//lab2
	root = tree_p(5);
	print_tree(root);
	//cout << google(root, 2)->data<<endl;
	//cout << googleCtrV(root, 2)->data << endl;
	//print_tree(root);
	//googledelet(root, 6);
	vivod(root, false); 
	print_tree(root);
    _CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}