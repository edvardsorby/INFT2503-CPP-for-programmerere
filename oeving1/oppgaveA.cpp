#include <iostream>

using namespace std;

int main() {

  const int length = 5;
  cout << "Du skal skrive inn " << length << " temperaturer.\n";

  int belowTen = 0;
  int tenToTwenty = 0;
  int aboveTwenty = 0;

  for (size_t i = 0; i < length; i++) {
    cout << "Temperatur nr " << i << ": ";

    double temp;
    cin >> temp;

    if (temp < 10) {
      belowTen++;
    } else if (temp >= 10 && temp <= 20) {
      tenToTwenty++;
    } else if (temp > 20) {
      aboveTwenty++;
    }
  }

  cout << "Antall under 10 er " << belowTen << "\n";
  cout << "Antall mellom 10 og 20 er " << tenToTwenty << "\n";
  cout << "Antall over 20 er " << aboveTwenty << "\n";
}
