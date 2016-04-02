#include "stdafx.h"
#include <stdlib.h>
#include "./../src/BetweenDays.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class BetweenDaysSpec
	{
	private:
		TestContext^ testContextInstance;
	public: 
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		#pragma endregion 

		struct node * createNode(int num) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->data= num;
			newNode->next = NULL;
			return newNode;
		}

		void addNode(struct node **head,int data){
			struct node * cur = createNode(data);
			if (*head == NULL){
				*head = cur;
			}
			else{
				struct node *temp = *head;
				cur->next = temp;
				*head = cur;
			}
		}
		
		[TestMethod, Timeout(2000)]
		void Sample1_BetweenDays()
		{
			int days = between_days(NULL, NULL);
			Assert::AreEqual(-1, days, L"Between Dates Null Case Failed", 1, 2);
		};

	
		
		[TestMethod, Timeout(2000)]
		void Sample2_BetweenDays()
		{
			int dates[2][8] = { { 0, 2, 0, 4, 2, 0, 1, 6 }, { 0, 4, 0, 4, 2, 0, 1, 6 } };

			struct node *date1head = NULL, *date2head = NULL;
			for (int i = 7; i >= 0; i--){
				addNode(&date1head, dates[0][i]);
				addNode(&date2head, dates[1][i]);
			}

			int days = between_days(date1head, date2head);
			Assert::AreEqual(1, days, L"Date between 2nd April and 4th April failed", 1, 2);
		};
		
	};
}
