#version 150
precision mediump float;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 mvp;

in vec3 position;
in vec4 color;
in vec3 normal;

out vec3 vPosition;
out vec3 vNormal;
out vec4 vColor;

void main() {
    
    vPosition=position;
    vNormal=normal;
    vColor = color;
    gl_Position = mvp * vec4(position, 1.0);
}
