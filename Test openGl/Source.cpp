//#include <glad/glad.h>   //ego vsegda pevim
#include <GLFW/glfw3.h>
#include <iostream>


//GLfloat vertices[] = {
//	-0.5f, -0.5f, 0.0f,
//	 0.5f, -0.5f, 0.0f,
//	 0.0f,  0.5f, 0.0f
//};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	//glViewport(0, 0, 600, 600);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main() {

	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	GLFWwindow*window = glfwCreateWindow(600, 600, "GOVNO", NULL, NULL);
	glfwMakeContextCurrent(window);





	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	int f = 0;
	while (!glfwWindowShouldClose(window))
	{
		// Обработка ввода
		processInput(window);
		f++;
		// Выполнение рендеринга
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT);
		
		glBegin(GL_TRIANGLES);
		glColor3ub(189,100,75);
		
			glVertex2f(0.5 * cos((atan(1) * 4) / 2.0 - f*atan(1) / 45.0), 0.5 * sin((atan(1) * 4) / 2.0 - f*atan(1) / 45.0));
			glColor3ub(189, 101, 76);
			glVertex2f(0.5 * cos((-atan(1) * 4) / 6.0 -f*atan(1) / 45.0), 0.5 * sin((-atan(1) * 4) / 6.0 -f*atan(1) / 45.0));
			glColor3ub(19, 10, 75);
		    glVertex2f((0.5 * cos(-5.0*atan(1) * 4/ 6.0 - f*atan(1) / 45.0)), 0.5*sin(-5.0 * atan(1) * 4 / 6.0 - f*atan(1) / 45.0));

		glEnd();
		


		glfwPollEvents();
		glfwSwapBuffers(window);
		
	}


	//govnagovna

	glfwTerminate();





	return 1;
}