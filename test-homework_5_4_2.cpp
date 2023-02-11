#include <iostream>
#include <windows.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


#include "classes.cpp"

//PushBack.
//PushFront.
//PopBack.Проверьте правильность работы на пустом списке.
//PopFront.Проверьте правильность работы на пустом списке.

TEST_CASE("test List", "[list]") {

	SECTION("push&pop") {
		List list1;
		list1.PushBack(3);
		int front = 2,
			back = 4;
		list1.PushFront(front);		
		list1.PushBack(back);		
		{
			INFO("Некорректно записан/извлечен первый элемент");
			CHECK(list1.PopFront() == front);
		}
		{
			INFO("Некорректно записан/извлечен последний элемент");
			CHECK(list1.PopBack() == back);
		}
		list1.PopBack();
		{
			INFO("Ошибка обработки извлечения первого элемента из пустого списка");
			CHECK_THROWS(list1.PopFront());
		}
		{
			INFO("Ошибка обработки извлечения последнего элемента из пустого списка");
			CHECK_THROWS(list1.PopBack());
		}	
	}

}

int main() {

	return Catch::Session().run();

}