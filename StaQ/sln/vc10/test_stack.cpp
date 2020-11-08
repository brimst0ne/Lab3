#include "Stack.h"

#include <gtest.h>

TEST(Stack, can_create_Stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> v(5));
}

TEST(Stack, can_create_Stack_with_zero_size)
{
	ASSERT_NO_THROW(Stack<int> v(0));
}

TEST(Stack, throws_when_creates_Stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> v(-5));
}



TEST(Stack, can_create_copied_Stack)
{
	Stack<int> v(10);

	ASSERT_NO_THROW(Stack<int> v1(v));
}



TEST(Stack, copied_Stack_has_its_own_memory)
{
	Stack<int>A(5);
	Stack<int>B(A);
	EXPECT_NE(A.GetMemory(), B.GetMemory());
}

TEST(Stack, can_get_size)
{
	Stack<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(Stack, can_get_start_index)
{
	Stack<int> v(4);

	EXPECT_EQ(0, v.GetFirstElem());
}

TEST(Stack, IsFull)
{
	Stack<int>q(1);
	int m = 2;
	q.PushElem(m);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Stack, IsEmpty)
{
	Stack<int>q(1);
	int m = 2;
	q.PushElem(m);
	q.PopElem();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Stack, push_and_pop_element)
{
	Stack<int>A(5);
	int a[6];
	for (int i = 0; i < 6; i++)
	{
		a[i] = 4 * i;
	}
	for (int i = A.GetFirstElem(); i < A.GetSize(); i++)
	{
		A.PushElem(a[i]);
	}
	EXPECT_EQ(A.PopElem(), 16);
}

TEST(Stack, find_in_nonexisting_Stack)
{
	Stack<int>a;
	ASSERT_ANY_THROW(a.FindElem(1));
}

TEST(Stack, find_in_empty_Stack)
{
	Stack<int>a(1);
	int b = 2;
	a.PushElem(b);
	a.PopElem();
	ASSERT_ANY_THROW(a.FindElem(2));
}
TEST(Stack, find_in_Stack)
{
	Stack<int>a(2);
	int b = 2;
	int c = 3;
	a.PushElem(b);
	a.PushElem(c);
	EXPECT_EQ(a.FindElem(1), 0);
}
TEST(Stack, find_element_in_Stack_2)
{
	Stack<int>a(2);
	int b = 2;
	int c = 3;
	a.PushElem(b);
	a.PushElem(c);
	EXPECT_EQ(a.FindElem(2), 1);
}
TEST(Stack, min_element_in_Stack)
{
	Stack<int>a(2);
	int b = 2;
	int c = 3;
	a.PushElem(b);
	a.PushElem(c);
	EXPECT_EQ(a.MinElem(), 2);
}
TEST(Stack, min_element_in_empty_Stack)
{
	Stack<int>a;
	ASSERT_ANY_THROW(a.MinElem());
}
