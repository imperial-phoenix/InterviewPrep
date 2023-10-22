# Задаем имя теста.
set(TARGET_NAME "MatrixTest")

# Создаем исполняемый файл для теста.
add_executable(${TARGET_NAME} MatrixTest.cpp)

# Подключаем тестируемую библиотеку.
target_link_libraries(${TARGET_NAME} PRIVATE Matrix)