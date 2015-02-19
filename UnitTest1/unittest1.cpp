#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include "../textBuddy/textBuddy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::string nameOfFile= "testFile1.txt";

const std::string WORD_REPORT = "report";

namespace UnitTest1
{		
	TEST_CLASS(searchTest) {
	public:
		TEST_METHOD(searchWordOne) {
			TextBuddy test(nameOfFile);
			std::vector<std::string> exactMatch;
			std::string existingString[2]={"report submission", "submit v0.0",};
			Assert::IsTrue(test.searchWord(WORD_REPORT, exactMatch));
			Assert::AreEqual(1, int(exactMatch.size()));
			for (int i=0; i<1; i++) {
				Assert::AreEqual(existingString[i], exactMatch[0]);
			}
			exactMatch.clear();			
		}	
	};

	TEST_CLASS(sortTest) {
    public:
		TEST_METHOD(sortAlphabetically) {
			TextBuddy test(nameOfFile);
			std::string expectedAlphabeticallySortedLines[8] = {
															"Add task.",
															"display tasks.",
															"report submission",
															"submit v0.0",		
															"test tomorrow",
															"The module is fun.",
															"unit testing now.",
															"University is fun.",
															};
			test.sortLines();

			for(int j = 0; j < 8; j++) {
				Assert::AreEqual(expectedAlphabeticallySortedLines[j],test.lineNumber(j+1));
			}
		}
	};

}