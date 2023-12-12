#include "Container.h"

void TreeCollection::delete_tree(Node* curr)
{
	if (curr)
	{
		delete_tree(curr->left);
		delete_tree(curr->right);
		delete curr;
	}
}

void TreeCollection::print_tree(Node* curr)
{
	if (curr)
	{
		print_tree(curr->left);
		cout << "day:" << curr->data->get_day() << endl;
		cout << "event_name: " << curr->data->get_event_name() << endl;
		print_tree(curr->right);
	}
}

void TreeCollection::fill_tree()
{
	list<Event*> tasks = this->db->get_tasks();

	auto it = tasks.begin();
	while (it != tasks.end())
	{
		insert(*it);
		it = tasks.erase(it);
	}
}

int TreeCollection::get_index(string day)
{
	for (int i = 0; i < days->length(); i++)
	{
		if (day == days[i]) return i + 1;
	}
	return 0;
}

Event* TreeCollection::find_by_event(string event)
{
	// этот метод не работает. Он делает обход по ключу event_name но дерево отсортированно по другосу ключу

	Node* curr = this->root;
	Event* result = nullptr;
	while (curr)
	{
		if (curr->data->get_event_name().find(event) != string::npos)
		{
			result = curr->data;
			return result;
		}
		if (curr->data->get_event_name() > event)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return result;
}


void TreeCollection::insert(Event* task)
{
	Node* curr = new Node(task);

	if (this->root == nullptr) {
		this->root = curr;
		size++;
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
}

void TreeCollection::print()
{
	print_tree(this->root);
	cout << endl;
}

void TreeCollection::remove(string day)
{
	Node* curr = this->root;
	Node* parent = nullptr;

	while (curr && get_index(curr->data->get_day()) != get_index(day))
	{
		parent = curr;
		if (get_index(curr->data->get_day()) > get_index(day))
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
			remove(replace_value->get_day());
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
	remove(replace_value->get_day());
	curr->data = replace_value;
}
// delete and create method with tree traversal and if statement
list<Event*> TreeCollection::get_tasks()
{
	return db->get_tasks();
}
void TreeCollection::delete_by_id_(Node* parent, Node* curr, string event_name)
{
	if (curr)
	{
		delete_by_id_(curr, curr->left, event_name);
		delete_by_id_(curr, curr->right, event_name);

		if (curr->data->get_event_name() == event_name)
		{
			if (curr == root)
			{
				if (curr->left == nullptr && curr->right == nullptr)
				{
					delete curr->data;
					delete curr;
					root = nullptr;

					--size;
					return;
				}
				else if (curr->left == nullptr)
				{
					root = curr->right;
					delete curr;

					--size;
					return;
				}
				else if (curr->right == nullptr)
				{
					root = curr->left;
					delete curr;

					--size;
					return;
				}
				else
				{
					Node* replace = curr->right;
					while (replace->left)
						replace = replace->left;

					Event* replace_value = replace->data;
					delete_by_id_(curr, curr->right, replace_value->get_event_name());
					curr->data = replace_value;

					--size;
					return;
				}
			}
			else
			{
				if (curr->left == nullptr && curr->right == nullptr)
				{
					delete curr->data;
					delete curr;

					if (parent->left == curr)
						parent->left = nullptr;
					else if (parent->right == curr)
						parent->right = nullptr;

					--size;
					return;
				}
				else if (curr->left == nullptr)
				{
					if (parent->left == curr)
						parent->left = curr->right;
					else if (parent->right == curr)
						parent->right = curr->right;

					delete curr;

					--size;
					return;
				}
				else if (curr->right == nullptr)
				{
					if (parent->left == curr)
						parent->left = curr->left;
					else if (parent->right == curr)
						parent->right = curr->left;

					delete curr;

					--size;
					return;
				}
				else
				{
					Node* replace = curr->right;
					while (replace->left)
						replace = replace->left;
					Event* replace_value = replace->data;
					delete_by_id_(curr, curr->right, replace_value->get_event_name());
					curr->data = replace_value;

					--size;
					return;
				}
			}
		}
	}
}

void TreeCollection::delete_by_event_name(string event_name)
{
	delete_by_id_(nullptr, root, event_name);
}