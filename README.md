# 🧱 BrickGame — Tetris на C

Реализация классического Tetris на языке C под Linux с использованием **ncurses**.  
Разделён на ядро (game logic) и интерфейс (UI), покрыт unit-тестами с использованием **Check**, включает Makefile и отчёт о покрытии кода.
![BrickGameConsole](misc/images/brickgame-console.jpg)
---

### 🧠 Основная идея

Проект демонстрирует архитектуру **Finite State Machine (FSM)** — конечного автомата, управляющего состояниями игры.  
Каждый элемент (фигуры, поле, события) реализован как отдельный модуль с чётким интерфейсом.

---

### 🧰 Технологии и стек

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![ncurses](https://img.shields.io/badge/ncurses-6C757D?style=for-the-badge)
![Makefile](https://img.shields.io/badge/Makefile-0769AD?style=for-the-badge)
![Check](https://img.shields.io/badge/Check-009639?style=for-the-badge)
![Gcov](https://img.shields.io/badge/Gcov-4B32C3?style=for-the-badge)
![GitHub Actions](https://img.shields.io/badge/GitHub_Actions-2088FF?style=for-the-badge&logo=githubactions&logoColor=white)

---

### 🧩 Возможности

- Полная игровая логика: генерация фигур, проверка столкновений, удаление линий  
- Хранение рекордов между сессиями  
- Динамическая скорость в зависимости от уровня  
- FSM для управления состояниями (`spawn`, `fall`, `clear`, `pause`)  
- Более 80% покрытия unit-тестами  
- Makefile-цели: `all`, `test`, `gcov_report`, `install`, `clean`

---

### ⚙️ Сборка и запуск

```bash
make
./bin/tetris
