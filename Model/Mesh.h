//
// Created by bainsky on 2020/4/25.
//

#ifndef MINECRAFT_MESH_H
#define MINECRAFT_MESH_H

#include <vector>
#include "../Texture/Texture.h"
#include "../Shader/shader.h"
#include "Attribute.h"

using namespace minecraft;
class Mesh
{
public:
	std::vector<Attribute> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	Mesh(std::vector<Attribute>& vertices, std::vector<unsigned int>& indices, std::vector<Texture>& textures);
	void draw(Shader shader);
private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	void setupMesh();
};

#endif //MINECRAFT_MESH_H
