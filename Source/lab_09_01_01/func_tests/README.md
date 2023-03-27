# Тесты к лабораторной работе 9, задача 1

Входные данные: app.exe FILE FIELD [KEY]  
Выходные данные : 
- Если значение ключа не указано, выводит упорядоченный массив.
- Если значение ключа указано, выполняет двоичный поиск по полю и значению  
ключа. Если кинофильм с искомым значением ключа найден, программа выводит  
информацию о нём на экран, иначе программа выводит сообщение «Not found». 

## Позитивные тесты:
- 01 - одна запись, сортировка по названию;  
- 02 - одна запись, сортировка по имени;
- 03 - одна запись, сортировка по году;
- 04 - несколько записей, сортировка по названию;  
- 05 - несколько записей, сортировка по имени;  
- 06 - несколько записей, сортировка по году;   
- 07 - несколько записей, проверка устойчивости сортировки по имени режиссера;
- 08 - несколько записей, поиск по названию (результативный);
- 09 - несколько записей, поиск по имени (результативный);
- 10 - несколько записей, поиск по году (результативный);
- 11 - несколько записей, поиск по названию (нерезультативный);
- 12 - несколько записей, поиск по имени (нерезультативный);
- 13 - несколько записей, поиск по году (нерезультативный);  


## Негативные тесты:
- 01 - несуществующий файл;
- 02 - некорректное кол-во ключей;
- 03 - кол-во ключей корректное, неправильные значения ключей;
- 04 - некорректное содержимое файла (некорректный год);
- 05 - некорректное содержимое файла (неверный формат записей);
- 06 - пустой файл;
- 07 - превышение количества записей;
- 08 - кол-во ключей корректное, некорректный ключ поиска года.