#ifndef MINECRAFT_WORLD_H
#define MINECRAFT_WORLD_H
#include "../GL/gl_imp.h"
#include "../Block/Chunk.h"
#include "../Block/Block.h"
#include <map>
#include <queue>
#include <list>
class World
{
public:
	struct chunk_less{
		bool operator()(const glm::vec3 &ls, const glm::vec3 &hs) const{
			return true;
		}
	};
	using BlockQueue = std::queue<Block*,std::list<Block*>>;
	using ChunkMap   = std::map<glm::vec3, Chunk *, chunk_less>;
	using const_vec3 = const glm::vec3;
public:
	World() = default;

	~World(){ destoryWorld(); }

	void initWorld();
	void destoryWorld();
	void addChunk(const_vec3 &position);
	void hideChunk(const_vec3 &position);

	Chunk *getCurrentChunk();
	void setCamera(const_vec3 &eye, const_vec3 &look, const_vec3 &up);
	void updateWorld();
private:
	ChunkMap m_chunk;
	BlockQueue m_blockQueue;
};
#endif //MINECRAFT_WORLD_H