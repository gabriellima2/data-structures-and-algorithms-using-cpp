#include <iostream>;
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
	Node(T data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

template <typename T>
class BinarySearchTree
{
private:
	Node<T>* root;

public:
	BinarySearchTree();
	Node<T>* get_root();
	void set_root(Node<T>* node);
	void pre_order(Node<T>* node);
	void in_order(Node<T>* node);
	void pos_order(Node<T>* node);
	Node<T>* insert(Node<T>* root, T data);
	Node<T>* remove(Node<T>* root, T data);
	Node<T>* search(Node<T>* root, T data);
	Node<T>* min_node(Node<T>* node);
	Node<T>* max_node(Node<T>* node);
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	this->root = nullptr;
}

template <typename T>
Node<T>* BinarySearchTree<T>::get_root()
{
	return this->root;
}

template <typename T>
void BinarySearchTree<T>::set_root(Node<T>* node)
{
	this->root = node;
}

template <typename T>
void BinarySearchTree<T>::pre_order(Node<T>* root)
{
	if (root == nullptr) return;
	cout << root->data << endl;
	pre_order(root->left);
	pre_order(root->right);
}

template <typename T>
void BinarySearchTree<T>::in_order(Node<T>* root)
{
	if (root == nullptr) return;
	in_order(root->left);
	cout << root->data << endl;
	in_order(root->right);
}

template <typename T>
void BinarySearchTree<T>::pos_order(Node<T>* root)
{
	if (root == nullptr) return;
	pos_order(root->left);
	pos_order(root->right);
	cout << root->data << endl;
}

template <typename T>
Node<T>* BinarySearchTree<T>::insert(Node<T>* root, T data)
{
	if (root == nullptr)
	{
		return new Node<T>(data);
	}
	if (data < root->data)
	{
		root->left = this->insert(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = this->insert(root->right, data);
	}
	return root;
}

template <typename T>
Node<T>* BinarySearchTree<T>::search(Node<T>* root, T data)
{
	if (root == nullptr) return NULL;
	if (data == root->data) {
		return root;
	}
	else if (data < root->data)
	{
		return this->search(root->left, data);
	}
	else if (data > root->data)
	{
		return this->search(root->right, data);
	}
}

template <typename T>
Node<T>* BinarySearchTree<T>::remove(Node<T>* root, T data)
{

	if (root == nullptr) return nullptr;
	if (data < root->data)
	{
		root->left = this->remove(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = this->remove(root->right, data);
	}
	// Se for o dado à remover, temos 3 casos de remoção
	else
	{
		// O nó não tem filhos: Remoção simples e retorna nulo.
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			return nullptr;
		}
		// O nó tem um filho: remove o nó e retorna o filho como a nova raiz desse nó(sub-árvore)
		else if (root->left == nullptr || root->right == nullptr)
		{
			Node<T>* node_temp = (root->left != nullptr) ? root->left : root->right;
			delete root;
			return node_temp;
		}
		// O nó tem dois filhos: encontra o sucessor(valor min na direita) ou seu predecessor
		// (valor max na esquerda), copia o valor para a raiz e exclui o nó sucessor ou predecessor
		else {
			Node<T>* node_temp = this->min_node(root->right);
			root->data = node_temp->data;
			root->right = this->remove(root->right, node_temp->data);
		}
	}
	return root;
}

template <typename T>
Node<T>* BinarySearchTree<T>::min_node(Node<T>* node)
{
	// Itera até o último da esquerda que é o menor valor na árvore.
	while (node != nullptr && node->left != nullptr)
	{
		node = node->left;
	}
	return node;
}

template <typename T>
Node<T>* BinarySearchTree<T>::max_node(Node<T>* node)
{
	// Itera até o último da direita que é o maior valor na árvore.
	while (node != nullptr && node->right != nullptr)
	{
		node = node->right;
	}
	return node;
}

int main()
{
	BinarySearchTree<int> numbers;
	numbers.set_root(new Node<int>(99));
	Node<int>* root = numbers.get_root();
	numbers.insert(root, 2);
	numbers.insert(root, 1);
	numbers.insert(root, 5);
	numbers.insert(root, 4);
	numbers.insert(root, 8);

	//cout << numbers.max_node(root)->data << endl;
	//cout << numbers.min_node(root)->data;
	numbers.remove(root, 5);
	numbers.in_order(root);
	return 0;
}
