#include "Node.hpp"

void Node::update(double delta) {
	updateChildren(delta);
}

void Node::render() {

}

void Node::translate(Vector2 p_position) {
	position = p_position;
	global_position = parent->global_position + position;
}

void Node::updateChildren(double delta) {
	for(int i = 0; i < children.size(); i++) {
		children.at(i)->update(delta);
	}
}

Node * Node::getChild(const char* p_name) {
	for(int i = 0; i < children.size(); i++) {
		if(children.at(i)->name == p_name) {
			return children.at(i).get();
		}
	}
	return nullptr;
}

Node * Node::getParent() {
	return parent.get();
}
