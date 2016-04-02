#include "stdafx.h";
#include <stdlib.h>;
#include "./../src/CircularListsMerge.cpp";

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class CircularListsMergeSpec
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
			newNode->data = num;
			newNode->next = NULL;
			return newNode;
		}

		void addNode(struct node **head, int data){
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
		void make_it_circular(struct node *head){
			struct node *temp = head;
			while (head->next != NULL){
				head = head->next;
			}
			head->next = temp;
		}
		int is_correct(struct node *head, int *arr, int len){
			int i = 0;
			while (head != NULL){
				int data = head->data;
				if (arr[i]!=data){
					return 0;
				}
				else{
					i++;
					head = head->next;
				}

				if (head == NULL){
					return 0;
				}
				if (i == len){
					return 1;
				}
			}
		}
		void mrnd_sort(int *arr, int len){
			for (int i = 0; i < len - 1; i++){
				for (int j = 0; j < len - i - 1; j++){
					if (arr[j] > arr[j + 1]){
						int t = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = t;
					}
				}
			}
		}

		[TestMethod, Timeout(1000)]
		void Sample1_CircularListsMerge()
		{
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			int len = merge_circularlists(&head1, &head2);

			Assert::AreEqual(-1, len, L"Failed sample 0 for NULL case in LL", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Sample2_CircularListsMerge()
		{
			int nums[5] = { 1, 3,5 };
			int nums2[5] = { 2, 4,6 };
			//Last 1 is for checking whether A is circular or not .6 should again point to 1
			int ans[10] = { 1, 2, 3, 4,5,6,1 };
			
			int l1 = 3, l2 = 3, i;
			struct node *head1 = NULL;
			struct node *head2 = NULL;
			for (i = l1 - 1; i >= 0; i--){
				addNode(&head1, nums[i]);
			}
			for (i = l2 - 1; i >= 0; i--){
				addNode(&head2, nums2[i]);
			}
			make_it_circular(head1);
			make_it_circular(head2);

			int len = merge_circularlists(&head1, &head2);
			int check = is_correct(head1, ans, len + 1);
			Assert::AreEqual(l1+l2, len, L"Failed for sample 2 in CLL 2", 1, 2);
			Assert::AreEqual(1, check, L"Failed for sample 2 in CLL 2", 1, 2);
		};


	};
}
