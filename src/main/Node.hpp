#pragma once

#include "Vector2.hpp"
#include <memory>
#include <vector>

using namespace std;

enum nodeType {
	NODETYPE_STATIC,
	NODETYPE_DYNAMIC
};

class Node {
	public:
		Vector2 position;
		Vector2 global_position;
		const char* name;
		uint8_t zIndex = 1;
		uint8_t nodeType = NODETYPE_STATIC;
	private:
		unique_ptr<Node> parent;
		vector<unique_ptr<Node>> children;
	public:
		virtual void update(double delta);
		virtual void render();
		virtual void translate(Vector2 p_position);
		Node * getChild(const char* p_name);
		Node * getParent();
	private:
		void updateChildren(double delta);
};

/*
*	TODO: z_index;
*/
