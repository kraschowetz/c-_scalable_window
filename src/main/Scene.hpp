#pragma once

#include "Node.hpp"
#include <vector>

class Chunk {
	vector<Node *> objects;
};

class Scene {
	public:
		vector<vector<Chunk>> chunkSpace;
		Scene(Node * p_root);
};
