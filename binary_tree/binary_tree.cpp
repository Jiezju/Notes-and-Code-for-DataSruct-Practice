// binary_tree 实现
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<typename Key, typename Value>
class BST
{
private:
	struct Node
	{
		Key key_;
		Value value_;
		Node* lchild_;
		Node* rchild_;
		
		// 初始化方法
		Node(Key key, Value value)
		{
			this->key_ = key;
			this->value_ = value;
			this->lchild_ = NULL;
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
			node->right = _insert(node->right, key, value);
		else // node.key_ > key
			node->left = _insert(node->left, key, value);
			
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
			return _contain(node->right, key, value);
		else // node.key_ > key
			return _contain(node->left, key, vlaue);		
	}
	
	Value* _search(Node* node, Key key)
	{
		if (node->key_ == key)
			return &node->vlaue_;
		else if (node->key_ < key)
			return _search(node->right, key);
		else
			return _search(node->left, key);
	}
	
	void _preorder(Node* node)
	{
		if (node == NULL)
			return;
		
		cout<<node->key_<<endl;
		_preorder(node->left);
		_preorder(node->right);
	}
	
	void _inOrder(Node* node)
	{
		if (node == NULL)
		{
			return;
		}
		
		_inOrder(node->left);
		cout<<node->key_<<endl;
		_inOrder(node->right);
	}
	
	void _postOrder(Node* node)
	{
		if (node == NULL)
		{
			return;
		}
		
		_postOrder(node->left);
		_postOrder(node->right);
		cout<<node->key_<<endl;
	}
	
	// 需要先释放左右子树，才能释放自己
	void _destroy(Node* node)
	{
		if (node == NULL)
			return;
		
		_destroy(node->left);
		_destroy(node->right);
		delete node;
		count_--;
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
			
			if (node->left)
				que.push(node->left);
			
			if (node->right)
				que.push(node->right);
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
				node = node->left;
			}
			
			Node* tmp = s.top();
			s.pop();
		}
		
	}
	
}
