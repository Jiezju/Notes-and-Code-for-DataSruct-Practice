// binary_tree 实现

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

public:
	BST():root_(NULL), count_(0){}
	~BST()
	{
		; // TODO
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
}
