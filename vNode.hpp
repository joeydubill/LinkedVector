/**
 * vNode.hpp
 *
 * Copyright 2018 Andrew Hughes (ahughes6@buffalo.edu)
 *
 * This work is licensed under the Creative Commons 
 * Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/4.0/.
 *
 */

#ifndef _VNODE_HPP_
#define _VNODE_HPP_


#include <vector>

namespace cse250 {
    template <typename T>
    struct vNode;
}

template <typename T>
struct cse250::vNode {
    std::vector<T> data;
    cse250::vNode<T>* next;
    cse250::vNode<T>* prev;
    vNode() : next(nullptr), prev(nullptr) {}
};

#endif //_VNODE_HPP_
