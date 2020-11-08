#include "Stack.h"

#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> v(5));
}

TEST(Stack, can_create_stack_with_zero_size)
{
    ASSERT_NO_THROW(Stack<int> v(0));
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(Stack<int> v(-5));
}



TEST(Stack, can_create_copied_stack)
{
 Stack<int> v(10);

  ASSERT_NO_THROW(Stack<int> v1(v));
}



TEST(Stack, copied_stack_has_its_own_memory)
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

  EXPECT_EQ(0, v.GetFirst());
}

TEST(Stack, IsFull)
{
	Stack<int>q(1);
	int m = 2;
	q.push(m);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Stack, IsEmpty)
{
	Stack<int>q(1);
	int m = 2;
	q.push(m);
	q.pop();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Stack, pushAndpop)
{
	Stack<int>A(5);
	int a[6];
	for (int i = 0; i < 6; i++)
	{
		a[i] = 4 * i;
	}
	for (int i = A.GetFirst(); i < A.GetSize(); i++)
	{
		A.push(a[i]);
	}
	EXPECT_EQ(A.pop(), 16);
}

TEST(Stack, findInNULLStack)
{
	Stack<int>a;
	ASSERT_ANY_THROW(a.find(1));
}

TEST(Stack, findInEmptyStack)
{
	Stack<int>a(1);
	int b = 2;
	a.push(b);
	a.pop();
	ASSERT_ANY_THROW(a.find(2));
}
TEST(Stack, findInStack)
{
	Stack<int>a(2);
	int b = 2;
	int c = 3;
	a.push(b);
	a.push(c);
	EXPECT_EQ(a.find(1),0);
}
TEST(Stack, findInStack2)
{
	Stack<int>a(2);
	int b = 2;
	int c = 3;
	a.push(b);
	a.push(c);
	EXPECT_EQ(a.find(2), 1);
}
TEST(Stack, minInStack)
{
	Stack<int>a(2);
	int b = 2;
	int c = 3;
	a.push(b);
	a.push(c);
	EXPECT_EQ(a.min(), 2);
}
TEST(Stack, minInEmptyStack)
{
	Stack<int>a;
	ASSERT_ANY_THROW(a.min());
}


