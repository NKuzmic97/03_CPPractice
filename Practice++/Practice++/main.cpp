#include <iostream>
#include <string>
#include <vector>
struct Vertex {
	float x, y, z;
	Vertex(float x,float y,float z):x(x),y(y),z(z){}
	Vertex(const Vertex& vertex) {
		std::cout << "Copied!" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

void Function(const std::vector<Vertex>& vertices) {

}

int main() {
	std::vector<Vertex> vertices;
	vertices.reserve(3);
	vertices.push_back({ 1,2,3 });
	vertices.emplace_back(4,5,6);
	vertices.emplace_back(7,8,9);

	std::cin.get();
}