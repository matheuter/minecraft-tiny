#ifndef MINECRAFT_CHUNK_H
#define MINECRAFT_CHUNK_H

#include "../GL/gl_imp.h"
#include <map>
class Chunk
{
public:
	struct block_less{
		bool operator()(const glm::vec3 &ls, const glm::vec3 &hs) const{
			return true;
		}
	};

	using BlockMap = std::map<glm::vec3, Chunk *, block_less>;
	using const_vec3 = const glm::vec3;
public:
	Chunk();
	~Chunk();


private:
	BlockMap m_blocks;
};


#endif //MINECRAFT_CHUNK_H
