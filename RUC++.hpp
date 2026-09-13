#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <random>
#include <type_traits>

std::random_device rd;
std::mt19937 rn(rd());

#define число int
#define строка std::string
#define символ char
#define дробьX2 float
#define дробьX4 double
#define бул bool
#define да true
#define нет false
#define пустота void
#define беззнаковый unsigned
#define конст const
#define длинный long

#define глав main
#define нач {
#define кон }
#define структура struct
#define класс class
#define публично public
#define приватно private


#ifdef _WIN32
void очистить_консоль() {
    std::system("cls");
}

void UTF8_виндовс() {
    std::system("chcp 65001 > nul");
}
#else
void очистить_консоль() {
    std::system("clear");
}
#endif

#define и &&
#define или ||
#define если if
#define иначе else
#define цикл for
#define пока while
#define свитч switch
#define кейс case
#define стоп break
#define прийти goto

#define ок ;
#define вернуть return


template <typename T>
using вектор = std::vector<T>;

template <typename T>
void добавить(std::vector<T>& vec, const T& arg) {
    vec.push_back(arg);
}

template <typename stdT, typename ... T>
void убрать(std::vector<stdT>& vec, const T& ... args) {
    (... , std::erase(vec, args));
}

template <typename T>
void развернуть_вектор(std::vector<T>& vec) {
    for (const auto& i : vec) {
        std::cout << i << '\n';
    }
}



#define флеш std::flush
#define эндл std::endl
#define стд std
#define коут std::cout
#define син std::cin

template <typename ... T>
void сказать(const T& ... args) {
    (std::cout << ... << args) << std::flush;
}

template <typename ... T>
void сказатьлн(const T& ... args) {
    (std::cout << ... << args) << std::endl; // flush + \n
}

template <typename ... T>
void читать(T& ... args) {
    (std::cin >> ... >> args);
}

template <typename T>
void читать_строку(T& x) {
    std::getline(std::cin, x);
}

void ждать(long long int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int рандом(long long int min, const long long int max) {
    std::uniform_int_distribution<long long int> frame(min, max);
    int x = frame(rn);

    return x;
}

void рамка(const std::string& c, const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << c;
    }
    std::cout << '\n';
}

template <typename T>
T монетка(const T& a, const T& b) {
    return (рандом(1, 2) == 1) ? a : b;
}

void систем(const std::string& command) {
    std::system(command.c_str());
}

#define __ДЛИННЫЙ_МАКС__ __LONG_MAX__
#define __ДЛИННЫЙ_ДЛИННЫЙ_МАКС__ __LONG_LONG_MAX__

void читать_игнор() {
    std::cin.ignore();
}


template <typename T>
T спросить(const std::string& vopros) {
    std::cout << vopros; // если надо можно написать /n в конце самому
    T x;

    if constexpr (std::is_same_v<T, std::string>) {
        if (std::cin.peek() == '\n') {
            std::cin.ignore();
        }
        std::getline(std::cin, x);
    }

    else {
        std::cin >> x;
    }
    return x;
}

void выход(const int x) {
    std::exit(x);
}

template <typename ... T>
std::string в_строку(T& ... args) {
    return (... + std::to_string(args));
}

template <typename ... T>
void ошибка(const T& ... args) {
    (std::cerr << ... << args);
}

template <typename ... T>
void ошибкалн(const T& ... args) {
    (std::cerr << ... << args) << '\n';
}

