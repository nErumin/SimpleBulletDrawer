#version 330 core

layout(location = 0) in vec3 positionAttribute;
layout(location = 1) in vec3 colorAttribute;

out vec3 passColorAttribute;

uniform mat4 TransformationMatrix;

void main()
{
    gl_Position = TransformationMatrix * vec4(positionAttribute, 1.0);

    passColorAttribute = colorAttribute;
}