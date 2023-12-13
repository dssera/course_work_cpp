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
	void delete_tree(Node* curr);

	void fill_tree();

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
		delete_tree(root);
	}

	void insert(User* user);
	void print();
	void remove(string day);

};

