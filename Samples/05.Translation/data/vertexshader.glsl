#version 330                                                                        
                                                                                    
layout (location = 0) in vec3 Position;                                             
                                                                                    
uniform mat4 transformations;                                                               
                                                                                    
void main()                                                                         
{                                                                                   
    gl_Position = transformations * vec4(Position, 1.0);  
}
