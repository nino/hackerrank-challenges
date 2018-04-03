#include <iostream>
#include <string>

// https://www.hackerrank.com/challenges/the-time-in-words/problem
// Run `clang++ the-time-in-words.cc -std=c++14 && ./a.out`.

std::string trim_whitespace(std::string s) {
  const std::string whitespace = " \n\t\r";
  int start = s.find_first_not_of(whitespace);
  int end = s.find_last_not_of(whitespace) + 1;
  int length = end - start;
  return s.substr(start, length);
}

std::string number_to_word(int number) {
  switch (number) {
  case 1:
    return "one";
  case 2:
    return "two";
  case 3:
    return "three";
  case 4:
    return "four";
  case 5:
    return "five";
  case 6:
    return "six";
  case 7:
    return "seven";
  case 8:
    return "eight";
  case 9:
    return "nine";
  case 10:
    return "ten";
  case 11:
    return "eleven";
  case 12:
    return "twelve";
  case 13:
    return "thirteen";
  }
  int tens = number / 10;
  switch (tens) {
  case 1:
    return number_to_word(number % 10) + "teen";
  case 2:
    return trim_whitespace("twenty " + number_to_word(number % 10));
  case 3:
    return trim_whitespace("thirty " + number_to_word(number % 10));
  case 4:
    return trim_whitespace("fourty " + number_to_word(number % 10));
  case 5:
    return trim_whitespace("fifty " + number_to_word(number % 10));
  }
  return "unknown number";
}

int base12_hour(int hour) { return ((hour - 1) % 12) + 1; }

std::string time_in_words(int hour, int minute) {
  std::string hour_word = number_to_word(base12_hour(hour));
  std::string next_hour_word = number_to_word(base12_hour(hour + 1));
  if (minute == 0) {
    return hour_word + " o' clock";
  } else if (minute == 1) {
    return "one minute past " + hour_word;
  } else if (minute == 15) {
    return "quarter past " + hour_word;
  } else if (minute == 30) {
    return "half past " + hour_word;
  } else if (minute == 45) {
    return "quarter to " + next_hour_word;
  } else if (minute == 59) {
    return "one minute to " + next_hour_word;
  } else if (minute > 30) {
    return number_to_word(60 - minute) + " minutes to " + next_hour_word;
  } else {
    return number_to_word(minute) + " minutes past " + hour_word;
  }
}

int main() {
  int hour;
  int minute;
  std::cin >> hour >> minute;
  std::cout << time_in_words(hour, minute) << std::endl;
}
