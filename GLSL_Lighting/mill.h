#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "glm/glm.h"

class Mill
{
	GLMmodel* objmodel_ptr;

public:
	Mill();

	void DibujarMill(float aX, float aY, float aZ);

	~Mill();
};