# Задаем имя теста.
set(TARGET_NAME "ArrayTest")

# Создаем исполняемый файл для теста.
add_executable(${TARGET_NAME} ArrayTest.cpp)

# Подключаем тестируемую библиотеку.
target_link_libraries(${TARGET_NAME} PRIVATE Array)

# Подключаем GoogleTest
target_link_libraries(${TARGET_NAME} PRIVATE gtest gtest_main)

# Автоматическое обнаружение и добавление тестов в пакет тестов CTest.
gtest_discover_tests(${TARGET_NAME})