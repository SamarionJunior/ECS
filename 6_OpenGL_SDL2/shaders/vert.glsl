#version 410 core
layout(location=0) in vec3 position;
layout(location=1) in vec3 vertexColors;
// uniform float u_OffsetX;
// uniform float u_OffsetY;
// uniform float u_OffsetZ;
uniform float u_ModelMatrix;
out vec3 v_vertexColors;
void main(){
  v_vertexColors = vertexColors;
  gl_Position = vec4(
    position.x + u_OffsetX, 
    position.y + u_OffsetY, 
    position.z + u_OffsetZ, 
    // position.x + u_OffsetX, 
    // position.y + u_OffsetY, 
    // position.z + u_OffsetZ, 
    1.0f
  );
}