/**
 * LinkedVector.hpp
 *
 * Copyright 2018 Joseph Dubill (jwdubill@buffalo.edu)
 *
 * This work is licensed under the Creative Commons 
 * Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/4.0/.
 *
 * Submission by
 * UBIT: jwdubill
 * Person#: 50239013
 */

#ifndef _LINKED_VECTOR_HPP_
#define _LINKED_VECTOR_HPP_

#include "vNode.hpp"
#include <cmath>


template<typename T>
class LinkedVector {
    cse250::vNode<T>* head = NULL;
    cse250::vNode<T>* tail = NULL;
public:

    /**
     * LinkedVector Iterator class.
     */
    class Iterator;

    /**
     * Constructor: construct an empty LinkedVector.
     */
    LinkedVector();
    
    /**
     * Destructor: cleanup any allocated memory.
     */
    ~LinkedVector();

    /**
     * Insert the given value in increasing order.
     * @param value the value to insert.
     * @return true if value is inserted and false if it is already present.
     */
    bool insert(const T& value);

    /**
     * Find the given value.
     * @param value the value to find.
     * @return an iterator at the value, if present, and end if not present.
     */
    LinkedVector<T>::Iterator find(const T& value) const;

    /**
     * Erase a value from the data storage.
     * @param value the value to remove.
     * @return true if the value was removed and false otherwise.
     */
    bool erase(const T& value);

    /**
     * Return the number of items currently stored.
     * @return the number of items currently stored.
     */
    std::size_t size() const;

    /**
     * Create an Iterator to the beginning of the stored sequence.
     * @return an Iterator to the beginning of the sequence.
     */
    LinkedVector<T>::Iterator begin() const;

    /**
     * Create an Iterator to just past the end of the sequence.
     * @return an Iterator that represents the position just past the end
     *         of the sequence.
     */
    LinkedVector<T>::Iterator end() const;

private:
    /**
     * Rebalance the loaded values within each node to satisfy the necessary
     * load-balance criteria.
     */
    void rebalance();
    int _size;
    int numNodes;
};//LinkedVector


template <typename T>
LinkedVector<T>::LinkedVector() {
    // TODO: FINISH THIS METHOD
    std::vector<T> start;
    head = new cse250::vNode<T>();
    tail = head;
    head->data = start;
    numNodes = 1;
    _size = 0;
}


template <typename T>
LinkedVector<T>::~LinkedVector() {
    //TODO: FINISH THIS METHOD
    bool flagg = true;
    while(flagg){
        if (head->next != NULL) {
            cse250::vNode<T>* temp1 = head->next;
            delete head;
            head = temp1;
            temp1 = NULL;
        }else {
            flagg = false;
            delete head;
            head = NULL;
        }
        tail = NULL;
    }
}


template <typename T>
bool LinkedVector<T>::insert(const T& value) {
    // TODO: FINISH THIS METHOD
    bool flag = true;
    cse250::vNode<T>* trav = head;
    while (trav->data.size() == 0 && trav->next != NULL) {
           trav = trav->next;
    }
    if (_size == 0){
        trav->data.push_back(value);
        _size = _size +1;
        if (trav->data.size() > (10 * numNodes)) { this->rebalance(); }
        return true;
    }
    if (numNodes == 1){
        for (auto i =  head->data.begin(); i < head->data.end(); i++){
            if (value == *i){
                return false;
            }
            if (value < *i){
                head->data.insert(i, value);
                _size = _size + 1;
                if (head->data.size() > (10 * numNodes)){ this->rebalance(); }
                return true;
            }
        }
        head->data.push_back(value);
        _size = _size +1;
        if (head->data.size() > (10 * numNodes)) { this->rebalance();}
        return true;

    }
    while (flag){
        if ((*trav->data.begin() < value || *trav->data.begin() == value) && (value < trav->data.back() || value == trav->data.back())) {
    for (auto i = trav->data.begin(); i < trav->data.end(); i++) {//startFOR
            if (value == *i) {
                return false;
            }
            if (value < *i) {
                   /* if (i == trav->data.begin() && trav->prev != NULL) {
                        if (trav->data.size() >= trav->prev->data.size()) {//checks front vs prev back placment based on node size
                            trav = trav->prev;
                            trav->data.push_back(value);
                            _size = _size + 1;
                        }

                        else if (trav->data.size() < trav->prev->data.size()){
                            trav->data.insert(i, value);
                            _size = _size + 1;
                        }
                        if (trav->data.size() > (10 * numNodes)) { this->rebalance(); }
                        return true;
                    }
                    */
                // Below is the normal insertion code -
                trav->data.insert(i, value);
                _size = _size + 1;
                    if (trav->data.size() > (10 * numNodes)){ this->rebalance(); }
                return true;
            }
    } //endFOR
    } //solves iterator issue where it inserted because of empty nodes
    // might not need code below might idk i think i fixed it above with putting the two iffs for back placement together

    if (value < *trav->data.begin()) { // checks front and back placment UPDATED
        if (trav->prev != NULL && trav->prev->data.size() <= trav->data.size()){
            trav = trav->prev;
            trav->data.push_back(value);
            _size = _size + 1;
            if (trav->data.size() > (10 * numNodes)) {
                this->rebalance();
            }
            return true;
        }
        trav->data.insert(trav->data.begin(), value);
        _size = _size + 1;
        if (trav->data.size() > (10 * numNodes)) {
            this->rebalance();
        }
        return true;
    }

    if (trav->next == NULL){// if the next node is null, this places it at the end of the first
        trav->data.push_back(value);
        _size = _size + 1;
        if (trav->data.size() > (10 * numNodes)){ this->rebalance(); }
        return true;
    }

    trav = trav->next;
    while (trav->data.size() == 0) {
        if (trav->next != NULL) {
            trav = trav->next;
        }else{
            trav->data.push_back(value);
            _size = _size + 1;
            if (trav->data.size() > (10 * numNodes)){ this->rebalance(); }
            return true;
        }
    }

}//endWHILE
    return false;
}

