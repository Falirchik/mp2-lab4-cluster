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
	
	try {
		Cluster cl(_cpu);
		cl.StartCluster(tact);
		cl.PrintStatistic();
	}
	catch (const char*str) {
		cout << str<<endl;
	}
	system("pause");
	return 0;
}