//
// Created by Fabrizio on 4/11/20.
//

#ifndef LINKEDLIST_LINKEDLIST_HPP
#define LINKEDLIST_LINKEDLIST_HPP

#include <cctype>
#include <ostream>
#include <algorithm>
#include <utility>
#include <vector>

using std::cout,
std::endl,
std::to_string
,std::string,
std::ostream,
std::vector;


namespace utec{
    template< typename T>
    struct node_t{
        T value{};
        node_t* next_ = nullptr;
    };

    inline namespace first{
        template <typename T>
        class LinkedList{
        private:
            typedef size_t type_u;
            typedef node_t<T>* node;
            node_t<T>* head_ = nullptr;
            node_t<T>* tail_ = nullptr;
            type_u size_ = 0;

        public:

            LinkedList()= default;                 //default
            LinkedList(const LinkedList &other);    //copy
            LinkedList &operator=(const LinkedList &other); // assignment
            LinkedList(LinkedList &&other)noexcept;         //move
            LinkedList &operator=(LinkedList &&other) noexcept; // assignment move
            bool empty() const;
            T getValue();

            friend ostream &operator<<(ostream& os, LinkedList &other){
                while (other.head_ != nullptr) {
                        os << other.head_->value << " - ";
                        other.head_ = other.head_->next_;
                        if(other.head_ == nullptr){
                            os<<"nullptr";
                            os<<endl;
                        }
                    }
                return os;
            }



            //DESTRUCTOR
            ~LinkedList();


            //OPERATION ADD

            void push_front(T VALUE);
            void push_back(T VALUE);
            void insert (type_u index,T VALUE);

            //OPERATION REMOVE

            void pop_front();
            void pop_back();
            void erase(type_u size, T VALUE);

            //OPERATION TRAVERSAL

            T& item(type_u index);
            const T& item(type_u index) const;


            type_u size()const;

        };

        template<typename T>
        LinkedList<T>::~LinkedList() {
            for(node_t<T>* c = head_; c != nullptr; ){
                node_t<T>* p = c;
                c = c->next_;
                delete p;
            }
        }

        template<typename T>
        LinkedList<T>::LinkedList(const LinkedList<T> &other){
            while(head_ != nullptr){
                pop_front();
            }
            size_ = other.size_;
            auto node = other.head_;
            while(node != nullptr){
                push_back(node->value);
                node = node->next_;
            }
        }

        template<typename T>
        LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other) {
            /*LinkedList<T> aux(other);
            std::swap(aux.head_, head_);*/
            /*size_ = other.size_;
            if(this == &other)
                return *this;
            for (type_u i = 0; i < this->size_; ++i) {
                pop_back();
            }
            for (type_u i = 0; i < other.size_ ; ++i) {
                push_back(other.item(i));
            }*/
            if(this == &other) return *this;
            size_ = other.size_;
            this->~LinkedList<T>();
            for (int i = 0; i < size_; ++i) {
                push_back(other.item(i));
            }
            size_ = other.size_;
            return *this;
        }

        template<typename T>
        LinkedList<T>::LinkedList(LinkedList<T> &&other) noexcept
        {
            head_ = other.head_;
            tail_ = other.tail_;
            size_ = other.size_;
            other.head_ = nullptr;
            other.tail_ = nullptr;
            other.size_ = 0;
        }

        template<typename T>
        LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&other) noexcept{
            return *this;
        }



        //OPERATION ADD


        template<typename T>
        void LinkedList<T>::push_front(T VALUE) {
            /*
             * auto node = new node_t<T>{value,head_};  AQUI NODE APUNTA AL TAIL O NODO POSTERIOR
             * head_ = node;        AQUI EL HEAD_ APUNTA A NODE(NUEVO NODO) Y ESE ULTIMO YA ESTA APUNTANDO AL TAIL
             * */
            head_ = new node_t<T>{VALUE,head_};     //SE CREA UN NODO Y EL HEAD APUNTA A NODE A TAIL YA HAY DOS NODOS
            if(tail_ == nullptr)
                tail_ = head_;
            size_++;
        }
        template<typename T>
        void LinkedList<T>::push_back(T VALUE) {
            auto last = new node_t<T>{ VALUE, nullptr };
            auto current = head_;
            if (head_ == nullptr)head_ = last;
            while (current->next_ != nullptr)
                current = current->next_;
            current->next_ = last;
            size_++;
        }

        template<typename T>
        void LinkedList<T>::insert(LinkedList::type_u index, T VALUE) {
            auto current = new node_t<T>{VALUE,head_};          // el agregar el value no entendi
            auto store = new node_t<T>{};

            for (size_t i = 0; i < index ; ++i) {
                current = current->next_;
            }
            auto p_node = new node_t<T>{VALUE,current};
            store->next_ = current->next_;
            current->next_ = p_node;
            p_node->next_ = store->next_;
        }

        template<typename T>
        void LinkedList<T>::pop_front() {
            if(head_ == tail_){
                delete head_;
                head_ = tail_ = nullptr;
                size_ = 0;
            }
            else{
                auto next = head_->next_;
                delete head_;
                head_ = next;
                --size_;
            }
        }

        template<typename T>
        void LinkedList<T>::pop_back() {
            auto aux = new node_t<T>{0,head_};
            if(head_ == tail_){
                delete tail_;
                head_ = tail_ = nullptr;
                size_ = 0;
            }
            else{
                for (type_u i = 0; i < size_-1 ; ++i) {
                    aux = aux->next_;
                }
                delete aux;
                aux->next_ = nullptr;
            }
            --size_;
            /*
            auto aux = new node_t<T>{0,head_};
            for (size_t i = 0; i < size_-1 ; ++i) {
                aux = aux->next_;
            }
            aux->next_ = nullptr;

            size_--;
             */
        }

        template<typename T>
        void LinkedList<T>::erase(LinkedList::type_u pos, T VALUE) {
            auto target = new node_t<T>{VALUE,head_};
            auto store = new node_t<T>{};
            auto prev = new node_t<T>{VALUE,head_};

            for (type_u i = 0; i <= pos ; ++i) {
                target = target->next_;
            }

            if(pos == 0 && target->value == VALUE) return pop_front();
            if(pos == size_ && target->value == VALUE) return pop_back();

            if (target->value == VALUE) {
                store->next_ = target->next_;
                delete target;
                target = store;
                for (type_u i = 0; i <= pos - 1; ++i)
                    prev = prev->next_;
                prev->next_ = target->next_;
                --size_;
            }
        }

        template<typename T>
        T &LinkedList<T>::item(LinkedList::type_u index) {
            auto current = head_;
            while(index--)
                current =  current->next_;
            return current->value;
        }

        template<typename T>
        const T &LinkedList<T>::item(LinkedList::type_u index) const {
            auto current = head_;
            while(index--)
                current =  current->next_;
            return current->value;
        }

        template<typename T>
        typename LinkedList<T>::type_u LinkedList<T>::size() const {
            return size_;
        }

        template<typename T>
        bool LinkedList<T>::empty() const {
            return (head_ == nullptr);
        }

        template<typename T>
        T LinkedList<T>::getValue() {
            while(head_ != nullptr) {
                head_ = head_->next_;
                return head_->value;
            }
        }


    }

}



#endif //LINKEDLIST_LINKEDLIST_HPP
