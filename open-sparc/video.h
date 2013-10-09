#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// glm provides vector, matrix classes like glsl
// Typedefs to make code more readable

typedef glm::mat3 mat3 ;
typedef glm::mat4 mat4 ;
typedef glm::vec3 vec3 ;
typedef glm::vec4 vec4 ;

class Video
{
public:


    vec3 cameye;
    vec3 camcenter;
    vec3 camup;

    Video(vec3 eye, vec3 center, vec3 up);
	void draw();
	static void glCuboid(float x1, float y1, float z1, float x2, float y2, float z2);
};

#endif // VIDEO_H_INCLUDED
