# Лабораторная работа 8

## Теоретическая справка
**Что такое алгоритмы STL?**

Контейнеры STL представляли бы собой красивую выдумку, достаточно далёкую от
практического использования (как и было в первые годы существования STL),
если бы не следующее обстоятельство: из-за единой общей природы всех контейнеров
основные алгоритмы, представляющие интерес на практике, могут быть реализованы
в обобщённом виде, применимом к любым типам контейнеров. Алгоритмы — это самая
объёмная и самая востребованная часть библиотеки. Предоставляется настолько много
алгоритмов, что для детального описания их всех не хватит и объёмной книги.
В данной лабораторной работе вам предстоит ознакомиться лишь с некоторыми из них.

Описание всех алгоритмов вы найдете по [ссылке](https://en.cppreference.com/w/cpp/algorithm).

### Использование алгоритмов STL

#### `std::find`
Функция `std::find` ищет в диапазоне параметров `[first, last)` первый элемент, равный `value`

```cpp
template< class InputIt, class T >
InputIt find( InputIt first, InputIt last, const T& value );
```


#### `std::find_if`
Алгоритм `std::find_if` находит позицию первого вхождения элемента, удовлетворяющего определенному условию,
в диапазоне `[first, last)`.

```cpp
template<class InputIterator, class Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate pred);
```

Параметр `pred` - определенная пользователем функция, объект функции или лямбда-выражение,
определяющее условие, которое должно удовлетворяться искомым элементом. Предикат
берет один аргумент и возвращает `true` (условие удовлетворено) или `false` (условие
не удовлетворено). Прототип `pred` должна быть `bool pred(const T& arg);`, где `T` — тип,
к которому можно явным образом привести `InputIterator` при разименовании. Ключевое
слово `const` указывает, что объект функции или лямбда не должен изменять аргумент.

**Задача**. Найти первое четное число в контейнере.
```cpp
bool even(int a)
{
    return !odd(a);
}

// ...
std::vector<int> v = {1, 3, 5, 6, 7, 8, 9};
auto it2 = std::find_if(v.begin(), v.end(), even);
if (it2 == v.end())
  std::cout << "Все число нечетные";
else
  std::cout << *it2;
```

#### `std::count_if`
С помощью `std::count_if` можно легко получить количество элементов в диапазоне `[first, last)`, удовлетворяющих определенному
условию. Подсчитывает элементы, для которых предикат `pred` возвращает значение true. О том,
что такое предикат, можно прочитать выше.

```cpp
template< class InputIt, class UnaryPredicate >
typename iterator_traits<InputIt>::difference_type
count_if(InputIt first, InputIt last, UnaryPredicate pred);
```

**Задача**. Посчитать какое количество четных элементов в массиве
```cpp
bool even(int a)
{
    return !odd(a);
}

// ...
std::vector<int> v = {1, 3, 5, 6, 7, 8, 9};
auto count = std::count_if(v.begin(), v.end(), even);
std::cout << count;
```

#### `std::transform`
```cpp
template <class InIter, class OutIter, class Funс>
OutIter transform(InIter start, InIter end,
		  OutIter result, Func unaryfunc);
template <class InIter1, class InIter2, class OutIter, class Func>
OutIter transform(InIter1 start1, InIter1 end1, InIter2 start2,
		  OutIter result, Func binaryfunc);
```
Алгоритм `transform()` применяет функцию к диапазону элементов и сохраняет результат
в последовательности, заданной параметром `result`. В первой форме диапазон задается
параметрами `start` и `end`. Применяемая функция задается параметром `unaryfunc`.
Она принимает значение элемента в качестве параметра и должна возвратить преобразованное
значение.
Во второй форме алгоритма преобразование применяется с использованием бинарной функции,
которая принимает значение элемента из последовательности, предназначенного для преобразования,
в качестве первого параметра и элемент из второй последовательности в качестве второго параметра.
Обе версии возвращают итератор, указывающий на конец результирующей последовательности.

**Задача**. Заменить в исходном массиве все элементы на квадрат этих значений.
```cpp
int pow2(int a)
{
    return a * a;
}

// ...
std::vector<int> v = {1, 3, 5, 6, 7, 8, 9};
std::transform(v.begin(), v.end(), v.begin(), pow2);
// или так
std::vector<int> v = {1, 3, 5, 6, 7, 8, 9};
std::transform(v.begin(), v.end(), v.begin(), [](int a){ retunr a * a; });
```

**Задача**. Данно два массива, получить новый массив, каждый элемент которого будет равен сумме соответсвующих элементов в изначальном.
```cpp
int sum(int a, int b)
{
    return a + b;
}

// ...
std::vector<int> v0 = {1, 3, 5, 6, 7, 8, 9};
std::vector<int> v1 = {-1, -3, -5, -6, -7, -8, -9};
std::vector<int> out(v0.size());
std::transform(v0.begin(), v0.end(), v1.begin(), out.begin(), sum);
```

#### `std::sort`
Сортировка последовательности `[first, last)`.
```cpp
template<class RandomAccessIterator>
void sort(RandomAccessIterator first,
          RandomAccessIterator last);

template<class RandomAccessIterator, class Predicate>
void sort(RandomAccessIterator first,
          RandomAccessIterator last,
          Predicate comp);
```

Первая форма алгоритма использует дефолтный функтор сравнения, а вторая позволяет
задать его самостоятельно.
Компаратор(смотри вторую форму) — это определенный пользователем объект функции
или лямбда-выражение, который как бы учит сортировать `sort`.

Так, например, можно сортировать по:
кратности на 3, четности или нечетности, изменить сторону сортировки на — по убыванию.
`sort` передает элементы компаратору, а компаратор проверяет их по вашему
алгоритму и передает `true` или `false`.

**Задача**. Отсортировать массив строк по *длине* строк, а не в лексикографическом порядке.
```cpp
bool compare_length(const std::string& a, const std::string& b)
{
    return a.size() < b.size();
}

std::sort(v.begin(), v.end(), compare_length);
```


#### `std::any_of`
Данный алгоритм проверяет, что предикат `pred` возвращает значение `true` для **хотя бы** одного элемента
в диапазоне `[first, last)`.
```cpp
template< class InputIt, class UnaryPredicate >
bool any_of(InputIt first, InputIt last, UnaryPredicate pred);
```

### Что такое лямбда-функция?
Лямбда-выражение (или просто лямбда) в `C++11` — это удобный способ определения анонимного
объекта-функции непосредственно в месте его вызова или передачи в функцию в качестве аргумента.
Если нужна функция, можно описать её лямбдой, а не описывать отдельную функцию, загромождая код.
Удобно в `STL`. Удобно когда выражение короткое. Иначе код становится ужасно читаем.
Лямбда-выражениями называются безымянные локальные функции, которые можно создавать
прямо внутри какого-либо выражения.
В этом примере лямбда-выражение передается в качестве аргумента функции `find_if`.
Лямбда-выражение возвращает значение `true`, если его параметром является четное число.
```cpp
list<int> numbers;
numbers.push_back(13);
numbers.push_back(17);
numbers.push_back(42);
numbers.push_back(46);
numbers.push_back(99);
auto result = find_if(numbers.begin(), numbers.end(),
                      [](int n){ return (n % 2) == 0; });
```
Для полного понимания того, как использовать лямбда- выражения, следует заглянуть
[сюда](https://msdn.microsoft.com/ru-ru/library/dd293599.aspx)

**Примеры, с которыми следует ознакомиться**
* [Здесь](https://github.com/bmstu-iu8-cpp/cpp-beginner-2017/tree/master/lab8)


## Задание
Требуется все задания выполнить с использованием библиотеки `<algorithm>`.

Пусть есть структура `Student`
```cpp
struct Student
{
  std::string Name;
  std::string GroupId;
  std::vector<unsigned> Ratings;
  std::vector<std::string> Subjects;
};
```
В поле `Ratings` представлены оценки по соответсвующему предмету из поля `Subjects`.
Предположим есть список студентов `std::vector<Student> students`.
Ваше задание состоит в реализации ряда функций. Все прототипы функций необходимо разместить
в файле header.hpp.

Реазилуйте функции, которые выполяют следующие действия с этим списком:
* отсортирует всех студентов по именам. Прототип:
```cpp
void SortByName(std::vector<Student>&);
```
* отсортирует всех студентов по средней оценке;
```cpp
void SortByRating(std::vector<Student>&);
```
* вернет количество студентов имеющих неудовлетворительную оценку хотя бы по одному предмету;
```cpp
size_t CountTwoness(const std::vector<Student>&);
```
* определит, сколько студентов сдали все экзамены на 5.
```cpp
size_t CountExcellent(const std::vector<Student>&);
```
* создаст массив `std::vector<Student>`, в который войдут студенты имеющие отметку отлично, по предмету "Math";
```cpp
std::vector<Student> VectorMathExcellent(const std::vector<Student>&);
```
* вернет массив уникальных названий групп студентов из списка students
```cpp
std::vector<std::string> GroupsId(const std::vector<Student>&);
```
* сформирует список групп, т.е. создаст массив структур `Group`
```cpp
struct Group
{
    std::string Id;
    std::vector<Student> Students;
};
```

Прототип:
```cpp
std::vector<Group> Groups(const std::vector<Student>&);
```
