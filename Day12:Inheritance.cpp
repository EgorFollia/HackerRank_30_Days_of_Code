#include <iostream>
#include <vector>

using namespace std;

class Person
{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification)
    {
			this -> firstName = firstName;
      this -> lastName = lastName;
			this -> id = identification;
		}

    void printPerson()
    {
			cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
		}
};

class Student :  public Person
{
	private:
		vector<int> testScores;
	public:
    Student(string fName, string lName, int id, vector<int> scores) : Person(fName, lName, id)
    {
      this -> testScores = scores;
    }

    char calculate()
    {
      int avg = 0, sum = 0;

      for (auto i : testScores)
        sum += i;

      avg = sum/testScores.size();
      char grade;

      if (avg >= 90 && avg <= 100)
         grade = 'O';
      else if(avg >= 80 && avg <= 90)
         grade = 'E';
      else if(avg >= 70 && avg <= 80)
         grade = 'A';
      else if(avg >= 55 && avg <= 75)
         grade = 'P';
      else if(avg >= 40 && avg <= 55)
         grade = 'D';
      else if(avg < 40)
         grade = 'T';

      return grade;
    }
};

int main()
{
	string firstName, lastName;
	int id, numScores;

  cin >> firstName >> lastName >> id >> numScores;

  vector<int> scores;
	for (int i = 0; i < numScores; i++)
  {
  	int tmpScore;
  	cin >> tmpScore;
	  scores.push_back(tmpScore);
  }

  Student* s = new Student(firstName, lastName, id, scores);
	s -> printPerson();

  cout << "Grade: " << s -> calculate() << "\n";

  return 0;
}
