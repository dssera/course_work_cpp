#pragma once
#include "db.h"
#include "User.h"

class UserTreeCollection
{
private:
	class Node
	{
	public:
		User* data;
		Node* left;
		Node* right;

		Node(User* val)
		{
			left = nullptr;
			right = nullptr;
			data = val;
		}
	};
	Node* root;
	int size;
	UserDataBase* db;

	void print_(Node* curr);
	void print_admins_(Node* curr);
	void delete_tree(Node* curr);

	void fill_tree();
	void save_in_file();
	void save_in_file_(Node* curr, ofstream& file);

public:
	UserTreeCollection(UserDataBase* db)
	{
		this->root = nullptr;
		this->size = 0;

		this->db = db;
		fill_tree();
	}
	~UserTreeCollection()
	{
		save_in_file();
		delete_tree(root);
	}

	void insert(User* user);
	void print();
	void print_admins();
	User* find(string username);
	void remove(string username);

};

