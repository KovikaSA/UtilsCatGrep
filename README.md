
# Проект: Реализация утилит `cat` и `grep`

## Описание

Данный проект представляет собой реализацию двух классических утилит командной строки: `cat` и `grep`, с поддержкой различных флагов и функций, аналогичных GNU-версиям. Основной целью проекта является создание собственных версий этих утилит с поддержкой всех необходимых флагов и возможностей для работы с файлами и текстом.

### Часть 1: Утилита `cat`

Утилита `cat` предназначена для отображения содержимого файлов в консоли. Реализованная версия поддерживает все стандартные флаги, предоставляемые GNU версией утилиты.

#### Поддерживаемые флаги:

- `-b` — нумерация непустых строк.
- `-e` — эквивалент флагов `-vE` (показывает символы конца строки).
- `-n` — нумерация всех строк.
- `-s` — удаление последовательных пустых строк.
- `-t` — эквивалент флагов `-vT` (показывает табуляции).
- Другие флаги согласно спецификации GNU `cat`.

#### Структура файлов для `s21_cat`:
- Исходные и заголовочные файлы: `src/cat/`
- Итоговый исполняемый файл: `src/cat/s21_cat`

### Часть 2: Утилита `grep`

Утилита `grep` предназначена для поиска строк в файлах на основе регулярных выражений. Реализованная версия поддерживает несколько ключевых флагов для гибкого поиска, а также возможность использования регулярных выражений через библиотеки `pcre` или `regex`.

#### Поддерживаемые флаги:

- `-e` — поиск по шаблону (регулярное выражение).
- `-i` — игнорирование регистра.
- `-v` — инверсия поиска (вывод строк, не совпадающих с шаблоном).
- `-c` — подсчет количества совпадающих строк.
- `-l` — вывод только имен файлов с совпадениями.
- `-n` — вывод номеров строк с совпадениями.

#### Структура файлов для `s21_grep`:
- Исходные и заголовочные файлы: `src/grep/`
- Итоговый исполняемый файл: `src/grep/s21_grep`

### Часть 3: Дополнительно: Расширенная реализация `grep`

В этом разделе реализованы дополнительные флаги для утилиты `grep` для улучшения функциональности.

#### Поддерживаемые флаги:

- `-h` — отключение вывода имен файлов в результатах поиска.
- `-s` — подавление сообщений об ошибках, например, когда файл не найден.
- `-f` — получение шаблонов поиска из файла.
- `-o` — вывод только совпадающих частей строк.

### Часть 4: Дополнительно: Комбинации флагов для `grep`

В этом разделе реализована поддержка комбинаций флагов, например, `-iv` или `-in`, для повышения гибкости использования утилиты `grep`.

## Установка и запуск

1. Клонируйте репозиторий проекта:
   ```bash
   git clone [<ссылка на репозиторий>](https://github.com/KovikaSA/UtilsCatGrep.git)
   ```

2. Перейдите в директорию проекта:
   ```bash
   cd <путь к проекту>
   ```

3. Для сборки утилит `cat` и `grep` используйте make:
   ```bash
   make
   ```

4. Для запуска утилиты `cat`:
   ```bash
   ./src/cat/s21_cat [флаги] [файлы]
   ```

5. Для запуска утилиты `grep`:
   ```bash
   ./src/grep/s21_grep [флаги] [шаблон] [файлы]
   ```

## Тестирование

Тесты для утилит можно запустить с помощью следующих команд:
```bash
make test_cat  # для тестов cat
make test_grep  # для тестов grep
```

Тесты проверяют корректность работы утилит с разными флагами и комбинациями флагов на основе нескольких тестовых файлов.

## Заключение

Проект реализует основные функции утилит `cat` и `grep`, обеспечивая поддержку всех необходимых флагов и возможностей для работы с текстовыми данными. Расширенная реализация также добавляет поддержку сложных комбинаций флагов и работу с регулярными выражениями, что делает утилиты гибкими и удобными в использовании.
