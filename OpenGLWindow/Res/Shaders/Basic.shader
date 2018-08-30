#shader vertex
#version 330 core

layout(location = 0) in vec4 postion;

void main()
{
	gl_Position = gl_Vertex;
};





#shader fragment

#version 330 core

layout(location = 0) out vec4 color;

void main(void)
{
    vec2 pos = mod(gl_FragCoord.xy, vec2(50.0)) - vec2(25.0);
    float dist_squared = dot(pos, pos);

    gl_FragColor = (dist_squared < 400.0)
? vec4(.90, .90, .90, 1.0)
: vec4(.20, .20, .40, 1.0);
}

 
 

