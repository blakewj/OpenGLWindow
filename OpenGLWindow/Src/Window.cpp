//including external lib files
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

static int compileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(GL_VERTEX_SHADER);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	return id;
}
 


static int createShader(const std::string& vertexShader, const std::string& fragmentShader) {
	// this will be our fuynction to complie the vertex and fragment shader

	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader); 
	//we have our two files and we are going to attach them to a program

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);
	return program;

}


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
	//this creates our gl render``
	glfwMakeContextCurrent(window);

	std::cout<< glGetString(GL_VERSION) <<std::endl;



	//test weather glew is running
	//remeber glew must be run after creating a context which is being done in the line above
	if (glewInit() != GLEW_OK) {

		std::cout << "ERROR WIth GLEW" << std::endl;

	}

	float postions[6] = {
		-0.5f, -0.5f,
		 0.0f, 0.5f,
		 0.5f, -0.5f
	};


	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER,buffer);
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float),postions,GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,0);

	//this is our game loop
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		

		glDrawArrays(GL_TRIANGLES,0,3);
		 
	



		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}