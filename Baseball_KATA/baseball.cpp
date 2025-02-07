#include <string>
#include <stdexcept>
using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& question) : question(question){}

	GuessResult guess(const string& guessNumber)
	{
		assertIligalArgument(guessNumber);

		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}
		else
		{
			int strike = 0;
			int ball = 0;
			for (int i = 0; i < 3; i++)
			{
				if (guessNumber[i] == question[i])
					strike++;
				else 
				{
					for (int j = 0; j < 3; j++)
					{
						if (i == j) continue;
						if (guessNumber[i] == question[j])
							ball++;
					}
				}
			}
			return { false, strike, ball };
		}
	}

	void assertIligalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters");

		for (char ch : guessNumber)
		{
			if (!('0' <= ch && ch <= '9'))
				throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber))
			throw invalid_argument("Must not have the same number");
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] ||
			guessNumber[2] == guessNumber[0];
	}
private:
	string question;
};
