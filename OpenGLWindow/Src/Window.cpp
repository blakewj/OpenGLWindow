//including external lib files
#include <gl/glew.h>

#include <GLFW/glfw3.h>
#include <iostream>




int main(void)
{
	GLFWwindow* window;

	
	/* Initialize the library */
	if (!glfwInit())
		return -1;
	

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	//this creates our gl render
	glfwMakeContextCurrent(window);

	std::cout<< glGetString(GL_VERSION) <<std::endl;
	//test weather glew is running
	//remeber glew must be run after creating a context which is being done in the line above
	if (glewInit() != GLEW_OK) {

		std::cout << "ERROR WIth GLEW" << std::endl;

	}



	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER,buffer);





	//this is our game loop
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();


		





		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}