
// gcc main_cglm.c -I./dep/ -o prog -lm && ./prog

// #define GLM_ENABLE_EXPERIMENTAL

// // #define GLM_SWIZZLE
// #define GLM_FORCE_SWIZZLE
// #define GLM_SWIZZLE_XYZW
// #define GLM_SWIZZLE_STQP
// #define GLM_SWIZZLE_RGBA

// #include <glm/glm.hpp>
// // #include <glm/gtc/swizzle.hpp>
// // #include <glm/gtc/type_ptr.hpp>

// #include <glm/vec3.hpp> // glm::vec3
// #include <glm/vec4.hpp> // glm::vec4
// #include <glm/mat4x4.hpp> // glm::mat4
// #include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
// #include <glm/ext/matrix_clip_space.hpp> // glm::perspective
// #include <glm/ext/scalar_constants.hpp> // glm::pi

// #include <glm/gtx/string_cast.hpp>
// glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
// {
// 	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
// 	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
// 	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
// 	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
// 	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
// 	return Projection * View * Model;
// }

// #include <iostream>

#include <stdio.h>

#include <cglm/cglm.h>
#include <cglm/call.h>
#include <cglm/struct.h>

int main(){
	// glm::vec3 A(2.0f);
	// glm::vec3 B(1.5f);
	float A[3] = {1.0f, 1.0f, 1.0f};
	vec3 B = {0.5f, 1.0f, 0.0f};
	mat4 mat = {1.0f, 1.0f, 1.0f, 1.0f};

	// glm_normalize(A);
	float f = glm_dot(
		A,
		B
	);

	// vec3 C = cross(A, B);
	// printf("cross(A, B): is %s\n", to_string(C));

	// printf("dot(A,B): is %s\n",dot(A, B));
	printf("dot(A,B): is %f\n", f);
	glm_normalize(A);
	glm_normalize(B);
	f = glm_dot(
		A,
		B
	);
	printf("dot(normalize(A),normalize(B)): is %f\n", f);

	// printf("A.xyz(): is %s\n", to_string(A.xyz()));
	// printf("B.zyx(): is %s\n", to_string(B.zyx()));
	// A.xyz() = B.zyx();
	// printf("A.xyz(): is %s\n", to_string(A.xyz()));
	// printf("B.zyx(): is %s\n", to_string(B.zyx()));
	// printf("A.xy(): is %s\n", to_string(A.xy()));

	// printf();
	// 	<< to_string(A)
	// 	<< std::endl;
	// printf();
	// 	<< to_string(B)
	// 	<< std::endl;

	// printf();
	// 	<< to_string(normalize(A))
	// 	<< std::endl;
	// printf();
	// 	<< to_string(normalize(B))
	// 	<< std::endl;

	// printf();
	// 	// << "dot(A,B): is " 
	// 	<< to_string(mat)
	// 	<< std::endl;
	
	return 0;
}