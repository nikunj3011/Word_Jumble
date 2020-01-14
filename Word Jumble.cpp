/**
* @file <Source.cpp>
*
* @author  <Nikunj Rathod>
* @version <1.0>
*
* change log
* name      date
*
*
* (file, auther, version, and change log are depricated with modern source code management system)
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
*
* @section DESCRIPTION
*  < Assignment 3 Word Jumble >
*
*
* @section LICENSE
*  <Public>
*
*  Copyright 2019
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/
#include <iostream>
#include <ctime>
#include<string>
#include<cstdlib>
#include <Windows.h>
#include<sstream>
#include <algorithm>
int main() {	
	std::stringstream ss{ "" };
	char c;
	bool isQuitting = false;
	//while loop for constantly be ingame unless user press quit i.e. Q or q
	while (!isQuitting) {
		system("cls");
		//main menu
		std::cout <<
			"****************Word Jumble*****************\n" <<
			"*  (P)- Play Word Jumble                   *\n" <<
			"*  (Q)- Quit Program                       *\n" <<
			"********************************************\n";
		std::cout << ss.str();
		std::stringstream().swap(ss);
		std::cin >> c;
		//using if loop for playing the game when player press p or P
		if (c == 'p' || c == 'P') {
			//10 words used in jumble game
			/*std::string jumbled[10][2]= {   {"hello","a"},
										{"dolly","b"},
										{"world","c"},
										{"correct","d"},
										{"information","e"},
										{"technology","f"},
										{"gaming","g"},
										{"development","h"},
										{"programming","i"},
										{"experience","j "}
									};
*/
			std::string jumbled[10][2] = { {"helly","a"},
										{"eleven","b"},
										{"wuhu","c"},
										{"noice","d"},
										{"happy","e"},
										{"uttarayan","f"},
										{"songs","g"},
										{"civil","h"},
										{"engineer","i"},
										{"plot","j "}
			};

			int word = 0;
			//select new word everytime loop starts
			srand((time(0)));

			int choice = (rand() % 10);

			std::string theword = jumbled[choice][word];
			std::string jumble = theword;

			int length = jumble.size();
			std::string guess;
			std::cout << "************Word Jumble Game***********\n";
			std::cout << "************Enter q or Q to quit*********\n";
			for (int i = 0; i < length; i++) {
				// to jumble the string
				int parameter1 = (rand() % length);

				int parameter2 = (rand() % length);

				char temp = jumble[parameter1];

				jumble[parameter1] = jumble[parameter2];

				jumble[parameter2] = temp;
			}

			std::cout << "the jumbled word= " << jumble << std::endl;

			std::cout << "enter your guess =  ";

			std::cin >> guess;
			//to be in loop until guess is right or user press q to quit
			while (guess != theword && guess != "q" && guess != "Q") {
				std::cout << "you have got wrong answer " << std::endl << std::endl;
				std::cout << std::endl << " guess again = ";
				std::cin >> guess;				
			}
			// for guess is right 
			if (guess == theword) {
				std::cout << std::endl << "you guessed it right " << std::endl;
			}
			// to quit from the loop
			else if (guess == "q" || guess == "Q") {
				std::cout << std::endl << "Bye" << std::endl;
			}

			//sleep to display option for 2s
			Sleep(2000);
			ss << "\nPress any key to continue\n";
		}
		//quit the program when player press q or Q 
		else if (c == 'q' || c == 'Q') {
			return 0;
		}
		//default option when user presses incorrect option
		else {
			std::cout << "Enter correct option";
			Sleep(2000);
		}
	}
		
}

