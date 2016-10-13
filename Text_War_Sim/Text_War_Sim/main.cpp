#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	int humans;
	int robots;
	int EMP = 0;
	int bomb = 0;
	//  Create random number generator
	mt19937 randomGenerator(time(0));
	uniform_real_distribution<float> attackVal(0.0f, 1.0f);

	// Print name of game
	cout << "The Omnic Crisis" << endl;

	cout << "Input number of humans: ";
	cin >> humans;
	cout << "Input number of robots: ";
	cin >> robots;
	cout << "\n\n";

	cout << "*Intense Combat noises*\n";
	cout << "Combat Ended\n";
	//cout << attackVal(randomGenerator) << endl;
	// If an attack is successful, the opponent loses a member
	// TODO: implement health, attack strength for soldiers

	while (robots > 0 && humans > 0) {
		float randomValue = attackVal(randomGenerator);
		// 30% chance of a successful attack
		if ( randomValue <= 0.30) {
			robots -= 1;
		}
		else if ( randomValue >= 0.5) {
			humans -= 1;
		}
		else if (randomValue > 0.30 && randomValue <= 0.40) {
			robots -= (robots / 10); // An EMP drops and kills 10% of the robots
			EMP += 1;
		}
		else {
			humans -= (humans / 10); // A bomb drops and kills 10% of the humans
			bomb += 1;
		}
		
	}
	// Print Bombs and Emp's dropped
	cout << EMP << " EMP's were dropped, and " << bomb << " bombs were dropped\n\n";

	// Print Victor and survivors
	if (robots > 0) {
		cout << "The Omnic are victorious!\n" << "There are " << robots << " omnic intact\n";
	}
	else {
		cout << "The Humans defeat the Machines!\n" << "There are " << humans << " still alive\n";
	}
	


	system("PAUSE");
	return 0;
}
