// binary_tree 实现
#include <iostream>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

template<typename Key, typename Value>
class BST
{
private:
	struct Node
	{
		Key key_;
		Value value_;
		Node* left_;
		Node* right_;
		
		// 初始化方法
		Node(Key key, Value value)
		{
			this->key_ = key;
			this->value_ = value;
			this->left_ = NULL;
			this->rchild_ = NULL;
		}
	}
	
	Node* root_;
	int count_;
	
	Node* _insert(Node* node, Key key, Value value)
	{
		if (node == NULL)
		{
			return new Node(key, value);
		}
			
		if (node->key_ == key)
		{
			node->value_ = value;
		}
		else if (node->key_ < key)
			node->right_ = _insert(node->right_, key, value);
		else // node.key_ > key
			node->left_ = _insert(node->left_, key, value);
			
		return node;
	}
	
	bool _contain(Node* node, Key key, Value value)
	{
		if (node == NULL)
			return false;
		
		if (node->key_ == key)
		{
			if (node->value_ == value)
				return true;
			return false;
		}
		else if (node->key_ < key)
			return _contain(node->right_, key, value);
		else // node.key_ > key
			return _contain(node->left_, key, vlaue);		
	}
	
	Value* _search(Node* node, Key key)
	{
		if (node->key_ == key)
			return &node->vlaue_;
		else if (node->key_ < key)
			return _search(node->right_, key);
		else
			return _search(node->left_, key);
	}
	
	void _preorder(Node* node)
	{
		if (node == NULL)
			return;
		
		cout<<node->key_<<endl;
		_preorder(node->left_);
		_preorder(node->right_);
	}
	
	void _inOrder(Node* node)
	{
		if (node == NULL)
		{
			return;
		}
		
		_inOrder(node->left_);
		cout<<node->key_<<endl;
		_inOrder(node->right_);
	}
	
	void _postOrder(Node* node)
	{
		if (node == NULL)
		{
			return;
		}
		
		_postOrder(node->left_);
		_postOrder(node->right_);
		cout<<node->key_<<endl;
	}
	
	// 需要先释放左右子树，才能释放自己
	void _destroy(Node* node)
	{
		if (node == NULL)
			return;
		
		_destroy(node->left_);
		_destroy(node->right_);
		delete node;
		count_--;
	}
	
	Node* _getMin(Node* node)
	{
		if (node->left_ == NULL)
			return node;
		return _getMin(node->left_);
	}
	
	Node* _getMax(Node* node)
	{
		if (node->right_ == NULL)
			return node;
		return _getMax(node->right_);`
	}
	
	Node* _removeMin(Node* node)
	{
		if (node->left_ == NULL)
		{
			Node* newNode = node->right_;
			delete node;
			count_--;
			return newNode;
		}
		
		node->left_ = _removeMin(node->left_);
		
		return node;
	}
	
	Node* _removeMax(Node* node)
	{
		if (node->right_ == NULL)
		{
			Node* newNode = node->left_;
			delete node;
			count_--;
			return newNode;
		}
		
		node->right_ = _removeMax(node->right_);
		return node;
	}
	
	Node* _remove(Node* node, Key key)
	{
		if (node == NULL)
			return node;

		if (node->key_ < key)
			node->right_ = _remove(node->right_, key);
		else if (node->key_ > key)
			node->left_ = _remove(node->left_, key);
		else
		{
			if (node->right_ == NULL)
			{
				Node* leftNode = node->left_;
				delete node;
				count_--;
				return leftNode;
			}
			else if (node->left_ == NULL)
			{
				Node* rightNode = node->right_;
				delete node;
				count_--;
				return rightNode;
			}
			else
			{   // node->left_ == NULL && node->right_ == NULL
				Node* successor = _getMin(node->right_);
				
				Node* newNode_cpy = new Node(successor->key_, successor->value_);
				
				newNode_cpy->left_ = node->left_; 
				newNode_cpy->right = _removeMin(node->right_);
				
				delete node;
				
				return newNode_cpy;
			}
		}
		
		return node;
	}
	
	Node* _floor(Node* node, Key key)
	{	
		if (node == NULL || node->key_ == key)
			return node;
		
		else if (node->key_ > key)
			return _floor(node->left, key);
		else // node->key_ < key
		{
			// node 本身可能就是，继续向右子树找，找不到就返回 node
			Node* t = _floor(node->right, key);
			if (t)
				return t;
			else
				return node;
		}	
	}
	
	Node* _ceil(Node* node, Key key)
	{
		if (node == NULL || node->key_ == key)
		{
			return node;
		}
		else if (node->key_ < key)
		{
			return _ceil(node->right, key);
		}
		else
		{
			Node* t = _ceil(node->left, key);
			if (t)
				return t;
			else:
				return node;
		}
	}

public:
	BST():root_(NULL), count_(0){}
	~BST()
	{
		_destroy(root_);
	}
	
	int size() const { return count_; }
	
	bool isEmpty() const { return count_ == 0; }
	
	bool contain(Key key, Value value)
	{
		return _contain(root_, key, value);
	}
	
	Value* search(Key key)
	{
		return _search(root_, key);
	}
	
	void insert(Key key, Value value)
	{
		root_ = _insert(root_, key, value);
		return;
	}
	
	void preOrder()
	{
		_preorder(root_);
	}
	
	void inOrder()
	{
		_inOrder(root_);
	}
	
	void postOrder()
	{
		_postOrder(root_);
	}
	
	void levelOrder()
	{
		queue<Node*> que;
		que.push(root_);
		
		while (!que.empty())
		{
			Node* node = que.front();
			cout<<node->key_<<endl;
			que.pop();
			
			if (node->left_)
				que.push(node->left_);
			
			if (node->right_)
				que.push(node->right_);
		}
	}
	
	void preOrder_seq()
	{
		stack<Node*> s;
		
		Node* node = root_;
		
		while (node && !s.empty())
		{
			while (node)
			{
				s.push(node);
				cout<<node->key_<<endl;
				node = node->left_;
			}
			
			Node* tmp = s.top();
			s.pop();
		}
		
	}
	
	Key getMin()
	{
		assert(count_ > 0);
		Node* minNode = _getMin(root_);
		return minNode->key_;
	}
	
	Key getMax()
	{
		assert(count_ > 0);
		Node* maxNode = _getMax(root_);
		return maxNode->key_;
	}
	
	void removeMin()
	{
		assert(count_ > 0);
		root_ = _removeMin(root_);
	}
	
	void removeMax()
	{
		assert(count_ > 0);
		root_ = _removeMax(root_);
	}
	
	void remove(Key key)
	{
		root_ = _remove(root_, key);
	}
	
	Key* floor(Key key)
	{
		if (Key < getMin())
			return NULL;
		Node* floorNode =  _floor(root_, key);
		return &(floorNode->key_);
	}
	
	Key* ceil(Key key)
	{
		if (key > getMax())
			return NULL;
			
		Node* ceilNode = _ceil(root_, key);
		return &(ceilNode->key_);
	}
	
};
