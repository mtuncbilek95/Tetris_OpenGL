#version 460 core

out vec4 FragColor;

//Defines
in vec3 UniColor; 

void main()
{
    FragColor = vec4(UniColor, 1.0f);
} 