#include "natural.h"

Natural::Natural() {
	objmodel_ptr = NULL;

	if (!objmodel_ptr) {
		objmodel_ptr = glmReadOBJ("./mallas/natural.obj");
		if (!objmodel_ptr)
			exit(0);

		glmUnitize(objmodel_ptr);
		glmFacetNormals(objmodel_ptr);
		glmVertexNormals(objmodel_ptr, 90.0);
		glmScale(objmodel_ptr, 0.2);
	}
}

void Natural::DibujarArbol(float aX, float aY, float aZ) {

	glPushMatrix();

	glTranslatef(aX, aY, aZ);
	glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL);

	glPopMatrix();
}



Natural::~Natural() {}