#include "Queue.h"

#include <gtest.h>

TEST(Queue, can_create_Queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> v(5));
}

TEST(Queue, can_create_Queue_with_zero_size)
{
	ASSERT_NO_THROW(Queue<int> v(0));
}

TEST(Queue, throws_when_create_Queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> v(-5));
}

TEST(Queue, IsFull)
{
	Queue<int>q(1);
	int m = 2;
	q.push(m);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Queue, IsEmpty)
{
	Queue<int>q(1);
	int m = 2;
	q.push(m);
	q.pop();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Queue, can_create_copied_Queue)
{
	Queue<int> v(10);

	ASSERT_NO_THROW(Queue<int> v1(v));
}

TEST(Queue, copied_Queue_has_its_own_memory)
{
	Queue<int>A(5);
	Queue<int>B(A);
	EXPECT_NE(A.GetMemory(), B.GetMemory());
}

TEST(Queue, can_get_size)
{
	Queue<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(Queue, can_get_start_index)
{
	Queue<int> v(4);

	EXPECT_EQ(0, v.GetFirst());
}

TEST(Queue, pushAndpop)
{
	Queue<int>A(5);
	int a[6];
	for (int i = 0; i < 6; i++)
	{
		a[i] = 4 * i;
	}
	for (int i = A.GetFirst(); i < A.GetSize(); i++)
	{
		A.push(a[i]);
	}
	EXPECT_EQ(A.pop(), 0);
}
TEST(Queue, findInNULLQueue)
{
	Stack<int>a;
	ASSERT_ANY_THROW(a.find(1));
}

TEST(Queue, findInEmptyQueue)
{
	Queue<int>a(1);
	int b = 2;
	a.push(b);
	a.pop();
	ASSERT_ANY_THROW(a.find(2));
}
TEST(Queue, findInQueue)
{
	Queue<int>a(2);
	int b = 2;
	int c = 3;
	a.push(b);
	a.push(c);
	EXPECT_EQ(a.find(1), 0);
}
TEST(Queue, findInQueue2)
{
	Queue<int>a(2);
	int b = 2;
	int c = 3;
	a.push(b);
	a.push(c);
	EXPECT_EQ(a.find(2), 1);
}
TEST(Queue, minInQueue)
{
	Queue<int>a(2);
	int b = 2;
	int c = 3;
	a.push(b);
	a.push(c);
	EXPECT_EQ(a.min(), 2);
}
TEST(Queue, minInEmptyQueue)
{
	Queue<int>a;
	ASSERT_ANY_THROW(a.min());
}



