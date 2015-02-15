struct Point {
	long long x, y;

	Point (long long a = 0, long long b = 0) : x(a), y(b) {}

	int dim() const {
		return x < 0 || (x == 0 && y < 0);
	}
};

long long det(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

bool byAng(const Point &a, const Point &b) {
	if (a.dim() == b.dim()) {
		return det(a, b) < 0;
	} 
	else {
		return a.dim() < b.dim();
	}
}
