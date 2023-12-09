﻿#pragma once
#include "db.h"
#include "User.h"
#include "Event.h"


class TreeCollection
{
private:
	string days[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
	class Node
	{
	public:
		Event* data;
		Node* left;
		Node* right;
	
		Node(Event* val)
		{
			left = nullptr;
			right = nullptr;
			data = val;
		}
	};
	Node* root;
	int size;
	TaskDataBase* db;


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
			cout << "id:" << curr->data->get_id() << endl;
			cout << "day:" << curr->data->get_day() << endl;
			print_tree(curr->right);
		}
	}

	void fill_tree()
	{
		list<Event*> tasks = this->db->get_tasks();

		auto it = tasks.begin();
		while (it != tasks.end())
		{
			insert(*it);
			it = tasks.erase(it);
		}
	}

	int get_index(string day)
	{
		for (int i = 0; i < days->length(); i++)
		{
			if (day == days[i]) return i + 1;
		}
		return 0;
	}
public:

	TreeCollection(string username)
	{
		this->root = nullptr;
		this->size = 0;

		this->db = new TaskDataBase("task_db.txt", username);
		fill_tree();
	}

	~TreeCollection()
	{
		delete_tree(root);
	}

	Event* find_by_event(string event)
	{
		Node* curr = this->root;
		Event* result = nullptr;
		while (curr)
		{
			if (curr->data->get_event().find(event) != string::npos)
			{
				result = curr->data;
				return result;
			}
			if (curr->data->get_event() > event)
				curr = curr->left;
			else
				curr = curr->right;
		}
		return result;
	}
	Event* find_by_id(int id)
	{
		Node* curr = this->root;
		Event* result = nullptr;
		while (curr)
		{
			if (curr->data->get_id() == id)
			{
				result = curr->data;
				return result;
			}
			if (curr->data->get_id() > id)
				curr = curr->left;
			else
				curr = curr->right;
		}
		return result;
	}
	
	void insert(Event* task)
	{
		Node* curr = new Node(task);

		if (this->root == nullptr) {
			this->root = curr;
			size++;
			curr->data->set_id(size);
			return;
		}

		Node* currNode = root;
		while (true) {
			if (get_index(task->get_day()) <= get_index(currNode->data->get_day())) {
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
		size++;
		curr->data->set_id(size);
	}

	void print()
	{
		print_tree(this->root);
		cout << endl;
	}

	void remove(int id)
	{
		Node* curr = this->root;
		Node* parent = nullptr;
		
		while (curr && curr->data->get_id() != id)
		{
			parent = curr;
			if (curr->data->get_id() > id)
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
				delete curr;
				root = nullptr;
			}
			else if (curr->left == nullptr)
			{
				root = curr->right;
				delete curr;
			}
			else if (curr->right == nullptr)
			{
				root = curr->left;
				delete curr;
			}
			else
			{
				Node* replace = curr->right;
				while (replace->left)
					replace = replace->left;

				Event* replace_value = replace->data;
				remove(replace_value->get_id());
				curr->data = replace_value;
			}
			--size;
			return;
		}
		if (curr->left == nullptr)
		{
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
			if (parent && parent->left == curr)
				parent->left = curr->left;
			if (parent && parent->right == curr)
				parent->right = curr->left;
			--size;
			delete curr;
			return;
		}
		Node* replace = curr->right;
		while (replace->left)
			replace = replace->left;
		Event* replace_value = replace->data;
		remove(replace_value->get_id());
		curr->data = replace_value;
	}
	// as static method
	list<Event*> get_tasks()
	{
		return db->get_tasks();
	}
	Event search_by_event()
	{
		//return db.
	}
};

