/**

#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

#define PI 3.141592

float speed = time * 1.0;

vec4 calc_line(vec2 coord, float offset, vec4 color)
{
	float pulse = sin(coord.x + speed + offset) + 2.0;
	pulse *= 0.25;
	float d = clamp(1.0 - distance(pulse, coord.y), 0.0, 1.0);
	d = pow(d, 10.0);
	return color * d;
}

void main(void)
{
	vec2 coord = gl_FragCoord.xy / min(resolution.x, resolution.y) - vec2(1.0, 0);
	
	// Line 1
	gl_FragColor += calc_line(coord, 0.0, vec4(1, 1, 0, 1));

	// Line 2
	gl_FragColor += calc_line(coord, PI, vec4(1, 0, 1, 1));
	
	float d = pow(1.0 - distance(vec2(0.5), coord.xy + vec2(0.5, 0)), 1.0);
	gl_FragColor *= d;
}

**/



#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main( void ) {

	vec2 position = gl_FragCoord.xy;
	float color;
	
	vec2 lightpos = resolution * mouse;
	
	vec2 norm = lightpos - position;
	float sdist = norm.x * norm.x + norm.y * norm.y;
	
	vec3 light_color = vec3(1.0,0.6,0.0);
	
	color = 1.0 / (sdist * 0.003);

	gl_FragColor = vec4(color,color,color,1.0)*vec4(light_color,1.0);

}