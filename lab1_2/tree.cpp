//
// Лабораторная рвбота №2. Деревья
// tree.cpp
//
#include <stdlib.h>
#include <iostream>
#include "crtdynmem.h"
#include "tree.h"
#include <algorithm>

tree *get_tree(const size_t count)
{
    tree *root = nullptr;
    tree::datatype x;
    size_t n = 0;
    while (count > n && std::cin >> x) {
        insert(root, x);
        n += 1;
    }
    return root;
}

void insert(tree *&root, tree::datatype x)
{
    if (root == nullptr) {
        root = new tree;
        root->data = x;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        if (rand() % 2 == 0)  // вставляем элемент в случайное поддерево
            insert(root->left, x);
        else
            insert(root->right, x);
    }
}

void delete_tree(tree *&root)
{
    if (root == nullptr) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = nullptr;
}

void print_tree(const tree *root, size_t space)
{
    if (root == nullptr) return;
    print_tree(root->left, space+1);
    for (int i = 0; i < space; i++) std::cout << '\t';
    std::cout << root->data << std::endl;
    print_tree(root->right, space+1);
}

size_t leaves_count(const tree *root)
{
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) 
        return 1;
    return leaves_count(root->left) + leaves_count(root->right);
}



size_t depth_tree(tree * root)
{
	if(!root) return size_t(0);
	return std::max(depth_tree(root->right), depth_tree(root->left)) + 1;
}

size_t knot_tree(tree * root, size_t i, size_t level)
{	
	if (!root) return size_t(0);
	if (level != i) return knot_tree(root->right, i, 1+level) + knot_tree(root->left, i, 1+level);
	return 1;
}

size_t fat_tree(tree * root)
{
	size_t depth = depth_tree(root);
	size_t fat, fat_max = 0;
	for (int i = 1; i <= depth; ++i)
	{	
		fat = knot_tree(root, i);
		if (fat_max < fat) fat_max = fat;
	}
	return size_t(fat_max);
}

void coppy(tree * root, tree *&  new_root)
{
	if (root == nullptr)
	{
		new_root = nullptr;
		return;
	}
	tree *p = new tree;

	p->data = root->data;
	p->left = nullptr;
	p->right = nullptr;
	 new_root = p;
	coppy(root->left, new_root->left);
	coppy(root->right, new_root->right);
	
}

bool equally(tree * root, tree * new_root)
{
	if (!root && !new_root) return true;
	if (root && new_root)
		return root->data == new_root->data && equally(root->left, new_root->left)
		&& equally(root->right, new_root->right);
	return false;
}

void sozd(tree *&root, tree::datatype x)
{
	if (root == nullptr) {
		root = new tree;
		root->data = x;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		if (root->data > x)
			if (!root->left)
				insert(root->left, x);
			else
				sozd(root->left, x);
		else
			if (!root->right)
			insert(root->right, x);
			else
				sozd(root->right, x);
	}
}

tree * tree_p(const size_t count)
{
	tree *root = nullptr;
	tree::datatype x;
	size_t n = 0;
	while (count > n && std::cin >> x) {
		sozd(root, x);
		n += 1;
	}
	return root;
}

void vivod(tree * root, bool a)
{
	if (a)
		if (root) 
		{	vivod(root->left, a);
			std::cout << root->data << " ";
			vivod(root->right, a);
			
			
		}
		else;
	else
		if (root)
		{
			vivod(root->right, a);
			std::cout << root->data << " ";
			vivod(root->left, a);
		}

		

	
}

tree * google(tree * root, int a)
{
	if (root)
	{
		
	
		if (root->data == a) return root;
		if ( root->data >a && root->left != nullptr) return google(root->left, a);
		if (root->data <=a && root->right!= nullptr) return google(root->right, a);
		/*if (!root->left) google(root->left, a);
		if (!root->right) google(root->right, a);
		*/
	}
	return nullptr;
}


tree * googlePred(tree * root, int a)
{
	if (root)
	{
		
		if (root->right->data == a) return root;
		if (root->left->data == a) return root;
		if (root->data > a && root->left != nullptr) return google(root->left, a);
		if (root->data <= a && root->right != nullptr) return google(root->right, a);
		/*if (!root->left) google(root->left, a);
		if (!root->right) google(root->right, a);
		*/
	}
	return nullptr;
}





tree * googleCtrV1(tree *& root, int a) //вспомогательная функция 
{
	if (root->left == nullptr  && root->data > a)
	{
		insert(root->left, a);
		return root->left;
	}
	if (root->right == nullptr  && root->data <= a)
	{
		insert(root->right, a);
		return root->right;
	}
	if (a >= root->data) return googleCtrV1(root->right, a);
	return googleCtrV1(root->left, a);
}

tree * googleCtrV(tree *& root, int a)
{
	tree *x = google(root, a);
	if (x!=nullptr) return(x);
	return googleCtrV1(root, a);

}



void googledelet(tree *&root, int a)
{
	tree *pred = googlePred(root, a);
	tree *x = google(root, a);


	if (!x->left && !x->right) // это правильно в дебаге показывает что элемента нету на примере 4 2 5
	{
		x = nullptr; delete x;
		if (pred->right->data == a) pred->right = nullptr;
		else
			pred->left = nullptr;
		return;
	}

	if (x->left == nullptr && x->right != nullptr)
	{
		if (pred->right->data == a) pred->right = x->right;
		else
		if (pred->left->data == a) pred->left = x->right;
		x = nullptr; delete x;
		return;
	}
	else
	if (x->left!=nullptr && x->right==nullptr)
	{
		if (pred->right->data == a) pred->right = x->left;
		else
		if (pred->left->data == a) pred->left = x->left;
		x = nullptr; delete x;
		return;
	}

	if (x->left != nullptr && x->right != nullptr)
	{
		tree *f = x->right;
		tree *pred = x->right;
		while (f->left->left != nullptr)
		{	pred = pred->left;
			f = f->left; //идем влево до конца чтобы взять самый маленикий из больших элементов
			
		}
		f = f->left;
		if (f->right == nullptr)
		{
			x->data = f->data;
			pred->left=nullptr;
			
			f = nullptr; delete f;
			return;
		}
		else
		{
			pred->left = f->right;
			x->data = f->data;
			f = nullptr; delete f;
			return;
		}
	}

}


