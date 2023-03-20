#include <iostream>;
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
	Node(T data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

template <typename T>
class Tree
{
private:
	Node<T>* root;

public:
	Tree();
	Node<T>* get_root();
	void set_root(Node<T>* node);
	Node<T>* insert_left(Node<T>* root, Node<T>* node);
	Node<T>* insert_right(Node<T>* root, Node<T>* node);
	void pre_order(Node<T>* root);
	void in_order(Node<T>* root);
	void pos_order(Node<T>* root);
	int size(Node<T>* root);
	int height(Node<T>* root);
};

template <typename T>
Tree<T>::Tree()
{
	this->root = nullptr;
}

template <typename T>
Node<T>* Tree<T>::get_root()
{
	return this->root;
}

template <typename T>
void Tree<T>::set_root(Node<T>* node)
{
	this->root = node;
}

template <typename T>
Node<T>* Tree<T>::insert_left(Node<T>* root, Node<T>* node)
{
	if (node == nullptr) return root;
	if (root == nullptr)
	{
		root = node;
		return root;
	}
	// O resultado da chamada recursiva � atribuido ao n� da esquerda do n� raiz, assim fazendo uma liga��o.
	root->left = this->insert_left(root->left, node);
	// Necess�rio para manter a liga��o com os n�s anteriores e poder modificar a �rvore original.
	return root;
}

template <typename T>
Node<T>* Tree<T>::insert_right(Node<T>* root, Node<T>* node)
{
	if (node == nullptr) return root;
	if (root == nullptr)
	{
		root = node;
		return root;
	}
	root->right = this->insert_right(root->right, node);
	return root;
}

template <typename T>
void Tree<T>::pre_order(Node<T>* root)
{
	if (root == nullptr) return;
	cout << root->data << endl;
	pre_order(root->left);
	pre_order(root->right);
}

template <typename T>
void Tree<T>::in_order(Node<T>* root)
{
	if (root == nullptr) return;
	in_order(root->left);
	cout << root->data << endl;
	in_order(root->right);
}

template <typename T>
void Tree<T>::pos_order(Node<T>* root)
{
	if (root == nullptr) return;
	pos_order(root->left);
	pos_order(root->right);
	cout << root->data << endl;
}

template <typename T>
int Tree<T>::size(Node<T>* root)
{
	if (root == nullptr) return 0;
	// Soma 1 � chamada recursiva para cada dire��o. Essas chamadas retornam os tamanhos das sub�rvores esq. e dir. 
	return 1 + size(root->left) + size(root->right);
}

template <typename T>
int Tree<T>::height(Node<T>* root)
{
	if (root == nullptr) return 0;
	// Soma 1 ao retorno da fun��o max. Essa fun��o (max) retorna o maior valor entre dois elementos.
	// Ent�o, ela ir� verificar qual valor � maior, entre as chamadas recursivas de cada dire��o.
	return 1 + max(height(root->left), height(root->right));
}


int main()
{
	Tree<int> numbers;
	numbers.set_root(new Node<int>(99));

	numbers.set_root(numbers.insert_left(numbers.get_root(), new Node<int>(2)));
	numbers.set_root(numbers.insert_left(numbers.get_root(), new Node<int>(7)));
	numbers.set_root(numbers.insert_left(numbers.get_root(), new Node<int>(1)));

	numbers.set_root(numbers.insert_right(numbers.get_root(), new Node<int>(12)));
	numbers.set_root(numbers.insert_right(numbers.get_root(), new Node<int>(15)));
	numbers.set_root(numbers.insert_right(numbers.get_root(), new Node<int>(11)));

	return 0;
}