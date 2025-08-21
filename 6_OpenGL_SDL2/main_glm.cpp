
// g++ -std=c++20 main_glm.cpp -I./dep/ -o prog && ./prog

#define GLM_ENABLE_EXPERIMENTAL

// #define GLM_SWIZZLE
#define GLM_FORCE_SWIZZLE
#define GLM_SWIZZLE_XYZW
#define GLM_SWIZZLE_STQP
#define GLM_SWIZZLE_RGBA

#include <glm/glm.hpp>
// #include <glm/gtc/swizzle.hpp>
// #include <glm/gtc/type_ptr.hpp>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

#include <iostream>

#include <glm/gtx/string_cast.hpp>
// glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
// {
// 	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
// 	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
// 	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
// 	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
// 	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
// 	return Projection * View * Model;
// }

int main(){
	// glm::vec3 A(2.0f);
	// glm::vec3 B(1.5f);
	glm::vec3 A(1.0f, 1.0f, 1.0f);
	glm::vec3 B(0.5f, 1.0f, 0.0f);
	glm::mat4 mat(1.0f);

	// float f = glm::dot(
	// 	glm::normalize(A),
	// 	glm::normalize(B)
	// );

	std::cout 
		<< "dot(A,B): is " 
		<< glm::dot(A, B) 
		<< std::endl;
	std::cout 
		<< "dot(normalize(A),normalize(B)): is " 
		<< glm::dot(
				glm::normalize(A),
				glm::normalize(B)
			)
		<< std::endl;

	// glm::vec3 C = glm::cross(A, B);
	// std::cout 
	// 	<< "cross(A, B): is " 
	// 	<< glm::to_string(C)
	// 	<< std::endl;

	// std::cout 
	// 	<< "dot(A,B): is " 
	// 	<< glm::dot(A, B) 
	// 	<< std::endl;
	// std::cout 
	// 	<< "dot(normalize(A),normalize(B)): is " 
	// 	<< f 
	// 	<< std::endl;

	// std::cout 
	// 	<< "A.xyz(): is " 
	// 	<< glm::to_string(A.xyz())
	// 	<< std::endl;
	// std::cout 
	// 	<< "B.zyx(): is " 
	// 	<< glm::to_string(B.zyx())
	// 	<< std::endl;
	// A.xyz() = B.zyx();
	// std::cout 
	// 	<< "A.xyz(): is " 
	// 	<< glm::to_string(A.xyz())
	// 	<< std::endl;
	// std::cout 
	// 	<< "B.zyx(): is " 
	// 	<< glm::to_string(B.zyx())
	// 	<< std::endl;
	// std::cout 
	// 	<< "A.xy(): is " 
	// 	<< glm::to_string(A.xy())
	// 	<< std::endl;

	// std::cout 
	// 	<< glm::to_string(A)
	// 	<< std::endl;
	// std::cout 
	// 	<< glm::to_string(B)
	// 	<< std::endl;

	// std::cout 
	// 	<< glm::to_string(glm::normalize(A))
	// 	<< std::endl;
	// std::cout 
	// 	<< glm::to_string(glm::normalize(B))
	// 	<< std::endl;

	// std::cout 
	// 	// << "dot(A,B): is " 
	// 	<< glm::to_string(mat)
	// 	<< std::endl;
	return 0;
}