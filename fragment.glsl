#version 330 core
in vec2 vPos;
out vec4 FragColor;

void main() {
    float mixValue = (vPos.y + 1.0) / 2.0; 
    FragColor  = mix(
        mix(vec4(1.0, 0.0, 0.0, 1.0), vec4(0.0, 0.0, 1.0, 1.0), mixValue), 
        mix(vec4(0.0, 0.0, 1.0, 1.0), vec4(0.0, 1.0, 0.0, 1.0), mixValue), 
        0.5
    );

}

