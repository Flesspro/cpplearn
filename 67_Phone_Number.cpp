#include <string>
#include <iostream>
#include <sstream>
#include "phone_number.h"

using namespace std;


  /* Принимает строку в формате +XXX-YYY-ZZZZZZ
     Часть от '+' до первого '-' - это код страны.
     Часть между первым и вторым символами '-' - код города
     Всё, что идёт после второго символа '-' - местный номер.
     Код страны, код города и местный номер не должны быть пустыми.
     Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

     Примеры:
//     * +7-495-111-22-33
//     * +7-495-1112233
//     * +323-22-460002
//     * +1-2-coursera-cpp
//     * 1-2-333 - некорректный номер - не начинается на '+'
//     * +7-1233 - некорректный номер - есть только код страны и города
  */

size_t FindChar (const string& str, const size_t& pos, const char& ch)
{
	size_t res = str.find(ch, pos);
	if (res == string::npos)
	{
		throw invalid_argument ("+ or - is missing");
		return 0;
	}

	return res;
}

PhoneNumber::PhoneNumber(const string& international_number)
{
	size_t plus, minus1, minus2;

	plus = FindChar(international_number, 0, '+');
	minus1 = FindChar(international_number, plus+1, '-');
	minus2 = FindChar(international_number, minus1+1, '-');

	if (plus + 1 == minus1) {
		throw invalid_argument ("Country code is missing");
	} else PhoneNumber::country_code_ = international_number.substr(plus+1, minus1 - plus - 1);

	if (minus1 + 1 == minus2) {
		throw invalid_argument ("City code is missing");
	} else PhoneNumber::city_code_
		= international_number.substr(minus1 + 1, minus2 - minus1 - 1);

	if (minus2 + 1 == international_number.size()) {
		throw invalid_argument ("Local number is missing");
	} else PhoneNumber::local_number_
		= international_number.substr(minus2 + 1, international_number.size() - minus2);
}

string PhoneNumber::GetCountryCode() const
{
  return PhoneNumber::country_code_;
}

string PhoneNumber::GetCityCode() const
{
  return PhoneNumber::city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
  return PhoneNumber::local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
  return "+" + PhoneNumber::GetCountryCode() + "-" + PhoneNumber::GetCityCode() + "-" + PhoneNumber::GetLocalNumber();
}

//     * +7-495-111-22-33
//     * +7-495-1112233
//     * +323-22-460002
//     * +1-2-coursera-cpp
//     * 1-2-333 - некорректный номер - не начинается на '+'
//     * +7-1233 - некорректный номер - есть только код страны и города

//int main() {
//	PhoneNumber ph("+1-2-coursera-cpp");
//	cout << ph.GetCountryCode() << endl
//			<< ph.GetCityCode() << endl
//			<< ph.GetLocalNumber() << endl
//			<< ph.GetInternationalNumber() ;
//	return 0;
//}
