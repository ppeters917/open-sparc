#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#define VIEW_EGO 0
#define VIEW_THIRD 1


#define LOOK_UP 2
#define LOOK_RIGHT 3
#define LOOK_DOWN 4
#define LOOK_LEFT 5

#define MOVE_FORWARD 6
#define MOVE_RIGHT 7
#define MOVE_BACKWARD 8
#define MOVE_LEFT 9

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
private:
    vec3 _cameye;
    vec3 _camcenter;
    vec3 _camup;

    vec3 _viewpos;
    vec3 _viewdir;
    float _viewdist;
    int _viewmode;
public:

    Video(vec3 eye, vec3 center, vec3 up);
    virtual ~Video();

	void draw();
	void setViewMode(int mode);
	void setViewPosition(vec3 pos);
	void setViewDir(vec3 dir);
	void setViewDistance(float dist);
	void lookRelative(float amount, int dir);
	void moveRelative(float amount, int dir);
	static void glCuboid(float x1, float y1, float z1, float x2, float y2, float z2);
};

#endif // VIDEO_H_INCLUDED