template <typename T>
typename LinkedVector<T>::Iterator LinkedVector<T>::find(const T& value) const {
    // TODO: FINISH THIS METHOD
    LinkedVector<T>::Iterator retVal = this->begin();
    retVal.makeValueIterator(value);
    return retVal;
}

template <typename T>
bool LinkedVector<T>::erase(const T& value) {
    // TODO: FINISH THIS METHOD
    if (_size == 0){return false;}

    bool flag = true;
    cse250::vNode<T> * trav = head;
    while (trav->data.size() == 0){
        trav = trav->next;
    }
    while (flag){
        if ((*trav->data.begin() < value || *trav->data.begin() == value) && (value < trav->data.back() || value == trav->data.back())){
            typename std::vector<T>::const_iterator IT = std::lower_bound(trav->data.begin(), trav->data.end(), value);
            if (*IT == value){
                trav->data.erase(IT);
                _size = _size - 1;
                return true;
            }else{
                return false;
            }

        }else{
            if (trav->next != NULL){
                trav = trav->next;
                while (trav->data.size() == 0){
                    if (trav->next != NULL){
                        trav = trav->next;
                    }else{
                        return false;
                    }
                }
            }
            else{
                return false;
            }
        }
    }return false;
}

template <typename T>
std::size_t LinkedVector<T>::size() const {
    // TODO: FINISH THIS METHOD
    return _size;
}

template <typename T>
typename LinkedVector<T>::Iterator LinkedVector<T>::begin() const {
    // TODO: FINISH THIS METHOD
    LinkedVector<T>::Iterator retVal = LinkedVector<T>::Iterator(this);
        return retVal;
}

template <typename T>
typename LinkedVector<T>::Iterator LinkedVector<T>::end() const {
    // TODO: FINISH THIS METHOD
    LinkedVector<T>::Iterator retVal = LinkedVector<T>::Iterator(this);
    retVal.getEndIterator();
    return retVal;
}

template <typename T>
void LinkedVector<T>::rebalance() {
    // TODO: FINISH THIS METHOD
    numNodes = std::floor(std::sqrt(_size)) + 1;
    int extraCount = std::fmod(_size, numNodes);
    int per = (_size - extraCount)/(numNodes);
    cse250::vNode<T>* newHead = new cse250::vNode<T>();
    std::vector<T> newData;
    auto i = this->begin();
    cse250::vNode<T>* prev = newHead;
    cse250::vNode<T>* newNode2 = NULL;
    for (int k = 1; k<=numNodes; k++) {
            if (k == 1) {
                for (int a = 0; a < per + 1; a++) {
                    newData.push_back(*i);
                    i.operator++();
                }
                newHead->data = newData;
                prev = newHead;
            }else if (k <= extraCount){
                std::vector<T> newData2;
                for (int b = 0; b < per + 1; b++){
                    newData2.push_back(*i);
                    i.operator++();
                }
                cse250::vNode<T>* newNode = new cse250::vNode<T>();
                newNode->data = newData2;
                prev->next =  newNode;
                newNode->prev = prev;
                prev = newNode;
             }else {
                std::vector<T> newData3;
                for (int c = 0; c < per; c++){
                    newData3.push_back(*i);
                    i.operator++();
                 }
            newNode2 = new cse250::vNode<T>();
            newNode2->data = newData3;
            prev->next = newNode2;
            newNode2->prev = prev;
            prev = newNode2;
        }
        if (k == numNodes){
            tail = newNode2;
        }
    }
    bool flagg = true;
    while(flagg){
        if (head->next != NULL) {
            cse250::vNode<T>* temp1 = head->next;
            delete head;
            head = temp1;
            temp1 = NULL;
        }else {
            flagg = false;
            delete head;
            head = NULL;
        }
    }
    head = newHead;
}

