#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
  const int length = 5;

  int belowTen = 0;
  int tenToTwenty = 0;
  int aboveTwenty = 0;

  double temperatures[length];

  read_temperatures(temperatures, length);

  for (size_t i = 0; i < length; i++) {

    double temp = temperatures[i];

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

void read_temperatures(double temperatures[], int length) {

  const char filename[] = "temps.dat";
  ifstream file;      
  file.open(filename);
  if (!file) {  
    cout << "Feil ved åpning av innfil." << endl;
    exit(EXIT_FAILURE);
  }

  int number;
  int i = 0;
  while (file >> number && i < length) {
    temperatures[i++] = number;
  }

  file.close();
}
