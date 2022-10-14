#include <stdio.h>
#define MAX(a,b) a > b ? a : b // a,b를 비교한뒤 더 큰값을 가져옴
#define MAX_DEGREE 100

typedef struct {			// 구조체 polynomial 정의 
	int degree;		// 다항식의 차수를 저장할 변수 
	float coef[MAX_DEGREE];	// 다항식의 각 항의 계수를 저장할 1차원 배열 
}polynomial;

polynomial addPoly(polynomial A, polynomial B) {

	polynomial C;
	int indexA = 0;
	int indexB = 0;
	int indexC = 0;
	int degreeA = A.degree;
	int degreeB = B.degree;
	int degreeC = C.degree;
	C.degree = MAX(degreeA,degreeB);
	while(indexA <= A.degree && indexA <= B.degree){
		if(degreeA < degreeB){
			C.coef[indexC++] = B.coef[indexB++];
			degreeB--;
		}
		else if(degreeA == degreeB){
			C.coef[indexC++] = A.coef[indexA++] + B.coef[indexB++];
			degreeA--;
			degreeB--;
		}
		else{
			C.coef[indexC++] = A.coef[indexA++];
			degreeA--;
		}
	}
	return C;
}

void printPoly(polynomial P) {
	int i, degree = P.degree;
	
	for(i=0; i<=P.degree; i++) {
		printf("%3.0fx^%d", P.coef[i], degree--);
		if(i < P.degree) printf(" +");
	}
	printf("\n");
}

int main() {

	polynomial A = {3, {4, 3, 5, 0}};
	polynomial B = {4, {3, 1, 0, 2, 1}};
	
	polynomial C = addPoly(A, B);
	
	printf("\n A(x)="); printPoly(A);
	printf("\n B(x)="); printPoly(B);
	printf("\n C(x)="); printPoly(C);

	return 0;

}