/**
 * Iterator class for the LinkedVector.
 *
 * Suggested: define Iterator functionality within class definition.
 */
template <typename T>
class LinkedVector<T>::Iterator {
    const LinkedVector<T>* associatedContainer = NULL;
    const T* position = NULL;
    cse250::vNode<T>* currentNode = NULL;
    typename  std::vector<T>::const_iterator it;
    int index;
    
    /**
     * Default constructor for Iterator is made private since we cannot have an
     * iterator without an associated container.
     */
    Iterator() { }

public:
    /**
     * Constructor: setup iterator.
     */
    Iterator(const LinkedVector<T>* container) {
        // TODO: FINISH THIS METHOD
        associatedContainer = container;
        currentNode = associatedContainer->head;
        while (currentNode->data.size() == 0 && currentNode->next != NULL){
                currentNode = currentNode->next;
        }
        it = currentNode->data.begin();
        position = &(*it);
        if (associatedContainer->size() == 0){
            position = NULL;
        }

        index = 0;
    }

    Iterator makeValueIterator(const T& value) {
        bool flaggy = true;
        index = 0;
        currentNode = associatedContainer->head;
        if (associatedContainer->size() == 0){ // handles an Empty List;
            this->getEndIterator();
            return *this;
        }
        while (currentNode->data.size() == 0){ // if the first node is empty, shifts to the next node
            currentNode = currentNode->next; // no need to worry about NULL because code above guarentees next node not null
        }
        while (flaggy == true) {
            if ((*currentNode->data.begin() < value || value == *currentNode->data.begin()) &&
                (value < currentNode->data.back() || value == currentNode->data.back())) {
               it = std::lower_bound(currentNode->data.begin(), currentNode->data.end(), value);
               if (it != currentNode->data.end() &&  *it == value) {
                   auto var = it - currentNode->data.begin();
                   index = var;
                   position = &(*it);
                   return *this;
               }
            }
            else {
                if (currentNode->next != NULL) {
                    currentNode = currentNode->next;
                    index = 0;
                    while (currentNode->data.size() == 0) {
                        if (currentNode->next != NULL) {
                            currentNode = currentNode->next;
                        }else{
                            this->getEndIterator();
                            return *this;
                        }
                    }
                }else{
                  this->getEndIterator();
                    flaggy = false;
                    return *this;
                }
            }
        }
        this->getEndIterator();
        return *this;
    }
    /**
     * Destructor: cleanup iterator. Remove if not used.
     */
    ~Iterator() {
        associatedContainer = NULL;
        currentNode = NULL;
        position = NULL;
    }


    /**
     * Return a copy of the value at the position held by the
     * iterator.
     * @return a copy of the value at the position held by the iterator.
     */
    T operator*() {
        return *(this->position);
    }

    /**
     * Prefix operator++
     * @return reference to this after incrementing position.
     */
    Iterator& operator++() {
        // TODO: FINISH THIS METHOD
        if (index == currentNode->data.size()-1){
            if (currentNode->next == NULL){
                this->getEndIterator();
                return *this;
            }
            currentNode = currentNode->next;
            while (currentNode->data.size() == 0){
                if (currentNode->next != NULL) {
                    currentNode = currentNode->next;
                }else{
                    this->getEndIterator();
                    return *this;
                }
            }
            it = currentNode->data.begin();
            position = &(*it);
            index = 0;
            return *this;
        }else{
            ++it;
            index++;
            position = &(*it);
        }

        return *this;
    }


    // returns iterator to the end passed
    Iterator getEndIterator(){
        position = NULL;
        return *this;
    }
    /**
     * Postfix operator++
     * @return copy of iterator before incrementing position.
     */
    Iterator operator++(int) {
        // Don't change this code.
        Iterator copy(*this);
        ++(*this);
        return copy;
    }

    /**
     * Compare equality of two iterators.
     * @param rhs is an iterator being compared with this iterator.
     * @return true if they represent the same position in the same container and false otherwise.
     */
    bool operator==(const Iterator& rhs) const {
        // TODO: FINISH THIS METHOD
        if (rhs.position == position){
            return true;
        }

        return false;
    }

    /**
     * Compare inequality of two iterators.
     * @param rhs is an iterator being compared with this iterator.
     * @return false if they represent the same position in the same container and true otherwise.
     */
    bool operator!=(const Iterator& rhs) const {
        return !(*this == rhs);
    }
};//LinkedVector::Iterator


#endif //_LINKED_VECTOR_HPP_