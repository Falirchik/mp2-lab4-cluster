#include "task.h"
#include "queue.h"
#include "cluster.h"
#include "statistic.h"
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");

	int tact,
		_cpu;

	srand(time(0));

	cout << "������� ���������� �����������: \t";
	cin >> _cpu;
	
	cout << "������� ���������� ������: \t";
	cin >> tact;
	

	Cluster cl(_cpu);
	cl.StartCluster(tact);
<<<<<<< HEAD
	cl.Print();
=======
	cl.PrintStatistic();
>>>>>>> lab4.0

	system("pause");
	return 0;
}