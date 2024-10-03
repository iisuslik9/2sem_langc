[Пересланное сообщение]
  Андрей Гребенщиков, вчера в 14:18
  #include <iostream>
  #include <fstream>
  #include <sstream>
  #include <string>
  
  using namespace std;
  //Стркуктура узла бинарного дерева;
  struct TreeNode
  {
      int data;
      TreeNode* left;
      TreeNode* right;
  //Конструктор по умолчанию
      TreeNode() : data(0), left(nullptr), right(nullptr) {}
      //Конструктор с параметрами
      TreeNode(int value)
      {
          data = value;
          left = nullptr;
          right = nullptr;
      }
  };
  //Структура бинарного дерева
  struct BinaryTree
  {
      TreeNode* root;
      //Конструктор по умолчанию
      BinaryTree() : root(nullptr) {}
      //Конструктор с параметрами
      BinaryTree(int value)
      {
          TreeNode* node = new TreeNode(value);
          root = node;
      }
      BinaryTree(int value1, int value2, int value3)
      {
          TreeNode* node = new TreeNode(value1);
          root = node;
          node = new TreeNode(value2);
          root->left = node;
          node = new TreeNode(value3);
          root->right = node;
      }
      //Диструктор
      ~BinaryTree()
      {
          if (root != nullptr)
          {
              DestroyTree(root);
          }
          cout « "Дерево удалено!!\n";
          root = new TreeNode();
      }
  
  };
      //Вспомогательная рекурсивная функция для диструктора;
      void DestroyTree(TreeNode* node)
      {
          if (node!=nullptr)
          { 
          DestroyTree(node->left);
          DestroyTree(node->right);
          delete node;
          }
      }
  };
  int main()
  {
      setlocale(LC_ALL, "rus");
  
      BinaryTree tree1(10, 5, 15);
      tree1.~BinaryTree();
      return 0;
  }
