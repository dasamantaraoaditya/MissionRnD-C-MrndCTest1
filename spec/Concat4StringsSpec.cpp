//Concat4Strings
//ArraySequences
#include "stdafx.h"
#include <stdlib.h>
#include "./../src/Concat4Strings.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Concat4StringsSpec
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
		void Sample1_Concat4Strings()
		{

			char *res = concat_4strings(NULL, NULL,NULL,NULL);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Null case failed for Concat 4 Strings", 1, 2);
		};
		
		[TestMethod, Timeout(2000)]
		void Sample2_Concat4Strings()
		{
			char str[4][100] = { "bd", "ab", "fg", "yz" };
			char ans[10] = "abdfgyz";
			char *res = concat_4strings(str[0], str[1], str[2], str[3]);
			int check = 0;
			check = strcmp(res, ans);
			Assert::AreEqual(0, check, L"Null case failed for Concat 4 Strings", 1, 2);
		};



	};
}
