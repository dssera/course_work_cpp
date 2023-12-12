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

	void print_tree(Node* curr);
	void print_tree_by_day(Node* curr, string day);

	void find_by_event_name_(Node* curr, string event_name);
	Event* get_by_event_name_(Node* curr, string event_name);

	void delete_tree(Node* curr);
	void delete_by_id_(Node* parent, Node* curr, string event_name);

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

	void find_by_event_name(string event_name);
	Event* get_by_event_name(string event_name);
	
	void insert(Event* task);

	void print();
	void print_by_day(string day);


	void remove(string day);
	// delete and create method with tree traversal and if statement
	list<Event*> get_tasks();

	void delete_by_event_name(string event_name);



};

