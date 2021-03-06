// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h" //ayuda a que compile mas rapido
#include <stdio.h> // esta cosa para librerias incluidas en c#
#include <stdlib.h>

#define GLEW_STATIC 

#include "GL/glew.h" //comillas para librerias personalizadas
#include "GLFW/glfw3.h"

#include <iostream>

#include "Shader.h"
#include "Vertice.h"

using namespace std; //aqui esta lo de c++

Shader *shader;
GLuint posicionID;
GLuint colorID;

//el vertice necesita saber como va a empezar a leer y donde
vector <Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

vector <Vertice> cuadrado1;
GLuint vertexArrayCuadrado1;
GLuint bufferCuadrado1;

vector <Vertice> cuadrado2;
GLuint vertexArrayCuadrado2;
GLuint bufferCuadrado2;

vector <Vertice> cuadrado3;
GLuint vertexArrayCuadrado3;
GLuint bufferCuadrado3;

vector <Vertice> cuadrado4;
GLuint vertexArrayCuadrado4;
GLuint bufferCuadrado4;

vector <Vertice> piso;
GLuint vertexArrayPiso;
GLuint bufferPiso;


void inicializarTriangulo()
{
	//al ponerle inicializador a la estructura da la capacidad de iniciarlas asi
	Vertice v1 =
	{
		vec3(-0.06f,0.42f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v2 =
	{
		vec3(0.06f,0.42f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v3 =
	{
		vec3(0.0f,0.30f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	//la funcion push back añade nuevos elementos a un vertice
	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);
}

void inicializarCuadrado1()
{
	Vertice v1 =
	{
		vec3(-0.13f,0.30f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v2 =
	{
		vec3(0.13f,0.30f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v3 =
	{
		vec3(0.13f,-0.3f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v4 =
	{
		vec3(-0.13f,-0.3f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	cuadrado1.push_back(v4);
	cuadrado1.push_back(v3);
	cuadrado1.push_back(v2);
	cuadrado1.push_back(v1);
}

void inicializarCuadrado2()
{
	Vertice v1 =
	{
		vec3(-0.3f,0.28f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v2 =
	{
		vec3(0.3f,0.28f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f) 
	};

	Vertice v3 =
	{
		vec3(0.3f,0.17f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v4 =
	{
		vec3(-0.3f,0.17f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	cuadrado2.push_back(v4);
	cuadrado2.push_back(v3);
	cuadrado2.push_back(v2);
	cuadrado2.push_back(v1);
}

void inicializarCuadrado3()
{
	Vertice v1 =
	{
		vec3(-0.22f,-0.3f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v2 =
	{
		vec3(0.22f,-0.3f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v3 =
	{
		vec3(0.22f,-0.6f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v4 =
	{
		vec3(-0.22f,-0.6f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	cuadrado3.push_back(v4);
	cuadrado3.push_back(v3);
	cuadrado3.push_back(v2);
	cuadrado3.push_back(v1);
}

void inicializarCuadrado4()
{
	Vertice v1 =
	{
		vec3(-0.39f,0.27f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v2 =
	{
		vec3(0.39f,0.27f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v3 =
	{
		vec3(0.39f,0.20f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	Vertice v4 =
	{
		vec3(-0.39f,0.20f,0.0f),
		vec4(0.9f,0.9f,0.9f,0.0f)
	};

	cuadrado4.push_back(v4);
	cuadrado4.push_back(v3);
	cuadrado4.push_back(v2);
	cuadrado4.push_back(v1);
}

void inicializarPiso()
{
	Vertice v1 =
	{
		vec3(-1.0f,-0.6f,0.0f),
		vec4(0.0f,1.0f,0.0f,0.0f)
	};

	Vertice v2 =
	{
		vec3(1.0f,-0.6f,0.0f),
		vec4(0.0f,1.0f,0.0f,0.0f)
	};

	Vertice v3 =
	{
		vec3(1.0f,-1.0f,0.0f),
		vec4(0.0f,1.0f,0.0f,0.0f)
	};

	Vertice v4 =
	{
		vec3(-1.0f,-1.0f,0.0f),
		vec4(0.0f,1.0f,0.0f,0.0f)
	};

	piso.push_back(v4);
	piso.push_back(v3);
	piso.push_back(v2);
	piso.push_back(v1);
}

void dibujar()
{
	//Elegir el shader
	shader->enlazar();
	//Elegir un vertex array
	glBindVertexArray(vertexArrayTrianguloID);
	//Dibujar
	//toma de parametro el tipo de primitivas que va a dibujar,despues si va a tener un desface y el numero de vertices
	glDrawArrays(GL_TRIANGLES,0,triangulo.size());

	//soltar el vertex array
	glBindVertexArray(0);

	glBindVertexArray(vertexArrayCuadrado1);
	glDrawArrays(GL_QUADS, 0, cuadrado1.size());
	glBindVertexArray(0);

	glBindVertexArray(vertexArrayCuadrado2);
	glDrawArrays(GL_QUADS, 0, cuadrado2.size());
	glBindVertexArray(0);

	glBindVertexArray(vertexArrayCuadrado3);
	glDrawArrays(GL_QUADS, 0, cuadrado3.size());
	glBindVertexArray(0);

	glBindVertexArray(vertexArrayCuadrado4);
	glDrawArrays(GL_QUADS, 0, cuadrado4.size());
	glBindVertexArray(0);

	glBindVertexArray(vertexArrayPiso);
	glDrawArrays(GL_QUADS, 0, piso.size());
	glBindVertexArray(0);


	//soltar el shader
	shader->desenlazar();
}

void actualizar() {

}

int main()
{
	//Declaramos apuntador de ventana

	GLFWwindow *window;

	//Si no se pudo iniciar glfw terminamos ejecución

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	//Si se pudo iniciar GLFW entonces inicializamos la ventana

	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	//Si no podemos iniciar la ventana entonces terminamos la ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido e contexto activamos funciones modernas
	glewExperimental = true; //permite trabajar con gpu y cpu al mismo tiempo,solo va a funcionar si ya esta establecido el contexto

	//en caso de haber error se guarda en la variable errorGlew que es tipo GLenum 
	GLenum errorGlew = glewInit(); //inicializa glew

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	//se obtiene la version de OpenGL y se imprime
	const GLubyte *versionGL = glGetString(GL_VERSION); 
	cout << "Version OpenGL: " << versionGL; 

	inicializarTriangulo(); 
	inicializarCuadrado1();
	inicializarCuadrado2();
	inicializarCuadrado3();
	inicializarCuadrado4();
	inicializarPiso();

	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	//Se crea una nueva instancia de la clase
	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	//lleva 2 atributos el id del programa y la variable que va a obtener
	//aqui se estan guardando las entradas del vertex
	posicionID = glGetAttribLocation(shader -> getID(),"posicion");

	colorID = glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader
	shader -> desenlazar();

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayTrianguloID);
	
	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferTrianguloID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER,bufferTrianguloID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * triangulo.size(), triangulo.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice),(void*) sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//------------------------------------------//

	glGenVertexArrays(1, &vertexArrayCuadrado1);
	glBindVertexArray(vertexArrayCuadrado1);

	glGenBuffers(1, &bufferCuadrado1);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadrado1);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadrado1.size(), cuadrado1.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//------------------------------------------//

	glGenVertexArrays(1, &vertexArrayCuadrado2);
	glBindVertexArray(vertexArrayCuadrado2);

	glGenBuffers(1, &bufferCuadrado2);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadrado2);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadrado2.size(), cuadrado2.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//------------------------------------------//

	glGenVertexArrays(1, &vertexArrayCuadrado3);
	glBindVertexArray(vertexArrayCuadrado3);

	glGenBuffers(1, &bufferCuadrado3);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadrado3);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadrado3.size(), cuadrado3.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//------------------------------------------//

	glGenVertexArrays(1, &vertexArrayCuadrado4);
	glBindVertexArray(vertexArrayCuadrado4);

	glGenBuffers(1, &bufferCuadrado4);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadrado4);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadrado4.size(), cuadrado4.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//------------------------------------------//

	glGenVertexArrays(1, &vertexArrayPiso);
	glBindVertexArray(vertexArrayPiso);

	glGenBuffers(1, &bufferPiso);
	glBindBuffer(GL_ARRAY_BUFFER, bufferPiso);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * piso.size(), piso.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//------------------------------------------//



	//ciclo de dibujo (draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768); //dice donde va a empezar a renderear y donde va a terminar
		//Establecer color de borrado
		glClearColor(0.1f, 0.8f, 0.8f, 0.0f);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffer
		glfwSwapBuffers(window); //cambia el buffer de la pantalla por el otro que se lleno
		//reconocer si hay entradas
		glfwPollEvents();

	}

	glfwDestroyWindow(window); //terminamos los procesos y eliminamos la ventana
	glfwTerminate();
	return 0;
}



