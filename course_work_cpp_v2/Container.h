#pragma once
#include "db.h"
#include "User.h"
#include "Task.h"

class Container
{
public:
	// Tree is public for debuging
	
	Container(TaskDataBase* db, User* user)
	{
		this->db = db;
		this->user = user;
		this->collection = new Tree();
		// container can create and initilaze(if there is data) Tree
	}
private:
	
	Tree* collection;
	TaskDataBase* db;
	User* user;
};
class Tree
{
public:
	class Node
	{
	public:
		Task data;
		Node* left;
		Node* right;
		Node(Task val)
		{
			left = nullptr; // В С++11 лучше использовать nullptr
			right = nullptr;
			data = val;
		}
	};
	Node* root;
	int size;

	~Tree()
	{
		delete_tree(root);
	}

	void delete_tree(Node* curr)
	{
		if (curr)
		{
			delete_tree(curr->left);
			delete_tree(curr->right);
			delete curr;
		}
	}
	Tree(Task task)
	{
		
		this->root = new Node(task);
		this->size = 1;
	}
	void insert(Task task)
	{
		Node* curr = root;
		while (curr && curr->data.get_day() != task.get_day())
		{
			if (curr->data.get_day().length() > task.get_day().length() &&
				curr->left == nullptr)
			{
				curr->left = new Node(task);
				++size;
				return;
			}
			if (curr->data.get_day().length() < task.get_day().length()
				&& curr->right == nullptr)
			{
				curr->right = new Node(task);
				++size;
				return;
			}
			if (curr->data.get_day().length() > task.get_day().length())
				curr = curr->left;
			else
				curr = curr->right;
		}
	}
	void print()
	{
		print_tree(root);
		cout << endl;
	}

	void print_tree(Node* curr)
	{
		if (curr) // Проверка на ненулевой указатель
		{
			print_tree(curr->left);
			cout << curr->data << " ";
			print_tree(curr->right);
		}
};

