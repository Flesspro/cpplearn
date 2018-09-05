#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons)
{
	int median_all,
		median_females,
		median_males,
		median_females_employed, median_females_unemployed,
		median_males_employed, median_males_unemployed;

	auto partition_by_gender = partition(begin(persons), end(persons),
			[](const Person& p) {
				return p.gender == Gender::FEMALE;
			}
	);

	auto partition_females_employment = partition(begin(persons), partition_by_gender,
			[](const Person& p) {
				return p.is_employed;
			}
	);

	auto partition_males_employment = partition(partition_by_gender, end(persons),
			[](const Person& p) {
				return p.is_employed;
			}
	);

	median_all = ComputeMedianAge (begin(persons), end(persons));
	cout << "Median age = " << median_all << endl;

	median_females = ComputeMedianAge (begin(persons), partition_by_gender);
	cout << "Median age for females = " << median_females << endl;

	median_males = ComputeMedianAge (partition_by_gender, end(persons));
	cout << "Median age for males = " << median_males << endl;

	median_females_employed = ComputeMedianAge (begin(persons),
			partition_females_employment);
	cout << "Median age for employed females = " << median_females_employed << endl;

	median_females_unemployed = ComputeMedianAge (partition_females_employment,
			partition_by_gender);
	cout << "Median age for unemployed females = " << median_females_unemployed << endl;

	median_males_employed = ComputeMedianAge (partition_by_gender,
			partition_males_employment);
	cout << "Median age for employed males = " << median_males_employed << endl;

	median_males_unemployed = ComputeMedianAge (partition_males_employment,
			end(persons));
	cout << "Median age for unemployed males = " << median_males_unemployed << endl;
}

int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
