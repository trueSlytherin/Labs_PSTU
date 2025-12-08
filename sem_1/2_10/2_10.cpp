int n, tmp, max;

cout << "Введите длину послед:" << endl;
cin >> n;

cout << "Введите первое число:" << endl;
cin >> n;
for (int i = 2; i <= n; i++)
{
	cout << "Введите след число:" << endl;
	cin >> tmp;
	if (tmo > max) { max = tmp; }
}
cout <<"максимальный элемент: " << max << endl;

