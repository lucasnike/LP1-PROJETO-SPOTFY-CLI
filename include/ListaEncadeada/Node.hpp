#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
public:
   /// @brief Valor do nó que será armezenado em uma lista
   T value;
   /// @brief Ponteiro para o próximo nó
   Node *next;

   /// @brief Construtor da classe, inicia os valores das propriedades
   /// @param value Valor do nó
   Node(T value)
   {
      this->value = value;
      this->next = nullptr;
   }

   /// @brief Destrutor do nó, desaloca da memória o valor
   ~Node()
   {
      delete value;
   }
};

#endif