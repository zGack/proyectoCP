#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "glm/glm.h"

class Devil
{
	GLMmodel* objmodel_ptr;

public:
	Devil();

	void DibujarDevil(float aX, float aY, float aZ);

	~Devil();
};