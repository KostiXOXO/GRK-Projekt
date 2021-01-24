#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"
#include <vector>


#define PARTICLES_COUNT 100

class ParticleEmitter
{
public:
	ParticleEmitter(GLuint* program);
	~ParticleEmitter();

	void update(const float dt, const glm::mat4 transformation, glm::mat4 cameraMatrix, glm::mat4 perspectiveMatrix);
	void draw();

private:
	struct Particle
	{
		glm::vec3 position;
		float lifetime = 0.0f;
		float radius = 0.0f;
	};

	float positionsArr[PARTICLES_COUNT * 4];
	GLuint* program;
	GLuint particleVertexBuffer;
	GLuint particlePositionBuffer;
	std::vector< Particle > particles;

	float randomFloat(float min, float max);
	void generateBuffers();
	void setupUniforms(const glm::mat4 transformation, glm::mat4 cameraMatrix, glm::mat4 perspectiveMatrix);
};