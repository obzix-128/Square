# Qwadratka
![alt text](1685400490_polinka-top-p-kotiki-milashki-kartinki-krasivo-36-1.jpg)
## Назначение:
Программа, предназначенная для решения квадратных уравнений.

> ax^2 + bx + c = 0
*****
## Инструкция:
Чтобы запустить программу необходимо указать хотя бы один из 4 флагов для выбора режима работы.

> - -h
> - -t
> - -s
> - -f *[Имя файла]*

Можно запускать программу указывая несколько флагов, все режимы будут запущены в соответствии с порядком введёных флагов.

### Флаг -h
Вам будет выведено руководство по запуску программы.

### Флаг -t
Будет запущенно встроенное тестирование программы, встроенных тестов 9, но пользователь может увеличить их количество (максимум 25), вписав в файле "Tese.txt" в новую строку сначала значения коэффициентов **a, b, c** затем корни и их количество, разделяя пробелами, а также в первой строке указать новое число тестов.

### Флаг -s
При запуске программы вам будет предложено ввести коэффициенты квадратного уравнения (a, b, c), нужно ввести их используя цифры и разделяя пробелами.

В случае невверного ввода вам будет предложено попробовать снова. После трёх неудачных повторных попыток программа завершится.

В случае успешного ввода на экране отобразятся принятые значения, и после завершения расчётов найденные корни уравнения выведутся на экран.

Далее вам будет предложено ввести [Enter], чтобы завершить программу либо любой другой знак, чтобы решить ещё одно квадратное уравнение.

### Флаг -f
Данный режим предлагает пользователю указать файл из которого программа возьмёт значения. Первой строкой должно быть указано количество тестов, а в следующих должны содержаться коэффициенты **a, b, c** разделённые пробелами.

Программа решает не более 10 уравнений из файла.
*****
## Автор:
Программа была написана студентом ФРКТ МФТИ *Горбуновым Константином* для изучения языка программирования С в рамках дополнительных курсов "Летняя школа".
*****
