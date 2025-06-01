#pragma once

constexpr size_t NO_MESSAGES = 0;
constexpr size_t INITIAL_CAPACITY = 50;
constexpr size_t INITIAL_SIZE = 0;
constexpr size_t DEFAULT_VALUE = 0;
constexpr size_t INDEX_FIX = 1;

constexpr int NOT_FOUND = -1;
constexpr int NO_ID = -1;

constexpr int COUNT_OF_BEST_SELLING_PRODUCTS = 3;


enum OrderStatus {
	PENDING,
	SHIPPED,
	DELIVERED
};

//constexpr char NO_NAME[] = "";
//constexpr char NO_PASSWORD[] = "";