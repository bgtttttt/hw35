#include <iostream>
#include <time.h>
#include <string>

#define m 3
#define n 4

using namespace std;

string matrToString(int matrix[][n]);
void randMatr(int matrix[][n], int min, int max);
int sum_higher_gen_diag(int matrix[][n]);
int max_under_gen_diag(int matrix[][n]);
int count_even_higher_sec_diag(int matrix[][n]);
int count_pos_under_sec_diag(int matrix[][n]);
bool is_there_zero_under_sec_diag(int matrix[][n]);

int main() {
	srand(time(0));
	int matrix[m][n];
	randMatr(matrix, -100, 100);
	cout << "Matrix:" << endl;
	cout << matrToString(matrix);

	cout << "Sum of values higher than gen diag: " << sum_higher_gen_diag(matrix);
	cout << "\nMax value under the gen diag: " << max_under_gen_diag(matrix);
	cout << "\nNumber of even numbers higher than sec diag: " 
		<< count_even_higher_sec_diag(matrix);
	cout << "\nNumber of positive numbers under the sec diag: " 
		<< count_pos_under_sec_diag(matrix);
	cout << "\nThere "<< (is_there_zero_under_sec_diag(matrix)?"are some":"aren't any") << " zeros";

	return 0;
}
//A1
int sum_higher_gen_diag(int matrix[][n]) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			sum += matrix[j][i];
		}
	}
	return sum;
}
//B2
int max_under_gen_diag(int matrix[][n]) {
	int max = -200;//генерация чисел от -100 до 100
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < m; j++) {
			if (max < matrix[j][i]) {
				max = matrix[j][i];
			}
		}
	}
	return max;
}
//C3
int count_even_higher_sec_diag(int matrix[][n]) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-1-i; j++) {
			if (matrix[j][i]%2==0) {
				count++;
			}
		}
	}
	return count;
}
//D4
int count_pos_under_sec_diag(int matrix[][n]) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = m - i; j < m; j++) {
			if (matrix[j][i] > 0) {
				count++;
			}
		}
	}
	return count;
}
//E4
bool is_there_zero_under_sec_diag(int matrix[][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = m - i; j < m; j++) {
			if (matrix[j][i] == 0) {
				return true;
			}
		}
	}
	return false;
}