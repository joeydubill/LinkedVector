/**
 * main.cpp
 *
 * Copyright 2018 Joseph Dubill (jwdubill@buffalo.edu)
 *
 * This work is licensed under the Creative Commons 
 * Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/4.0/.
 *
 * Note: This file is ignored in your submission.
 */

#include "LinkedVector.hpp"

#include "vNode.hpp"

#include <iostream>
#include <algorithm>

// Shows how to use a vNode.
void testVNode() {
    std::cout << "Begin function testVNode:\nvvvvvvvvvv\n";
    std::vector<int> values;
    for(int i = 1; i <= 5; ++i) {
        values.push_back(i);
    }

    cse250::vNode<int>* node = new cse250::vNode<int>();
    node->data = values;
    std::cout << "Printing values stored in node: ";
    for(auto val : node->data) {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    delete node;

    std::cout << "^^^^^^^^^^\nEnd function testVNode:\n";
}

void testIterator() {
    std::cout << "Begin function testIterator:\nvvvvvvvvvv\n";
    std::vector<int> values;
    LinkedVector<int> linkedVector;
    for(int i = 1; i <= 5; ++i) {
        values.push_back(i);
        linkedVector.insert(i);
    }

    for(int i = 1; i <= 5; ++i) {
        values.push_back(i);
        linkedVector.insert(i);
    }

    LinkedVector<int>::Iterator position = linkedVector.begin();
    std::cout << "Printing stored sequence: ";
    while(position != linkedVector.end()) {
        std::cout << *(position) << ' ';
        position++;
    }
    std::cout << '\n';

    std::cout << "^^^^^^^^^^\nEnd function testIterator:\n";
}

void testCallAll() {
    LinkedVector<int> linkedVector;
    linkedVector.insert(0);
    linkedVector.find(0);
    linkedVector.erase(0);
    linkedVector.insert(0);
    linkedVector.size();
    LinkedVector<int>::Iterator iter = linkedVector.begin();
    LinkedVector<int>::Iterator iter2 = linkedVector.begin();
    LinkedVector<int>::Iterator end = linkedVector.end();
    while(iter != end) {
        if(iter == iter2) {
            ++iter;
        }
        else {
            iter++;
        }
    }
}
void customTest(){
    LinkedVector<int> linkedVector;
    int testSize = 10000;
    for(int i = testSize; i > 0; i--){
        linkedVector.insert(i);
    }
    int a = 1;



    for(auto position = linkedVector.begin(); position != linkedVector.end(); position.operator++()){
        if(*position != a){
            std::cout<<"not equal" << std::endl;
        }
        a++;
    }

    for(int i = testSize; i > 0; i--){
        linkedVector.erase(i);
    }

    auto iter = linkedVector.begin();
    auto iter2 = linkedVector.end();

    if(iter.operator!=(iter2)){
        std::cout<<"begin not equal to end" << std::endl;
    }

    for(int i = testSize; i > 0; i--){
        linkedVector.insert(i);
    }

    int b = 1;
    for(auto position = linkedVector.begin(); position != linkedVector.end(); position.operator++()){
        if(*position != b){
            std::cout<<"not equal";
        }
        b++;
    }
    std::cout << "customTest finished -------------------" << std::endl;
}

void testEmpty(){
    LinkedVector<int> lv;
   for (int i=0; i <11; i++){
       lv.insert(i);
   }
   lv.erase(5);
   lv.erase(6);
   lv.erase(7);
   lv.erase(8);
   lv.erase(9);
   auto a = lv.find(5);
   auto b = lv.find(7);
   std::cout << b.operator==(lv.end());
}



int main() {
    // To skip running a test here, simply comment it out.
    testVNode();
    // Calls all functions to test compilation (does not call private method rebalance).
    testCallAll();
    // Note: Iterator test will print nothing until the Iterator works.
    testIterator();

    customTest();
    testEmpty();
    LinkedVector<int> linkedVector;
    int testSize = 100;
    for(int i = testSize; i > 0; i--){
        linkedVector.insert(i);
    }
    for(int i = (testSize >> 1); i > 0; i--){
        if(!linkedVector.erase(i)) { std::cout << "Invalid erase." << std::endl;}
    }
    auto startPos = linkedVector.begin();
    auto endPos = linkedVector.end();
    for(int i = (testSize >> 1)+1; i <= testSize; i++){
        if(startPos == endPos) { std::cout << "At end early." << std::endl;}
        if(*(startPos++) != i) { std::cout << "Incorrect value." << std::endl;}
    }

    for(int i = (testSize >> 1)+1; i <= testSize; ++i){
        if(linkedVector.insert(i)) { std::cout << "Incorrect insert." << std::endl;}
    }

    for(int i = (testSize >> 1); i > 0; --i){
        if(linkedVector.erase(i)) { std::cout << "Incorrect erase." << std::endl;}
    }

    for(int i = (testSize >> 1); i > 0; --i){
        if(!linkedVector.insert(i)) { std::cout << "Incorrect insert." << std::endl;}
    }

    for(int i = testSize; i > (testSize >> 1); i--){
        if(!linkedVector.erase(i)) { std::cout << "Invalid erase." << std::endl;}
    }

    startPos = linkedVector.begin();
    endPos = linkedVector.end();
    for(int i = 1; i <= (testSize >> 1)+1; i++){
        if(startPos == endPos) { std::cout << "At end early." << std::endl; }

    }



     LinkedVector<std::string> k;
    k.insert("a");
    k.insert("ab");
    k.erase("a");
    k.insert("a");
    LinkedVector<std::string>::Iterator l = k.begin();
    std::cout<< *l;
    ++l;
    std::cout << *l;




 LinkedVector<int> stri;
   for (int i=0; i<100; i++){
       stri.insert(i);
   }
   std::vector<int> hey;
   for (int i=0; i<100; i++){
       hey.push_back(i);
   }
   std::random_shuffle(hey.begin(), hey.end());
   LinkedVector<int>::Iterator itty = stri.begin();

   for (auto i = hey.begin(); i != hey.end(); ++i){
       if (!stri.erase(*i)){
           std::cout << "incorrect erase";
       }
   }

 std::cout<< "BEGIN NEXT TESTS ______________ " << std::endl;
 LinkedVector<int> test;
 for (int i=0; i<55; i++){
     test.insert(i);
 }
 std::cout << "plaver" << std::endl;
 for (int i=10; i < 40; i++){
     test.erase(i);
 }
 LinkedVector<int>::Iterator ayy = test.begin();
 for (int i=0; i<25; i++){
     std::cout << *ayy << std::endl;
     ++ayy;
 }
 std::cout << "END TEST REMOVE THEN ITERATE_____" <<std::endl;
 for (int i=10; i<40; i++){
     std::cout<< test.insert(i);
 }

 ayy = test.begin();
 for (int i=0; i< 55; i++){
     std::cout << *ayy << std::endl;
     ++ayy;
 }
 std::cout << "_____________________________________ ttttttttttt" << std::endl;
 ayy = test.begin();
 for (int i=30; i <55; i++) {
    test.erase(i);

 }
 for (int i=5; i<20; i++){
     test.erase(i);
 }
 for (int i = 30; i <55; i++){
     test.insert(i);
 }
 for (int i=5; i<20; i++){
     test.insert(i);
 }
 ayy= test.begin();
 for (int i=0; i<55; i++){
     std::cout << *ayy<< std::endl;
     ++ayy;
 }
std::cout << " HOPEFULLY LAST TEST ______________________________________" << std::endl;

 LinkedVector<int> thisguy;
 for (int i=0; i <55; i++){

     thisguy.insert(i);
 }
    for (int i=10; i <50; i++){
        thisguy.erase(i);
    }
    for (int i=10; i <50; i++){

        thisguy.insert(i);
    }
    for (int i = 55; i < 300; i++){
        thisguy.insert(i);
    }
    LinkedVector<int>::Iterator Josh = thisguy.begin();
    for (int i=0; i <55; i++){
        std::cout << *Josh << std::endl;
        ++Josh;
    }
    Josh = thisguy.begin();
    std::cout << " LAST TEST" <<std::endl;
    for (int i=0; i < 300; i++ ){
        std::cout << *Josh << std::endl;
        ++Josh;
    }
    for (int i=0; i < 300; i++){
        Josh = thisguy.find(i);
        std::cout << *Josh << std::endl;
    }
    for (int i=0; i < 300; i++){
        std::cout << thisguy.erase(i);
    }


    for (int i=0; i<55; i++){
        std::cout <<*test.find(i) << std::endl;
    }
std::cout << " LARGE TEST______________";


    LinkedVector<int> big;
    std::vector<int> pre;
    for (int i = 0; i<51; i++){
        pre.push_back(i);
    }
    std::random_shuffle(pre.begin(), pre.end());
    for (int i=0; i < 51; i++){
        big.insert(pre.at(i));
    }
    for (int i=10; i<30; i++){
        std::cout << big.erase(i);
    }

    for (int i =5; i<10; i++){
       std::cout << big.erase(i);
    }
    for (int i =30; i < 40; i++){
       std::cout<<  big.erase(i);
    }
    LinkedVector<int>::Iterator biggy = big.begin();
    for (LinkedVector<int>::Iterator biggy = big.begin(); biggy!=big.end(); ++biggy){
        std::cout << *biggy<< std::endl;
    }
    for (int i=0; i<5; i++){
        std::cout << *big.find(i) << std::endl;
    }
    for (int i=40; i<51; i++){
        std::cout << *big.find(i) << std::endl;
    }
    std::cout << " ____ANOTHER TEST________" << std::endl;
    LinkedVector<int> another;
    for (int i =0; i < 100; i++) {
        another.insert(i);
    }
    /*
    another.erase(3);
    another.erase(4);
    another.erase(5);
    another.erase(6);
    another.erase(7);
    another.erase(8);
    another.insert(3);
    another.insert(4);
    */
    std::vector<int> guyer;
    for (int i=0; i<100; i++){
        guyer.push_back(i);
    }
    std::random_shuffle(guyer.begin(), guyer.end());
    for (auto i = guyer.begin(); i != guyer.end(); ++i){
        if (!another.erase(*i)){std::cout << "ERASE FLAG" << std::endl;}
    }
    if (another.size() != 0){std::cout << "PROBLEM" << std::endl;}
    for (auto i = guyer.begin(); i != guyer.end(); ++i){
        if (!another.insert(*i)){std::cout << "Insert FLAG" << std::endl;}
    }
    for (LinkedVector<int>::Iterator chance = another.begin(); chance != another.end(); ++chance) {
        std::cout << *chance << std::endl;
    }
    for (int i=0; i<100; i++){
        std::cout << *another.find(i)<< std::endl;
    }

    LinkedVector<int> neww;
   std::cout << neww.erase(1);











    // Add more tests here or modify those above.
    
}
