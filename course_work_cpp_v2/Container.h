#pragma once
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


	void delete_tree(Node* curr);

	void print_tree(Node* curr);

	void fill_tree();

	int get_index(string day);
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

	Event* find_by_event(string event);
	Event* find_by_id(int id);
	
	void insert(Event* task);

	void print();

	void remove(string day);
	// delete and create method with tree traversal and if statement
	list<Event*> get_tasks();
	void delete_by_id_(Node* parent, Node* curr, string event_name);

	void delete_by_name(string event_name);



};

