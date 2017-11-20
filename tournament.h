/*
 * hw5.h
 *
 *  Created on: Oct 14, 2017
 *      Author: andrewratz
 */

#ifndef HW5_H_
#define HW5_H_

#include <iostream>
#include <cstdio>
using namespace std;

namespace cop3530 {
		struct Node {
		int data;
		Node* left;
		Node* right;
		//Constructor
		Node();
		Node(int element) {
			data = element;
			left = nullptr;
			right = nullptr;
		}
		//Destructor
		~Node() {

		}
	};
		Node* winner(int* scores_begin, int* scores_end) {
			int* middle = ((scores_end - scores_begin)/2) + scores_begin;
			Node* n = new Node(*middle);
			if (scores_begin == scores_end)
				return n;
			n->left = winner(scores_begin, middle);
			middle++;
			n->right = winner(middle, scores_end);

			n->data = (n->left->data < n->right->data) ? n->right->data : n->left->data;
			return n;
		}
		int* makeTT(int* scores_begin, int* scores_end) {
			int* temp = scores_begin;
			//size of passed in array
			int counter = 1;
			while (temp != scores_end) {
				temp++;
				counter++;
			}
			//packed array needs to hold up to 2n elements
			counter = 2*counter;
			int* array = new int[counter];
			Node* n = winner(scores_begin, scores_end);
			Node* prev;
			int i = 1;
			bool left = true;
			array[0] = n->data;
			while (i < counter) {
				if (n->left != nullptr) {
					array[i] = n->left->data;
					i++;
				}
				if (n->right != nullptr) {
					array[i] = n->right->data;
					i++;
				}
				if (n->left == nullptr && n->right == nullptr) {
					array[i] = n->data;
					i++;
				}
				if (n->left == nullptr && n->right == nullptr)
					break;
				if (left == true) {
					prev = n;
					n = n->left;
					left = false;
				}
				else {
					n = prev;
					n = n->right;
					left = true;
				}
			}
			return array;
		}

}

#endif /* HW5_H_ */
