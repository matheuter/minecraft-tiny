//
// Created by bainsky on 2020/4/19.
// tips: world
//

#ifndef MINECRAFT_WORLD_H
#define MINECRAFT_WORLD_H
#include "../GL/gl_imp.h"
#include <map>
class Chunk;
class World
{
public:
		struct chunk_less{
				bool operator()(const glm::vec3 &ls, const glm::vec3 &hs) const{
					return true;
				}
		};

		using ChunkMap = std::map<glm::vec3, Chunk *, chunk_less>;
		using vec3 = const glm::vec3;
public:
		World() = default;
		~World(){destoryWorld();}
		void initWorld();



		void destoryWorld();
		void addChunk(vec3 &position);
		void hideChunk(vec3 &position);
		Chunk *getCurrentChunk();
		void setCamera(vec3 &eye, vec3 &look, vec3 &up);
		void updateWorld();
private:
		ChunkMap m_chunk;
};

#endif //MINECRAFT_WORLD_H
