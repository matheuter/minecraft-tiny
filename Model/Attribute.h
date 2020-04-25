//
// Created by bainsky on 2020/4/25.
//

#ifndef MINECRAFT_ATTRIBUTE_H
#define MINECRAFT_ATTRIBUTE_H
#include "../GL/gl_imp.h"

struct  Attribute
{
	glm::vec3 position;//顶点坐标
	glm::vec3 normal;  //法向量
	glm::vec2 texCoords;
};

#endif //MINECRAFT_ATTRIBUTE_H
