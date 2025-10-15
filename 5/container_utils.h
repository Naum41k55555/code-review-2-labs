/*  
    Продолжение задания №5 файл реализации
    Элементами контейнеров являются целые числа. Для
    заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
    для вывода элементов использовать итератор (для вывода элементов в обратном порядке
    использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
    Обязательно наличие дружественного интерфейса. Ввод данных организовать 
    разными способами (с клавиатуры, рандом, из файла)

    Даны вектор V, дек D и список L. Каждый исходный контейнер содержит не менее
    двух элементов, количество элементов является четным. Поменять значения двух средних
    элементов каждого из исходных контейнеров. Использовать алгоритм swap (не путать его с
    одноименной функцией-членом контейнера).
*/

#ifndef CONTAINER_UTILS_H
#define CONTAINER_UTILS_H

#include <vector>
#include <deque>
#include <list>
#include <string>

/**
 * @class ContainerUtils
 * @brief Класс-утилита со статическими методами для работы с контейнерами STL.
 */
class ContainerUtils {
public:
	/**
	 * @enum InputMethod
	 * @brief Определяет способы заполнения контейнера данными.
	 */
	enum class InputMethod {
		kKeyboard = 1,
		kRandom = 2,
		kFile = 3
	};

	/**
	 * @brief Заполняет контейнер данными выбранным способом.
	 * @tparam Container Тип контейнера (std::vector, std::deque, std::list).
	 * @param container Ссылка на контейнер для заполнения.
	 * @param size Требуемое количество элементов (должно быть четным и >= 2).
	 * @param method Метод заполнения из перечисления InputMethod.
	 * @return `true` в случае успеха, `false` при возникновении ошибки.
	 */
	template<typename Container>
	static bool FillContainer(Container& container, size_t size, InputMethod method);

	/**
	 * @brief Выводит элементы контейнера в консоль в прямом порядке.
	 * @tparam Container Тип контейнера.
	 * @param container Константная ссылка на контейнер для вывода.
	 */
	template<typename Container>
	static void PrintContainer(const Container& container);

	/**
	 * @brief Выводит элементы контейнера в консоль в обратном порядке.
	 * @tparam Container Тип контейнера.
	 * @param container Константная ссылка на контейнер для вывода.
	 */
	template<typename Container>
	static void PrintReversed(const Container& container);

	/**
	 * @brief Меняет местами два средних элемента в контейнере.
	 * @details Работает только для контейнеров с четным количеством элементов >= 2.
	 * @tparam Container Тип контейнера.
	 * @param container Ссылка на контейнер для модификации.
	 */
	template<typename Container>
	static void SwapMiddleElements(Container& container);

private:
	/**
	 * @brief [Приватный] Заполняет контейнер целыми числами с клавиатуры.
	 */
	template<typename Container>
	static void FillFromKeyboard(Container& container, size_t size);

	/**
	 * @brief [Приватный] Заполняет контейнер случайными числами.
	 */
	template<typename Container>
	static void FillWithRandom(Container& container, size_t size);

	/**
	 * @brief [Приватный] Заполняет контейнер данными из файла.
	 */
	template<typename Container>
	static bool FillFromFile(Container& container, size_t size);
};

#endif // CONTAINER_UTILS_H
