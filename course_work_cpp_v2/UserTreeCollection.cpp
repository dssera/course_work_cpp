#include "UserTreeCollection.h"

void UserTreeCollection::print_(Node* curr)
{
	if (curr)
	{
		print_(curr->left);
		print_(curr->right);
		curr->data->print();
		cout << endl;
	}
}
void UserTreeCollection::print_admins_(Node* curr)
{
	if (curr)
	{
		print_admins_(curr->left);
		print_admins_(curr->right);
		if (curr->data->is_admin())
		{
			curr->data->print();
			cout << endl;
		}
	}
}
void UserTreeCollection::delete_tree(Node* curr)
{
	if (curr)	
	{
		delete_tree(curr->left);
		delete_tree(curr->right);
		delete curr;
	}
}

void UserTreeCollection::fill_tree()
{
	User* users = this->db->get_users();

	for (int i = 0; i < this->db->get_user_count(); i++)
	{
		insert(&users[i]);
	}
}

void UserTreeCollection::insert(User* user)
{
	Node* curr = new Node(user);

	if (this->root == nullptr) {
		this->root = curr;
		size++;
		return;
	}

	Node* currNode = root;
	while (true) {
		if (user->get_username() <= currNode->data->get_username()) {
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
User* UserTreeCollection::find(string username) {

	Node* curr = this->root;
	User* result = nullptr;
	while (curr)
	{
		if (curr->data->get_username() == username)
		{
			result = curr->data;
			return result;
		}
		if (curr->data->get_username() > username)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return result;
}
void UserTreeCollection::print()
{
	print_(this->root);
	cout << endl;
}
void UserTreeCollection::print_admins()
{
	print_admins_(this->root);
	cout << endl;
}
void UserTreeCollection::remove(string username)
{
	Node* curr = this->root;
	Node* parent = nullptr;

	while (curr && curr->data->get_username() != username)
	{
		parent = curr;
		if (curr->data->get_username() > username)
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

			User* replace_value = replace->data;
			remove(replace_value->get_username());
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
	User* replace_value = replace->data;
	remove(replace_value->get_username());
	curr->data = replace_value;
}

void UserTreeCollection::save_in_file()
{
	ofstream file(this->db->get_filename(), ofstream::trunc);
	save_in_file_(this->root, file);
	file.close();
}
void UserTreeCollection::save_in_file_(Node* curr, ofstream& file)
{
	if (curr)
	{
		save_in_file_(curr->left, file);
		save_in_file_(curr->right, file);
		file << curr->data->get_username() << ";"
			<< curr->data->get_password() << ";"
			<< curr->data->is_admin() << endl;
	}
}