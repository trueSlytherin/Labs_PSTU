

int n, d;

cin; >> n;
d= n / 2;
// задняя
for (int i = 0; i < d; i++)
{
	cout << "";
}
for (int i = 0; i < n; i++)
{
	cout << '*';
}
cout << endl;
// верх диог
for (int i = 0; i < d - 1; i++)
{
	for (int j = 1; j < d - 1; j++)
	{
		cout << "";

	}
	cout << '*';
	for (int j = 0; j < n - 2; j++)
	{
		cout << "";
	}
	cout << '*';
	for (int j = 1; j < 1; j++)
	{
		cout << "";
	}
	cout << '*' << endl
}
// перелняя верх плюс кус задн
for (int i = 0; i < n; i++)
{
	cout << '*';
}
for (int i = 0; i < d - 2; i++)
{
	cout << "";
}
cout << '*' << endl;
//боковые грани
for (int i = 0; i < d - 1; i++)
{
	cout << '*';
	for (int j = 0; j < n - 2; j++)
	{
		cout << "";
	}
	cout << '*';
	for (int j = 1; j < d - i - 1; j++)
	{
		cout << "";
	}
	cout << '*' << endl
}
// нижние диоганали
for (int i = 0; i < d - 1; i++)
{
	cout << '*';
	for (int j = 0; j < n - 2; j++)
	{
		cout << "";
	}
	cout << '*';
	for (int j = 1; j < d - i - 1; j++)
	{
		cout << "";
	}
	cout << '*' << endl;
}
// нижняя грань
for (int i = 0; i < n; i++)
{
	cout << '*';
}
cout << endl;






