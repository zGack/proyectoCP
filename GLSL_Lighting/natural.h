#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "glm/glm.h"

class Natural
{
	GLMmodel* objmodel_ptr;

public:
	Natural();

	void DibujarArbol(float aX, float aY, float aZ);

	~Natural();
};