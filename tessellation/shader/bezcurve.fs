#version 400

layout ( location = 0 ) out vec4 FragColor;

in vec3 color;

void main()
{
    FragColor.xyz = color;
}
