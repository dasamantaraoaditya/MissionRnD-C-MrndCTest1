//ArraySequences
#include "stdafx.h"
#include <stdlib.h>
#include "./../src/ArraySequences.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class ArraySequencesSpec
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
		int compare_arrays(int *res, int *ans){
			for (int i = 0; i < 6; i++){
				if (res[i] != ans[i]){
					return 0;
				}
			}
			return 1;
		}

		[TestMethod, Timeout(2000)]
		void Sample1_ArraySequences()
		{

			int *res = find_sequences(NULL,0);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Null case failed for Array Sequences", 1, 2);
		};

		[TestMethod, Timeout(2000)]
		void Sample2_ArraySequences()
		{
			int input[10] = { 1, 2, 3, 5, 10, 15, 30, 60 };
			int ans[6] = { 0, 2, 3, 5, 5, 7 };
			int len = 8;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Sample2 Case failed for ArraysSequences", 1, 2);
		};
		

		
	};
}
