//Michael Jonas
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

string percentToLetter(double percentGrade){
	round(percentGrade);
	if(percentGrade >= 90)
		return "A+";
		
	else if(percentGrade >= 85 && percentGrade <= 89)
		return "A";
		
	else if(percentGrade >= 80 && percentGrade <= 84)
		return "A-";
		
	else if(percentGrade >= 77 && percentGrade <= 79)
		return "B+";
		
	else if(percentGrade >= 73 && percentGrade <= 76)
		return "B";
		
	else if(percentGrade >= 70 && percentGrade <= 72)
		return "B-";
		
	else if(percentGrade >= 67 && percentGrade <= 69)
		return "C+";
		
	else if(percentGrade >= 63 && percentGrade <= 66)
		return "C";
		
	else if(percentGrade >= 60 && percentGrade <= 62)
		return "C-";
		
	else if(percentGrade >= 57 && percentGrade <= 59)
		return "D+";
		
	else if(percentGrade >= 53 && percentGrade <= 56)
		return "D";
		
	else if(percentGrade >= 50 && percentGrade <= 52)
		return "D-";
		
	else if(percentGrade <= 49)
		return "F";
}

void quizCalc(double q1, double q2, double q3, double q4, double & quiz){
	quiz = (q1 + q2 + q3 + q4) / 4.0;
}

void gradeCalc(double PVS, double quiz, double FDL, double FDRNS, double reflect, double MTE, double FE, double& percentGrade){
	percentGrade = (PVS * 0.05) + (quiz * 0.1) + (FDL * 0.1) + (FDRNS * 0.06) + (reflect * 0.15) + (MTE * 0.27) + (FE * 0.27);
}

void outputStudent(ostream & out, string letterGrade, double grade){
	out << grade << "%   " << letterGrade << endl << endl;
}

//void

int main(){
	
	ofstream fout("grades.txt");
	
	cout << fixed << setprecision(2);
	
	double PVS, q1, q2, q3, q4, FDL, FDRNS, reflect, MTE, FE, quiz, percentGrade, roundedGrade;
	char cont;
	
	cout << "Hello Rachel! This program will help you calculate your student's grades! Hit enter after each piece of data that you submit!" << endl;
	
	//for(int i = 1; i <= 55; i++)
	do {
		cout << "Now enter the students PVS, 4 quiz grades, FD leader, FDRNS, reflection, MTE, and FE " << endl;
		cin >> PVS >> q1 >> q2 >> q3 >> q4 >> FDL >> FDRNS >> reflect >> MTE >> FE;
		quizCalc(q1,q2,q3,q4,quiz);
		gradeCalc(PVS, quiz, FDL, FDRNS, reflect, MTE, FE, percentGrade);
		roundedGrade = round(percentGrade);
		outputStudent(cout, percentToLetter(roundedGrade), percentGrade);
		cout << "would you like to enter more data?(y/n)" << endl;
		cin >> cont;
	}while(cont == 'y' || cont == 'Y');
		
	
	cout << "Thank you" << endl;
	
	return 0;
}

