//
// ������������ ������ �2. �������
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
  /*  cout << "���������� �������: " << leaves_count(root) << endl;
	cout << "������� " << depth_tree(root)<< " "<<endl;
	cout << "���������� ����� " << knot_tree(root,2) << " " << endl;
	cout << "������ " << fat_tree(root) << " " << endl;
	cout << "��������� ����������� "   << endl;
	coppy(root, new_root);
	print_tree(new_root);
	cout << "������ ����� ������� "<< equally(root, new_root) << endl;
	delete_tree(new_root);
	
	new_root = get_tree(4);
	cout << "������ ����� ������� " << equally(root, new_root) << endl;
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