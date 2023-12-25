#pragma once
#include "db.h"
#include "Event.h"


class EventTreeCollection
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
	EventDataBase* db;

	void print_(Node* curr);
	void print_by_day_(Node* curr, string day);

	void find_by_event_name_(Node* curr, string event_name);
	Event* get_by_event_name_(Node* curr, string event_name);

	void delete_tree(Node* curr);
	void delete_by_id_(Node* parent, Node* curr, string event_name);

	void save_in_file_(Node* curr, ofstream& file);

	void fill_tree();
	// void save_in_file();

	int get_index(string day);


public:
	EventTreeCollection(string username)
	{
		this->root = nullptr;
		this->size = 0;

		this->db = new EventDataBase("task_db.txt", username);
		fill_tree();
	}
	~EventTreeCollection()
	{
		delete_tree(root);
	}

	void find_by_event_name(string event_name);
	Event* get_by_event_name(string event_name);
	void insert(Event* task);
	void print();
	void print_by_day(string day);
	void remove(string day);
	void delete_by_event_name(string event_name);
	void save_in_file();
};

