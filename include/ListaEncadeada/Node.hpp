#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
public:
   T value;
   Node *next;

   Node(T value)
   {
      this->value = value;
      this->next = nullptr;
   }
   ~Node()
   {
   }
};

#endif