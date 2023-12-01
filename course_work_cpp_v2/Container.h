#pragma once
#include "db.h"
#include "User.h"
#include "Task.h"


class TreeCollection
{
private:
	class Node
	{
	public:
		Task* data;
		Node* left;
		Node* right;
	
		Node(Task* val)
		{
			left = nullptr;
			right = nullptr;
			data = val;
		}
	};
	void delete_tree(Node* curr)
	{
		if (curr)
		{
			delete_tree(curr->left);
			delete_tree(curr->right);
			delete curr;
		}
	}
	void print_tree(Node* curr)
	{
		if (curr)
		{
			print_tree(curr->left);
			cout << curr->data->get_day() << " ";
			print_tree(curr->right);
		}
	}
	Node* root;
	int size;
	TaskDataBase* db;
public:

	TreeCollection(TaskDataBase* db)
	{
		this->root = nullptr;
		this->size = 0;

		this->db = db;
		fill_tree();
	}

	~TreeCollection()
	{
		delete_tree(root);
	}

	
	Task* find(string day)
	{
		// must me changed because it's simple comparison now
		Node* curr = this->root;
		Task* result = nullptr;
		while (curr)
		{
			if (curr->data->get_day() == day)
			{
				result = curr->data;
				return result;
			}
			if (curr->data->get_day() > day)
				curr = curr->left;
			else
				curr = curr->right;
		}
		return result;
	}
	
	void insert(Task* task)
	{
		/*Node* curr = this->root;
		if (!curr)
		{
			root = new Node(task);
			++size;
			return;
		}
		while (curr && curr->data.get_day() != task.get_day())
		{
			if (curr->data.get_day().length() > task.get_day().length() &&
				curr->left == nullptr)
			{
				curr->left = new Node(task);
				++size;
				return;
			}
			if (curr->data.get_day().length() <= task.get_day().length()
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
		}*/
		Node* curr = new Node(task);

		if (this->root == nullptr) {
			this->root = curr;
			return;
		}

		Node* currNode = root;
		while (true) {
			if (task->get_day().length() <= currNode->data->get_day().length()) {
				if (currNode->left == nullptr) {
					currNode->left = curr;
					break;
				}
				currNode = currNode->left;
			}
			else {
				if (currNode->right == nullptr) {
					currNode->right = curr;
					break;
				}
				currNode = currNode->right;
			}
		}
	}
	void print()
	{
		// обход всегда с самой левой ветки
		print_tree(this->root);
		cout << endl;
	}

	

	void remove(string day)
	{
		Node* curr = this->root;
		Node* parent = nullptr;
		
		while (curr && curr->data->get_day() != day)
		{
			parent = curr;
			if (curr->data->get_day().length() > day.length())
			{
				curr = curr->left;
			}
			else
			{
				curr = curr->right;
			}
		}
		if (!curr)
			return;
		if (curr == root)
		{
			if (curr->left == nullptr && curr->right == nullptr)
			{
				// Tree only has the root node
				delete curr;
				root = nullptr;
			}
			else if (curr->left == nullptr)
			{
				// Replace root with its right child
				root = curr->right;
				delete curr;
			}
			else if (curr->right == nullptr)
			{
				// Replace root with its left child
				root = curr->left;
				delete curr;
			}
			else
			{
				// Node has two children
				Node* replace = curr->right;
				while (replace->left)
					replace = replace->left;

				Task* replace_value = replace->data;
				remove(replace_value->get_day());
				curr->data = replace_value;
			}
			--size;
			return;
		}
		if (curr->left == nullptr)
		{
			// Вместо curr подвешивается его правое поддерево
			if (parent && parent->left == curr)
				parent->left = curr->right;
			if (parent && parent->right == curr)
				parent->right = curr->right;
			--size;
			delete curr;
			return;
		}
		if (curr->right == nullptr)
		{
			// Вместо curr подвешивается его левое поддерево
			if (parent && parent->left == curr)
				parent->left = curr->left;
			if (parent && parent->right == curr)
				parent->right = curr->left;
			--size;
			delete curr;
			return;
		}
		// У элемента есть два потомка, тогда на место элемента поставим
		// наименьший элемент из его правого поддерева
		Node* replace = curr->right;
		while (replace->left)
			replace = replace->left;
		Task* replace_value = replace->data;
		remove(replace_value->get_day());
		curr->data = replace_value;
	}

	void fill_tree()
	{
		list<Task*> tasks = this->db->get_tasks();
		
		auto it = tasks.begin();
		while (it != tasks.end())
		{
			insert(*it);
			it = tasks.erase(it);
		}
	}
};

